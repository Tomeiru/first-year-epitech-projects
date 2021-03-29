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
        const email = request.user.email;
        const id = query.getUserIdFromEmail(response, email, db);

        query.sendUserTodos(response, id, db);
    });

    router.get('/:value', (request, response) => {
        const value = request.params.value;

        if (isNaN(value))
            query.sendUserInfosFromEmail(response, value, db);
        else
            query.sendUserInfosFromId(response, value, db);
    });

    router.put('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            return;
        }
        query.updateUserInfos(id, request, response, db);
    });

    router.delete('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            return;
        }
        query.deleteUser(id, response, db);
    });

    return (router);
};