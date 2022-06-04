Part 1:
Question #1: No you cannot because it makes a new temporary value that stores the parameter's value and which means you can't change the original variables value
Question #2: If an & is added in front of a character then it is being passed by reference which means that the variable is being copied under an alias name with 
the same memory address which means the orginal variable can be changed.

Part2:

Design: I need to get a string and then turn it into dashes and then reveal the string when a user enters a character that is in a string, a concept very similiar
to the game hangman. There is a requirement of three functions the prototypes look like this.

void get_string(string& str_to_store); - this will get a string from the user and store it in a variable
void set_replace_string(string copy_str, string& dash_str); - this will take that string and output a string of dashes with the size of the inputted string
int get_search_replace(char c, string copy_str, string& dash_str); - this will replace the dash string with the character inputted if it was in the original string

These will all work with c++ string objects and I will loop through them to change their input and to make the game functional.

