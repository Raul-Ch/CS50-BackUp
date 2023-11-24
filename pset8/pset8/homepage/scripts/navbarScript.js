// Use a function to load the navigation bar into the specified container
function loadNavbar() {
  // Fetch the container element
  var container = document.getElementById('navbar-container');

  fetch('../navbar.html')  // Adjust the path to go up one level to the root directory
    .then(response => response.text())
    .then(data => {
      container.innerHTML = data;
    });
}

loadNavbar();
