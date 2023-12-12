import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    return apology("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

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
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        # Get user input from the registration form
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Validate the password
        password_valid = validate_password(password)

        # Check if the passwords match
        passwords_match = password == confirmation

        # If there are validation errors, redirect to apology page with error message
        if not password_valid or not passwords_match:
            error_message = "Invalid password. Please make sure your password meets the criteria and confirmation matches."
            flash(error_message)
            return render_template("apology.html", top="Registration Error", bottom=error_message)

        # Check if the username is available
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(rows) > 0:
            error_message = "Username already taken. Please choose a different username."
            flash(error_message)
            return render_template("apology.html", top="Registration Error", bottom=error_message)

        # Hash the password
        hashed_password = generate_password_hash(password)

        # Insert the new user into the database
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed_password)

        # Redirect to login page after successful registration
        flash("Registration successful! You can now log in.")
        return redirect("/login")

    else:
        return render_template("register.html")

def validate_password(password):
    password_regex = r"^(?=(?:.*[a-zA-Z]){8})(?=(?:.*\d){2})(?=(?:.*\W){1})[a-zA-Z\d\W]{11,}$"

    if re.match(password_regex, password):
        return True, None
    else:
        return False, "User passwords need to have at least 8 letters, 2 numbers, and 1 symbol."

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
