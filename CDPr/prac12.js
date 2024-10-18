var mysql=require('mysql');
var conn=mysql.createConnection({
host:"localhost",
user:"root",
password:"",
database:"sam"
});
conn.connect(function(err){
if(err)
throw err;
conn.query("DELETE FROM employee WHERE name='Rohit'",function (err, result, fields){
if(err)
throw err;
console.log("Delete data successfully");
console.log(result);
});
});
