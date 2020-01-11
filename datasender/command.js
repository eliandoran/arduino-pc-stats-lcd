class CommandSender {
    constructor(port) {
        this.port = port;
    }

    sendCommand(command, ...args) {   
        let output = [ command, ...args ].join(" ") + "\r\n";
        console.log("send:", output);
        this.port.write(output);
    }
    
    setRegister(id, value) {
        this.sendCommand("s", id, value);
    }
    
}

module.exports = CommandSender;