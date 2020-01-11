const FLUSH_INTERVAL = 10;

class CommandSender {
    constructor(port) {
        this.port = port;
        this.queue = [];
        this.timer = null;
    }

    queueCommand(command, ...args) {   
        let output = [ command, ...args ].join(" ") + "\r\n";        
        this.queue.push(output);
        this.processQueue();
    }

    processQueue() {
        if (this.timer === null) {
            this.timer = setInterval(this.processQueueInterval.bind(this), FLUSH_INTERVAL);
        }
    }

    processQueueInterval() {
        let output = this.queue.shift();
        console.log("send:", output);        
        this.port.write(output);

        if (this.queue.length == 0) {
            clearInterval(this.timer);
            this.timer = null;
        }
    }
    
    setRegister(id, value) {
        this.queueCommand("s", id, value);
    }
    
}

module.exports = CommandSender;