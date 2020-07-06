const path = require('path');

const express = require('express');

const router = express.Router();

const rootDir = require('../util/path');

router.get('/', (request, respond, next) => {
    // console.log('In the  another middlewhere');
    //.. handle the request
    respond.sendFile(path.join(rootDir, 'views', 'shop.html'));
});

module.exports = router;