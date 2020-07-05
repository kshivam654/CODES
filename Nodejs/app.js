const http = require('http');
const express = require('express');

const app = express();

app.use((request, respond, next) => {
    console.log('In the middlewhere');
    next(); // allows requesto to go to another middlewherer
});

app.use((request, respond, next) => {
    console.log('In the  another middlewhere');
    //.. handle the request
});

// const routes = require('./routes');
// console.log(routes.someText);
// const server = http.createServer(routes.handler);
const server = http.createServer(app);

server.listen(3000);
