#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
//void and other functions
void OverView();



int main()
{
   

        //Display Title of the program to the user
        cout << "\n\n\t Welcome to Keywords2 recruit\n\n\t" << endl;

        // Ask the recruit to log in using their name
        string name;
        cout << "\n\nPlease log in using your first name\n\n";
        cin >> name;
        // Hold the recruit's name in a var, and address them by it throughout the simulation.
        cout << "\n\nWelcome " << name << " to the code breaker program\n\n";
        // Display an overview of what Keywords II is to the recruit 
        OverView();

        bool exit = false;
        int play = 0;
        do {

            cout << "You have played the simulation " << play << " times";
        //the replay statment (for loop)
        for (int j = 1; j <= 3; j++)
        {
            cout << "You are on simulation word " << j << "\n\n";
            const int MAX_WRONG = 10;  //maximum number of incorrect guesses allowed

            vector<string> words;   // Create a collection of 10 words you had written down manually
            words.push_back("AGENT");
            words.push_back("BAGMAN");
            words.push_back("BLOWN");
            words.push_back("CASE_OFFICER");
            words.push_back("COVER");
            words.push_back("EXPATS");
            words.push_back("OSS");
            words.push_back("PLAYBACK");
            words.push_back("SHOE");
            words.push_back("STATION");
            words.push_back("THROWAWAY");

            srand(static_cast<unsigned int>(time(0)));
            random_shuffle(words.begin(), words.end());

            const string THE_WORD = words[0];           //word to guess

            int wrong = 0;                              //number of incorrect guesses
            string soFar(THE_WORD.size(), '-');         //word guessed so far
            string used = "";                           //letters already guessed

            cout << "Welcome, Good luck!\n";

            //main loop
            while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
            {
                cout << "\n\nYou have " << (MAX_WRONG - wrong);
                cout << " incorrect guesses left.\n"; //Tell recruit how many incorrect guesses he or she has left
                cout << "\nYou’ve used the following letters:\n" << used << endl; //Show recruit the letters he or she has guessed
                cout << "\nSo far, the word is:\n" << soFar << endl;//Show player how much of the secret word he or she has guessed

                char guess;
                cout << "\n\nEnter your guess: ";
                cin >> guess;
                guess = toupper(guess); //make uppercase since secret word in uppercase
                while (used.find(guess) != string::npos)
                {
                    cout << "\nYou’ve already guessed " << guess << endl;

                    cout << "Enter your guess: ";
                    cin >> guess;
                    guess = toupper(guess);
                }

                used += guess;

                if (THE_WORD.find(guess) != string::npos)
                {
                    cout << "That’s right! " << guess << " is in the word.\n";
                    //update soFar to include newly guessed letter
                    for (int i = 0; i < THE_WORD.length(); ++i)
                    {
                        if (THE_WORD[i] == guess)
                        {
                            soFar[i] = guess;
                        }
                    }
                }
                else
                {
                    cout << "Sorry, " << guess << " isn’t in the word.\n";
                    ++wrong;
                }
            }

            //shut down
            if (wrong == MAX_WRONG)
            {
                cout << "\nYou’ve been found out " << name << " !";
            }
            else
            {
                cout << "\nYou guessed it!";
            }

            cout << "\nThe word was " << THE_WORD << endl;


        }


        cout << "You have completed 3 rounds and the game is over!\n";
        cout << "Would you like to try again? (0 to exit and 1 to continue)";
        cin >> exit;
        play++;
    } while (exit);

    cout << "\nThanks for playing.\n";

    system("pause");
	return 0;
}


void OverView()
{
	cout << "\nWelcome to the next step in your training recruit\n,";
	cout << "this will be what you will be training with from here on,\n";
	cout << "a more advanced version of the pervious program, so good luck, and do your best!\n\n";
	// Display directions to the recruit on how to use Keywords
	cout << " \n\n\t-- This is how you play --\n\n\t";
	cout << "Input one letter at a time, and you will slowly fill in the word\n";
	cout << "Take your time, and do not rush, you only have 10 guesses before you are found out!";
}