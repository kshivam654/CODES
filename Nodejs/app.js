// const http = require('http'); --> removed as the app.listen(); works for an alternatively
const express = require('express');

const path = require('path');

const bodyParser = require('body-parser');

const adminData = require('./routes/admin');
const shopRouters = require('./routes/shop');

const app = express();

app.set('view engine', 'pug');
app.set('views', 'views');

app.use(bodyParser.urlencoded({extended: false}));

// commented this dummy request handling out as its not doing anything it was to show how to jmup from one request to another lol
// app.use((request, respond, next) => {
//     console.log('In the middlewhere');
//     next(); // allo ws requesto to go to another middlewherer
// });

app.use(express.static(path.join(__dirname, 'public')))

app.use('/admin', adminData.routes);

app.use(shopRouters);


// const routes = require('./routes');
// console.log(routes.someText);
// const server = http.createServer(routes.handler);

//for any random page to show 404 page not found
app.use('/', (request, respond, next) =>{
    respond.status(404).render('404', {pageTitle: 'Page Not Found'});
});

// const server = http.createServer(app);

// server.listen(3000);
//  or we can sorten this to.
app.listen(8080);
