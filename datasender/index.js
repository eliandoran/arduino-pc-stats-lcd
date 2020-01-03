const SerialPort = require("serialport");

const port = new SerialPort("COM3");

port.write("n\n", (err) => {
    console.log(err);
});