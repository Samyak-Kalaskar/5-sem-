var mysql = require('mysql');

var conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "123456"
});

conn.connect(function(err) {
    if (err) {
        throw err;
    }
    console.log("Connection successful");
});
