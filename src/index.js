require('dotenv').config();

const app = require('express')();
const mysql = require('mysql2');
const bodyParser = require('body-parser');

const PORT = process.env.PORT;

const db = mysql.createConnection({
    host: process.env.MYSQL_HOST,
    database: process.env.MYSQL_DATABASE,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
});

db.connect((err) => {
    if (err)
        throw err;
    console.log("Connected to the database");
});

const register = require('./register.js');
const login = require('./login.js');
const auth = require('./middleware/auth.js');
const userRoute = require('./routes/user/user.js');
const todoRoute = require('./routes/todos/todos.js');

app.use(bodyParser.json());

app.post('/register', (request, response) => register(request, response, db));
app.post('/login', (request, response) => login(request, response, db));
app.use(auth);
app.use('/user', userRoute(db));
app.use('/todos', todoRoute(db));

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});