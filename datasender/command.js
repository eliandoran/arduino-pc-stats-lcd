const FLUSH_INTERVAL = 2;

class CommandSender {
    constructor(port, writeCallback) {
        this.port = port;
        this.queue = [];
        this.timer = null;
        this.writeCallback = writeCallback;
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
        this.port.write(output);

        if (this.writeCallback != null) {
            this.writeCallback(output);
        }

        if (this.queue.length == 0) {
            clearInterval(this.timer);
            this.timer = null;
        }
    }
    
    setRegister(id, value) {
        this.queueCommand("s", id, value);
    }

    goToNextPage() {
        this.queueCommand("n");
    }

    goToPrevPage() {
        this.queueCommand("p");
    }
    
}

module.exports = CommandSender;