const bcrypt = require('bcryptjs');
const { generateToken } = require('../../token.js');

function registerUser(response, data, db) {
    const salt = bcrypt.genSaltSync(10);
    const hash = bcrypt.hashSync(data.password, salt);

    const sql = "INSERT INTO user (email,name,firstname,password) VALUES (?,?,?,?)";

    db.query(sql, [data.email, data.name, data.firstname, hash], (err, result) => {
        if (err) {
            if (err.code == "ER_DUP_ENTRY") {
                response.send('{"msg": "account already exists"}');
                return;
            } else {
                response.send('{"msg": "internal server error"}');
                throw err;
            }
        }
        response.send(`{"token": "${generateToken(data.email)}"}`);
        console.log(`Create user ${data.email}`);
    });
}

function loginUser(response, data, db) {
    const sql = "SELECT password FROM user WHERE email = ?";

    db.query(sql, [data.email], (err, result) => {
        const hash = result != undefined ? result[0].password : undefined;

        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        }
        if (hash != undefined && bcrypt.compareSync(data.password, hash))
            response.send(`{"token": "${generateToken(data.email)}"}`);
        else
            response.send('{"msg": "Invalid Credentials"}')
    });
}

module.exports = {
    registerUser,
    loginUser
};