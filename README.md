The following programs have been created for the purpose of the Final Project for class SE 3377 - C/C++ in Unix Environment

Problem 1 - Files to run - piMonteCarlo.c , pi.sh, Answer1CPP.txt, Answer1Bash.txt
    To compile the C and .sh file use the following command.

For piMonteCarlo.c use ---- gcc -o pi -I$HOME/Users/amankhoja/gsl/include piMonteCarlo.c -lgsl -lgslcblas -L$HOME/gsl/lib

For pi.sh use - in terminal ------->  ./pi.sh
    

Problem 2 - Dealer.cpp Handler.cpp mytools.c mytools.h
For dealer.pp use ----gcc -o dealer -I$HOME/Users/amankhoja/gsl/include dealer.cpp handler.cpp -lgsl -lgslcblas -L$HOME/gsl/lib

***** Note Problem 2 is unfinished *******


Problem 3 - instead of getting commands from command line prompt, the script runs and will then ask you to enter a filename whom contents you want to copy, following the filename entered, it will then ask you to enter the file you would want to paste this contents to. If the filename doesn't exist, the program will create a new file or if it does exist it will append it. 
For mighty.c use ---- gcc -o mighty -I$HOME/Users/amankhoja/gsl/include mighty.c -lgsl -lgslcblas -L$HOME/gsl/lib


Problem 4 - Signal.c
For Signal.c please use --- gcc -o signals -I$HOME/Users/amankhoja/gsl/include Signal.c -lgsl -lgslcblas -L$HOME/gsl/lib

******* Note Problem 4 is Unfinished *******;


Bonus Question 1 - bonus1.cpp

For bonus1.cpp please use ---- gcc -o bonus1 -I$HOME/Users/amankhoja/gsl/include bonus1.cpp -lgsl -lgslcblas -L$HOME/gsl/lib

Bonus Question 2 - bonus2.cpp

For bonus2.cpp please use ---- g++ -o bonus2 bonus2.cpp

Bonus Question 3 - bonus3.cpp

For using bonus3.cpp please use ----- gcc -o bonus3 bonus3.c
