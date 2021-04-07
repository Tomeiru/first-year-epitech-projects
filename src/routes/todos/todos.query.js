const bcrypt = require('bcryptjs');

function sendAllTodosInfo(response, db) {
    const sql = "SELECT * FROM todo";
    let array = [];

    db.query(sql, (err, results) => {
        if (err) {
            response.status(500).send('{"msg": "internal server error"}');
            throw err;
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
            response.status(500).send('{"msg": "internal server error"}');
            throw err;
        } else if (result[0] == undefined) {
            response.status(404).send('{"msg": "Not found"}');
            return;
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

function createTodo(response, data, db) {
    const sql = "INSERT INTO todo (title,description,due_time,user_id,status) VALUES (?,?,?,?,?)";
    const args = [data.title, data.description, data.due_time, data.user_id, data.status];

    db.query(sql, args, (err, result) => {
        if (err) {
            response.status(500).send('{"msg": "internal server error"}');
            throw err;
        }
        sendTodoInfosFromId(response, result.insertId, db);
    });
}

function updateTodoInfos(response, data, db) {
    const sql = "UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?";
    const args = [data.title, data.description, data.due_time, data.user_id, data.status, data.id];

    db.query(sql, args, (err) => {
        if (err) {
            response.status(500).send('{"msg": "internal server error"}');
            throw err;
        } else if (result.affectedRows == 0) {
            response.status(404).send('{"msg": "Not found"}');
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

function deleteTodo(response, id, db) {
    const sql = "DELETE FROM todo WHERE id = ?";

    db.query(sql, [id], (err) => {
        if (err) {
            response.status(500).send('{"msg": "internal server error"}');
            throw err;
        } else if (result.affectedRows == 0) {
            response.status(404).send('{"msg": "Not found"}');
            return;
        }
        response.send(`{"msg": "successfully deleted record number: ${id}"}`);
    });
}

module.exports = {
    sendAllTodosInfo,
    sendTodoInfosFromId,
    createTodo,
    updateTodoInfos,
    deleteTodo,
};