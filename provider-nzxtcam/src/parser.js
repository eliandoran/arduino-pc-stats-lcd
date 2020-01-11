const { camelCase } = require("./utils");

function parse(pc) {
    const data = {};

    data.cpus = pc.cpus.map((cpu) => ({
        usage: cpu.load,
        freq: parseInterval(cpu, "frequency"),
        fanSpeed: parseInterval(cpu, "fanSpeed"),
        temperature: parseInterval(cpu, "temperature")
    }));

    data.gpus = pc.gpus.map((gpu) => ({
        usage: gpu.load,
        freq: parseInterval(gpu, "frequency"),
        fanSpeed: parseInterval(gpu, "fanSpeed"),
        temperature: parseInterval(gpu, "temperature")
    }));

    return data;
}

function parseInterval(obj, propertyName) {
    return {
        min: obj[camelCase("min", propertyName)],
        max: obj[camelCase("max", propertyName)],
        current: obj[propertyName]
    };
}

module.exports = parse;