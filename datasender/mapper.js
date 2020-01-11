const config = require("./mapping.json");
const objectPath = require("object-path");

const typeMappings = {
    "int": Math.round
};

function map(data) {
    let output = { };

    for (const path of Object.keys(config)) {
        let value = objectPath.get(data, path);
        const { id, type } = config[path];

        if (value === undefined)
            continue;

        const typeMapping = typeMappings[type];
        if (typeMapping !== undefined) {
            value = typeMapping(value);
        }

        output[id] = value;
    }
    
    return output;
}

const parsedData = require("../provider-nzxtcam/parsed.json");
const output = map(parsedData);
console.log(output);