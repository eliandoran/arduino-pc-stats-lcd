const {monitor} = require('../dist/lib').getCore();
const parse = require("./parser");

const DataSender = require("datasender");

const { globalShortcut } = require("electron");

function start() {
    const sender = new DataSender();

    sender.on("ready", () => {
        monitor.on('initialized', (refresh) => {
            const pc = refresh.pc;
            const commandSender = sender.getCommandSender();
            console.log("hardware monitor loaded, initial values: ", pc)

            let hotkeysOK = true;
            hotkeysOK &= globalShortcut.register("Super+[", () => {
                commandSender.goToPrevPage();
            });

            hotkeysOK &= globalShortcut.register("Super+]", () => {
                commandSender.goToNextPage();
            });
                    
            if (!hotkeysOK) {
                console.error("Registration failed.");
            }            
        })
    
        monitor.on('refresh', (refresh) => {
            const pc = refresh.pc
            const data = parse(pc);
                 
            console.log("data:", new Date());
            sender.sendData(data);
        });
    });

    sender.on("read", (data) => {
        console.log("<", data.trimRight());
    });

    sender.on("write", (data) => {
        console.log(">", data.trimRight());
    });

    sender.start();
}

module.exports = start;