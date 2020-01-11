const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const map = require("./mapper");
const command = require("./command");

const parsedData = require("../provider-nzxtcam/parsed.json");

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

        command.setRegister(port, 0, 50);

        const output = map(parsedData);
        console.log(output);
    }
});