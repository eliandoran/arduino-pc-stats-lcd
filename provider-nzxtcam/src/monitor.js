const {monitor} = require('../dist/lib').getCore();
const parse = require("./parser");

const DataSender = require("datasender");

function start() {
    const sender = new DataSender();

    sender.start(() => {
        monitor.on('initialized', (refresh) => {
            const pc = refresh.pc
            console.log("hardware monitor loaded, initial values: ", pc)
        })
    
        monitor.on('refresh', (refresh) => {
            const pc = refresh.pc
            const data = parse(pc);
            
            require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\data.json", JSON.stringify(pc, null, 4), () => {});
            require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\parsed.json", JSON.stringify(data, null, 4), () => {});        
            console.log("data:", new Date());
            sender.sendData(data);
        });
    });    
}

module.exports = start;