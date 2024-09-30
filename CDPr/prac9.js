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
console.log("Database is Connected!");
var sql= "CREATE TABLE employee (name VARCHAR(255), address VARCHAR(255))";
//Query
conn.query(sql,function(err,result){
if(err)
throw err;
console.log("Employee Table is Created");
});
});
