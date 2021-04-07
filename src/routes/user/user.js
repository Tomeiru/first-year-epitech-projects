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
        const id = query.getUserIdFromEmail(email, db);

        if (id == undefined) {
            response.status(404).send('{"msg": "Not found"}');
            return;
        }
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
        const data = {
            email: request.body.email,
            password: request.body.password,
            created_at: request.body.created_at,
            name: request.body.name,
            firstname: request.body.firstname,
            id: request.params.id
        };

        if (!data.email || !data.password || !data.created_at || !data.name || !data.firstname || isNaN(data.id)) {
            response.status(400).send('{"msg": "Bad request"}');
            return;
        }
        query.updateUserInfos(id, request, response, db);
    });

    router.delete('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            response.status(400).send('{"msg": "Bad request"}');
            return;
        }
        query.deleteUser(response, id, db);
    });

    return (router);
};