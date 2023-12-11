// Function to validate the password
function validatePassword() {
    console.log("validatePassword function called");
    var password = document.getElementById('password').value;
    var passwordRegex = /^(?=.*[a-zA-Z])(?=.*\d|\W).+$/;
    var parentElement = document.getElementById('password').parentNode;
    var errorLabel = document.getElementById('errorLabel');

    // Check if the password meets the requirements
    if (passwordRegex.test(password)) {
        console.log("Password is valid");
        errorLabel.className = 'good_password';
        document.getElementById('Consideration').textContent = "Consideration:";
        document.getElementById('Note').textContent = ": Good password!";
    } else {
        console.log("Password is invalid");
        document.getElementById('Consideration').textContent = "Consideration: ";
        document.getElementById('Note').textContent = "User passwords need to have some number of letters, numbers, and/or symbols.";
        errorLabel.className = 'bad_password';
        parentElement.insertBefore(errorLabel, document.getElementById('password'));
    }
}
