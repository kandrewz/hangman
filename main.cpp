//
//  main.cpp
//  hangman.cpp
//
//  Created by Andrew  on 6/21/16.
//  Copyright © 2016 Andrew . All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
//---------------------------------------------------------------------------------------------------------------------------------------------------------
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std ;
//most of the lines are for drawing the hangman, copy paste your words into a file called dictionary.txt (make sure all letters lowercase), um directions are p simple + explained when program is ran
int main()
{
    ifstream fin ("dictionary.txt") ;
    ofstream fout ("hangman.txt") ;
    srand (time(NULL)) ;
    int N ;
    string numbers[10000], test1, retry = "again";
    //this is so that you dont need to actually count # of words in your dictionary
    for (N = 0; ; N++)
    {
        fin >> numbers[N] ;
        if (fin.eof())
            break ;
    }
    for ( ; retry == "again" ;){
        int x = rand() % N;     //choose word from dictionary
                //int x = N ;
        string word = numbers[x] ;

        
        int life ;
        string maskedword ;
        string chosenletters ;
        char letter ;
        
        int found, found2 ;
        
        life = 5 ;      //rand() = random number generator
        int y = word.length() ;
        
        for ( int counter = -1 ; counter < y - 1; counter++)
            maskedword = maskedword + "_" ;
        int n = maskedword.length() ;
        do
        {
            if (life != 1)
                cout << "You have " << life << " lives."  << endl ;     //print lives(life)
            else
                cout << "You have 1 life." << endl ;
            
            cout << maskedword << endl ;  //print word
            cout << chosenletters << endl  ;    //show used letters
            cout <<          "   _____ " << endl ;      //drawing the hangman
            cout <<         "   |    | " << endl ;
            cout <<         "   |    0 " << endl ;
            if (life == 5)
                cout <<     "   |       " << endl ;     //drawing parts based on life
            if (life == 4)
                cout   <<   "   |    |" << endl ;
            if (life == 3)
                cout <<     "   |   /|" << endl ;
            if (life <= 2)
                cout <<     "   |   /|\\" << endl ;
            if (life == 1)
                cout <<     "   |   /" << endl ;
            else
                cout <<     "   |      " << endl ;
            cout <<         "___|___ "  << endl ;
            
            cout << "There are " << y << " letters left." << endl ;
            cin >> letter ;     //choose letter  //REMEMBER TO ADD SOMETHING THAT CHECKS IF IT IS
            //ACTUALLY A LETTER
            //find letter
            found2 = chosenletters.find(letter) ;
            found = word.find(letter) ;
            if (found2 != - 1)
            {
                cout << "Already used!" << endl ;
                continue ;
            }
            for (int counter2 = 0; counter2 < n; counter2++)
            {
                if (letter == word[counter2])
                {
                    maskedword[counter2] = letter ;      //put in letters
                    y = y - 1 ;      //you have 1 less letter left
                }
            }
            if (found == -1)         //lose life
                life-- ;
            
            chosenletters = chosenletters + " "  + letter;      //show chosen letters
            
        }
        while (life != 0 && maskedword  != word) ;
        if (life != 0)
        {
            cout << word << endl ;
            cout << "You Won! Good Job! Would you like to play again?" << endl ;
        }
        else
        {
            cout << "   ______" <<      endl ;      //dead guy
            cout << "   |    |" <<      endl;
            cout << "   |    0" <<      endl ;
            cout << "   |   /|\\" <<    endl ;
            cout << "   |   / \\" <<     endl ;
            cout << "___|___"  <<       endl ;
            cout << "The word was " << word << "." << endl ;
            cout << "You Lost! Nice Try!" << endl ;
            
        }
        cout << "type 'again' if you want to retry" << endl ;
        cin >> retry ;
    }
}
