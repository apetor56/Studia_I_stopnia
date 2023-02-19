const router = require('express').Router();
const Comment = require('../models/comment');

var flag = false;
var name = 'default';

function handlePage(url) {
    router.get(url, (req, res) => {
        if(req.isAuthenticated()) {
            flag = true;
            name = req.user.username;
        } else {
            flag = false;
        }
        Comment.find({section: url})
        .sort({createdAt: -1})
        .then((result) => {
            res.render(url.substring(1), {logged: flag, username: name, comment_block: result});
        })
        .catch((err) => {
            console.log(err);
        })
    });
    
    router.post(url, (req, res) => {
        if(req.isAuthenticated()) {
            flag = true;
            name = req.user.username;
        }
        const comment = new Comment({
            username: req.user.username,
            section: url,
            comment: req.body.comment
        });
        comment.save();
        res.redirect(url);
    });
}

module.exports = {handlePage, router};