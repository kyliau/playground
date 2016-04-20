const AWS_ACCESS_KEY_ID     = 'AKIAI3XCMPYZETTHC6MQ';
const AWS_SECRET_ACCESS_KEY = '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';
const AWS_REGION            = 'us-east-1';

var aws = require('aws-sdk');
aws.config.update({
    region          : AWS_REGION,
    accessKeyId     : AWS_ACCESS_KEY_ID,
    secretAccessKey : AWS_SECRET_ACCESS_KEY
});

//var db = new aws.DynamoDB();
//new aws.DynamoDB().listTables({}, function(err, data) {
//    console.log("\nList tables");
//    if (err) {
//        console.log(err, err.stack);
//    } else {
//        console.log(data.TableNames);
//    }
//});

// Describe table
new aws.DynamoDB().describeTable({TableName: "2012"}, function(err, data) {
    console.log("\nDescribe table");
    if (err) {
        console.log(err, err.stack);
    } else {
        console.log(data.Table.KeySchema);
    }
});

// Query table
var db = new aws.DynamoDB.DocumentClient();

var params = {
    TableName: '2012',
    KeyConditionExpression: '#t = :ticker and #d between :date1 and :date2',
    ExpressionAttributeNames: {
        '#t': 'Ticker',
        '#d': 'Date'
    },
    ExpressionAttributeValues: {
        ':ticker': 'UKRPI Index',
        ':date1' : '2012-01-01',
        ':date2' : '2012-06-30'
    }
};

db.query(params, function(err, data) {
    console.log("\nQuery table");
    if (err) {
        console.log(err, err.stack);
    } else {
        console.log(data);
    }
});

db.scan({TableName: "2012"}, function(err, data) {
    if (err) {
        console.log(err);
    } else {
        console.log(data);
    }
});
