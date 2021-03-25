const bcrypt = require('bcryptjs');
const { generateToken } = require('./token.js');

const sql = "INSERT INTO user (email,name,firstname,password) VALUES (?,?,?,?)";

module.exports = function register(request, response, db) {
    const email = request.body.email;
    const name = request.body.name;
    const firstname = request.body.firstname;
    const password = request.body.password;

    const salt = bcrypt.genSaltSync(10);
    const hash = bcrypt.hashSync(password, salt);

    response.set('Content-Type', 'application/json');
    db.query(sql, [email, name, firstname, hash], (err, result) => {
        if (err) {
            if (err.code == "ER_DUP_ENTRY") {
                response.send('{"msg": "account already exists"}');
                return;
            } else {
                response.send('{"msg": "internal server error"}');
                throw err;
            }
        }
        response.send(`{"token": "${generateToken(email)}"}`);
        console.log(`Create user ${email}`);
    });
};