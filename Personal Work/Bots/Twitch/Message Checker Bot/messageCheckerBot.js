
const tmi = require('tmi.js');

// Define configuration options
const opts = {
	identity: {
		username: 'userName',
		password: 'oauth:123abc'
	},

	//List of channels
	channels: [
		'channel1'
	] //End channel list
}; //End opts
 
// Create a client with our options
const client = new tmi.client(opts);

// Register our event handlers (defined below)
client.on('message', onMessageHandler);
client.on('connected', onConnectedHandler);

// Connect to Twitch:
client.connect();

//List of banned words
var bandWords = ["word1, "word2"];

// Called every time a message comes in
function onMessageHandler (target, userstate, msg, self) {

	// Ignore messages from the bot and the broadcaster
	if (self || userstate.username === target.split('#').pop()) { return; }

	//Checks if a banned word was found in the message
	if (messageChecker(msg.toLowerCase().split(" ")) == true)
	{

		//Tries to time out user from channel
		client.timeout(target, userstate.username, 300, "Said the b word").then((data) => {
			//Loggs command in console
			console.log(`* ${userstate.username} was timed out for saying a banned word`);
		}).catch((err) => {
			//Logs that the user could not be timed out
			console.log(`* ${userstate.username} could not be timed out despite saying a banned word`);
		});

	} // end if
	else
	{

		//Logs that the message did not contain any of the banned words
		console.log(`* "${msg}" from ${userstate.username} was cleared`);

	} //End else

} //End messageHandeler
 

// Called every time the bot connects to Twitch chat
function onConnectedHandler (addr, port) {
	console.log(`* Connected to ${addr}:${port}`);
} //End onConnectedHandler


//This will check the message to see if there are any of the banned words in it
function messageChecker(msg)
{

	//Checks if a band word is in the message
	for(i in bandWords)
	{

		//Nested loop for looping through message
		for(j in msg)
		{

			console.log(`* ${bandWords[i]} ${msg[j]}`);

			//Checks if the current word from the banned words array is in the message
			if(bandWords[i] == msg[j])
			{

				//Returns true as a banned word was found
				return true;

			} //End if

		} //End inner loop

	} //End for

	//Returns false as no banned words were found
	return false
} //End messageChecker
