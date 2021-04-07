const express = require('express');
const router = express.Router();
const query = require('./auth.query.js');

router.use((request, response, next) => {
    response.set('Content-Type', 'application/json');
    next();
});

module.exports = function authRoute(db) {
    router.post('/register', (request, response) => {
        query.registerUser(request, response, db);
    });

    router.post('/login', (request, response) => {
        query.loginUser(request, response, db);
    });

    return (router);
};