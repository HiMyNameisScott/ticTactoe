#pragma once
#include <iostream>
#include <string>

class TicTacToe {
    public:

    /// @brief checks vertical for win condition, sets winning player
    /// @return returns true if winning condition is met
    bool check_vert(){
        for(int i = 0 ; i < 3 ; i++){
            if(board[i][1] == board[i][2] && board[i][1] == board[i][0]){
                if (board[i][1] == 'X') { player_won = 1;}
                if (board[i][1] == 'O') { player_won = 2;}
                game_active = false;
                return true;    
            }
        }
        return false;
    }

    /// @brief  checks the horizontal win conditions, and sets winning player
    /// @return returns true if winning condition is met
    bool check_horz(){
        for (int i = 0; i < 3 ; i++){
            if(board[1][i] == board [0][i] && board[1][i] == board[2][i] ){
            if (board[1][i] == 'X') { player_won = 1;}
            if (board[1][i] == 'O') { player_won = 2;}
            game_active = false;
            return true;      
            }
        }
        return false;
    }

    /// @brief  checks diags for win condition, sets the winning player if winning condition is true
    /// @return returns true if win condition exists
    bool check_diag(){
        if (board[1][1] == board[0][0] && board[1][1] == board[2][2]){
            if (board[1][1] == 'X') { player_won = 1;}
            if (board[1][1] == 'O') { player_won = 2;}
            game_active = false;
            return true;
        } else if (board[1][1] == board[0][2] && board[1][1] == board[2][0]){
            if (board[1][1] == 'X') { player_won = 1;}
            if (board[1][1] == 'O') { player_won = 2;}
            game_active = false;
            return true;
        } else {
            return false;
        }

    }
    
    /// @brief populates the starting board to label the numbers on the board
    void pop_board(){
        char spot_number = 49;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                board[i][j] = spot_number;
                spot_number ++;
            }
        }
    };

    /// @brief used to display the board state
    void display_board(){
        using namespace std;
        cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "---------" << endl;
        cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "---------" << endl;
        cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    };

    /// @brief this function will add spots to the game board
    void add_spot(){
        std::string input;
        std::cout << "Enter a spot 1-9." << std::endl;
        std::cin >> input;
        
        for(int i = 0; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(static_cast<char>(input[0]) == board[i][j]){
                    if(player_turn == 1){ 
                        board[i][j] = 'X';
                        player_turn = 2;
                        spots_used++;
                    }else if(player_turn == 2){
                         board[i][j] = 'O';
                         player_turn = 1;
                         spots_used++;}
                }
            }
        }


    }

    /// @brief This is the function that runs the game
    void run_game(){
        pop_board();
        std::cout << "before loop " << std::endl;
        while(spots_used != 9 && game_active != false){
            display_board();
            add_spot();
            check_vert();
            check_horz();
            check_diag();
        }

        if(player_won == 1 || player_won == 2){
            display_board();
            std::cout << "Player " << player_won <<" has won!" << std::endl;
        } else {
            display_board();
            std::cout << "The game is a draw!" << std::endl; 
        }
    }

    private:

    char board[3][3];           // Holds to board, and state of game
    bool game_active = true;    // lets us know if the game is still able to run
    int player_won = 0;         // determines which player won the game
    int player_turn = 1;        // keeps track of the turn order
    int spots_used = 0;         // used to track spots, in case of draw
    

};