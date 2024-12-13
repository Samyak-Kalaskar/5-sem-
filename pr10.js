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
console.log("Database is Connected!");
var sql= "INSERT INTO employee (name, address) VALUES ?";
var VALUES =[ ['Dhoni','Ranchi'],
['Virat','Delhi'],
['Shreyash','Mumbai'],
['Rohit','Mumbai']
];
conn.query(sql,[VALUES],function(err,result){
if(err)
throw err;
console.log("Number of Records are inserted");
});
});