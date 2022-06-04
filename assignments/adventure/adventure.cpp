/**************************************************
Program: assignment2.cpp or adventure.cpp
Author: Riley Rice
Date: 4/23/22
Input: The inputs of the program are different combinations of chars, integers, and floats in order to make decisions in the game 
that changes the story based on those inputs. There are a total of two branches with a depth of 3 in each and there is a total of 5 user 
inputs that must be entered for each branch.
Output: The output of the programs are different storylines based on each user input for each branch of the story, and there is one branch
that changes the chosen storyline based on chance.
***************************************************/

//include libraries needed to output text and take in text and to generate random numbers
#include <iostream>
#include <cstdlib>
#include <ctime>

//using the namespace std so that outputting text is a lot easier
using namespace std;

//initialize main function
int main(){
	
	//initialize main loop variables
	bool run = false;
	char init;

	//generate all the random numbers for the chance branch and other numbers for a question in one of the branches
	srand(time(NULL));
	int rand_num = (rand() % 100) + 1;
	int rand_num1 = (rand() % 100) + 1;
	int rand_num2 = (rand() % 100) + 1;

	//calculate correct answer to question in one the nested brancehs a few options down.
	float correct_answer = float(rand_num1 * rand_num2);
	
	//prompt the user and tell them how to start the game
	cout << endl << endl << "Welcome to the text survival/adventure game!" << endl << endl << "Enter 's' to continue, and any other key to quit: ";
	cin >> init;
	
	//conditional if user inputs 's' then it will initialize main loop if not it will cancel and tell them to run it again.
	init == 's' ? run = true : cout << endl << endl << "Looks like you want to cancel. Run it again if you didn't mean to quit." << endl << endl;
	
	//main game loop when we finish the game it will break out
	while(run){

		//initialize variables for the do while loop logic and user input
		char chance_input;
		bool good;		
		bool first_iter = true;		

		//prompt the user what branch they want to go into
		cout << endl << endl; 
		cout << "You wake up on a deserted island on the beach, and don't remember anything, the first thing you notice is a \n";  
		cout << "massive forest right off the beach. Do you want to stay on the beach press 'b' or go in the forest press 'f': ";
		
		//start a do while loop, we want this to run at least once and then loop if the input is bad
		do {
			
			//for the element of chance the loop may break out and force you into another case statement
			//in this switch and so if that's the case we don't want to take in the input again, so I set a
			//boolean that keeps track of this, and will only take user input if first_iter is true.
			if(first_iter == true){
				//take in user input
				cin >> chance_input;
				cout << endl << endl;
			}

			//the first switch statement which will hold all the branches and options and it's based off
			//the user's input for chance_input
			switch(chance_input){
				//goes into the 'b' or beach branch based on chance or because the user inputted that
				case 'b':
					//this is where the element of chance is implemented one of the random numbers that were initialized 
					//at the top of the program rand_num is being checked if it's under 50 or not and if that's true then we 
					//need to break out and force them into the 'f' branch. we also don't want to do this if the loop if coming
					//back to change the user into a different branch so the and operator is added and we evaluate if first_iter 
					//is used.
					if(rand_num < 50 && first_iter == true){
						//change user input
						chance_input = 'f';

						//tell them why they changed to beach
						cout << "You decided to stay on the beach, but then a bear came out of nowhere and chased you into the forest.";
						cout << endl << endl;
						
						//make sure it loops again and doesn't take in input again and go straight into else statement in other branch
						good = false;
						first_iter = false;
					}
					else {
						//This is where the beach branch begins and variables for the next do-while loop are declared
						int shelteropt;
						bool sheltergood;

						//storyline for beach
						cout << "You are on the beach either because you decided to or you had no choice, it's extremely hot and theres no shade \n";
						cout << "so you decide you should build a shelter. You see some wood sticks and leaves that you could make a shelter with \n";
						cout << "or you see an abandoned old boat on the beach which is infested with crabs that you could use as a shelter.";
						cout << endl << endl;
						cout << "Do you want to 1. build a shelter out of the sticks and brush or 2. use the old boat as a shelter?: ";
						cout << endl << endl;

						//do-while loop to handle input
						do {
							//take in user input
							cin >> shelteropt;
							cout << endl << endl;

							//start switch based on that input
							switch (shelteropt) {

							//if user inputs 1
							case 1:
								//variables for next do-while loop are declared
								char fishopt;
								bool fishgood;

								//storyline for shelter out of sticks
								cout << "You decide to make your house out of stick and brush becuase you think they will be a good option to shade \n";
								cout << "you from the sun at least, and you don't have to deal with a crab infestation. You go ahead and build a pretty \n";
								cout << "good shelter that's a big relief from the sun.";
								cout << endl << endl;
								cout << "Now that you have your house you want to go get some food because your starving. Do you want to go fish press 'f', \n";
								cout << "or do you want to see if you can find some crabs press 'c'?: ";

								//do-while loop to handle input
								do {
									//variables for next do-while loop are declared
									cin >> fishopt;
									cout << endl << endl;

									//switch based on the user input
									switch (fishopt) {

									//if user inputs 'f'
									case 'f':
										//variables for next do-while loop are declared
										int poleopt;
										bool polegood;

										//fishing storyline
										cout << "You decide that you want to go fishing because you think that being able to get fish would be a good food source. \n";
										cout << "Although, you don't really know how to fish and need a pole or some type of spear.";
										cout << endl << endl;
										cout << "Do you want to 1. make a makeshift fishing pole or 2. make and use a spear: ";

										//do-while loop to handle input
										do {
											//take in user input
											cin >> poleopt;
											cout << endl << endl;

											//switch based on that input
											switch (poleopt) {
											
											//if the user inputs 1
											case 1:
												//ending for branch 'b'
												cout << "You decide to make a fishing pole using a twig a little loop rock that you found and tied to the pole, and \n";
												cout << "then you found some string by taking grass and weaving it. The hook was made out of a rock that you sharpened. \n";
												cout << "You took the pole and start throwing the hook into the ocean, and after about a few hours you still didn't catch \n";
												cout << "anything, but the eye of a survival rescuer who saw you fishing and called you out. He told you that you were in a \n";
												cout << "shipwreck and he was here to save you.";
												cout << endl << endl;
												cout << "Thanks for playing! Also good job on surviving. Play again if you want to take another path. ";
												cout << endl << endl;

												//break out of all the do-while loops and end program
												polegood = true;
												break;

											//if user inputs 2
											case 2:
												//ending for branch 'b'
												cout << "You decide to make a spear out of a stick that you sharpened down with a rock, and go swim in the water to \n";
												cout << "try and spear some fish for food. The only thing is you didn't realize that while making the spear you cut yourself \n";
												cout << "a little bit and you were bleeding. While you were in the water the blood attracted a shark and it ate you.";
												cout << endl << endl;
												cout << "Thanks for playing! play again and see if you can survive next time.";
												cout << endl << endl;

												//break out of all the do-while loops and end program
												polegood = true;
												break;

											//if invalid input
											default:
												//clear the cin buffer and ignore 1000 characters or go into there's a new line
												cin.clear();
												cin.ignore(1000, '\n');

												//tell the user what they need to input
												cout << "Invalid input, enter 1 or 2. Try Again: ";
												cout << endl << endl;

												//make it so that the do-while loop loops again and prompts the user again to input 
												//a hopefully valid input this time
												polegood = false;
												break;
											}
										//start loop again if polegood isn't good
										} while (!polegood);
										
										//break out of this loop and end game
										fishgood = true;
										break;

									//if user inputs 'c'
									case 'c':
										//variables for next do-while loop are declared
										char crabopt;
										bool crabgood;

										//crab storyline
										cout << "You decide to go look for crabs instead of going fishing because it's a lot easier to get crabs since they're on the floor \n";
										cout << "and you need a fishing pole or spear to fish which are hard to make. You go over near the crab infested boat as that's the \n";
										cout << "perfect spot to go. ";
										cout << endl << endl;
										cout << "Do you want to smash them with a rock press 'r' or grab them press 'g'?: ";

										//do-while loop to handle input
										do {
											//take in user-input
											cin >> crabopt;
											cout << endl << endl;

											//switch statement based on user input
											switch (crabopt) {

											//if user inputs 'r'
											case 'r':
												//one of the beach branch endings
												cout << "You find a big rock and creep  up on the crab infested boat. You hit about 4 of them and they stop moving, \n";
												cout << "which means you have food! although some of the meat is ruined from crushing them with a rock you still had all the legs. \n";
												cout << "while out on the beach you see a man walk up to you, and hes on a rescuer crew and tells you that you were in a \n";
												cout << "shipwreck and that they were looking for you. He took you back to safety and you surived.";
												cout << endl << endl;
												cout << "Thanks for playing! Also good job on surviving. Play again if you want to take another path.";
												cout << endl << endl;

												//break out of this do-while loop
												crabgood = true;
												break;

											//if user inputs 'g'
											case 'g':
												//one of the beach brand endings
												cout << "you decide to grab the crabs because you didn't want to ruin the meat by smashing them with a rock. So you sneak up \n";
												cout << "on them by the boat and you grab one, and he turns out to be the master crab, which you didn't know at the time. All \n";
												cout << "the other crabs didn't like that and they started to gang up on you. They crawled all over you and ate you.";
												cout << endl << endl;
												cout << "Thanks for playing! Play again and see if you can survive next time.";
												cout << endl << endl;

												//break out of this do-while loop
												crabgood = true;
												break;

											//if user input is invalid or unexpected
											default:
												//clears the user input space in case they put an input thats of a different data type
												cin.clear();
												cin.ignore(1000, '\n');

												//tell the user the input is wrong and what they should do
												cout << "Invalid input, enter 'g' or 'b'. Try again:";
												cout << endl << endl;

												//loop the do-while again so that they get prompted until they put in a correct input
												crabgood = false;
												break;
											}
										//loop while the input is invalid otherwise break out
										} while (!crabgood);

										//break out of this do-while loop
										fishgood = true;
										break;
									
									//if user input is invalid or unexpected
									default:
										//clears the user input space in case they put an input thats of a different data type than we were expecting
										cin.clear();
										cin.ignore(1000, '\n');

										//tells the user there input is wrong and tells them what to do
										cout << "Invalid input, enter 1 or 2. Try again: ";
										cout << endl << endl;

										//loop the do-while loop again so that they get prompted until they put in a correct input
										fishgood = false;
										break;
									}
								//loop while the input is invalid otherwise break out
								} while (!fishgood);

								//break out of this do-while loop
								sheltergood = true;
								break;

							//if the user inputs 2
							case 2:
								//next do-while loop variables are declared
								int boatopt;
								bool boatgood;

								//old boat storyline in beach branch
								cout << "You decided that you wanted to use the old boat as your shelter because it was already made and sturdy. The \n";
								cout << "only issue is the crabs that you would have to get rid of. ";
								cout << endl << endl;
								cout << "You figure there's two options that you could go about to get rid of the crabs 1. you could go ahead and fight the crabs \n";
								cout << "or 2. you could go and make them a trade offer: ";

								//do while loop to handle user input
								do {
									//take in user input
									cin >> boatopt;
									cout << endl << endl;

									//switch based on user input
									switch (boatopt) {
									
									//if user inputs 1
									case 1:
										//next do-while loop variables are declared
										int fightopt;
										bool fightgood;

										//fighting the crabs storyline in beach branch
										cout << "You decided that the only way to go and get the boat from the crabs for you shelter was to fight them \n";
										cout << "so you ran up to the boat and started swinging and smashing until you had killed about half of them, \n";
										cout << "you were an absolute monster. Until you got to the king crab, he was about 3x the size of all the other crabs. \n";
										cout << "you were terrified.";
										cout << endl << endl;
										cout << "Do you want to 1. fight the king crab or 2. run from the king crab?: ";

										//do-while loop to handle user-input
										do {
											//take in user input
											cin >> fightopt;
											cout << endl << endl;

											//switch based on user input
											switch (fightopt) {
											
											//if user inputs 1
											case 1:
												//one of the beach branch endings
												cout << "You decide that you aren't a woosy and you want to fight the king crab, so you run up to him and start \n";
												cout << "swinging and he starts clamping. You get a few good punches on him, but unfortunately his snips were too strong \n";
												cout << "and you died to the king crab.";
												cout << endl << endl;
												cout << "Thanks for playing. Play again and see if you can survive next time.";
												cout << endl << endl;

												//break out of this do-while loop
												fightgood = true;
												break;
											
											//if user inputs 2
											case 2:
												//one of the beach branch endings
												cout << "You decide to run from the king crab, because you don't want to die and you don't think that you can beat \n";
												cout << "him in a fight. So you use your running skils and run into the forest away from the crab all the way to a village \n";
												cout << "where you see a bunch of people and they tell you that you were in a shipwreck and people had been looking for you. ";
												cout << endl << endl;
												cout << "Thanks for playing. Also good job on surviving. Play again to try a different path";
												cout << endl << endl;

												//break out of this do-while loop
												fightgood = true;
												break;

											//if user input is invalid
											default:
												//clear the user input space in case they put in an input of a different data type than we were expecting
												cin.clear();
												cin.ignore(1000, '\n');

												//tell the user that there input is invalid and tell them what to do
												cout << "Invalid input, enter 1 or 2. Try again: ";
												cout << endl << endl;

												//loop again until we get a good user input
												fightgood = false;
												break;
											}
										//loop while user input is bad and then break out when it's good
										} while (!fightgood);

										//break out of this do-while loop
										boatgood = true;
										break;

									//if user inputs 2
									case 2:
										//do-while loop variables are declared
										float multiplicationinput;
										bool multiplicationgood;

										//negotiate storyline
										cout << "You decide that you should negotiate with the crabs since there are too many of them for you to fight them and win. \n";
										cout << "You walk up to the king crab and tell them you need a shelter for a little until you could figure out where you were \n";
										cout << "and what you're going to do. He says ok but only if you can solve this math problem: ";
										cout << endl << endl;
										//use the ranomly generated variables from the top of the program to make a random multiplication problem
										cout << "What is " << rand_num1 <<  " times " << rand_num2 << "?: ";

										//do-while loop to handle user-input
										do {
											//take in user input
											cin >> multiplicationinput;
											cout << endl << endl;

											//switch based on user input
											switch (multiplicationinput == correct_answer) {

											//if the user inputs the right answer to the math problem
											case true:
												//one of the beach endings
												cout << "You answered with the right solution and so the king crab agrees for you to have his boat house and  \n";
												cout << "tells all the other crabs to leave for you. You then use the boat for shelter and you survive until people \n";
												cout << "come rescue you and tell you that you were in a shipwreck.";
												cout << endl << endl;
												cout << "Thanks for playing. Also good job on surviving. Play again to try a different path. ";
												cout << endl << endl;

												//break out of this do-while loop
												multiplicationgood = true;
												break;

											//if the user inputs the wrong answer to the math problem
											case false:
												//one of the beach endings
												cout << "You answered with the wrong solution and so the king crab doesn't move out of the boar for you. He also \n";
												cout << "didn't like the way you came up and asked to steal his home so he tells all his crab minions to gang up and ";
												cout << "attack you, ending up in you dying.";
												cout << endl << endl;
												cout << "Thanks for playing. Play again and see if you can survive next time. ";
												cout << endl << endl;

												//break out of this do-while loop
												multiplicationgood = true;
												break;

											//if the user inputs an invalid input
											default:
												//clears the user input space in case the user inputs something of a data type we weren't expecting
												cin.clear();
												cin.ignore(1000, '\n');

												//tell the user there input is invalid and then tell them what to do
												cout << "Invalid input, enter a number for the answer. Try again: ";
												cout << endl << endl;
												
												//loop again since the user input is invalid
												multiplicationgood = false;
												break;
											}
										//loop until the user input is valid
										} while (!multiplicationgood);

										//break out of this do-while loop
										boatgood = true;
										break;

									//if user input is invalid 
									default:
										//clears the user input space in case the user inputs something of a data type we weren't expecting
										cin.clear();
										cin.ignore(1000, '\n');

										//tell the user their input is invalid and tell them what to do
										cout << "Invalid input, enter 'b' or 'g'. Try Again: ";
										cout << endl << endl;

										//loop again since the user input is invalid
										boatgood = false;
										break;
									}

								//loop until the user input is valid
								} while (!boatgood);

								//break out of this do-while loop
								sheltergood = true;
								break;

							//if the user input is invalid
							default:
								//clears the user input space in case the user inputs something of a data type we weren't expecting
								cin.clear();
								cin.ignore(1000, '\n');

								//tell the user their input is invalid and tell them what to do
								cout << "Invalid input, enter 1 or 2. Try Again: ";
								cout << endl << endl;

								//loop again since the user input is invalid
								sheltergood = false;
								break;
							}
						//loop until the user input is valid
						} while (!sheltergood);
						
						//break out of this do-while loop
						first_iter = false;
						good = true;	
					}

					//break out of 'b' branch
					break;

				//this branch is practically identical to the 'b' branch look at that for reference on how this works
				case 'f':
					if(rand_num < 50 && first_iter == true){
						chance_input = 'b';
						
						cout << "You walked into the forest and saw a massive bug and decided to run back out to the beach because your a woosy.";
						cout << endl << endl; 
						
						good = false;
						first_iter = false;
					}
					else {
						bool food;
						bool good_1;

						cout << "You are now in the forest exploring either because your decided to or had no choice. While your here exploring \n";
						cout << "and you find yourself getting really hungry, you see some cocunuts up on a tree do you decide to 1: go up the \n";
						cout << "tree and get some cocunuts (enter 1), or 2: decide to stay on the ground and find food somewhere else? (enter 0): ";
						
						do {
							cin >> food;
							cout << endl << endl;

							switch(food){
								case 1:
									int treeopt;
									bool treegood;
									
									cout << "You decided to to climb the tree, and you almost made it all the way up, when all of a sudden \n";
									cout << "you lose your grip and fall. You may have broken a bone your not sure but you know it's hard to walk now";
									cout << endl << endl;
									cout << "Do you want to 1. try and climb the tree again or 2. give up and go forage for food on the ground? ";

									do {
										cin >> treeopt;
										cout << endl << endl;

										switch(treeopt){
											case 1:
											   	int cocunutopt;
												bool cocunutgood;

										   		cout << "You decide that you really want the cocunut and try to climb the tree again, and this time your succesfull \n";
												cout << "you grab the cocunut and make it back down to the safe ground. Although how are you going to open it now? \n";
												cout << endl << endl;
												cout << "Do you want to 1. try and smash the cocunut on a rock to try and open it or 2. drop it from a cliff: ";
												
												do{
													cin >> cocunutopt;
												    cout << endl << endl;	

											   		switch(cocunutopt){
														case 1:
															cout << "You decide to smash the cocunut off of a rock, you limp over to the nearest rock and start smashing \n";
															cout << "the cocunut on the rock and it opens up. You eat all the food and feel replenishe.d while on the beach \n";
															cout << "you see a man that approaches you and tells you that you were on a ship that crashed offshore and he's apart \n";
															cout << "the search crew looking for you. He takes you back and you are saved.";
														   	cout << endl << endl;
													     	cout << "Thanks for playing! Also good job on surviving. Play again if you want to take another path. ";
															cout << endl << endl;		
															
															cocunutgood = true;
														   	break;
														case 2:
															cout << "You decide to drop it off a cliff becuase it will be too hard to open by hand which is a smart \n";
															cout << "decision. The only cliff you see is a whiles away from where you are in the forest but you still \n";
															cout << "do it anyways because your hungry and you need food. You make it to the cliff safely and get ready \n";
															cout << "to throw the cocunut but slip while throwing it and fall to your death.";
															cout << endl << endl;
															cout << "Thanks for playing! play again and see if you can survive next time.";
															cout << endl << endl;

															cocunutgood = true;
															break;
														default:
															cin.clear();
															cin.ignore(1000, '\n');
															cout << "Invalid input, enter 1 or 2. Try Again: ";
														   	cout << endl << endl;
														   	cocunutgood = false;
														   	break;
													}
												}while(!cocunutgood);

												treegood = true;
												break;
											case 2:
												char mushroomopt;
												bool mushroomgood;
												
												cout << "You already hurt yourself climbing the tree so you decide to not climb it again and risk getting injured even more. \n";
												cout << "You go forace on the ground and see some mushrooms, and they look really tasty, there are some green ones which look \n";
												cout << "scary and some brown ones that look really good, like shitake mushrooms.";
												cout << endl << endl;
												cout << "Do you want to eat the green mushrooms 'g' or the brown mushrooms 'b': ";

												do{
													cin >> mushroomopt;
													cout << endl << endl;

											   		switch(mushroomopt){
														case 'b':
															cout << "You go ahead and decide to eat the brown mushrooms because they look a lot better, and then you \n";
															cout << "start to feel funny, and you start to see things. This is when you realize that they were magic \n";
															cout << "mushrooms. You start to see a path and follow it and then realize your ina village, and that you \n";
															cout << "had made it back to civilization, and they tell you that you had been missing from a ship wreck \n";
															cout << "that you were in. You were the only surivor.";
															cout << endl << endl;
															cout << "Thanks for playing! Also good job on surviving. Play again if you want to take another path.";
															cout << endl << endl;

														   	mushroomgood = true;
														   	break;
														case 'g':
															cout << "You decide to eat the green ones because you like interesting foods, although right after eating \n";
															cout << "it you start to feel funny, and then you start to throw up, and then you start to realize that they \n";
															cout << "were poisonious mushrooms. Theres not much you can do now you lay on the beach and don't make it.";
															cout << endl << endl;
															cout << "Thanks for playing! Play again and see if you can survive next time.";
															cout << endl << endl;

														   	mushroomgood = true;
														   	break;
														default:
															cin.clear();
															cin.ignore(1000, '\n');
														   	cout << "Invalid input, enter 'g' or 'b'. Try again:";
															cout << endl << endl;
														   	mushroomgood = false;
														   	break;
													}
												}while(!mushroomgood);
												
												treegood = true;
												break;
											default:
												cin.clear();
												cin.ignore(1000, '\n');
												cout << "Invalid input, enter 1 or 2. Try again: ";
										     	cout << endl << endl;
												treegood = false;
												break;		
										}
									}while(!treegood);

									good_1 = true;
									break;
								case 0:
									char groundopt;
									bool groundgood;

									cout << "You decided to not climb the tree, a safe choice, and you start to forage for food on the \n";
									cout << "ground in bushes and other things such as that. ";
									cout << endl << endl;
									cout << "You find two berries after foraging for food green ones and blue ones. Which one do you want to eat? \n";
									cout << "Press 'g' for green and 'b' for blue: ";
									
									do{
										cin >> groundopt;
										cout << endl << endl;

										switch(groundopt){
											case 'b':
												int searchopt;
												bool searchgood;	

												cout << "You decided to eat the blue berries, and turns out they are just regular old wild blue berries \n";
												cout << "You eat those and feel nourished, now that you're not hungry anymore you try to figure out where \n";
												cout << "you're at and how you got here. You see a big old cliff and think you might be able to get a vantage \n";
												cout << "point and some information about your location. You also see a big pile of rocks and what looks like a \n";
												cout << "A crashed boat.";
												cout << endl << endl;
												cout << "Do you want to 1. go check out the cliff or 2. go check out the wrecked boat near the rocks: ";
												
												do{	
													cin >> searchopt;
													cout << endl << endl;

													switch(searchopt){
														case 1:
															cout << "You decide to go check out the cliff so you can try and get a vantage point and see whats goind on. \n";
															cout << "You make it there just fine and take a look over the cliff and see people searching for you and a crashed \n";
															cout << "boat, which all makes sense to you now you survived a shipwreck and people are searching for you. In your \n";
															cout << "excitement at this realization you start to dance next to the cliff when you accidentally slip and fall \n";
															cout << "to your death.";
															cout << endl << endl;
															cout << "Thanks for playing. Play again and see if you can survive next time.";
															cout << endl << endl;

														   	searchgood = true;
														   	break;
														
														case 2:
															cout << "You decide to go see the wrecked boat next to the rocks, and when you get there you suspicions are \n";
															cout << "true. It is a wrecked boat and there is stuff spread out everywhere, and in this sight you remember \n";
															cout << "that you were in a shipwreck. At this realization you think your lucky but also stranded. You also \n";
													     	cout << "suspect that people would look for you and this is where they would go first. So you wait. After waiting \n";
															cout << "a while you see rescue people and they come and save you.";
															cout << endl << endl;
															cout << "Thanks for playing. Also good job on surviving. Play again to try a different path";
															cout << endl << endl;

															searchgood = true;
															break;
														default:
															cin.clear();
															cin.ignore(1000, '\n');
														   	cout << "Invalid input, enter 1 or 2. Try again: ";
														   	cout << endl << endl;
														   	searchgood = false;
														   	break;
													}
												}while(!searchgood);

												groundgood = true;
											   	break;

											case 'g':

												int gberryopt;
												bool gberrygood;

												cout << "You decide to eat the green berry and you start to feel a little weazy, so you start looking for remedies, and you see a tree \n";
												cout << "and you know that this specific tree's sap is known to make you puke which would help get the berries our of your system \n";
												cout << "the only thing is you read this a long time ago in a book and your not entirely sure if that's the same tree. ";
												cout << endl << endl;
												cout << "Do you want to 1. try the sap and see if it helps or 2. wait it out and hope the berries don't kill you: ";
													
												do{
													cin >> gberryopt;
													cout << endl << endl;

													switch(gberryopt){
														case 1:
															cout << "you decide to trust your gut and take some of the sap and to your suprise IT WORKS! you start \n";
															cout << "throwing up and you start to feel less weazy. After feeling a lot better you decide to eat the other \n";
															cout << "berries and get some energy to go explore. After exploring you found a man who said you were in a ship \n";
															cout << "wreck and that he was here to save you. You go back with him and survived the wilderness. ";
															cout << endl << endl;
															cout << "Thanks for playing. Also good job on surviving. Play again to try a different path. ";
															cout << endl << endl;
															
														   	gberrygood = true;
														   	break;
														case 2:
															cout << "You decide that eating the sap is too risky of a move because you don't really know if the sap is \n";
															cout << "edible, and you don't really want to die. Although your stomach continues to hurt and then you start \n";
															cout << "puking. After about 30 mins you decide to eat the sap although it's too late and you die, should've \n";
															cout << "trusted your gut more. ";
															cout << endl << endl;
															cout << "Thanks for playing. Play again and see if you can survive next time. ";
															cout << endl << endl;

														   	gberrygood = true;
														   	break;
														default:
															cin.clear();
															cin.ignore(1000, '\n');
														   	cout << "Invalid input, enter in 1 or 2. Try again: ";
														   	cout << endl << endl;
														   	gberrygood = false;
														   	break;
													}
												}while(!gberrygood);

												groundgood = true;
											   	break;

											default:
												cin.clear();
												cin.ignore(1000, '\n');
												cout << "Invalid input, enter 'b' or 'g'. Try Again: ";
												cout << endl << endl;
												groundgood = false;
											   	break;
										}

									}while(!groundgood);

									good_1 = true;
									break;
								default:
									cin.clear();
									cin.ignore(1000, '\n');
									cout << "Invalid input, enter 1 or 0. Try Again: ";
									cout << endl << endl;
									good_1 = false;
									break;
							}		
						}while(!good_1);

						good = true;
						first_iter = false;
					}

					break;
				default:
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid input, enter either 'b' or 'f'. Try again: " << endl << endl;
					good = false;
					first_iter = true;
					
					break;
			}

		} while(!good);	

		//break out of main game while loop
		break;
	}	

	//return 0 and end program
	return 0;
}
