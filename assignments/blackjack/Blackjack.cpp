/*******************************
* Program: Assignment3.cpp or Blackjack.cpp
* Author: Riley Rice
* Date: 5-7-2022
* Description: This program is supposed to be a game that resembles the popular vegas game Blackjack. The goal 
* of the game is to get as close to 21 without going over, and you have to either get exactly 21 or closer to 21
* than the dealer, and then you win. Before the game begins though each player bets and then depending on if they win 
* or lose they either win or lose their bets.
* Input: The inputs will be of types chars and ints which will basically tell the program the difficulty of the dealer they want, 
* how many users are playing the game, how much each player has in their bank account, how much each player wants to bet each round, 
* whether they want another card or not, and finally whether they want to play another betting round after the first one has finished.
* Output: The output of the program will be the randomly generated "cards they get" (random number betwen 1-11), their running total
* or in other words how much the cards they have gotten add up to, the dealers playing round, whether they beat the dealer or not, and 
* the amount in their bank account after the betting round. It will also skip players if their bank account is empty and end the game if 
* all the players have empty bank accounts.
*******************************/


//include the libraries for outputting to console and receiving input, and also the libraries to generate random numbers
#include <iostream>
#include <cstdlib>
#include <ctime>

//makes outputting to console and using cout and cin a lot easier (uses std namespace for all functions)
using namespace std;

/******************************
* Function: isinteger()
* Description: It takes in a float and determines if it's an integer with no values after the decimal point
* Parameters: It takes in a single float
* Pre-conditions: The float needs to be initialized
* Post-conditions: A boolean would be returned which is true if integer and false if not
*******************************/
bool isinteger(float x) {
	int s = x;
	float temp = x - s;

	if (temp > 0) {
		return false;
	}
	else {
		return true;
	}
}

/*****************************
* Function: dealer()
* Description: The dealer() function is designed to take in all the players bank accounts, bets, and playing amount to then have 
* the dealer play it's own round through set conditions that are based on the user's desired difficulty, and then evaluate whether 
* the dealer won or lost against each player and output that along with their new bank account amounts.
* Parameters: The parameters include the integer arrays (which should each be the size of the amount of players) for the player's bank 
* accounts, running totals, and bets. Also it needs the amount of players and the desired difficulty for the dealer.
* Pre-conditions: All the parameters need to be initialized before the function call, and you need to include the <cstdlib> library and set
* the seed with srand().
* Post-conditions: The player's bank accounts will be changed by either adding or subtracting their bets from their bank accounts
* depending on whether they won or not.
******************************/
void dealer(float players[], int totals[], float bets[], float playernum, float difficulty) {
	//create and initialize the variables for the dealer's running total, and the randomnumber for the dealer's first card
	int dtotal = 0;
	int randnumd = (rand() % 10) + 1;

	//This will be the boolean that determines if the dealer will get another card or not
	bool danothercard = false;

	//we want to update the total with the first random number so the dealer has a total to start with and evaluate
	dtotal += randnumd;

	//output first card
	cout << endl;
	cout << "The dealer gets a(n) " << randnumd << ", running total is " << dtotal << ". ";

	//This do-while loop will keep on running as long as the conditions for the dealer holds and another card is needed
	do {
		//make a randnum between 1 and 11 everytime the dealer wants a new card
		int randnumd2 = (rand() % 10) + 1;

		//these next if else statements change up the conditions in which the dealer will decide to get another card, and this is 
		//based off of the difficulty parameter
		if (difficulty == 3) {
			if (dtotal > 10) {
				if (randnumd2 <= (21 - dtotal)) {
					danothercard = true; //want another card
				}
				else {
					danothercard = false; //don't want another card
				}
			}

			else if (dtotal <= 10) {
				danothercard = true; //want another card
			}
		}
		else if (difficulty == 2) {
			if (dtotal > 10) {
				if (dtotal <= 16) {
					danothercard = true; //want another card
				}
				else {
					danothercard = false; //don't want another card
				}
			}

			else if (dtotal <= 10) {
				danothercard = true; //want another card
			}
		}
		else if (difficulty == 1) {
			int easyrand = rand() % 100;

			if (dtotal > 10) {
				if (easyrand >= 90) {
					danothercard = true; //want another card
				}
				else {
					danothercard = false; //don't want another card
				}
			}

			else if (dtotal <= 10) {
				danothercard = true; //want another card
			}
		}
		
		//if the parameters are met above and the dealer should get another card then this happens
		if (danothercard) {
			//add the randomnumber generated at the top to their total
			dtotal += randnumd2;

			//display the randomnumber they got and their total
			cout << endl;
			cout << "The dealer gets a(n) " << randnumd2 << ", running total is " << dtotal << ". ";

			//if the dealer bust we want to break them out of the loop
			if (dtotal > 21) {
				cout << endl;
				cout << "The dealer busts!";
				cout << endl;
				danothercard = false;
			}
			//if the dealer gets blackjack we want to break out the loop
			else if(dtotal == 21) {
				cout << endl;
				cout << "The dealer got blackjack!";
				cout << endl;
				danothercard = false;
			}
		}
		//if the parameter say they shouldn't get another card then this happens
		else {
			cout << endl;
			cout << "The dealer stops...";
			cout << endl;
			danothercard = false;
		}
	} while (danothercard); //while they want another card

	//after the dealer did their playing round it then goes through and iterates for the amount of players
	for (int i = 1; i <= playernum; i++) {
		//if the players bet == -2 then that means the player busted so they don't need to be evaluated and 
		//the loop continues. Also don't want to do this if the bank account is 0 since they aren't playing
		if (bets[i - 1] == -2 && players[i - 1] != 0) {
			cout << endl;
			cout << "Player " << i << ", already busted. They have " << players[i - 1] << ". ";
			cout << endl;
			continue;
		}
		//if the players bet == - 1 then that means the player got blackjack so they don't need to be evaluated
		//and the loop continues. Also don't want to do this if the bank account is 0 since they aren't playing
		else if (bets[i - 1] == -1 && players[i - 1] != 0) {
			cout << endl;
			cout << "Player " << i << ", already got blackjack. They have " << players[i - 1] << ". ";
			cout << endl;
			continue;
		}
		//if the players bank account isn't 0 which means they are playing and they haven't busted or got blackjack
		//alread then we need to check if the dealer or player won.
		else if(players[i - 1] != 0){
			//if the dealer busted then all the players who didn't bust before automatically win so we need to iterate
			//through the players who didn't bust and tell them they won
			if (dtotal > 21) {
				cout << endl;
				cout << "Player " << i << ", wins. The dealer busted";
				players[i - 1] += bets[i - 1];
				cout << " Player " << i << ", has " << players[i - 1] << ". ";
				cout << endl;
				continue;
			}
			//If the players running total is bigger than the dealers running total then the player wins
			else if (totals[i - 1] > dtotal) {
				cout << endl;
				cout << "Player " << i << ", wins. They were closer to 21! ";
				players[i - 1] += bets[i - 1];
				cout << " Player " << i << ", has " << players[i - 1] << ". ";
				cout << endl;
				continue;
			}
			//If the players running total is less than the dealer's running total then the dealer wins
			else if (totals[i - 1] < dtotal) {
				cout << endl;
				cout << "Player " << i << ", loses. They dealer was closer to 21! ";
				players[i - 1] -= bets[i - 1];
				cout << " Player " << i << ", has " << players[i - 1] << ". ";
				cout << endl;
				continue;
			}
			//If the players running total equals the dealer's running total then they tie and dealer doesn't win or lose
			else if (totals[i - 1] == dtotal) {
				cout << endl;
				cout << "Player " << i << ", ties. They were the same distance to 21! ";
				cout << " Player " << i << ", has " << players[i - 1] << ". ";
				cout << endl;
				continue;
			}
		}
	}

	//tell them that the betting round has finished
	cout << endl;
	cout << "The betting round has finished!";
	cout << endl << endl;
}

//main function
int main() {

	//initialize the seed for the rand() function that I use to generate cards and other things
	srand(time(NULL));

	//start variable which will determing if the main while loop starts or not
	char start;

	//declare and intialize some booleans which will start and end the game
	bool starter = false;
	bool endgame = false;

	//welcome the users and ask them to input the start char
	cout << endl << endl;
	cout << "Welcome to Blackjack!";
	cout << endl;
	cout << "Enter 's' to start the game and anything else to quit: ";
	cin >> start;
	cout << endl << endl;

	//if start == s then start the main loop otherwise end the game right here
	if (start == 's') {
		starter = true;
	}
	else {
		cout << "Exitting... You can run it again if you didn't mean to quit." << endl << endl;
	}

	//main game loop
	while (starter) {
		//declare the variables which will store the playernumber and whether the playernumber input is valid
		float playernum = 0;
		bool playergood;

		//ask how many players
		cout << "How many players are there (must be in between 1 and 4): ";

		//do-while loop which will loop until playernum recieves a good value and playergood=true;
		do {
			//take in the input for playernum
			cin >> playernum;
			cout << endl << endl;

			//if the playernum input is valid
			if (1 <= playernum && playernum <= 4 && isinteger(playernum)) {
				//declare and intialize some booleans which will determine if the playagain input is valid
				//and whether the loop is on it's first iteration
				bool playagaingood = false;
				bool first_iter = true;

				//declare 3 integer arrays, with a size of 4 because that's the max players, for the bank accounts, bets, and running totals
				float players[4];
				float bets[4];
				int totals[4];

				//declare the integer which will hold the difficulty of the dealer the players want
				float difficulty;

				//this do-while loop which will hold all the content for the betting round and will loop everytime the user wants to play again
				//and it will also stop looping if the endgame boolean is set to true.
				do {
					//declare an integer which holds the amount of players that have a bank account value of 0
					int zeros = 0;

					//declare booleans which will loop the next do-while loops until the starting value and difficulty inputs are valid
					bool dealgood;
					bool playersvalid;

					//if this is the first iteration of the loop 
					if (first_iter) {
						//for each player
						for (int i = 1; i <= playernum; i++) {
							//do-while loop which loops until input is valid
							do {
								//takes in bank account input
								cout << "Player " << i << ", how much money are you starting with? ";
								cin >> players[i - 1];
								cout << endl;

								//if input is invalid
								if (players[i - 1] < 4 || players[i - 1] > 500 || !(isinteger(players[i - 1]))) {
									cout << "You need to chose a number between 5 and 500, try again: ";
									cout << endl << endl;
									playersvalid = false;
									cin.clear();
									cin.ignore(1000, '\n');
								}
								//if input is valid
								else {
									playersvalid = true;
								}
							} while (!playersvalid); 
						}
						//do-while loop which loops until input is valid
						do {
							//takes the difficulty input
							cout << "What difficulty dealer do you want? 1 (easy), 2 (medium), or 3 (hard): ";
							cin >> difficulty;
							cout << endl << endl;

							//if input is valid
							if (1 <= difficulty && difficulty <= 3 && isinteger(difficulty)) {
								dealgood = true;
							}
							//if input is invalid
							else {
								cout << "That's an invalid input, try again.";
								cout << endl << endl;
								cin.clear();
								cin.ignore(1000, '\n');
								dealgood = false;
							}

						} while (!dealgood);
					}
					//if this isn't the first iteration of the main do-while loop
					else {
						//for each player
						for (int k = 1; k <= playernum; k++) {
							//output their bank account values so if they start another betting round they know how much money they have
							cout << "Player " << k << " has " << players[k - 1] << " in their bank account";
							cout << endl;
						}
						cout << endl;
					}

					//for each player
					for (int j = 1; j <= playernum; j++) {
						//if players bank account is 0 then increment the zeros value
						if (players[j - 1] == 0) {
							zeros++;
						}
						//if all the players have 0 in their bank account and there are more than 2 players then end game
						if (zeros == playernum && playernum >= 2) {
							cout << endl;
							cout << "All the players ran out of money! Ending the game, play again if you want!";
							cout << endl << endl;

							//set this true to endgame
							endgame = true;
							break;
						}
						//if all the players have 0 in their bank account and there is only 1 player then end game
						else if (zeros == playernum && playernum == 1) {
							cout << endl;
							cout << "All the players ran out of money! Ending the game, play again if you want!";
							cout << endl;

							//set this true to endgame
							endgame = true;
							break;
						}
					}

					//if engame is true then run this if not break out and end game
					if (!endgame) {
						//start betting round
						cout << "Place your bets:";
						cout << endl << endl;

						//for each player
						for (int j = 1; j <= playernum; j++) {
							//if the player has 0 in their bank account skip them because they aren't playing
							if (players[j - 1] == 0) {
								cout << endl;
								cout << "Player " << j << " is skipped...";
								cout << endl << endl;
								continue;
							}
							//if the player has money
							else {
								//boolean to represent the validity of each players bet input
								bool betgood = true;

								//do while the bet input is invalid
								do {
									//ask for players bet
									cout << "Player " << j << ", How much do you bet you can beat the dealer? ";
									cin >> bets[j - 1];
									cout << endl;

									//if input is invalid
									if (bets[j - 1] > players[j - 1] || bets[j - 1] <= 0 || !(isinteger(bets[j - 1]))) {
										betgood = false;
										cin.clear();
										cin.ignore(1000, '\n');
										cout << endl;
										cout << "You can't bet more than you have in your bank or put 0, try again.";
										cout << endl;
									}
									//if input is valid
									else {
										betgood = true;
									}
								} while (!betgood);
							}
						}

						//for each player
						for (int j = 1; j <= playernum; j++) {
							//if player's bank account is 0 then they are playing so skip them
							if (players[j - 1] == 0) {
								continue;
							}
							//if player has money 
							else {
								//generate starting card for players
								int randnum = (rand() % 10) + 1;

								//intialize the players running total then add the first card to it
								totals[j - 1] = 0;
								totals[j - 1] += randnum;

								//declare variables to see if the player wants another card or not
								bool anothercard;
								char another;

								//start turn
								cout << "Player " << j << "'s turn...";
								cout << endl;

								//tell them their starting amount
								cout << "Player " << j << ", you got a(n) " << randnum << ". Your running total is " << totals[j - 1] << ". Do you want another number ('n'-no, 'y'-yes)? ";

								//do while the player wants another card until they don't want one anymore
								do {
									//generate a random number everytime they want another card
									int randnum2 = (rand() % 10) + 1;
									
									//take in whether they want another card
									cin >> another;

									//if they want another card
									if (another == 'y') {
										//add the other randomnumber to their running total
										totals[j - 1] += randnum2;

										//set this true so that it will iterate again when they are asked if they want another card
										anothercard = true;

										//if their total is greater then 21 then they busted so they can't get another card
										if (totals[j - 1] > 21) {
											cout << "Player " << j << ", you got a(n) " << randnum2 << ". Your running total is " << totals[j - 1];
											cout << endl;
											cout << "You bust. You lose!";
											cout << endl;
											
											//take away their bet since they automatically lose
											players[j - 1] -= bets[j - 1];
											cout << "Player " << j << " has " << players[j - 1] << ". ";
											cout << endl << endl;

											//set their bets to -2 so the dealer knows they busted and doesn't have to play them
											bets[j - 1] = -2;
											break;
										}
										//if their total is equal to 21 they got blackjack which means they can't get another card
										else if (totals[j - 1] == 21) {
											cout << "Player " << j << ", you got a(n) " << randnum2 << ". Your running total is " << totals[j - 1];
											cout << endl;
											cout << "you won!";
											cout << endl;

											//give them their bet since they automatically win
											players[j - 1] += bets[j - 1];
											cout << "Player " << j << " has " << players[j - 1] << ". ";
											cout << endl << endl;

											//sets their bets to -1 so the dealer knows they got blackjack and doesn't have to play them
											bets[j - 1] = -1;
											break;
										}

										//if they don't have blackjack or didn't bust then ask them if they want another card again and loop again
										cout << "Player " << j << ", you got a(n) " << randnum2 << ". Your running total is " << totals[j - 1] << ". Do you want another number ('n'-no, 'y'-yes)? ";
									}
									//if they don't want another card
									else if (another == 'n') {
										cout << "Player " << j << "'s " << "total points are " << totals[j - 1];
										cout << endl << endl;
										anothercard = false;
										break;
									}
									//if their input is invalid
									else {
										cout << "That's an invalid input, try again: ";
										cin.clear();
										cin.ignore(1000, '\n');
										anothercard = true;
									}
								} while (anothercard);

							}
						}

						//now that the betting round finished for the players it's time for the dealer to play
						cout << endl;
						cout << "All the players have gone now its the dealer's turn...";
						cout << endl;

						//call the dealer function with all the player arrays along with the number of players and the desired difficulty
						dealer(players, totals, bets, playernum, difficulty);
						cout << endl << endl;

						//set variables which get whether the player wants to play again if that input is valid
						bool play;
						char playagain;

						//do while the input for the playagain variable is invalid
						do {
							//take in playagain input
							cout << "Do you want to do another betting round ('n'-no, 'y'-yes)? ";
							cin >> playagain;
							cout << endl;

							//switch for playagain's values
							switch (playagain) {
							//if they want to play again then set playagaingood to true to restart betting round and set first_iter to false so
							//the program knows that it isn't the first iteration and don't need to ask for difficulty 
							case 'y':
								play = true;
								playagaingood = true;
								first_iter = false;
								break;
							//if they don't want to play again then set playagaingood to false so that the loop doesn't restart and break out of all the loops
							case 'n':
								play = true;
								playagaingood = false;
								cout << endl;
								cout << "Quitting... Thanks for playing!";
								cout << endl << endl;
								break;
							//if the input is invalid clear the cin space and remprompt them through the do-while loop
							default:
								cout << "Invalid input, try again:";
								cout << endl;
								cin.clear();
								cin.ignore(1000, '\n');
								play = false;
								break;
							}
						} while (!play);
					}

					//makes the loop exit because input is valid
					playergood = true;

				}while (playagaingood == true && endgame == false);
			}
			//if the playernum value isn't valid then clear the input space and restart the prompt at top of the do-while loop
			else {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << endl;
				cout << "There can only be 4 players, re-enter a value between 1 and 4: ";
				
				//makes the loop restart
				playergood = false;
			}

		} while (!playergood); //loop while playernum value isn't valid

		//break out of main game loop
		break;
	}

	//return 0 from the main function so you know that the program finished properly
	return 0;
}
