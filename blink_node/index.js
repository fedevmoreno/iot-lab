const {Board, Led} = require('johnny-five');

let myBoard, myLed, myRedLed;

myBoard = new Board();

myBoard.on('ready', function(){
   myLed = new Led(13);
   myLed.strobe(1000);
   myRedLed = new Led(8);
   myRedLed.strobe(500);

   this.repl.inject({
      ledControl: myLed,
      redLedControl: myRedLed
   });
});

myBoard.on('error', function(err){
   console.log(err);
});