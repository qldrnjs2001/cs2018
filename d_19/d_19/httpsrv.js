const http = require("http");

const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Hello nodejs! it's Chryso Milo!\n");
});

server.listen(8080, "211.230.117.178", () => {
    console.log("server is running...");
});