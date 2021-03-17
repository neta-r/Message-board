# include "Board.hpp"
# include "Direction.hpp"
#include <exception>

using namespace std;

namespace ariel {
    //TODO: add comments

    Board::Board() {
        this->max_col = 10;
        this->max_row = 10;
    }

    void Board::post(int row, int column, ariel::Direction direction, std::string message) {
        if (row > this->max_row) {
            max_row = row;
        }
        if (column > this->max_col) {
            max_col = row;
        }
        switch (direction) {
            case (Direction::Horizontal):
                for (int i = 0; i < message.size(); i++) {
                    board[row][column + i] = message.at(i);
                }
                break;
            case (Direction::Vertical):
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


    void Board::show() {}

}
