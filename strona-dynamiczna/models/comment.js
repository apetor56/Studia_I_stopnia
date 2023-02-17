const mongoose = require('mongoose');
const passportLocalMongoose = require('passport-local-mongoose');

const commentSchema = new mongoose.Schema({
    username: {
        type: String,
        required: true,
        unique: false
    },
    section: {
        type: String,
        required: true,
        unique: false
    },
    comment: {
        type: String,
        required: false 
    }
}, {timestamps: true});

// hash password
commentSchema.plugin(passportLocalMongoose);

module.exports = mongoose.model('Comment', commentSchema);