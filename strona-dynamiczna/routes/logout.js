const express = require('express');
const passport = require('passport');
const router = express.Router();

// to get body from submitted post request 
router.use(express.urlencoded({extended: true}));

// user model
const User = require('../models/user');

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

router.get('/logout', (req, res) => {
    req.logout(function(err) {
        if(err) {
            return next(err);
        }
    });
    res.redirect('/');
});

module.exports = router;