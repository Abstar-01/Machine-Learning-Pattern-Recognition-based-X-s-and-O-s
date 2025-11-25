#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

using namespace std;

    char var[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char wins[8][3] = {{'1', '2', '3'}, {'1', '4', '7'}, {'1', '5', '9'}, {'2', '5', '8'}, {'3', '6', '9'}, {'3', '5', '7'}, {'4', '5', '6'} ,{'7', '8', '9'}};
    vector <char> player1_choice;
    vector <char> Computer_choice;
    vector<int> options;
    char input, Computers_mark, Players_mark;
    bool ch1, ch2, ch3;
    bool m_1,m_2,m_3;
    bool flag = false, Move, jump_check = false, move_check;
    bool Determining_measure, new_pattern, done;
    string winner, champion1, champion2;
    int turns = 1;
    string W_turn;
   
void players_move_system(){
    do{
        cout << '\n' << endl;
        cout << setw(110) << "Player please enter in your choice: ";
        cin >> input;
        flag = false;

        for(int a = 0; a < Computer_choice.size(); a++){
            if(input == Computer_choice[a]){
                cout << setw(110) << "Enter a value that has not been entered" << '\n' <<endl;
                flag = true;
                break;
            }
        }
        if(turns >= 3){
            for(int a = 0; a < player1_choice.size(); a++){
                if(input == player1_choice[a]){
                    cout << "Please enter in a value that hasn't been entered" << endl;
                    flag = true; 
                }
            }
        }

        }while(flag);

        player1_choice.push_back(input);

        for(int a =0; a < 9; a++){
            if(input == var[a]){
                var[a] = Players_mark;
                break;
            }
        }
}
    
void Defensive_measure(){
   /*
        The below Function determines any possible winning patter that the player
        might have and defend by placing the next move on the missing position for the
        win. The code is run based on the condition that a winning move has not been played
    */     
        char n;
          
       for(int row = 0; row < 9; row++){
             m_1 = false, m_2 = false, m_3 = false; 
        for(int see = 0; see < player1_choice.size(); see++){
            if(player1_choice[see] == wins[row][0]){
            m_1 = true;
                    }
            if(player1_choice[see] == wins[row][1]){
            m_2 = true;
                    }
            if(player1_choice[see] == wins[row][2]){
            m_3 = true;
                    }
                }
            if((m_1 && m_3)||(m_2 && m_3)){
                if((m_1 && m_2) || m_2){
                    n =  wins[row][0];
                    Computer_choice.push_back(n);
                    new_pattern = false;   
                }else{
                    n = wins[row][1];
                    Computer_choice.push_back(n);
                    new_pattern = false;
                }
            }else if((m_1 && m_2)||(m_2 && m_3)){
                if((m_1 && m_3) || m_3){
                    n = wins[row][0];
                    Computer_choice.push_back(n);
                    new_pattern = false;
                }else{
                    n = wins[row][2];
                    Computer_choice.push_back(n);
                    new_pattern = false;
                }
            }else if((m_1 && m_2)||(m_1 && m_3)){
                if((m_2 && m_3) || m_3){
                     n = wins[row][1];
                     Computer_choice.push_back(n);
                     new_pattern = false;
                }else{
                     n = wins[row][2];
                     Computer_choice.push_back(n);
                     new_pattern = false; 
                }
            }
                for(int a = 0; a < 9; a++){
                        if(var [a] == n){
                            var[a] = 'X';
                            done = true;
                            break;
                        }
                    }
            }
}

void Attacking_measure(){
      char n;
          
       for(int row = 0; row < 9; row++){
             m_1 = false, m_2 = false, m_3 = false; 
        for(int see = 0; see < Computer_choice.size(); see++){
            if(Computer_choice[see] == wins[row][0]){
            m_1 = true;
                    }
            if(Computer_choice[see] == wins[row][1]){
            m_2 = true;
                    }
            if(Computer_choice[see] == wins[row][2]){
            m_3 = true;
                    }
                }
            if((m_1 && m_3)||(m_2 && m_3)){
                if((m_1 && m_2) || m_2){
                    n =  wins[row][0];
                    Determining_measure = false;   
                }else{
                    n = wins[row][1];
                    Determining_measure = false;
                }
            }else if((m_1 && m_2)||(m_2 && m_3)){
                if((m_1 && m_3) || m_3){
                    n = wins[row][0];
                    Computer_choice.push_back(n);
                    Determining_measure = false;
                }else{
                    n = wins[row][2];
                    Determining_measure = false;
                }
            }else if((m_1 && m_2)||(m_1 && m_3)){
                if((m_2 && m_3) || m_3){
                     n = wins[row][1];
                     Determining_measure = false;
                }else{
                     n = wins[row][2];
                     Determining_measure = false;
                }
            }
                for(int p1m_seen = 0; p1m_seen < player1_choice.size(); p1m_seen++){
                    if(n == player1_choice[p1m_seen]){ // This checks whether the player has already entered in the placment n
                        char n;
                        Determining_measure = true;
                        done = true;
                        goto skip; 
                    }
                }
                 Computer_choice.push_back(n);
                 new_pattern = false;
                for(int a = 0; a < 9; a++){
                        if(var [a] == n){
                            var[a] = Computers_mark;
                            done = true;
                            break;
                        }
                    }
                skip:
                if(done){
                    break;
                }
            }
}

void Searching_For_Pattern(){
    move_check = false;
            for(int st_val = 0; st_val < Computer_choice.size(); st_val++){
        bool c1, c2, c3, numb_check;
        for(int a = 0; a < 8; a++){
            c1 = false, c2 = false, c3 = false;
        if(Computer_choice[st_val] == wins[a][0]){
            c1 = true;
        }
        if(Computer_choice[st_val] == wins[a][1]){
            c2 = true;
        }
        if(Computer_choice[st_val] == wins[a][2]){
            c3 = true;
        }
        numb_check = true;
        if(c1){
            for(int i = 0; i < player1_choice.size(); i++){
                if (player1_choice[i] == wins[a][1] || player1_choice[i] == wins[a][2]){
                    numb_check = false;
                    break;
                }
            }
            if(numb_check){
             options.push_back(a);   
            }
        }
        numb_check = true;
        if(c2){
            for(int i = 0; i < player1_choice.size(); i++){
                if (player1_choice[i] == wins[a][0] || player1_choice[i] == wins[a][2]){
                    numb_check = false;
                    break;
                }
            }
            if(numb_check){
             options.push_back(a);   
            }
        }
        numb_check = true;
        if(c3){
            for(int i = 0; i < player1_choice.size(); i++){
                if (player1_choice[i] == wins[a][0] || player1_choice[i] == wins[a][1]){
                    numb_check = false; 
                    break;
                }
            }
            if(numb_check){
             options.push_back(a);   
            }
        }
    }

    if(!options.empty()){
    srand(static_cast<unsigned>(time(0)));
    int n = rand() % options.size();
       
    m_back:
    int n_th = rand() % 3;
    
    if(Computer_choice[st_val] == wins[options[n]][n_th]){
        goto m_back;
    }
    for(int j = 0; j < Computer_choice.size(); j++)
    if(Computer_choice[j] == wins[options[n]][n_th]){
        goto m_back;
    }
    for(int j = 0; j < player1_choice.size(); j++){
        if(player1_choice[j] == wins[options[n]][n_th]){

        }
    }
        Computer_choice.push_back(wins[options[n]][n_th]);

        for(int a = 0; a < 9; a++){
            if( Computer_choice[Computer_choice.size() - 1] == var[a]){
            var[a] = Computers_mark;
                }
            }
            move_check = true;
    }
    if(move_check){
        break;
    }else{
        options.clear();
    }
    } 
}

void Win_check(){
    /*
        The below blocks of code check if any of the winning patterns have been
        achived by either the computer or the player
        Once a winning pattern has been iden 
    */
        if(turns%2 != 0){ // Computer check
            for(int row = 0; row < 8; row++){
                    ch1 = false, ch2 = false, ch3 = false; // Boolean check marks, these check if the markers for a winning pattern is identified
                for(int point_val = 0; point_val < Computer_choice.size(); point_val++){
                    if(Computer_choice[point_val] == wins[row][0]){
                        ch1 = true;
                    }else if(Computer_choice[point_val] == wins[row][1]){
                        ch2 = true;
                    }else if(Computer_choice[point_val] == wins[row][2]){
                        ch3 = true;
                    }else{
                        // null esle statment
                    }
                    }
                    if(ch1 && ch2 && ch3){
                        jump_check = true;
                        winner = champion1;
                }
            }
        }else{ // Player 1 check
            for(int row = 0; row < 8; row++){
                ch1 = false, ch2 = false, ch3 = false;
                for(int point_val = 0; point_val < player1_choice.size(); point_val++){
                    if(player1_choice[point_val] == wins[row][0]){
                        ch1 = true;
                    }
                    if(player1_choice[point_val] == wins[row][1]){
                        ch2 = true;
                    }
                    if(player1_choice[point_val] == wins[row][2]){
                        ch3 = true;
                    }
                    if(ch1 && ch2 && ch3){
                        jump_check = true;
                        winner = champion2;
                    }
                }
            }
        }
}

void Computers_move(){
    Computers_mark = 'X', Players_mark = 'O';
    champion1 = "Compuer", champion2 = "Player 1";
    h1:
    ch1 = false, ch2 = false, ch3 = false;
    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << endl; 
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
    
    if (turns%2 != 0){
        // First random number being added to the grid
        if(turns == 1){
        srand(static_cast<unsigned>(time(0)));

        int r = rand() % 9;
        Computer_choice.push_back(var[r]); 
        
        for(int a = 0; a < 9; a++){
        if(Computer_choice[0] == var[a]){
            var[a] = Computers_mark;
                }
            }
        }else if(turns == 3){ 
           /* 
                    # 2ND MOVE
                This identifies the second position to add the computers value 
                with respect to the players moves 
            */
           Searching_For_Pattern();
            
        }else{ 
        Determining_measure = true, new_pattern = true, done = false;
        // A - Attacking system measure
        Attacking_measure();

        // D - Defnencive system measure
        if(Determining_measure){
         Defensive_measure();
        }

        // S - searching for new patterns 
        if(!done){
            Searching_For_Pattern();
        }
    }
    }else{
        players_move_system();
    }

        Win_check();
    if(jump_check){
        goto End;
    }

    turns++;
    if(turns <= 9){
        system("cls");
        goto h1;
    }
    End:
    system("cls");
        cout << '\n' << '\n' << '\n' << '\n' << endl;
        cout << setw(56) << "GAME HAS ENDED!!" << endl;
        if(winner == "Player 1"){
            cout << setw(69) << "Congradulation Player 1 YOU HAVE WON!!!" << endl;
        }else if(winner  == "Computer"){
            cout << setw(54) << "I HAVE WON!!!" << endl;
        }else{
            cout << setw(67) << "Nither Player 1 nor the Computer HAS WON" << endl;
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

    cout << '\n' << '\n' << setw(55) << "Player 1's choices : ";
    // The below loops display the moves made by both players
    for(int a = 0; a < player1_choice.size(); a++){
        if(player1_choice[a] == 0){
        cout << "" << endl;
        }
        cout << player1_choice[a] << " ";
    }

    cout << '\n' << '\n' << setw(55) << "Player 2's choices : ";
    for(int a = 0; a < Computer_choice.size(); a++){
        if(Computer_choice[a] == 0){
        cout << "" << endl;
        }
        cout << Computer_choice[a] << " ";
    }
    cout << endl;
}