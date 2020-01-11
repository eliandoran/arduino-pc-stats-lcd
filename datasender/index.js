const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

console.time("connect");

const port = new SerialPort("COM3", {
    baudRate: 115200
});
 
const parser = port.pipe(new Readline());
parser.on("data", (data) => {
    data = data.toString("utf8").trim();    
    console.log("board:", data);

    if (data == "Ready.") {
        console.timeEnd("connect");
    }
});