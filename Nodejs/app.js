// const http = require('http'); --> removed as the app.listen(); works for an alternatively
const express = require('express');

const bodyParser = require('body-parser');

const adminRoutes = require('./routes/admin');

const shopRouters = require('./routes/shop');

const app = express();


app.use(bodyParser.urlencoded({extended: false}));

// commented this dummy request handling out as its not doing anything it was to show how to jmup from one request to another lol
// app.use((request, respond, next) => {
//     console.log('In the middlewhere');
//     next(); // allows requesto to go to another middlewherer
// });

app.use('/admin', adminRoutes);

app.use(shopRouters);

// const routes = require('./routes');
// console.log(routes.someText);
// const server = http.createServer(routes.handler);

//for any random page to show 404 page not found
app.use('/', (request, respond, next) =>{
    respond.status(404).send('<h1>Page not found!</h1>');
});

// const server = http.createServer(app);

// server.listen(3000);
//  or we can sorten this to.
app.listen(3000);
