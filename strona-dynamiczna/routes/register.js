const express = require('express');
const passport = require('passport');
const router = express.Router();

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

// to get body from submitted post request 
router.use(express.urlencoded({extended: true}));

router.get('/register', (req, res) => {
    res.render('register');
})

router.post('/register', async (req, res) => {
    try {
        console.log(req.body);
        const exists = await User.findOne({
            username: req.body.username
        });

        if(exists) {
            res.redirect('/register');
        }
        else {
            const registerUser = await User.register({
                username: req.body.username,
                email: req.body.email,
                password: req.body.password
            }, req.body.password);
            if(registerUser) {
                passport.authenticate('local', {failureRedirect: '/register'})(req, res, function() {
                    res.redirect('/index');
                })
            }
            else {
                res.redirect('/register');
            }
        }
    } catch(err) {
        res.send(err);
    }
});

module.exports = router;