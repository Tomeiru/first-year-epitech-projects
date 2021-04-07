const express = require('express');
const router = express.Router();
const query = require('./auth.query.js');

router.use((request, response, next) => {
    response.set('Content-Type', 'application/json');
    next();
});

module.exports = function authRoute(db) {
    router.post('/register', (request, response) => {
        const data = {
            email: request.body.email,
            name: request.body.name,
            firstname: request.body.firstname,
            password: request.body.password
        };

        if (!data.email || !data.name || !data.firstname || !data.password) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.registerUser(response, data, db);
    });

    router.post('/login', (request, response) => {
        const data = {
            email: request.body.email,
            password: request.body.password
        };

        if (!data.email || !data.password) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.loginUser(response, data, db);
    });

    return (router);
};