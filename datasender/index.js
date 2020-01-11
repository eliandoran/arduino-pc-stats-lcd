const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const map = require("./mapper");
const CommandSender = require("./command");

class DataSender {
    start(callback) {
        console.time("connect");

        const port = new SerialPort("COM3", {
            baudRate: 115200
        });
         
        const parser = port.pipe(new Readline());
        this.command = new CommandSender(port);
        
        parser.on("data", (data) => {
            data = data.toString("utf8").trim();    
            console.log("recv:", data);
        
            if (data == "Ready.") {
                console.timeEnd("connect");
                callback();
            }
        });
    }

    sendData(data) {
        const output = map(data);
        for (const id of Object.keys(output)) {
            const value = output[id];
            this.command.setRegister(id, value);
        }
    }
}

module.exports = DataSender;