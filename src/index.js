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

const authRoute = require('./routes/auth/auth.js');
const userRoute = require('./routes/user/user.js');
const todoRoute = require('./routes/todos/todos.js');

const authVerif = require('./middleware/auth.js');

app.use(bodyParser.json());

app.use('/', authRoute(db));
app.use(authVerif);
app.use('/user', userRoute(db));
app.use('/todos', todoRoute(db));

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});