const bcrypt = require('bcryptjs');

function sendAllTodosInfo(response, db) {
    const sql = "SELECT * FROM todo";
    let array = [];

    db.query(sql, (err, results) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        for (let i = 0; i < results.length; i++) {
            result = results[i];
            array.push({
                id: result.id,
                title: result.title,
                description: result.description,
                created_at: result.created_at,
                due_time: result.due_time,
                user_id: result.user_id,
                status: result.status
            });
        }
        response.send(JSON.stringify(array));
    });
}

function sendTodoInfosFromId(response, id, db) {
    const sql = "SELECT * FROM todo WHERE id = ?";

    db.query(sql, [id], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        }
        response.send(JSON.stringify({
            id: result[0].id,
            title: result[0].title,
            description: result[0].description,
            created_at: result[0].created_at,
            due_time: result[0].due_time,
            user_id: result[0].user_id,
            status: result[0].status,
        }));
    });
}

function createTodo(request, response, db, id) {
    const title = request.body.title;
    const description = request.body.description;
    const due_time = request.body.due_time;
    const user_id = request.body.user_id;
    const status = request.body.status;

    const sql = "UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ?";
    const args = [title, description, due_time, user_id, status];

    response.send(JSON.stringify({
        id: id,
        title: args[0],
        description: args[1],
        due_time: args[2],
        user_id: args[3],
        status: args[4]
    }));
}

function updateTodoInfos(id, request, response, db) {
    const title = request.body.title;
    const description = request.body.description;
    const due_time = request.body.due_time;
    const user_id = request.body.user_id;
    const status = request.body.status;

    const sql = "UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ?";
    const args = [title, description, due_time, user_id, status];

    db.query(sql, args, (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        response.send(JSON.stringify({
            title: args[0],
            description: args[1],
            due_time: args[2],
            user_id: args[3],
            status: args[4]
        }));
    });
}

function deleteTodo(id, response, db) {
    const sql = "DELETE FROM todo WHERE id = ?";

    db.query(sql, [id], (err) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        response.send(`{"msg": "successfully deleted record number: ${id}"}`);
    });
}

module.exports = {
    sendAllTodosInfo,
    sendTodoInfosFromId,
    updateTodoInfos,
    deleteTodo,
};