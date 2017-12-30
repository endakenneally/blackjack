#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Card structure definition
struct Card
{
	char suit;
	int number;
};

// Declaration of functions to be used
struct Card whatCard(int send);

int getCard();

// Main body
int main(void)
{
	struct Card c, d;
	char suit;
	int card, i, playertotal, ace;
	int input;
	int player[5];
	char playersuit[5];
	int dealer[5];
	char dealersuit[5];
	int dealertotal;

	// Initiliastion of certain variables;
	playertotal = 0;
	dealertotal = 0;
	input = 1;

	srand(time(0));

	// Calling of function which generates numbers between 1 and 52
	for(i = 0; i < 5; i++)
	{
		player[i] = getCard();
		dealer[i] = getCard();
	}

	// Converts these numbers generated below into a card and suit. For Player.
	for (i = 0; i < 5; i++)
	{
		int send = player[i]; 
		c = whatCard(send);
		player[i] = c.number;
		playersuit[i] = c.suit;
	}

	// Converts numbers into cards for the dealer. 
	for (i = 0; i < 5; i++)
	{
		int send = dealer[i];
		d = whatCard(send);
		dealer[i] = d.number;
		dealersuit[i] = d.suit;
	}

	// Player
	for (i = 0; i < 5; i++)
	{	
		if(i > 1 && playertotal < 22 && input == 1)
		{
			printf("Would you like another card? (1 for new)\n");
			scanf("%d", &input);
		}

		// If more than 22, player loses and programs shuts down.
		else if (playertotal > 22)
		{
			printf("Bust! You lose.\n");
			return 0;
		}

		// So long as the player wants another card, this will run
		if( input == 1 )
		{
			// Incase the card drawn is an ace.
			if(player[i] == 1)
			{
				printf("You've drawn an ace of %c! Should it count for 1 or 11?\n", playersuit[i]);
				scanf("%d", &ace);

				// Make sure the user has entered a value that is either 1 or 11
				if( ace == 1 || ace == 11)
				{
					playertotal += ace;
				}

				else
				{
					printf("Please enter a 1 or 11 next time!");
					return 0;
				}
			}

			else if(player[i] > 9)
			{
				// To check if one of these is a picture card.
				switch(player[i])
				{
					case 10 :
						suit = 'J';
						break;
					case 11 :
						suit = 'Q';
						break;
					case 12 :
						suit = 'K';
						break;
				}
	
				printf("You've drawn a %c of %c\n", suit, playersuit[i]);
				playertotal += 10;
			}

			else
			{
				printf("Your card is a %d of %c\n", player[i], playersuit[i]);
				playertotal += player[i];
			}
				// running total
			printf("Your current total is = %d\n", playertotal);
		}
	}

	if(playertotal > 21){return 0;} // Quick check to verify that the player does not have over 21

	printf("Your final total is %d\n\n\n", playertotal);

	// Dealers cards. Same as Players
	for(i = 0; i < 5; i++)
	{
		if ( dealertotal < playertotal && dealertotal < 22)
		{
			if(dealer[i] == 1)
			{
				printf("The dealer has drawn an ace of %c!\n", dealersuit[i]);

				// Calculations for if the dealer draws an ace
				if( (dealertotal + 11 > playertotal || dealertotal < 3 )  && dealertotal+ 11 <= 21)
				{
					printf("He chooses to count it as 11.\n");
					dealertotal += 11;
				}

				else
				{
					printf("He chooses to count it as 1.\n");
					dealertotal += 1;
				}
			}

			else if(dealer[i] > 9)
			{
				switch(player[i])
				{
					case 10 :
						suit = 'J';
						break;
					case 11 :
						suit = 'Q';
						break;
					case 12 :
						suit = 'K';
						break;
				}
	
				printf("The dealer's drawn a %c of %c\n", suit, dealersuit[i]);
				dealertotal += 10;
			}

			else
			{
				printf("The dealer has drawn a %d of %c\n", dealer[i], dealersuit[i]);
				dealertotal += dealer[i];
			}

			printf("Dealer's current total is = %d\n", dealertotal);
		}
	}

	printf("The dealer's final total is = %d\n", dealertotal);

	// Win/Lose conditions.
	if(dealertotal >= playertotal && dealertotal < 22)
	{
		printf("The dealer wins!\n");
	}

	else if(dealertotal > 21)
	{
		printf("The dealer has gone bust! You've won!\n");
	}

	else
	{
		printf("You win\n");
	}

	return 0;
}

// Function to generate 10 numbers between 0 and 52
int getCard()
{
	int random, number;

	random = rand();
	number = random % 13;

	return number;
}

struct Card whatCard(int send)
{
	struct Card a;

	int test = send%4;
	int number = send%13;

	switch(test)
	{
		case 0 :
			a.suit = 'H';
			break;
		case 1:
			a.suit = 'D';
			break;
		case 2:
			a.suit = 'S';
			break;
		case 3:
			a.suit = 'C';
			break;
	}

	switch(number)
	{
		case 0 :
			a.number = 1;
			break;
		case 1:
			a.number = 2;
			break;
		case 2:
			a.number = 3;
			break;
		case 3:
			a.number = 4;
			break;
		case 4:
			a.number = 5;
			break;
		case 5:
			a.number = 6;
			break;
		case 6:
			a.number = 7;
			break;
		case 7:
			a.number = 8;
			break;
		case 8:
			a.number = 9;
			break;
		case 9:
			a.number = 10;
			break;
		case 10:
			a.number = 11;
			break;
		case 11:
			a.number = 12;
			break;
		case 12:
			a.number = 13;
			break;
	}

	return a;

}