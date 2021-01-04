import os
import string

def txt_convert(txt_list):
	"""This function will convert a text string to a binary one"""

	bin_str = ""
	char_dict = {}
	alpha_list = list(string.ascii_letters[:int(len(string.ascii_letters)/2)])
	front = "01100000"

	#Adds a space to the dict
	char_dict["01100000"] = " "

	#Creates dict to convert from text to binary
	for i in range(0, 2):

		#Loops through alpha_list and creates dict
		for j in range(0, len(alpha_list)):

			#Gets binary number to corospond with alphabet
			lr_num = num_convert(j+1)

			#Adds element to dict
			char_dict[alpha_list[j]] = front[:int(len(front)-len(lr_num))]+lr_num

		#This changes front to work with upper case chars
		front = "01000000"

		#This changes the alpha_list to upper case letters
		alpha_list = list(string.ascii_letters[int(len(string.ascii_letters)/2):])

	#This will concatinate the result from the char_list on to the end of the bin_str and then concatinate a space after it
	for char in txt_list:
		bin_str+=char_dict[char]+" "

	#returns the new binary string
	return bin_str


def bin_convert(bin_input):
	"""This function will convert a binary string to a text one"""

	txt_str = ""
	bin_list = txt_convert(string.ascii_letters).split()
	alpha_list = list(string.ascii_letters)
	char_dict = {}

	#Creates dict to be used for conversion
	for i in range(0, len(alpha_list)):
		char_dict[bin_list[i]] = alpha_list[i]

	#This will concatinate the result from the char_dict on to the end of the txt_str
	for char in bin_input:
		txt_str+=char_dict[char]

	#Returns new text string
	return txt_str


def num_convert(bin_num ):
	"""This will convert an intager to a binary number"""

	bin_str = ""

	#This will get the list of remainders using the % operator
	while bin_num > 0:
		bin_str = str(bin_num%2)+bin_str
		bin_num = int(bin_num / 2)

	#Returns bin_str
	return bin_str


option = 0

#Asks the user whether they want to enter the input or use a file
print("Please choose an option:\n1. Use the input file\n2. Manually enter a value")

#Gets user input
while option != 1 and option != 2:
	#Validates input
	try:
		option = int(input("Please enter a value"))
	except:
		print("Invalid input please try again")

#Checks what the user entered
if option == 1:

	#Checks if the input file exists
	try:
		#Opens input file for reading
		file = open("input.txt", "r")
	except:

		#Lets the user know that the file did not exist and then creates it
		print("The input file does not exist let me create it and open it for you")

		#Opens the input file for writing
		file = open("input.txt", "w")

		#Writes to the file to help the user
		file.write("""Here I have made the file for you follow the instructions below
		1. Please remove this text, 
		2. type your input, 
		3. save the file and
		4. return to the program
		""")

		#Closes file
		file.close()

		#This opens the output.txt file for the user
		os.system('cmd /c "input.txt"')

		#Asks for input while waiting for user
		input("Press enter to continue:\n")

		#re-opens file for reading
		file = open("input.txt", "r")

	#Stores contents of the file
	user_input = file.read()

	#Closes file
	file.close

elif option == 2:

	#Gets an input from the user
	user_input = input("Please enter your string:\n")

else:

	#Lets the user know that something went wrong
	print("Something has gone wrong please retry")
	exit()


#Checks what kind of string the user entered
if option == 1:
	#This will convert a text string to a binary one
	user_input = txt_convert(list(user_input))
elif option ==2:
	#This will convert a binary string to a text one
	user_input = bin_convert(user_input.split())
else:
	Print("Something went wrong please try again")

#Opens file for writing output to
file = open("output.txt", "w")
 
#Writes output to file
file.write(user_input)

#Closes file
file.close()

#This opens the output.txt file for the user
os.system('cmd /c "output.txt"')
