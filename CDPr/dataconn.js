var mysql = require('mysql');

// Create a connection to the database
var conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",  // Leave empty if there's no password
    database: "sam"
});


// Connect to the database
conn.connect(function(err) {
    if (err) {
        throw err;
    }
    console.log("Connection successful");
});
