// Function to validate the password
function validatePassword() {
    console.log("validatePassword function called");
    var password = document.getElementById('password').value;
    //  regular expression to enforce a minimum length of 11 characters for the password, which includes at least 8 letters, 2 numbers, and 1 symbol
    var passwordRegex = /^(?=(?:.*[a-zA-Z]){8})(?=(?:.*\d){2})(?=(?:.*\W){1})[a-zA-Z\d\W]{11,}$/;
    var parentElement = document.getElementById('password').parentNode;
    var errorLabel = document.getElementById('errorLabel');

    // Check if the password meets the requirements
    if (passwordRegex.test(password)) {
        console.log("Password is valid");
        document.getElementById('Consideration').textContent = "Consideration:";
        document.getElementById('Note').textContent = ": Good password!";
        document.getElementById('Consideration').className = 'good_password';
        document.getElementById('Note').className = 'good_password';
    } else {
        console.log("Password is invalid");
        document.getElementById('Consideration').textContent = "Consideration: ";
        document.getElementById('Note').textContent = "User passwords need to have at least 8 number of letters, 2 numbers, and 1 symbol.";
        document.getElementById('Consideration').className = 'validate';
        document.getElementById('Note').className = 'validate';
    }
}


    // Check if the passwords coincide
    if (password === confirmation) {
        document.getElementById('confirmation').textContent = "";
    } else {
        document.getElementById('confirmation').className = 'validate';
        document.getElementById('confirmation').className = "Passwords do not match.";
    }

// Show password
// Function to toggle password visibility
function togglePasswordVisibility() {
    var passwordInput = document.getElementById('password');
    var toggleButton = document.getElementById('togglePasswordBtn');

    // Toggle the type attribute of the password input field
    if (passwordInput.type === 'password') {
        passwordInput.type = 'text';
        toggleButton.textContent = 'Hide Password';
    } else {
        passwordInput.type = 'password';
        toggleButton.textContent = 'Show Password';
    }
}
