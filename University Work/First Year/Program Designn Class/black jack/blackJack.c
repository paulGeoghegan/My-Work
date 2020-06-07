/*
Program description:
    A blackjack game with basic logic using an automated player. The logic was found on the Wikipedia page for
    blackjack. The program prompts the user for total amount of money, how much they will bet
    each round and amount of hands to be played.
date:
    Start: 03/12/2019 
    Last edited:06/12/2019
authors:
    Paul Geoghegan, Yasir Celtik
OS:
    Windows
Compiler:
    Mingw
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//declaring functions
char cardSort(int card);
char suitSort(int suit);
void draw(int decks[2][4][13], int *decksPtr, int *suitPtr, int *cardPtr);


//main function
int main()
{

	int deck[2][4][13];
	int x, suit, card, bet, totalMoney, hands, decks, i, userHandSize, dealerHandSize;
	char *userHand, *dealerHand;
	char *userSuit, *dealerSuit;
	int userTotal = 0, dealerTotal = 0;
	time_t t;
	char mode, suitChar, cardChar;
	bool loop;


	//seeds rand
	srand(time(0));



	//fills out deck
	for(int i = 0;i < 4;i++)
	{

		//inner loop
		for(int j = 0;j < 13;j++)
		{

			//this fills each row with the numbers 1 to 13
			deck[0][i][j] = j+1;

		} //end for

	} //end for


	//asks the user what mode they wish to play in
	printf("What mode do you wish to play the game in?\nA automated player\nT test\n\n");
	scanf("%1s", &mode);

	//gets bet amount, total money available and hands to be played
	printf("How much money do you wish for your player to have?\n");
	scanf("%d", &totalMoney);

	printf("How much will this player bet on each game?\n");
	scanf("%d", &bet);

	printf("how many hands should they play?\n");
	scanf("%d", &hands);

	printf("how many decks should the dealer have?\n");
	scanf("%d", &decks);


	//main game loop
	do
	{


		//resets values every time there is a new hand
		userTotal = 0;
		dealerTotal = 0;
		userHandSize = 2;
		dealerHandSize = 2;

		//allocates memory for dealer and user hands
		userHand = calloc(userHandSize, sizeof(char));
		userSuit = calloc(userHandSize, sizeof(char));
		dealerHand = calloc(dealerHandSize, sizeof(char));
		dealerSuit = calloc(dealerHandSize, sizeof(char));

		//prints out your total amount of money if the user is not in test mode
		if(mode == 'A' || mode == 'a')
		{

			printf("The current balance is %d\n", totalMoney);

		} //end if 


		//this gives the user and dealer there first 2 cards
		for(i = 0 ; i < 2 ; i++)
		{

			if(mode =='A' || mode == 'a')
			{

				printf("A card is dealt to the player\n");
				printf("A card is dealt to the dealer\n");

			} //end if

			//this gets a card
			draw(deck, &decks, &suit, &card);  

			//this converts the card to 2 characters so that they can be displayed propperly
			suitChar = suitSort(suit);
			cardChar = cardSort(card);

			//adds them to the memory blocks
			*(userSuit+i) = suitChar;
			*(userHand+i) = cardChar;

			//checks if the user has an ace
			if(card == 1)
			{

				if(userTotal < 11)
				{

					card = 11;

				} //end if
				else
				{

                    card = 1;

				} //end if

			} //end if
			else
			{

				//turns anything above a 10 in to a 10
				if(card > 10)
				{

					card = 10;

				} //end if

			} //end else

			//sets user total
			userTotal = userTotal + card;


			//this gets a card
			draw(deck, &decks, &suit, &card);  // <=======

			//this turns the card in to characters so that they can be propperly displayed
			suitChar = suitSort(suit);
			cardChar = cardSort(card);

			//this adds them to the memory block
			*(dealerSuit+i) = suitChar;
			*(dealerHand+i) = cardChar;

			//turns anything above a 10 in to a 10
			if(card > 10)
			{

				card = 10;

			} //end if

			//sets dealer total
			dealerTotal = dealerTotal + card;

			//displays cards drawn if user is in automatic player mode
			if(mode == 'a' || mode == 'A')
			{

			if(*(userHand+i) == '0')
			{

				printf("You drew a 10 of %c\n", *(userSuit+i));

			} //end if
			else
			{

				printf("You drew a %c of %c\n", *(userHand+i), *(userSuit+i));

			} //end else

			} //end for

		} //end for

		//printing the dealers face up card
		if(mode =='A' || mode == 'a')
		{

			printf("The dealers face up card is: %c of %c\n", *(dealerHand+0), *(dealerSuit+0));

		} //end if

		//this is where the extra cards are delt
		do
		{
            loop = true;

            switch (*(dealerHand+0))
            {
                case 2:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        loop = false;
                    }
                    if (userTotal == 15)
                    {
                        loop = false;
                    }
                    if (userTotal == 16)
                    {
                        loop = false;
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }
                    break;
                }
                case 3:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        loop = false;
                    }
                    if (userTotal == 15)
                    {
                        loop = false;
                    }
                    if (userTotal == 16)
                    {
                        loop = false;
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }case 4:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        loop = false;
                    }
                    if (userTotal == 12)
                    {
                        loop = false;
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        loop = false;
                    }
                    if (userTotal == 15)
                    {
                        loop = false;
                    }
                    if (userTotal == 16)
                    {
                        loop = false;
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 5:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        loop = false;
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        loop = false;
                    }
                    if (userTotal == 15)
                    {
                        loop = false;
                    }
                    if (userTotal == 16)
                    {  
                        loop = false;
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 6:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        loop = false;
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        loop = false;
                    }
                    if (userTotal == 15)
                    {
                        loop = false;
                    }
                    if (userTotal == 16)
                    {
                        loop = false;
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 7:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }  
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 8:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 9:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }
                    
                    break;
                }
                case 10:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        loop = false;
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 1:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }
                case 11:
                {
                    if (userTotal == 4 || userTotal == 5 || userTotal == 6 || userTotal == 7 || userTotal == 8)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 9)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 10)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 11)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 12)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 13 || userTotal == 14)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 15)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 16)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 17)
                    {
                        draw(deck, &decks, &suit, &card);
                    }
                    if (userTotal == 18 || userTotal == 19 || userTotal == 20 || userTotal == 21)
                    {
                        loop = false;
                    }

                    break;
                }//end case 11
            }//end switch      

                if (loop == true)
                {
                    //this converts the card to 2 characters so that they can be displayed propperly
                    suitChar = suitSort(suit);
                    cardChar = cardSort(card);

                    //adds them to the memory blocks
                    *(userSuit+i) = suitChar;
                    *(userHand+i) = cardChar;

                    //checks if the user has an ace
                    if(card == 1)
                    {

                        if(userTotal < 11)
                        {

                            card = 11;

                        } //end if
                        else
                        {

                            card = 1;

                        } //end if
                    }

					                //sets user total
					userTotal = userTotal + card;

                } //end if
                else
                {

                    //turns anything above a 10 in to a 10
                    if(card > 10)
                    {

                        card = 10;

                    } //end if

					                //sets user total
					userTotal = userTotal + card;

                } //end else


		} //end while loop
		while(userTotal < 21 && loop == true);

		do
		{

			//this gets a card
			draw(deck, &decks, &suit, &card);  // <=======

			//this turns the card in to characters so that they can be propperly displayed
			suitChar = suitSort(suit);
			cardChar = cardSort(card);

			//this adds them to the memory block
			*(dealerSuit+i) = suitChar;
			*(dealerHand+i) = cardChar;

			//turns anything above a 10 in to a 10
			if(card > 10)
			{

				card = 10;

			} //end if

			//sets dealer total
			dealerTotal = dealerTotal + card;

		} //end while
		while(dealerTotal < 17);

	if(mode == 'a' || mode == 'A')
	{

		printf("Your total was %d\n", userTotal);
		printf("The dealers total was %d\n", dealerTotal);

	} //end if

		//this checks to see who won this hand
		if (userTotal > 21)
		{

			totalMoney = totalMoney - bet;

			if(mode == 'a' || mode == 'A')
			{

				printf("You lost this hand\n");

			} //end if

		} //end else if
		else if (userTotal < 22 && dealerTotal > 21)
		{

			totalMoney = totalMoney + bet;

			if(mode == 'a' || mode == 'A')
			{

				printf("You won this hand\n");

			} //end if

		} //end else if
		else if (userTotal < 22 && dealerTotal < 22 && userTotal < dealerTotal)
		{

			totalMoney = totalMoney - bet;

			if(mode == 'a' || mode == 'A')
			{

				printf("You lost this round\n");

			} //end if

		} //end else if
		else if (userTotal < 22 && dealerTotal < 22 && userTotal > dealerTotal)
		{

			totalMoney = totalMoney + bet;

			if(mode == 'a' || mode == 'A')
			{

				printf("You won this hand\n");

			} //end if

		} //end else if
		else if(userTotal < 22 && dealerTotal < 22 && userTotal == dealerTotal)
		{

			if(mode == 'a' || mode == 'A')
			{

				printf("You drew with the dealer\n");

			} //end if

		} //end else if
		else
		{

			printf("well something went wrong\n");

		} //end else

		hands--;

	} //end do while
	while(hands > 0);

	printf("Your final balance is %d", totalMoney);

	return 0;
} //end main


//function to draw a card
void draw(int deck[2][4][13], int *decksPtr, int *suitPtr, int *cardPtr)
{

	bool loop = false;

	do
	{

		*suitPtr = rand() %4;
		*cardPtr = rand() %13;

		if(deck[1][*suitPtr][*cardPtr] == *decksPtr)
		{

			loop = true;

		} //end if
		else
		{

			deck[1][*suitPtr][*cardPtr] = deck[1][*suitPtr][*cardPtr] + 1;
			loop = false;

		} //end else

	} //end do while loop
	while(loop == true);

	//this sets card to equal the contents in the array
	*cardPtr = deck[0][*suitPtr][*cardPtr];

	return;

} //end draw function

//function to sort the cards out
char suitSort(int suit)
{

	char suitChar;

	//this turns the number generated by the draw function in to a character for the suit
	switch(suit)
	{

		case 0:
		{

			suitChar = 'h';
			break;

		} //end case 0

		case 1:
		{

			suitChar = 'd';
			break;

		} //end case 1

		case 2:
		{

			suitChar = 's';
			break;

		} //end case 2

		case 3:
		{

			suitChar = 'c';
			break;

		} //end case 3

		default:
		{

			printf("Something went wrong while sorting suit with the value %d\n", suit);

		} //end default 

	} //end suit switch

	return suitChar;

} //end suit sort function


char cardSort(int card)
{

	char cardChar;

	switch(card)
	{

		case 1:
		{

			cardChar = '1';
			break;

		} //end case 1

		case 2:
		{

			cardChar = '2';
			break;

		} //end case 2

		case 3:
		{

			cardChar = '3';
			break;

		} //end case 3

		case 4:
		{

			cardChar = '4';
			break;

		} //end case 4

		case 5:
		{

			cardChar = '5';
			break;

		} //end case 5

		case 6:
		{

			cardChar = '6';
			break;

		} //end case 6

		case 7:
		{

			cardChar = '7';
			break;

		} //end case 7

		case 8:
		{

			cardChar = '8';
			break;

		} //end case 8

		case 9:
		{

			cardChar = '9';
			break;

		} //end case 9

		case 10:
		{

			cardChar = '0';
			break;

		} //end case 10

		case 11:
		{

			cardChar = 'J';
			break;

		} //end case 11

		case 12:
		{

			cardChar = 'Q';
			break;

		} //end case 12

		case 13:
		{

			cardChar = 'K';
			break;

		} //end case 13

		default:
		{

			printf("Something went wrong while sorting card with the value %d\n", card);

		} //end default

	} //end switch

	return cardChar;

} //end card sort function
