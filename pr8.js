var mysql = require('mysql');


var conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",  
    database: ""
});


// Connect to the database
conn.connect(function(err) {
    if (err) {
        throw err;
    }
    console.log("Connection successful");
});