const { response } = require("express");

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
    const sql = "SELEFT * FROM user WHERE id = ?";

    db.query(sql, [id], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
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

function getUserInfosFromEmail(response, email, db) {
    const sql = "SELEFT * FROM user WHERE email = ?";

    db.query(sql, [email], (err, result) => {
        if (err) {
            response.send('{"msg": "internal server error"}');
            return;
        }
        response.send(JSON.stringify({
            id: result[0].id,
            email: result[1].email,
            name: result[2].name,
            firstname: result[3].firstname,
            password: result[4].password,
            created_at: result[5].created_at
        }));
    });
}

module.exports = {
    sendAllUsersInfo,
    sendUserInfosFromId,
    getUserInfosFromEmail
};