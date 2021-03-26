const jwt = require('jsonwebtoken');

function generateToken(email) {
    const secret = process.env.SECRET;
    const payload = {
        email: email
    };
    const token = jwt.sign(payload, secret);

    return (token);
}

module.exports = { generateToken };