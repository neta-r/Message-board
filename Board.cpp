# include "Board.hpp"

using namespace std;

namespace ariel {

    Board::Board() {
        this->max_col = 10;
        this->max_row = 10;
    }

    void Board::post(int row, int column, ariel::Direction direction, std::string message) {
        if (row> this->max_row){
            max_row=row;
        }
        if (column> this->max_col){
            max_col=row;
        }
        for (int i = 0; i < message.size(); i++) {
            if (direction==Direction::Horizontal){
                board[row][column+i]=message.at(i);
            } else{
                board[row+i][column]=message.at(i);
            }
        }
    }

    std::string Board::read(int row, int column, ariel::Direction direction, int length) {
//        if (board.find(key) == board.end()) { //key doesn't exist in the map
//            board.insert(key, message.at(i));
//        }
        return "";
    }

    void Board::show() {}
}