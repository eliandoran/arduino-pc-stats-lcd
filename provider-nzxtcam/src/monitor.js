const {monitor} = require('../dist/lib').getCore();
const parse = require("./parser");

function start() {
    monitor.on('initialized', (refresh) => {
        const pc = refresh.pc
        console.log("hardware monitor loaded, initial values: ", pc)
    })

    monitor.on('refresh', (refresh) => {
        const pc = refresh.pc
        const data = parse(pc);
        
        require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\data.json", JSON.stringify(pc, null, 4), () => {});
        require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\parsed.json", JSON.stringify(data, null, 4), () => {});
    });    
}

module.exports = start;