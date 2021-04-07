const bcrypt = require('bcryptjs');

function getUserIdFromEmail(email, db) {
    const sql = "SELECT id FROM user WHERE email = ?";

    db.query(sql, [email], (err, result) => {
        if (err)
            return (undefined);
        return (result[0].id);
    });
}

function sendAllUsersInfo(response, db) {
    const sql = "SELECT * FROM user";
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
                email: result.email,
                name: result.name,
                firstname: result.firstname,
                password: result.password,
                created_at: result.created_at
            });
        }
        response.send(JSON.stringify(array));
    });
}

function sendUserInfosFromId(response, id, db) {
    const sql = "SELECT * FROM user WHERE id = ?";

    db.query(sql, [id], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        } else if (result[0] == undefined) {
            response.send('{"msg": "Not found"}');
            return;
        }
        response.send(JSON.stringify({
            id: result[0].id,
            email: result[0].email,
            name: result[0].name,
            firstname: result[0].firstname,
            password: result[0].password,
            created_at: result[0].created_at
        }));
    });
}

function sendUserInfosFromEmail(response, email, db) {
    const sql = "SELECT * FROM user WHERE email = ?";

    db.query(sql, [email], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        } else if (result[0] == undefined) {
            response.send('{"msg": "Not found"}');
            return;
        }
        response.send(JSON.stringify({
            id: result[0].id,
            email: result[0].email,
            name: result[0].name,
            firstname: result[0].firstname,
            password: result[0].password,
            created_at: result[0].created_at
        }));
    });
}

function sendUserTodos(response, id, db) {
    const sql = "SELECT * FROM todo WHERE user_id = ?";
    let array = [];

    db.query(sql, [id], (err, results) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        }
        for (let i = 0; i < results.length; i++) {
            array.push({
                id: result[i].id,
                title: result[i].title,
                description: result[i].description,
                created_at: result[i].created_at,
                due_time: result[i].due_time,
                status: result[i].status,
                user_id: result[i].user_id
            });
        }
        response.send(JSON.stringify(array));
    });
}

function updateUserInfos(response, data, db) {
    const salt = bcrypt.genSaltSync(10);
    const hash = bcrypt.hashSync(data.password, salt);

    const sql = "UPDATE user SET email = ?, password = ?, created_at = ?, name = ?, firstname = ? WHERE id = ?";
    const args = [data.email, hash, data.created_at, data.name, data.firstname, data.id];

    db.query(sql, args, (err) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        } else if (result.affectedRows == 0) {
            response.send('{"msg": "Not found"}');
            return;
        }
        response.send(JSON.stringify({
            id: data.id,
            email: args[0],
            password: args[1],
            created_at: args[2],
            name: args[3],
            firstname: args[4]
        }));
    });
}

function deleteUser(response, id, db) {
    const sql = "DELETE FROM user WHERE id = ?";

    db.query(sql, [id], (err) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        } else if (result.affectedRows == 0) {
            response.send('{"msg": "Not found"}');
            return;
        }
        response.send(`{"msg": "successfully deleted record number: ${id}"}`);
    });
}

module.exports = {
    getUserIdFromEmail,
    sendAllUsersInfo,
    sendUserInfosFromId,
    sendUserInfosFromEmail,
    sendUserTodos,
    updateUserInfos,
    deleteUser
};