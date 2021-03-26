const express = require('express');
const router = express.Router();
const query = require('./user.query.js');

router.use((request, response, next) => {
    next();
});

module.exports = function userRoute(db) {
    router.get('/', (request, response) => {
        query.sendAllUsersInfo(response, db);
    });

    router.get('/todos', (request, response) => {

    });

    router.get('/:id', (request, response) => {
        query.sendUserInfosFromId(response, request.params.id, db);
    });

    router.get('/:email', (request, response) => {
        query.getUserInfoFromEmail(response, request.params.email, db);
    });

    router.put('/:id', (request, response) => {

    });

    router.delete('/:id', (request, response) => {

    });

    return (router);
};