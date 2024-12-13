




 var fs=require('fs') 
 
  fs.writeFile('test.txt', 'Welcome to this file from node js', function(err) 
 { 
     if (err) throw err; 
     console.log('Saved!'); 
 }); 
 



// var fs=require('fs') 
 
// fs.rename('test.txt', 'test2.txt', function(err) 
// { 
//     if (err) throw err; 
//     console.log('File Renamed Successfully!'); 
// }); 
 



// var fs=require('fs') 
 
// fs.unlink('test2.txt', function(err) 
// { 
//     if (err) throw err; 
//     console.log('File Deleted Successfully!'); 
// }); 