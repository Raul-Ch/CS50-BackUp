import os
import re

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    rows = db.execute("SELECT username, cash FROM users WHERE id = ?", (user_id,))
    cash = (rows[0]["cash"]) if rows else None

    transactions = db.execute(
        "SELECT symbol, name, shares, price, timestamp, shares * price AS total FROM transactions WHERE user_id = ? GROUP BY symbol",
        user_id,
    )

    total_rows = db.execute(
        "SELECT SUM(shares * price) AS overall_total FROM transactions WHERE user_id = ?",
        user_id,
    )
    overall_total = (
        float(total_rows[0]["overall_total"])
        if total_rows and total_rows[0]["overall_total"] is not None
        else 0
    )
    total = overall_total + float(cash)

    # FORMAT
    cash = usd(cash)
    total = usd(total)

    return render_template(
        "index.html", cash=cash, transactions=transactions, total=total
    )


@app.route("/profile", methods=["GET", "POST"])
@login_required
def profile():
    user_id = session["user_id"]
    rows = db.execute("SELECT username, cash FROM users WHERE id = ?", (user_id,))
    username = rows[0]["username"] if rows else None
    cash = rows[0]["cash"] if rows else None
    cash = usd(cash)

    if request.method == "POST":
        form_name = request.form.get("form_name")
        if form_name == "Change Password":
            password = request.form.get("password")

            # Ensure password was submitted
            if not password:
                return apology("Must provide password", 400)

            else:
                # Validate the password
                password_valid = validate_password(password)

            # If there are validation errors, redirect to apology page with error message
            if not password_valid:
                return apology(
                    "Invalid password. Please make sure your password meets the criteria.",
                    400,
                )

            # Hash the password
            hashed_password = generate_password_hash(password)

            # Insert the new user into the database
            db.execute(
                "UPDATE users SET hash = ? WHERE id = ?",
                hashed_password,
                user_id,
            )

            # Redirect to login page after successful registration
            flash("Password Update successful!")
            return redirect(url_for("profile"))

        elif form_name == "Update Money":
            cashAmount = request.form.get("cashAmount")
            if not cashAmount:
                return apology("Must provide cash amount to increment", 400)

            else:
                db.execute(
                    "UPDATE users SET cash = cash + ? WHERE id = ?",
                    cashAmount,
                    user_id,
                )

                # Redirect to login page after successful registration
                flash("Cash update successful!")
                return redirect(url_for("profile"))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("profile.html", username=username, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        symbol = symbol.strip().upper()
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("shares must be a valid number", 400)

        if not symbol:
            return apology("must provide symbol", 400)
        elif shares <= 0:
            return apology("invalid number of shares", 400)
        else:
            dic_symbol = lookup(symbol)
            if dic_symbol is None:
                return apology("invalid symbol", 400)
            else:
                user_id = session["user_id"]
                rows = db.execute(
                    "SELECT username, cash FROM users WHERE id = ?", (user_id,)
                )
                money = rows[0]["cash"] if rows else None
                cost = dic_symbol["price"] * int(shares)
                cash = money - cost

                if cash < 0:
                    return apology(
                        "user cannot afford the number of shares at the current price",
                        402,
                    )

                else:
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
                    foundshares = db.execute(
                        "SELECT shares FROM transactions WHERE user_id = ? AND symbol = ?",
                        user_id,
                        symbol,
                    )
                    foundshares = foundshares[0]["shares"] if foundshares else None
                    if not foundshares:
                        db.execute(
                            "INSERT INTO transactions (user_id, symbol, shares, price, timestamp, name, type) VALUES (?, ?, ?, ?, CURRENT_TIMESTAMP, ?, ?)",
                            user_id,
                            symbol,
                            shares,
                            dic_symbol["price"],
                            dic_symbol["name"],
                            "b",
                        )
                    else:
                        shares = shares + foundshares
                        db.execute(
                            "UPDATE transactions SET shares = ? WHERE user_id = ? AND symbol = ?",
                            shares,
                            user_id,
                            symbol,
                        )
                    transactions = db.execute(
                        "SELECT symbol, name, shares, price, timestamp, shares * price AS total FROM transactions WHERE user_id = ?  GROUP BY symbol",
                        user_id,
                    )
                    total_rows = db.execute(
                        "SELECT SUM(shares * price) AS overall_total FROM transactions WHERE user_id = ?",
                        user_id,
                    )
                    overall_total = (
                        float(total_rows[0]["overall_total"])
                        if total_rows and total_rows[0]["overall_total"] is not None
                        else 0
                    )
                    total = overall_total + float(cash)
                    # FORMAT
                    cash = usd(cash)
                    total = usd(total)
                    flash("Transaction: Bought shares, successful!")
                    return render_template(
                        "index.html", cash=cash, transactions=transactions, total=total
                    )
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions = db.execute(
        "SELECT symbol, name, shares, price, type, timestamp, shares * price AS total FROM transactions WHERE user_id = ? ",
        user_id,
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        symbol = symbol.strip().upper()
        # Ensure username was submitted
        if not symbol:
            return apology("must provide symbol", 400)
        else:
            dic_symbol = lookup(symbol)
            if dic_symbol is None:
                return apology("invalid symbol", 400)
            else:
                dic_symbol['price'] = usd(dic_symbol['price'])
                return render_template("quoted.html", dic_symbol=dic_symbol)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Get user input from the registration form
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("must provide username", 400)

        if not password:
            return apology("must provide password", 400)

        if not confirmation:
            return apology("must provide password confirmation", 400)

        # Validate the password
        password_valid = validate_password(password)

        # Check if the passwords match
        passwords_match = password == confirmation

        # If there are validation errors, redirect to apology page with error message
        if not password_valid or not passwords_match:
            return apology(
                "Invalid password. Please make sure your password meets the criteria and confirmation matches.",
                400,
            )

        # Check if the username is available
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(rows) > 0:
            return apology(
                "Username already taken. Please choose a different username.", 400
            )

        # Hash the password
        hashed_password = generate_password_hash(password)

        # Insert the new user into the database
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            username,
            hashed_password,
        )

        # Redirect to home page after successful registration
        session["user_id"] = db.execute(
            "SELECT id FROM users WHERE username = ?", username
        )[0]["id"]
        return redirect(url_for("index"))

    else:
        return render_template("register.html")


def load_index():
    user_id = session["user_id"]
    rows = db.execute("SELECT username, cash FROM users WHERE id = ?", (user_id,))
    username = rows[0]["username"] if rows else None
    rows = db.execute(
        "SELECT id, username, cash FROM users WHERE username = ?", username
    )
    cash = rows[0]["cash"] if rows else None
    user_id = rows[0]["id"] if rows else None
    transactions = db.execute(
        "SELECT symbol, name, shares, price, timestamp, shares * price AS total FROM transactions WHERE user_id = ?  GROUP BY symbol",
        user_id,
    )
    total_rows = db.execute(
        "SELECT SUM(shares * price) AS overall_total FROM transactions WHERE user_id = ?",
        user_id,
    )
    overall_total = (
        float(total_rows[0]["overall_total"])
        if total_rows and total_rows[0]["overall_total"] is not None
        else 0
    )
    total = overall_total + float(cash)
    # FORMAT
    cash = usd(cash)
    total = usd(total)
    flash("Registration successful! You can now log in.")

    return render_template(
        "index.html", cash=cash, transactions=transactions, total=total
    )


def validate_password(password):
    password_regex = (
        r"^(?=(?:.*[a-zA-Z]){5})(?=(?:.*\d){2})(?=(?:.*\W){1})[a-zA-Z\d\W]{8,}$"
    )

    if re.match(password_regex, password):
        return True
    else:
        return False


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        symbol = symbol.strip().upper()
        shares = int(request.form.get("shares"))

        if not symbol:
            return apology("must provide symbol", 400)
        elif not shares:
            return apology("must provide shares", 400)
        else:
            dic_symbol = lookup(symbol)
            if dic_symbol is None:
                return apology("invalid symbol", 400)
            else:
                user_id = session["user_id"]
                rows = db.execute(
                    "SELECT username, cash FROM users WHERE id = ?", (user_id,)
                )
                money = rows[0]["cash"] if rows else None
                cost = dic_symbol["price"] * int(shares)
                cash = money + cost

                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
                db.execute(
                    "INSERT INTO transactions (user_id, symbol, shares, price, timestamp, name, type) VALUES (?, ?, ?, ?, CURRENT_TIMESTAMP, ?, ?)",
                    user_id,
                    symbol,
                    shares,
                    dic_symbol["price"],
                    dic_symbol["name"],
                    "s",
                )

                # (TODO) NEED TO UPDATE AMOUNT OF SHARES IN TRANSACTIONS WHERE SYMBOL AND USER:ID
                user_shares = db.execute(
                    "SELECT shares FROM transactions WHERE user_id = ? AND symbol = ?",
                    user_id,
                    symbol,
                )
                user_shares = user_shares[0]["shares"] if user_shares else None
                newshares = user_shares - shares
                if newshares < 0:
                    return apology("not enough shares to sell", 400)
                else:
                    db.execute(
                        "UPDATE transactions SET shares = ? WHERE user_id = ? AND symbol = ?",
                        newshares,
                        user_id,
                        symbol,
                    )

                transactions = db.execute(
                    "SELECT symbol, name, shares, price, timestamp, shares * price AS total FROM transactions WHERE user_id = ?  GROUP BY symbol",
                    user_id,
                )
                total_rows = db.execute(
                    "SELECT SUM(shares * price) AS overall_total FROM transactions WHERE user_id = ?",
                    user_id,
                )
                overall_total = (
                    float(total_rows[0]["overall_total"])
                    if total_rows and total_rows[0]["overall_total"] is not None
                    else 0
                )
                total = overall_total + float(cash)
                # FORMAT
                cash = usd(cash)
                total = usd(total)
                flash("Transaction: Sell shares, successful!")
                return render_template(
                    "index.html", cash=cash, transactions=transactions, total=total
                )
    else:
        user_id = session["user_id"]
        symbols = db.execute(
            "SELECT DISTINCT symbol FROM transactions WHERE user_id = ?", user_id
        )
        return render_template("sell.html", symbols=symbols)
