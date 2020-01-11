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
    console.log("recv:", data);

    if (data == "Ready.") {
        console.timeEnd("connect");        

        const output = map(parsedData);
        for (const id of Object.keys(output)) {
            const value = output[id];
            command.setRegister(port, id, value);
        }

        console.log(output);
    }
});