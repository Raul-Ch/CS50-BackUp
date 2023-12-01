// Fetch the CSV file using the Fetch API
fetch('../text/DailyBunnyQuote.csv')
    .then(response => {
        if (!response.ok) {
            throw new Error(`Network response was not ok: ${response.status}`);
        }
        return response.text();
    })
    .then(data => {
        // Split the CSV string into an array of lines
        let lines = data.split('\n');
        if (lines[lines.length - 1] === '') {
            lines.pop();
        }

        // Remove the header line (if present)
        if (lines.length > 0) {
            lines.shift();
        }

        // Parse each line into a quote and an author
        const quotes = lines.map(line => {
            const [quote, author] = line.split('|');
            return { quote: quote.trim().replace(/"/g, ''), author: author.trim().replace(/"/g, '') };
        });

        // Function to display a random quote
        function getRandomQuote() {
            // Get a random index
            const randomIndex = Math.floor(Math.random() * quotes.length);

            // Get the random quote and author
            const randomQuote = quotes[randomIndex];

            // Display the quote and author on the webpage
            document.getElementById('quote').textContent = `"${randomQuote.quote}"`;

            // Split the author's name into an array of words
            let words = randomQuote.author.split(' ');

            // Wrap the first letter of each word in a <span> tag with class "CapitalAuthor"
            words = words.map(word => '<span class="CapitalTitle">' + word[0] + '</span>' + word.slice(1));

            // Join the words back together into a single string
            let authorWithStyledInitials = words.join(' ');

            // Set the styled author string as the HTML content of the author element
            document.getElementById('author').innerHTML = authorWithStyledInitials;
        }

        // Initial display
        getRandomQuote();
    })
    .catch(error => console.error('Error fetching the file:', error));
