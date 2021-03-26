const jwt = require('jsonwebtoken');

module.exports = function auth(request, response, next) {
    const auth = request.headers.authorization;

    response.set('Content-Type', 'application/json');
    if (auth) {
        const token = auth.split(' ')[1];

        jwt.verify(token, process.env.SECRET, (err, user) => {
            if (err) {
                throw err;
            }
            request.user = user;
            next();
        });
    } else
        response.send('{"msg":"No token, authorization denied"}');
}