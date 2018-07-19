var host = {
    address: "211.230.117.178",
    port: 13333
}

var remote = {
    address: "14.55.207.250",
    port : 13333
}

var dgram = require("dgram");
var udp_socket = dgram.createSocket("udp4");

udp_socket.on("message", (msg, remote_info) => {
    console.log("address :" + remote_info.address + ", port :", + remote_info.port);
    console.log(msg.toString());
})
udp_socket.bind(host.port, () => {
    console.log('binding port' + host.port);
});

var repl = require('repl');

var theApp = repl.start({
    prompt: 'input cmd>',
    input: process.stdin,
    output: process.stdout
}).context;

theApp.io = {
    test: function() {
        console.log('test');
    },
    remote: remote,
    sendTest: function(text) {
        //var text = "hello udp!";
        udp_socket.send(Buffer(text), 0, text.length, remote.port, remote.address);
        console.log('send text :' + text);
    }
}