var SerialPort = require('serialport');
var Readline = require('@serialport/parser-readline')

var port = new SerialPort('/dev/cu.SLAB_USBtoUART', {baudRate: 115200});
var read_data;

const parser = port.pipe(new Readline({ delimiter: '\r\n' }))
parser.on('data', function (data) {
  read_data = data;
  console.log('Read:', read_data);
});
