var mysql=require('mysql');
var conn=mysql.createConnection({
host:"localhost",
user:"root",
password:"1234",
database:"ayush"
});
conn.connect(function(err){
if(err)
throw err;
console.log("Database is Connected!");
var sql= "CREATE TABLE employeee (name VARCHAR(255), address VARCHAR(255))";
//Query
conn.query(sql,function(err,result){
if(err)
throw err;
console.log("Employee Table is Created");
});
});