require = require('esm')(module /*,options*/);
var http = require('http');
var u=require('uppercase');
http.createServer(function(req,res){
    res.writeHead(200,{'content-type':'text/html'});
    res.write(u("hello world"));
    res.end();
}).listen(8080);



