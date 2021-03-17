# include "Board.hpp"
# include "Direction.hpp"
#include <exception>

using namespace std;

namespace ariel {
    //TODO: add comments

    Board::Board() { //explain this!
        this->min_col = std::numeric_limits<int>::max();
        this->min_row = std::numeric_limits<int>::max();
        this->max_col = std::numeric_limits<int>::min();
        this->max_row = std::numeric_limits<int>::min();
    }

    void Board::horizontal_dimensions (int row, int col, int length){
        if (row+1 > this->max_row) {
            max_row=row+1;
        }
        if (row-1 < this->min_row){
            if (row >=0 && row<=1) {
                min_row=0;
            }
            else {
                min_row = row - 1;
            }
        }
        if (col+length+3 > this->max_col) {
            max_col = col  +length +3;
        }
        if (col-3 < this->min_col){
            if (col>=0 && col<=3){
                min_col=0;
            } else{
                min_col = col-3;
            }
        }
    }

    void Board::vertical_dimensions(int row, int col, int length) {
        if (col+3 > this->max_col) {
            max_col=col+3;
        }
        if (col-3 < this->min_col){
            if (col >=0 && col<=3) {
                min_col=0;
            }
            else {
                min_col = col - 3;
            }
        }
        if (row+length+1 > this->max_row) {
            max_row =row+length+1;
        }
        if (row-1 < this->min_row){
            if (row>=0 && row<=1){
                min_row=0;
            } else{
                min_row = row-1;
            }
        }
    }
    void Board::post(int row, int column, ariel::Direction direction, std::string message) {
        switch (direction) {
            case (Direction::Horizontal):
                horizontal_dimensions (row,column,message.size());
                for (int i = 0; i < message.size(); i++) {
                    board[row][column + i] = message.at(i);
                }
                break;
            case (Direction::Vertical):
                vertical_dimensions(row, column, message.size());
                for (int i = 0; i < message.size(); i++) {
                    board[row + i][column] = message.at(i);
                }
                break;
        }
    }



    std::string Board::read(int row, int column, ariel::Direction direction, int length) {
        std::string ans = "";
        switch (direction) {
            case (Direction::Horizontal):
                for (int i = 0; i < length; i++) {
                    try { //trying to get to board[row][column + i]
                        char cur = board.at(row).at(column + i);
                        ans = ans + cur; //the char exist
                    }
                    catch (exception ex) { //the char doesn't exist
                        ans = ans + "_";
                    }
                }
                return ans;

            case (Direction::Vertical):
                for (int i = 0; i < length; i++) {
                    try { //trying to get to board[row + i][column]
                        char cur = board.at(row + i).at(column);
                        ans = ans + cur; //the char exist
                    }
                    catch (exception ex) { //the char doesn't exist
                        ans = ans + "_";
                    }
                }
                return ans;
        }
    }


    void Board::show() {
        cout << "min_row: " << min_row <<", min_col: " << min_col << ", max_row: " << max_row << ", max_col: " << max_col <<endl;
        int min_i = min_row, min_j = min_col, max_i = max_row, max_j = max_col;
        if (this->min_col == std::numeric_limits<int>::max()){ // No posts were made
            min_i = 0;
            min_j = 0;
            max_i = 10;
            max_j = 10;
        }
        cout << "min_i: " << min_i <<", min_j: " << min_j << ", max_i: " << max_i << ", max_j: " << max_j <<endl;

        std::string ans = "";
        for (int i = 0; i < max_j-min_j; i++) {
            ans = ans + read(min_i, min_j+i, Direction::Horizontal, max_i-min_i) +"\n";
        }
        std:: cout << ans << endl;
    }

}
