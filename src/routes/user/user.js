const express = require('express');
const router = express.Router();
const query = require('./user.query.js');

router.use((request, response, next) => {
    next();
});

module.exports = function userRoute(db) {
    router.get('/', (request, response) => {

    });

    router.get('/:id', (request, response) => {

    });

    router.put('/:id', (request, response) => {

    });

    router.delete('/:id', (request, response) => {

    });

    return (router);
};