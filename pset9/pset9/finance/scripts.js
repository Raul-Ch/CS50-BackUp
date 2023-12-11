
// Add an event listener to the password input field
document.getElementById('password').addEventListener('input', validatePassword);

// Function to validate the password
function validatePassword() {
    var password = document.getElementById('password').value;
    var passwordRegex = /^(?=.*[a-zA-Z])(?=.*\d|\W).+$/;

    // Check if the password meets the requirements
    if (passwordRegex.test(password)) {
        document.getElementById('Consideration').textContent = "Consideration: Good password!";
        document.getElementById('Note').textContent = "";
    } else {
        document.getElementById('Consideration').textContent = "Consideration: ";
        document.getElementById('Note').textContent = "User passwords need to have some number of letters, numbers, and/or symbols.";
    }
}
