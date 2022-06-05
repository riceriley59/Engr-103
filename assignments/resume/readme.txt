Name: Riley Rice
ONID: 934127342
Section: Engr 103-020
Assignment 5, due 6/5/2022

Description: 

Welcome to the resume builder! You can input a file with a specified layout, which is shown later in the readme.txt, 
with all the information that you would put on a resume. It will then take that file and output a resume in 
lastname.txt where lastname is the last name specified in your inputs resume file! 

Instructions:

1) Compile the program with (make sure you also have the helper_funcs.cpp and helper_funcs.h in the directory)

g++ resume.cpp helper_funcs.cpp -o resume

2) Run the program with (also make sure that you have your input txt file in the same directory)

./resume

3) You will then get prompted by the program with a welcome message that looks like

"Welcome to the resume builder! Refer to the readme.txt to know the file layout required for the program 
and then you can input that into the program when you run it. It will take that file and output a resume 
in lastname.txt where lastname is the last name specified in your inputs resume file!".

4) And then that will be followed by another prompt that looks like: 

"Input file name?: "

In which you should enter the name of the input file without the .txt extension, and it will re-prompt until
it gets a valid file name wich exists. Then the program will do all the work and build the resume.

5) Then the program will prompt you on whether you want to run the program again in which you should press the y key
for yes and the n key for no. The prompt will look like this.

"Do you want to build another resume again (y-yes, n-no)?: "

6) After running the program you can enter the command ls and you should see the (lastname from resume).txt which 
you can then concatenate or open with a text editor.

7) Format For The Input File: 

(start of the file)
1. # of work experiences you want to put on your resume
2. # of skills that you want to put on your resume
3. First Name and Last Name(this will be the name of the output file) followed with a ~
4. Email followed with a ~
5. Name of your educational institution followed by with a ~
6. Major: (Your Major) followed with a ~
7. Graduation Year
8. GPA

(This is where the experience inputs start)

9. Company: (your company name) followed with a ~
10. Start Date: (Your start date) followed with a ~
11. End Date: (Your end date) followed with a ~
12. Description: (your Description of your experience at this work place) followed with a ~

(repeat this chunk with how many work experiences you want to input or the number that you have on line 1)

(This is where the skills input starts)

13. One of the skills you want to input 
(repeat this for how many skills you want to put on your resume or the number on line 2)

(End of the file)

There will also be an example input file included with this which is called inputs.txt, and the output file
will look very similiar to a basic resume.

Limitations:
- There is no error handling for the things inside of the input file.
- There input file has to be formatted in a specific way or the program won't work correctly
- The input file must also be in the same directory of where the binary is run

Extra Credit: 
- This program takes its inputs from another file as opposed to taking them from a console where they would need to 
  be re-typed everytime the user re-ran the program which makes it a lot more efficient. Although it still has it's 
  limitations with things such as error handling and usability, which are also listed above.