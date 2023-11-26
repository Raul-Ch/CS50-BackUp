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
        const lines = data.split('\n');

        // Remove the header line (if present)
        if (lines.length > 0) {
            lines.shift();
        }

        // Parse each line into a quote and an author
        const quotes = lines.filter(line => line.trim() !== '').map(line => {
            const [quote, author] = line.split(',');
            return { quote: quote.trim().replace(/"/g, ''), author: author.trim().replace(/"/g, '') };
        });

        // Function to display a random quote
        function getRandomQuote() {
            // Get a random index
            const randomIndex = Math.floor(Math.random() * quotes.length);

            // Get the random quote and author
            const randomQuote = quotes[randomIndex];

            // Display the quote and author on the webpage
            document.getElementById('quote').textContent = randomQuote.quote;
            document.getElementById('author').textContent = `- ${randomQuote.author}`;
        }

        // Initial display
        getRandomQuote();
    })
    .catch(error => console.error('Error fetching the file:', error));
