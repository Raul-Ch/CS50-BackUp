import React, { useEffect } from 'react';

const Navbar = () => {
  useEffect(() => {
    // Add logic to fetch and load the navbar content
  }, []);

  return (
    <nav id="navbar-container" className="navbar navbar-expand-lg bg-transparent">
      <div className="container-fluid">
        <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent"
          aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className="collapse navbar-collapse" id="navbarSupportedContent">
          <ul className="navbar-nav me-auto mb-2 mb-lg-0 mx-auto">
            <li className="nav-item">
              <a className="nav-link active" aria-current="page" href="/index">Home</a>
            </li>
            <li className="nav-item">
              <a className="nav-link" href="#">About Us</a>
            </li>
            <li class="nav-item">
                    <a class="nav-link" href="#">Shelters</a>
                </li>
          </ul>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
