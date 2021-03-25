const jwt = require('jsonwebtoken');

function generateToken(email) {
    const secret = process.env.SECRET;
    const payload = {
        email: email
    };
    const token = jwt.sign(payload, secret);

    return (token);
}

function verifyToken(token, email) {
    const secret = process.env.SECRET;
    const payload = jwt.verify(token, secret);

    return (payload.email === email)
}

module.exports = { generateToken, verifyToken };