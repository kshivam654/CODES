const path = require('path');

const express = require('express');

const router = express.Router();

const rootDir = require('../util/path');

const adminData = require('./admin');

router.get('/', (request, respond, next) => {
    // console.log('In the  another middlewhere');
    //.. handle the request
    // console.log(adminData.products);
    // respond.sendFile(path.join(rootDir, 'views', 'shop.html'));
    const products = adminData.products;
    respond.render('shop', {prods: products, docTitle: 'Shop'});
});

module.exports = router;