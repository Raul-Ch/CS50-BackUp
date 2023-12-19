from flask import Flask, flash, redirect, render_template, request, session, url_for
#from flask_session import Session
from functools import wraps

# Configure application
app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")
