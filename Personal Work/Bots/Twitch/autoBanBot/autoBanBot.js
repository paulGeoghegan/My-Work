
const tmi = require('tmi.js');

// Define configuration options
const opts = {
	identity: {
		username: 'userName',
		password: 'oauth:1234abcd'
	},

	//List of channels
	channels: [
		'channel1',
		'channel2'
	] //End channel list
}; //End opts
 
// Create a client with our options
const client = new tmi.client(opts);

// Register our event handlers (defined below)
client.on('message', onMessageHandler);
client.on('connected', onConnectedHandler);

// Connect to Twitch:
client.connect();

// Called every time a message comes in
function onMessageHandler (target, userstate, msg, self) {

	// Ignore messages from the bot and non moderators
	if (self || userstate.username !== target.split('#').pop()) { return; }

	//This splits up the command wherever there will be a space e.g. 1 command 2 userName 3 reason
	const commandName = msg.split(' ');

	//This will check which command the broadcaster wants to use by passing the first part of the commandName array to a switch case NOTE: the 0th element of the array should contain the command
	switch(commandName[0].toLowerCase()) {

		//Bans the user
		case '!ban':

			//Converts all elements after the 1st element in the commandName array to a string called reason
			const reason = commandName.slice(2, commandName.length).join(' ');

			//This loop will ban the user in each chat
			for(let i = 0;i < opts.channels.length;i++)
			{

				//Tries to ban user from channel
				client.ban(opts.channels[i], commandName[1], reason).then(function() {

					//Loggs command in console
					console.log(`* Executed ${commandName[0]} command in ${opts.channels[i]} channel`);    

					//This shows who has been banned and why
					client.action(opts.channels[i], `${commandName[1]} has been banned. Reason: ${reason}`);

				}, function(err) {

					//Logs error in console
					console.log(err in ${opts.channels[i]});

				}); //End error checking

			} //End for

			break;
			//Unbanns a user
		case '!unban':

			//This loop will unban a user in all chats
			for(let i = 0;i < opts.channels.length;i++)
			{

				//Unbanns user from chat
				client.unban(opts.channels[i], commandName[1]).then(function() {

					//logs command on console
					console.log(`* Executed ${commandName[0]} command in ${opts.channels[i]} channel`);

					//This shows who has been unbanned
					client.action(opts.channels[i], `${commandName[1]} has been unbanned`);

				}, function(err) {

					//Logs error in console
					console.log(err in ${opts.channels[i]});

				}); //End error checking

			} //End for

			break;
		default:
			console.log(`* Unknown command ${commandName[0]}`);
	} //End switch case
} //End messageHandeler
 
// Called every time the bot connects to Twitch chat
function onConnectedHandler (addr, port) {
	console.log(`* Connected to ${addr}:${port}`);
}