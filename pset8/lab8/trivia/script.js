// This is a function declaration for checkAnswer which takes a boolean parameter isCorrect.
function checkAnswer(isCorrect) {
    /* This line gets all HTML elements with the class name "button1" and stores them in the buttons variable.*/
    var buttons = document.getElementsByClassName("button1");
    /*  This line gets the HTML element with the id "feedback" and stores it in the feedbackDiv variable.*/
    var feedbackDiv = document.getElementById("feedback");

    // The for loop iterates over each button and removes the classes "correct" and "incorrect" from them
    for (var i = 0; i < buttons.length; i++) {
        buttons[i].classList.remove("correct", "incorrect");
    }

    /* Checks if isCorrect is true. If it is, it adds the class "correct" to the button that triggered
     If isCorrect is false, it adds the class "incorrect" to the button*/
    if (isCorrect) {
        event.target.classList.add("correct");
        feedbackDiv.textContent = "Correct!";
        feedbackDiv.className = "correct-feedback";
    } else {
        event.target.classList.add("incorrect");
        feedbackDiv.textContent = "Incorrect";
        feedbackDiv.className = "incorrect-feedback";
    }
}

// This is a function declaration for checkFreeResponse which takes a text parameter and evaluates it.
function checkFreeResponse() {
    /* This line gets the HTML element with the id "freeResponse", from a text input field where the user enters their answer.*/
    var inputField = document.getElementById("freeResponse");
    /*  This line gets the HTML element with the id "freeResponseFeedback", which is a div where feedback will be displayed*/
    var feedbackDiv = document.getElementById("freeResponseFeedback");

    var userAnswer = inputField.value.toLowerCase(); // Convert to lowercase for case-insensitive comparison

    // Replace "Bugs Bunny" with the correct answer you are expecting
    var correctAnswer = "Bugs Bunny".toLowerCase();
    // This line sets the correct answer to "Bugs Bunny", also converted to lowercase for a case-insensitive comparison

    // This line removes the "correct-input" and "incorrect-input" classes from the input field, if they exist.
    inputField.classList.remove("correct-input", "incorrect-input");
    /* This line clears any existing text in the feedback div.*/
    feedbackDiv.textContent = '';

    /* checks if the user's answer matches the correct answer. If it does, it adds the "correct-input" class to the input field, sets the feedback text to "Correct!", and sets the feedback div's class to "correct-feedback".
    If the user's answer does not match the correct answer, it does the same but with "incorrect-input" and "incorrect-feedback" instead.*/
    if (userAnswer === correctAnswer) {
        inputField.classList.add("correct-input");
        feedbackDiv.textContent = "Correct!";
        feedbackDiv.className = "correct-feedback";
    } else {
        inputField.classList.add("incorrect-input");
        feedbackDiv.textContent = "Incorrect";
        feedbackDiv.className = "incorrect-feedback";
    }
}