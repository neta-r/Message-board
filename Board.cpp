#include "Board.hpp"
#include "Direction.hpp"
#include <exception>

using namespace std;

namespace ariel {


    Board::Board() { //Initialize of the board's proportion to +-infinity
        this->min_col = std::numeric_limits<int>::max();
        this->min_row = std::numeric_limits<int>::max();
        this->max_col = std::numeric_limits<int>::min();
        this->max_row = std::numeric_limits<int>::min();
    }

    /*
     * Board's proportions: 1. The board will show 3 squares before and 3 squares after the message that has the smallest row.
     * Beside for the case that the message is posted in row 0-3 -> in this case the minimum row allowed is 0.
     * 2. The board will show 1 square above and 1 square under the message that has the smallest column.
     * Beside for the case that the message is posted in column 0-1 -> in this case the minimum column allowed is 0.
     */

    //This function fixes the board's proportions when the user want to post a horizontal message.
    void Board::horizontal_proportion(int row, int col, int length) {
        if (row + 1 > this->max_row) {
            max_row = row + 1;
        }
        if (row - 1 < this->min_row) {
            if (row >= 0 && row <= 1) {
                min_row = 0;
            } else {
                min_row = row - 1;
            }
        }
        if (col + length + 3 > this->max_col) {
            max_col = col + length + 3;
        }
        if (col - 3 < this->min_col) {
            if (col >= 0 && col <= 3) {
                min_col = 0;
            } else {
                min_col = col - 3;
            }
        }
    }

    //This function fixes the board's proportions when the user want to post a vertical message.
    void Board::vertical_proportion(int row, int col, int length) {
        if (col + 3 > this->max_col) {
            max_col = col + 3;
        }
        if (col - 3 < this->min_col) {
            if (col >= 0 && col <= 3) {
                min_col = 0;
            } else {
                min_col = col - 3;
            }
        }
        if (row + length + 1 > this->max_row) {
            max_row = row + length + 1;
        }
        if (row - 1 < this->min_row) {
            if (row >= 0 && row <= 1) {
                min_row = 0;
            } else {
                min_row = row - 1;
            }
        }
    }

    void Board::post(int row, int column, ariel::Direction direction, std::string message) {
        switch (direction) {
            case (Direction::Horizontal):
                horizontal_proportion(row, column, message.size());
                for (int i = 0; i < message.size(); i++) {
                    board[row][column + i] = message.at(i);
                }
                break;
            case (Direction::Vertical):
                vertical_proportion(row, column, message.size());
                for (int i = 0; i < message.size(); i++) {
                    board[row + i][column] = message.at(i);
                }
                break;
        }
    }


    std::string Board::read(int row, int column, ariel::Direction direction, int length) {
        std::string ans;
        switch (direction) {
            case (Direction::Horizontal):
                for (int i = 0; i < length; i++) {
                    try { //trying to get to board[row][column + i]
                        char cur = board.at(row).at(column + i);
                        ans +=cur; //the char exist
                    }
                    catch (exception ex) { //the char doesn't exist
                        ans+= "_";
                    }
                }
                return ans;

            case (Direction::Vertical):
                for (int i = 0; i < length; i++) {
                    try { //trying to get to board[row + i][column]
                        char cur = board.at(row + i).at(column);
                        ans +=cur; //the char exist
                    }
                    catch (exception ex) { //the char doesn't exist
                        ans +="_";
                    }
                }
                return ans;
        }
    }


    void Board::show() {
        int min_r = min_row;
        int min_c = min_col;
        int max_r = max_row;
        int max_c = max_col;
        // No posts were made.
        // Usage of the board's default proportions.
        if (this->min_col == std::numeric_limits<int>::max()) {
            min_r = default_min_row;
            min_c = default_min_col;
            max_r = default_max_row;
            max_c = default_max_col;
        }
        std::string ans;
        for (int i = 0; i < max_r - min_r; i++) {
            //sending to the read function each line (horizontal) as the number of the lines (maximum column - minimum column).
            ans += read(min_r + i, min_c, Direction::Horizontal, max_c - min_c);
            ans +="\n";
        }
        std::cout << ans << endl;
    }

}
