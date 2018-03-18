var VirtualSerialPort = require('udp-serial').SerialPort;
var firmata = require('firmata');
var five = require("johnny-five");
var sp = new VirtualSerialPort({
    host: '192.168.4.1'
});
io.once('ready', function(){
  console.log('Io Connected');
  io.isReady = true;

  var board = new five.Board({io: io,repl:true});

  board.on("ready", function() {
  // This requires OneWire support using the ConfigurableFirmata
    var thermometer = new five.Thermometer({
        controller: "DS18B20",
        pin: 2
        });

    thermometer.on("change", function() {
    console.log(this.celsius + "°C");
    // console.log("0x" + this.address.toString(16));
  });
});
});
