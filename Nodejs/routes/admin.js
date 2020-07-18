const express = require('express');

const router = express.Router();

const rootDir = require('../util/path');

const path = require('path');

const products = [];

//this block is added before the other use as the process in nodejs use top to down approach the any url is taken as / as the first pattern must match...
// if another link is passed the default use with '/' is called .. .crazy stuff
router.get('/add-product', (request, respond, next) => {
    //.. handle the request
    // respond.sendFile(path.join(rootDir, 'views', 'add-product.html'));
    respond.render('add-product', {
        pageTitle: 'Add Product', 
        path: '/admin/add-product',
        formsCSS: true,
        productCSS: true,
        activeAddProduct: true});
});
router.post('/add-product', (request, respond, next) =>{
    // console.log(request.body);
    products.push({ title: request.body.title });
    console.log(products);
    respond.redirect('/');
});

// module.exports = router;
exports.routes = router;
exports.products = products;