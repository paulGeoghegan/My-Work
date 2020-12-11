import os

def txt_convert(txt_list):
	"""This function will convert a text string to a binary one"""

	bin_str = ""
	char_list = {"A":"01000001", "a":"01100001", "B":"01000010", "b":"01100010"}

	for char in txt_list:
		bin_str+=char_list[char]+" "

	#returns the new binary string
	return bin_str


def bin_convert(bin_list):
	"""This function will convert a binary string to a text one"""



	#Returns new text string
	return txt_str


option = 0

#Gets an input from the user
str = input("Please enter your string:\n")

#Asks the user what kind of string this is
print("What kind of string is this?\n1. Text\n2. Binary")

#Gets users input
while option != 1 and option != 2:
	#Validates input
	try:
		option = int(input("Enter either 1 for text or 2 for binary:\n"))
	except:
		print("Please enter either 1 for text or 2 for binary as your input was invalid")

#Checks what kind of string the user entered
if option == 1:
	#This will convert a text string to a binary one
	str = txt_convert(list(str))
elif option ==2:
	#This will convert a binary string to a text one
	str = bin_convert(str.split())
else:
	Print("Something went wrong please try again")

#Opens file for writing output to
file = open("output.txt", "w")

#Writes output to file
file.write(str)

#Closes file
file.close()

#This opens the output.txt file for the user
os.system('cmd /c "output.txt"')
