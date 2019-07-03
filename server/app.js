var express = require('express');
const nodeMailer = require('nodemailer');
var app = express();
var port = 9030;
var server = require('http').createServer(app);
var io = require('socket.io')(server);
const Gpio = require('onoff').Gpio;
const led = new Gpio(23, 'out');
const button = new Gpio(24, 'in', 'both');
var mon=Math.floor((Math.random() * 50) + 1);

const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
const sport = new SerialPort('/dev/ttyS0');
const parser = sport.pipe(new Readline({ delimiter: '\r\n' }));

app.use(express.static(__dirname + '/'));


io.on('connection', function(socket){
  console.log('the sockets are connected');
  parser.on('data', function (data) {

    var str = data;
    var res = str.split(",");
    console.log(res[0]);
  });

  function buttonRead(err, state) {

    if(state == 1) {
      console.log("BUTTON IS ON");
      socket.emit('gpio', {value:1});
    }
  }

// pass the callback function to the
// as the first argument to watch()
  button.watch(buttonRead);

  socket.on('gpioStat', function (data) {

    console.log(data);
  });

  socket.on('send', function (data) {
    mon=Math.floor((Math.random() * 50) + 1);
    console.log(data);
    console.log(mon);
    led.writeSync(1); //turn on LED
    setTimeout(function(){
      led.writeSync(0);
    }, 5);

  //write to Arduino
  sport.write('2'+'\n', (err) => {
      if (err) {
        return console.log('Error on write: ', err.message);
      }
      console.log('message written');
    });


  setTimeout(function(){
  //write to Arduino
    sport.write('L'+'\n', (err) => {
        if (err) {
          return console.log('Error on write: ', err.message);
        }
        console.log('message written');
    });

  }, 500);

  //check to see if user entered something
  if (data.r!=""){
    console.log("EMAIL= "+data.r);
    let transporter = nodeMailer.createTransport({
      host: 'smtp.gmail.com',
      port: 465,
      secure: true,  //true for 465 port, false for other ports
      auth: {
          user: 'iyaporepository@gmail.com',
          pass: 'ayosalome'
      }
    });

        let mailOptions = {
            from: '"Your Name" <iyaporepository@gmail.com>', // sender address
            to:  data.r, // list of receivers
            subject: 'Iyapo Repository x Black Unicorn Library & Archives Project' // Subject line
            // text: 'Hello world?', // plain text body
            // html: '<b>Hello world?</b>' // html body
        };

        let message = {
          to: '<'+data.r+'>',

        // Subject of the message
          subject: 'Iyapo Repository x Black Unicorn Library & Archives Project',
        // HTML body
          html:
            '<p>Welcome to the Rare Media Division. <br/><br> The current collection has been curated by Bekezela Mguni and the Black Unicorn Library & Archives Project. <img src="cid:nyan@example.com"/></p>',
          attachments: [
            {   // utf-8 string as an attachment
              filename: 'monolith-'+mon+'.html',
              path: 'http://iyaporepository.org/_monolith/monolith-'+mon+'.html'
            }
          ]
        }

          transporter.sendMail(message, (error, info) => {
            if (error) {
                console.log(error);
                res.status(400).send({success: false})
            } else {
                res.status(200).send({success: true});
            }
          });


    }

  });
});

server.listen(9030);
