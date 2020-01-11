const config = require("./mapping.json");
const objectPath = require("object-path");

function map(data) {
    let output = {};

    for (const path of Object.keys(config)) {
        const value = objectPath.get(data, path);
        const { id, type } = config[path];

        output[id] = value;
    }
    
    return output;
}

const parsedData = require("../provider-nzxtcam/parsed.json");
const output = map(parsedData);
console.log(output);