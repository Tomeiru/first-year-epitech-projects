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

    router.get('/:value', (request, response) => {
        const value = request.params.value;
        query.sendTodoInfosFromId(response, value, db);
    });

    router.post('/', (request, response) => {
        query.createTodo(request, response, db, id);
    });
    
    router.put('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            return;
        }
        query.updateTodoInfos(id, request, response, db);
    });

    router.delete('/:id', (request, response) => {
        const id = request.params.id;

        if (isNaN(id)) {
            return;
        }
        query.deleteTodo(id, response, db);
    });
}
