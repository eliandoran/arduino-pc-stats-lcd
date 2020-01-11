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
    const data = {};

    data.cpus = pc.cpus.map((cpu) => {
        return {
            usage: cpu.load,
            freq: {
                min: cpu.minFrequency,
                max: cpu.maxFrequency,
                current: cpu.frequency
            }
        };
    });

    console.log(data);

    require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\data.json", JSON.stringify(pc, null, 4), () => {});
    require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\parsed.json", JSON.stringify(data, null, 4), () => {});
})