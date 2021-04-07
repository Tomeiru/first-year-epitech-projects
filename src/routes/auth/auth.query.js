const bcrypt = require('bcryptjs');
const { generateToken } = require('../../token.js');

function registerUser(request, response, db) {
    const email = request.body.email;
    const name = request.body.name;
    const firstname = request.body.firstname;
    const password = request.body.password;

    const salt = bcrypt.genSaltSync(10);
    const hash = bcrypt.hashSync(password, salt);

    const sql = "INSERT INTO user (email,name,firstname,password) VALUES (?,?,?,?)";

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
}

function loginUser(request, response, db) {
    const email = request.body.email;
    const password = request.body.password;

    const sql = "SELECT password FROM user WHERE email = ?";

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
}

module.exports = {
    registerUser,
    loginUser
};