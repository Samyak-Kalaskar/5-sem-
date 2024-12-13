
var mysql=require('mysql');
var conn=mysql.createConnection({
host:"localhost",
user:"root",
password:"",
database:""
});
conn.connect(function(err){
if(err)
throw err;
conn.query("SELECT * FROM employee",function (err, result, fields){
if(err)
throw err;
console.log(result);
});
});