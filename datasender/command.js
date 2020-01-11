function sendCommand(port, command, ...args) {   
    output = [ command, ...args ].join(" ");
    port.write(output + "\r\n");
}

function setRegister(port, id, value) {
    sendCommand(port, "s", id, value);
}

module.exports = {
    sendCommand,
    setRegister
};