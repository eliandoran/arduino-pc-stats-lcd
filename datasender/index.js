const EventEmitter = require("events");

const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const map = require("./mapper");
const CommandSender = require("./command");

class DataSender extends EventEmitter {
    constructor() {
        super();
        this.lastData = {};
    }

    start() {
        console.time("connect");

        const port = new SerialPort("COM3", {
            baudRate: 345600
        });
         
        const parser = port.pipe(new Readline());
        this.command = new CommandSender(port);
        
        parser.on("data", (data) => {
            data = data.toString("utf8").trim();                
        
            if (data == "Ready.") {
                console.timeEnd("connect");
                this.emit("ready");
            } else {
                this.emit("data", data);
            }
        });
    }

    sendData(data) {
        const output = map(data);
        for (const id of Object.keys(output)) {            
            const value = output[id];

            if (value == this.lastData[id]) {
                continue;
            }

            this.command.setRegister(id, value);
            this.lastData[id] = value;
        }
    }

    getCommandSender() {
        return this.command;        
    }

}

module.exports = DataSender;