 const bcrypt = require('bcryptjs');
const { generateToken } = require('./token.js');

const sql = "SELECT password FROM user WHERE email = ?";

module.exports = function login(request, response, db) {
    const email = request.body.email;
    const password = request.body.password;

    response.set('Content-Type', 'application/json');
    db.query(sql, [email], (err, result) => {
        const hash = result[0].password;

        if (err) {
            response.send('{"msg": "internal server error"}');
            throw err;
        }
        if (hash != undefined && bcrypt.compareSync(password, hash))
            response.send(`{"token": "${generateToken(email)}"}`);
        else
            response.send('{"msg": "Invalid Credentials"}')
    });
};