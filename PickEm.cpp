#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



using namespace std;

class Profile {
    public:
        string name;
        double balance;
        double bet;
        int guess;
};
Profile set_Player(Profile Player){
    Player.name = "";
    Player.balance = 0.0;
    Player.bet = 0.0;
    Player.guess = 0.0;
    return Player;
}





Profile info(double balance, double bet, int guess, string playername, Profile Player){

    cout<<"LET'S PICK EM'!\n";
    cout<<"Enter your name: ";
    scanf("%s", &Player.name);
    Player.balance = rand() % 100 + 1;
    cout<<"\nHeres your randomized balance "<< Player.name <<": "<<Player.balance << "\n";
    return Player;

}
double number_engine(int balance, int bet, int guess){
    int answer = rand() % 10 + 1; 
    cout<<"Place your bet between $1 and $100: ";
    scanf("%d", &bet);
    cout<<"\nGuess a number between 1-10: ";
    scanf("%i", &guess);
    if(answer == guess){
        cout<<"Correct! The answer was " << answer;
        balance *= 2;
        cout<<"\nCurrent balance is: $"<<balance<<" || DOUBLE SCORE!!";
        return balance;
    }
    else if (abs(answer - guess) != 1){
        cout<<"Incorrect! The answer was " <<answer<< "\n";
        balance -= bet;
        cout<<"Current balance is: &"<<balance<<" || Better Luck next time!\n";
        return balance;
    }
    cout<<"Close! The answer was " <<answer<<" || Get your bet back!\n";
    return balance;

}
int casino(double balance, double bet, int guess){
    double curr_balance = number_engine(balance, bet, guess);
    char playagain;
    cout<<"\nPLAY AGAIN? Y/N: ";
    scanf(" %c", &playagain);
    if(playagain == 'Y'){
       return casino(balance, bet, guess);
    }
    else
        return 0;
}

int run(){
    Profile Player;
    Player = set_Player(Player);
    Player = info(Player.balance, Player.bet, Player.guess, Player.name, Player);
    casino(Player.balance, Player.bet, Player.guess);
    return 0;
}
int main(){
    run();
    return 0;

}
