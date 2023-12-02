const express = require('express');
const passport = require('passport');
const router = express.Router();

// user model
const User = require('../models/user');

var comment_block = {
    username: 'default',
    section: 'default',
    comment: 'default',
    createdAt: '21:37'
};

// create passport local strategy
passport.use(User.createStrategy());

// serialize and deserialize user
passport.serializeUser(function(user, done) {
    done(null, user.id)
});

passport.deserializeUser(function(id, done) {
    User.findById(id, function(err, user) {
        done(err, user);
    })
});

// to get body from submitted post request 
router.use(express.urlencoded({extended: true}));

router.get('/login', (req, res) => {
    res.render('login');
})

router.post('/login', (req, res) => {
    const user = new User({
        username: req.body.username,
        password: req.body.password
    });

    req.login(user, (err) => {
        if(err) {
            console.log(err);
        }
        else {
            passport.authenticate('local', {failureRedirect: '/login'})(req, res, function() {
                res.redirect('/');
            });
        }
    })
})

module.exports = router;