#include <iostream>
#include<cstdio>
#include<cstdlib>



using namespace std;

int number_engine(int balance, int bet){ //GAME ENGINE
    int answer = rand() % 10 + 1;
    int guess;
    cout<<"\nPlace your bet: ";
    scanf("%d", &bet);
    while(bet > balance){
        cout<<"Invalid bet, try again: ";
        scanf("%d", &bet);
    }
    cout<<"\nGuess a number between 1-10: ";
    scanf("%i", &guess);
    if(answer == guess){
        cout<<"Correct! The answer was " << answer;
        balance += (bet*2);
        cout<<"\nCurrent balance is: $"<<balance<<" || DOUBLE SCORE!!";
        return balance;
    }
    else if (abs(answer - guess) != 1){
        cout<<"Incorrect! The answer was " <<answer<< "\n";
        balance -= bet;
        cout<<"Current balance is: $"<<balance<<" || Better Luck next time!\n";
        return balance;
    }
    cout<<"Close! The answer was " <<answer<<" || Get your bet back!\n";
    cout<<"\nNew Balance: $"<<balance;
    return balance;

}
int casino(int balance, int bet, char* name){ //PLAY AGAIN RECURSION
    char c;
    cout<<"\nCurrent balance: $"<<balance;
    double curr_balance = number_engine(balance, bet);
    cout<<"\nPLAY AGAIN? Y/N: ";
    while((getchar()!= '\n'));
    c = getchar();
    if(c == 'Y' || c == 'y'){
       return casino(balance, bet, name);
    }
    else
        return curr_balance;
}

int main(){
    int balance; int bet; char name[30];
    cout<<"ENTER NAME (max 30 characters): ";
    fgets(name, sizeof name, stdin);
    cout<<"\nENTER BALANCE: ";
    scanf("%d", &balance);
    cout<<"\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    casino(balance, bet, name);
    return 0;

}
