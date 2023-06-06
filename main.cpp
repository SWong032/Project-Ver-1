/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sydney Wong
 *
 * Created on May 9, 2023, 5:21 PM
 * Purpose: Project 2 Ver 1
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Prototypes
//selection sort
void selSort(int [], int);
bool linSrch(int [], int, int); //linear search

int main(int argc, char** argv) {
    // Initialize random seed
    srand(time(NULL));

    //players' scoring
    float dealer = rand() % 10 + 12;  // Dealer starts with random score between 12 and 21 (can't be 13 since it'll go over 21)
    int p1 = 0; //player 1
    int p2 = 0; //player 2

    // Draw two cards for each player
    p1 += rand() % 10 + 2;
    p2 += rand() % 10 + 2;

    string intro = "                           A Game of Blackjack"; //Welcome Title
    cout << intro << endl; //printing out title

    cout << endl;

    cout << "                              -Instructions-        \n"; //print out instructions

    cout << "A simple multiplayer card game. An easy game of chance, just like rock, paper, scissors.\n";
    cout << "The goal of Blackjack is to beat the dealer or get close to 21. First step is to place\n";
    cout << "in your bets. Players either choose hit or stand. If you choose hit, another card will be\n";
    cout << "added to your deck to add to your card value. If you choose stand, you will keep your card\n";
    cout << "value. Each player's card value will total up which will determine whether you win or lose.\n";
    cout << "For example, your first card is a 10 and you choose to hit. The second card is 9 which totals\n";
    cout << "to 19, if the dealer's hand is 20, the player can hit or stand until the dealer reveals their\n";
    cout << "hand. If the player's hand is closer to 21, you win. You lose if your hand went over 21 or under\n";
    cout << "since your goal is to beat other players and the dealer. Best of luck!" << endl;
    cout << endl << endl;

    //Easy Read to instructions
    cout << "*If you didn't bother reading the instructions, here's how it works.*\n";
    cout << "1. Win? You want to score under 21 and not over to beat the dealer.\n";
    cout << "2. How? The cards given to you are your score and it either adds or doesn't.\n";
    cout << "3. Add to your score? Choose hit.\n";
    cout << "4. Don't want to add to your score?  Choose stand.\n";
    cout << "5. Score = close to 21 & dealer & other players' hand is lower than yours. Win.\n";
    cout << "6. Score = lower than dealer & other player's hand. Lose.\n";
    cout << "7. Strategize because you placed bets, or not and just wing it.\n";
    cout << endl << endl;

    cout << "                               *Notice* \n"; //Note for development
    cout << "Please be aware this game is in development so bets will not be included at the moment. \n";

    bool playing = true; //game starts

    ofstream myFile;
    myFile.open("myFile.txt"); //open the file

    do {
        //Display the scores

        cout << endl;
        cout << "Scoreboard" << endl;
        cout << "Player 1 score: " << p1 << endl;
        cout << "Player 2 score: " << p2 << endl;
        cout << "Dealer score: " << dealer << endl;
        cout << endl;
        myFile << endl;
        myFile << "Scoreboard" << endl;
        myFile << "Player 1 score: " << p1 << endl;
        myFile << "Player 2 score: " << p2 << endl;
        myFile << "Dealer score: " << dealer << endl;
        myFile << endl;

        //Players will either choose hit or stand (h/s) to decide their fate
        //Player 1's turn
        cout << "Player 1, would you like to hit or stand? (Press h or s)" << endl;
        myFile << "Player 1, would you like to hit or stand? (Press h or s)" << endl;
        char choice1; //player's input
        cin >> choice1;
        myFile << choice1 << endl;

        //Player 2's turn
        cout << "Player 2, would you like to hit or stand? (Press h or s)" << endl;
        myFile << "Player 2, would you like to hit or stand? (Press h or s)" << endl;
        char choice2; //player's 2 input
        cin >> choice2;
        myFile << choice2 << endl;

        if (choice1 == 'h') { //if player 1 chooses hit
            p1 += static_cast<int>(rand() % 10 + 2); //The player draws another card
            if (p1 > 21) { // Check if player 1 passes 21
                cout << "Player 1 beats everyone! Congrats on winning!" << endl;
                myFile << "Player 1 beats everyone! Congrats on winning!" << endl;
                playing = false; //ends the loop and game
            }
        }

        if (choice2 == 'h') { //if player 2 chooses hit
            p2 += static_cast<int>(rand() % 10 + 2); //The player draws another card
            if (p2 > 21) { // Check if player 2 busts
                cout << "Player 2 beats everyone! Congrats on winning!!" << endl;
                myFile << "Player 2 beats everyone! Congrats on winning!!" << endl;
                playing = false; //ends the loop and game
            }
        }

        if (choice1 == 's' && choice2 == 's') { //If both players choose stand
            while (dealer < 17) { // Dealer's turn
                dealer += static_cast<int>(rand() % 10 + 2); // Draw another card for the dealer
            }

            if (dealer >= 17 && dealer <= 21) { // If the dealer's score is between 17 and 21
                if (dealer >= p1 && dealer >= p2) { // If the dealer beats both players
                    cout << "Dealer beats everyone! Better luck next time!" << endl;
                    myFile << "Dealer beats everyone! Better luck next time!" << endl;
                } else if (p1 > p2 && p1 > dealer) { // If player 1 beats the dealer and player 2
                    cout << "Player 1 beats everyone! Congrats on winning!" << endl;
                    myFile << "Player 1 beats everyone! Congrats on winning!" << endl;
                } else if (p2 > p1 && p2 > dealer) { // If player 2 beats the dealer and player 1
                    cout << "Player 2 beats everyone! Congrats on winning!" << endl;
                    myFile << "Player 2 beats everyone! Congrats on winning!" << endl;
                }
                playing = false; //ends the loop and game
            } else if (dealer > 21) { // If the dealer busts
                if (p1 <= 21 && p2 <= 21) { // If both players are under 21
                    cout << "Both players beat the dealer! Congrats on winning!" << endl;
                    myFile << "Both players beat the dealer! Congrats on winning!" << endl;
                } else if (p1 > 21 && p2 > 21) { // If both players bust
                    cout << "Both players bust! Dealer wins!" << endl;
                    myFile << "Both players bust! Dealer wins!" << endl;
                } else if (p1 <= 21 && p2 > 21) { // If player 1 is under 21 and player 2 busts
                    cout << "Player 1 beats the dealer! Congrats on winning!" << endl;
                    myFile << "Player 1 beats the dealer! Congrats on winning!" << endl;
                } else if (p1 > 21 && p2 <= 21) { // If player 2 is under 21 and player 1 busts
                    cout << "Player 2 beats the dealer! Congrats on winning!" << endl;
                    myFile << "Player 2 beats the dealer! Congrats on winning!" << endl;
                }
                playing = false; //ends the loop and game
            }
        }

    } while (playing);

    myFile.close(); //close the file

    return 0;
}

//selection sort
void selSort(int array[], int size) { 
    for (int i = 0; i < size - 1; i++) {
        int mIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[mIndex]) {
                mIndex = j;
            }
        }
        swap(array[i], array[mIndex]);
    }
}

//linear search
bool linSrch(int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return true;
        }
    }
    return false;
}