function sendCommand(port, command, ...args) {   
    output = [ command, ...args ].join(" ") + "\r\n";
    console.log("send:", output);
    port.write(output);
}

function setRegister(port, id, value) {
    sendCommand(port, "s", id, value);
}

module.exports = {
    sendCommand,
    setRegister
};