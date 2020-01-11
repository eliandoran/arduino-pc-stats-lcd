const {monitor} = require('../dist/lib').getCore();

function start() {
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
                freq: parseInterval(cpu, "frequency"),
                fanSpeed: parseInterval(cpu, "fanSpeed"),
                temperature: parseInterval(cpu, "temperature")
            };
        });

        data.gpus = pc.gpus.map((gpu) => ({
            usage: gpu.load,
            freq: parseInterval(gpu, "frequency"),
            fanSpeed: parseInterval(gpu, "fanSpeed"),
            temperature: parseInterval(gpu, "temperature")
        }));

        require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\data.json", JSON.stringify(pc, null, 4), () => {});
        require("fs").writeFile("D:\\Projects\\Arduino PC Stats LCD\\provider-nzxtcam\\parsed.json", JSON.stringify(data, null, 4), () => {});
    });    
}

function parseInterval(obj, propertyName) {
    return {
        min: obj[camelCase("min", propertyName)],
        max: obj[camelCase("max", propertyName)],
        current: obj[propertyName]
    };
}

function camelCase(...segments) {
    if (segments.length === 0)
        return "";

    let output = segments[0];
    for (let i=1; i<segments.length; i++) {
        let segment = (
            segments[i].substring(0, 1).toUpperCase() +
            segments[i].substring(1));
        output += segment;
    }

    return output;
}

module.exports = start;