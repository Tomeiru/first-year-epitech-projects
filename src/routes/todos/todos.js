const express = require('express');
const router = express.Router();
const query = require('./todos.query.js');

router.use((request, response, next) => {
    next();
});

module.exports = function todosRoute(db) {
    router.get('/', (request, response) => {
        query.sendAllTodosInfo(response, db);
    });

    router.post('/', (request, response) => {
        const data = {
            title: request.body.title,
            description: request.body.description,
            due_time: request.body.due_time,
            user_id: request.body.user_id,
            status: request.body.status
        };

        if (!data.title || !data.description || !data.due_time || !data.user_id || !data.status) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.createTodo(response, data, db);
    });

    router.get('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.sendTodoInfosFromId(response, id, db);
    });

    router.put('/:id', (request, response) => {
        const data = {
            title: request.body.title,
            description:  request.body.description,
            due_time: request.body.due_time,
            user_id: request.body.user_id,
            status: request.body.status,
            id: request.params.id
        };

        if (!data.title || !data.description || !data.due_time || !data.user_id || !data.status || isNaN(data.id)) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.updateTodoInfos(response, data, db);
    });

    router.delete('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        query.deleteTodo(response, id, db);
    });

    return (router);
}