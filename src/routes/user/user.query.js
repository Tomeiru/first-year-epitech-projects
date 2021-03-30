const bcrypt = require('bcryptjs');

function getUserIdFromEmail(result, email, db) {
    const sql = "SELECT id FROM user WHERE email = ?";

    db.query(sql, [email], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
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

function updateUserInfos(id, request, response, db) {
    const email = request.body.email;
    const password = request.body.password;
    const created_at = request.body.created_at;
    const name = request.body.name;
    const firstname = request.body.firstname;

    const salt = bcrypt.genSaltSync(10);
    const hash = bcrypt.hashSync(password, salt);

    const sql = "UPDATE user SET email = ?, password = ?, created_at = ?, name = ?, firstname = ? WHERE id = ?";
    const args = [email, hash, created_at, name, firstname, id];

    db.query(sql, args, (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        console.log(result.affectedRows);
        response.send(JSON.stringify({
            id: id,
            email: args[0],
            password: args[1],
            created_at: args[2],
            name: args[3],
            firstname: args[4]
        }));
    });
}

function deleteUser(id, response, db) {
    const sql = "DELETE FROM user WHERE id = ?";

    db.query(sql, [id], (err) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
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