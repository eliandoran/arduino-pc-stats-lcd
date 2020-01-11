const path = "C:\\Program Files\\NZXT CAM";

const process = require("process");
process.chdir(path);

const app = require("electron").app;
app.setPath("userData", path);

const {monitor} = require('./dist/lib').getCore()

monitor.on('initialized', (refresh) => {
    const pc = refresh.pc
    console.log("hardware monitor loaded, initial values: ", pc)
})

monitor.on('refresh', (refresh) => {
    const pc = refresh.pc
    console.log("hardware info at ", pc.timestamp, ": ", pc);
    require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\data.json", JSON.stringify(pc, null, 4), () => {});
})