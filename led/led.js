var five = require("johnny-five"),
    board = new five.Board();

board.on("ready", function() {
  
  var led = new five.Led(12);

    led.blink(2000);

})
board.on("error",function(err)  {
  console.log(err)
})