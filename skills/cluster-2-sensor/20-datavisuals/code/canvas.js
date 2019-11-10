var http = require('http').Server(app);
var io = require('socket.io')(http);
var app = require('express')();
var fs = require('fs');

// Gets index.html for webpage
app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
  // Gets stocks.txt
  app.get('/data', function(req, res) {
    res.sendFile(__dirname + '/stocks-csv.txt');
  });
});

// Read the file
filename = __dirname + '/stocks-csv.txt';
var csv_data = fs.readFileSync(filename, 'utf8').toString().split("\n");

// Parse csv_data values, skipping first line (column names)
var data = [];
for (i=1;i<csv_data.length -1; i++) {
  data[i-1] = csv_data[i];
}

// Establish socket connection and send the data
io.on('connection', function(socket){
  io.emit('transmit_data', data);
});

// Listening on localhost:3000
http.listen(3000, function() {
  console.log('listening on: 3000');
});