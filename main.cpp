#include <iostream> // standard I/O input streams
#include <cmath> // mathematical operations
#include <iomanip> // standard functions like setw, etc....
#include <vector> // Houses the vector syntax that will be used for storing players choice 
#include <array> // Used for the size function (determines the size of the vector)
#include <stdlib.h> // Used for the system("cls") and the rand() & srand();
#include "Sub_file\DATS.cpp"
using namespace std;

void Game_fun(); // this is the game function that is used for the grid and the other
int player1_score = 0, player2_score = 0; 
/*
    the above variables are globalised, emaning that they can be 
    used by all function including the main and the Game_fun function

    This allow us to manipulate the variables in the game function and 
    refere to them in the main function
*/   
int main()
{   // the below are the options provided to the user
    cout << setw(79) << "TIK TAK TOE" << endl;
    cout << setw(78) << "GAME MODE" << endl;
    int selection;
    cout << setw(86) << "1) Two player Single Game" << endl;
    cout << setw(88) << "2) Two player Multiple Game" << endl;
    cout << setw(95) << "3) A Game With The Mind Of The Computer" << endl;

    /* 
        Selection operation (The below loop works to make sure that the user enters
        the proper choice within the given choices)
    */
    do{
    cout << setw(85) << "Select a game mode:";
    cin >> selection;
    if(selection < 1 || selection > 3){
        cout << '\n' << setw(88) << "Selection choic is invalid" << endl;
        cout << setw(93) << "Enter in a correct selection choice" << '\n' << endl;
    }
    }while(selection <= 0 || selection > 3); // prompts the use to enter the right value of the option
    system("cls");
    /*
        The system("cls") is used to clear out the console
        of any outputted stream this syntax comes from the library
        <stdlib.h> 
    */
    cout << endl;

    // The following if/else statments are for the options
    if(selection  == 1){
            cout << '\n' << '\n' << '\n' << '\n' << '\n' << endl; 
            cout << setw(98) << "TWO PLAYER SINGLE GAME" << endl;
        Game_fun(); // this calls the function Game_fun and runs the code in the function
    }else if ( selection == 2){
            string player1, player2;
            cout << "Player 1 name : ";
            cin >> player1;
            cout << "Player 2 name : ";
            cin >> player2;
            bool c1 = false;
        do{
            cout << setw(83) << player1 << "| " << player1_score << " : " << player2_score << " |" << player2 << endl;
            Game_fun();// this calls the function Game_fun and runs the code in the function
            
            char next_game_choice;
            c1 = false;
            invalid:
            cout << "Do you want to play another game : ";
            cin >> next_game_choice;
                if(next_game_choice != 'Y' &&  next_game_choice !='y' && next_game_choice != 'N' &&  next_game_choice !='n'){
                    cout << "Invalid choice entered please enter in a proper choice " << '\n' << endl;
                    goto invalid;
                }
            if(next_game_choice == 'Y' ||  next_game_choice =='y'){
                c1 = true;
                system("cls");
            }else{
                system("cls");
                cout << '\n' << setw(50) <<  "Thank you for playing :-) " << endl;
                if(player1_score > player2_score){
                    cout << setw(76) << "Congragulation "<< player1 << " YOU HAVE WON!!!!" << endl;
                }else if( player2_score > player1_score){
                    cout << setw(76) << "Congragulation " << player2 << " YOU HAVE WON!!!!" << endl;
                }else{
                    cout << setw(56) << "WE HAVE A DRAW" << endl;
                }
            }
            
            
        }while(c1); // This do while loop counts the score for the multiplayer mode
    }else{
        cout << setw(80) << "Hello There" << '\n' << endl;
        cout << setw(84) << "My name is D.A.T.S" << endl;
        cout << setw(103) << "It stands for Defensive or Attacking Terminating System" << endl;
        cout << setw(89) << "I will be your oponent today" << endl;
        cout << setw(91) << "I must warn you I am pretty good" << endl;
        cout << '\n' << endl;

        bool respect = true;
        do{
        string responce;
        cout << setw(95) << "Before we begin can i know you name [Y/N]: ";
        cin >> responce;

        if(responce == "Y" || responce == "y" || responce == "N" || responce == "n" ){
            if(responce == "Y" || responce == "y" ){
                string asked_name;
                cout << "Oh Great, whats your name?" << endl;
                cout << "Name : ";
                cin >> asked_name;
                cout << "Its a pleasure to meet you " << asked_name << endl;
                cout << "May the best oponent WIN " << endl;
                break;
            }else{
                cout << "Oh thats okay!" << endl;
                cout << "Its a pleasure to meeting you anyway"<< endl;
                cout << "May the best oponent WIN " << endl;
                break;
            }
        }else{
            cout << "Sorry, I didnt get that, could you please respond with one of the following" << endl;
            cout << "[Y] or [y] or [N] or [n] " << endl;
            respect = false;
        }
        }while(!respect);
        string proceed;
        cout << "Shal we proceed [y/n] : ";
        cin >> proceed;
        if(proceed == "Y" || proceed == "y"){
            Computers_move();
        }else{
            cout << "Alright, it was nice meeting you " << endl;
        }
    }

    return 0;
}

void Game_fun(){

    char var[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};  // array of the values on the grid
    char wins[8][3] = {{'1', '2', '3'}, {'1', '4', '7'}, {'1', '5', '9'}, {'2', '5', '8'}, {'3', '6', '9'}, {'3', '5', '7'}, {'4', '5', '6'} ,{'7', '8', '9'}};
    vector <char> player1_choice; // player 1s vector for the choice that are done thorughout the game
    vector <char> player2_choice; // player 2s vector for the choice that are done thorughout the game
    char input;
    bool ch1, ch2, ch3;
    bool flag = false;
    string winner;
    int turns = 1;
    bool comparism, nt;

    start:
        ch1 = false, ch2 = false, ch3 = false;
        if(turns > 1){
            cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << endl; 
        }
    // The entire for loop below displays the grid  
    cout << '\n' << '\n' << setw(84);
    for(int i = 1; i <= 9; i++){
        if(i == 4 || i == 7){
         cout << endl << setw(83);
         for(int j = 1; j <= 11; j++){
            cout << "-";
         }
         cout << endl << setw(84);
        }
        cout << var[i - 1];
        if(i%3 != 0){
        cout << " |" << setw(2);
        }
    }

// This if statments below coordinates the turns system 
// The turns are done through even and odd number determination 
    if(turns%2 != 0){
        do{
            comparism = false, nt = true;
        cout << '\n' << endl;
        cout << setw(110) << "PLAYER 1 :  Enter in a number between 1 - 9: ";
        cin >> input;
        for(int a = 0; a < player2_choice.size(); a++){ // Conducts the comparism with player 2's moves
                if(input == player2_choice[a]){ // prevents the same move to be don by the player if already entered
                    comparism = true, nt = false;
                    cout << "Please enter in a value that has not already been enterd" << endl;
                    break;
                }
        }
        if(nt){
            for(int a = 0; a < player1_choice.size(); a++){// Conducts the comparism with player 2's moves
                if(input == player1_choice[a]){// prevents the same move to be don by the player if already entered
                    cout << "Please enter in a value that has not already been enterd" << endl;
                    comparism = true;
                    break;
                }
            }
        }
        }while(comparism);
    player1_choice.push_back(input);
    cout << endl;
    /*
        This loop looks at the users input and tries
        to identify the identical look-a-like within
        the var array
    */
    for(int look = 0; look < 9; look++){
        if(var[look] == input){
            var[look] = 'X'; 
            // The above operation converst the look-a-like into the char X
            break;
        }
      }
    }else{ // If the turns value is not an odd number then the else statment takes into action 
        // The same logic applied in the first section is also alppied here but for player 2
    do{
        char marker = player1_choice[player1_choice.size()-1];
        cout << '\n' << endl;
        cout << setw(110) << "PLAYER 2 :  Enter in a number between 1 - 9: ";
        cin >> input;
        for(int a = 0; a < player2_choice.size(); a++){
            if(input == player1_choice[a]){
                cout << setw(110) << "Enter a value that has not been entered" << '\n' <<endl;
                flag = true;
                break;
            }else if(input == player2_choice[a]){
                cout << setw(110) << "Enter a value that has not been entered" << '\n' <<endl;
                flag = true;
                break;
            }else if(input == marker){
                cout << setw(110) << "Enter a value that has not been entered" << '\n' <<endl;
                flag = true;
                break;
            }else{
                flag = false;
            }
        }
        if(turns == 2){
            if(player1_choice[0] == input){
                cout << setw(110) << "Enter a value that has not been entered" << '\n' <<endl;
                flag = true;
            }else{
                flag = false;
            }
        }
    }while(flag);

    player2_choice.push_back(input);
    cout << endl;

    for(int look = 0; look < 9; look++){
        if(input == var[look]){
            var[look] = 'O';
            break;
        }
      }
    }
    /*
        The below if statment is used to determine if any winning patterns
        have been entered by either player 1 or 2 
    */
        if(turns%2 != 0){ // player 1 check
            for(int row = 0; row < 8; row++){
                    ch1 = false, ch2 = false, ch3 = false; // Boolean check marks, these check if the markers for a winning pattern is identified
                for(int point_val = 0; point_val < player1_choice.size(); point_val++){
                    if(player1_choice[point_val] == wins[row][0]){
                        ch1 = true;
                    }else if(player1_choice[point_val] == wins[row][1]){
                        ch2 = true;
                    }else if(player1_choice[point_val] == wins[row][2]){
                        ch3 = true;
                    }else{
                        // null esle statment
                    }
                    }
                    if(ch1 && ch2 && ch3){
                        winner = "Player 1";
                        goto End;
                }
            }
        }else{ // player 2 check
            for(int row = 0; row < 8; row++){
                ch1 = false, ch2 = false, ch3 = false;
                for(int point_val = 0; point_val < player2_choice.size(); point_val++){
                    if(player2_choice[point_val] == wins[row][0]){
                        ch1 = true;
                    }
                    if(player2_choice[point_val] == wins[row][1]){
                        ch2 = true;
                    }
                    if(player2_choice[point_val] == wins[row][2]){
                        ch3 = true;
                    }
                    if(ch1 && ch2 && ch3){
                        winner = "Player 2";
                        goto End;
                    }
                }
            }
        }
     turns++; // After every operation the the turns variabe increase 

    if(turns <= 9){ // the maximum number of turns per player is 4 thus resulting in a total of 8 turns
        system("cls"); // clears the console 
        goto start;
    }else{
        End:
        system("cls");
        cout << '\n' << '\n' << '\n' << '\n' << endl;
        cout << setw(56) << "GAME HAS ENDED!!" << endl;
        if(winner == "Player 1"){
            cout << setw(69) << "Congradulation Player 1 YOU HAVE WON!!!" << endl;
            player1_score++; // For multiplayer 
        }else if(winner  == "Player 2"){
            cout << setw(69) << "Congradulation Player 2 YOU HAVE WON!!!" << endl;
            player2_score++; // For multiplayer 
        }else{
            cout << setw(67) << "Nither Player 1 nor Player 2 HAS WON" << endl;
        }

        // reprints out the table with all the changes made
        cout << '\n' << setw(44);
        for(int i = 1; i <= 9; i++){
            if(i == 4 || i == 7){
            cout << endl << setw(43);
        for(int j = 1; j <= 11; j++){
            cout << "-";
         }
            cout << endl << setw(44);
        }
            cout << var[i - 1];
            if(i%3 != 0){
            cout << " |" << setw(2);
        }
      }
    }

    cout << '\n' << '\n' << setw(55) << "Player 1's choices : ";
    // The below loops display the moves made by both players
    for(int a = 0; a < player1_choice.size(); a++){
        if(player1_choice[a] == 0){
        cout << "" << endl;
        }
        cout << player1_choice[a] << " ";
    }

    cout << '\n' << '\n' << setw(55) << "Player 2's choices : ";
    for(int a = 0; a < player2_choice.size(); a++){
        if(player2_choice[a] == 0){
        cout << "" << endl;
        }
        cout << player2_choice[a] << " ";
    }
    cout << endl;
}