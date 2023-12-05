# Greets user

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html", name=request.args.get("name", "world"))


# Notice that this code defines app as the Flask application. Then, it defines the / route of app as returning the contents of index.html with the argument of name. By default, the request.args.get function will look for the name being provided by the user. If no name is provided, it will default to world.
