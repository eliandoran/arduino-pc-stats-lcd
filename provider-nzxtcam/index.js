const path = "C:\\Program Files\\NZXT CAM";

const process = require("process");
process.chdir(path);

const app = require("electron").app;
app.setPath("userData", path);

const start = require("./src/monitor");

start();