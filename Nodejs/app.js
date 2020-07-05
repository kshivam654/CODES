// const http = require('http'); --> removed as the app.listen(); works for an alternatively
const express = require('express');

const app = express();

// commented this dummy request handling out as its not doing anything it was to show how to jmup from one request to another lol
// app.use((request, respond, next) => {
//     console.log('In the middlewhere');
//     next(); // allows requesto to go to another middlewherer
// });

//this block is added before the other use as the process in nodejs use top to down approach the any url is taken as / as the first pattern must match...
// if another link is passed the default use with '/' is called .. .crazy stuff
app.use('/shivamhome', (request, respond, next) => {
    console.log('In the  another middlewhere');
    //.. handle the request
    respond.write('<h1>this is the special page for riya</h1>');


});app.use('/', (request, respond, next) => {
    console.log('In the  another middlewhere');
    //.. handle the request
    respond.write('<h1>Hello Shivam its Express</h1>');
});

// const routes = require('./routes');
// console.log(routes.someText);
// const server = http.createServer(routes.handler);



// const server = http.createServer(app);

// server.listen(3000);
//  or we can sorten this to.
app.listen(3000);
