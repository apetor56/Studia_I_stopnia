require('dotenv').config();
const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
const session = require('express-session');
const passport = require('passport');
const ejs = require('ejs');

const register_route = require('./routes/register');
const login_route = require('./routes/login');
const logout_route = require('./routes/logout');

const handlePage = require('./routes/pages').handlePage;
const route_pages = require('./routes/pages').router;

const app = express();

// register view engine
app.set('view engine', 'ejs');

// listen for requests on port 3000 (localhost)
app.listen(process.env.PORT);

// middleware and static files (like css, images)
app.use(express.static('public'));

// to get body from submitted post request 
app.use(express.urlencoded({extended: true}));

// setup session
app.use(session({
    secret: process.env.SECRET,
    resave: false,
    saveUninitialized: false
}));

// initialize passport
app.use(passport.initialize());

// use passport to deal with session
app.use(passport.session());

// connect to database
mongoose.set('strictQuery', true);
mongoose.connect(process.env.DB_CONNECT)
    .then(() => console.log('database connected'))
    .catch((err) => console.log(err));

// get and post requests for all pages
handlePage('/');
handlePage('/colors');
handlePage('/textures');
handlePage('/triangle');

app.use(route_pages);

app.use(register_route);

app.use(login_route);

app.use(logout_route);

// redirect
app.get('/index', (req, res) => {
    res.redirect('/')
});

// 404
// 'use' is for every coming request
app.use((req, res) => {
    res.render('404')
});
