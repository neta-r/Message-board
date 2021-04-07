#include "Board.hpp"
#include "Direction.hpp"
#include <exception>

using namespace std;

namespace ariel {


    Board::Board() { //Initialize of the board's proportion to +-infinity
        this->min_col = std::numeric_limits<unsigned int>::max();
        this->min_row = std::numeric_limits<unsigned int>::max();
        this->max_col = std::numeric_limits<unsigned int>::min();
        this->max_row = std::numeric_limits<unsigned int>::min();
    }

    /*
     * Board's proportions: 1. The board will show 3 squares before and 3 squares after the message that has the smallest row.
     * Beside for the case that the message is posted in row 0-3 -> in this case the minimum row allowed is 0.
     * 2. The board will show 1 square above and 1 square under the message that has the smallest column.
     * Beside for the case that the message is posted in column 0-1 -> in this case the minimum column allowed is 0.
     */


    //This function fixes the board's proportions when the user want to post a vertical message.
    void Board::fix_proportion(unsigned int row,unsigned int col,unsigned int length, ariel::Direction direction) {
        unsigned int r_length=0;
        unsigned int c_length=0;
        switch (direction) {
            case (Direction::Horizontal):
                r_length = 0;
                c_length = length;
                break;
            case (Direction::Vertical):
                r_length = length;
                c_length = 0;
                break;
        }
        if (col + c_length + 1 > this->max_col) {
            max_col = col + c_length + 1;
        }
        if (col - 1 < this->min_col) {
            if (col >= 0 && col <= 1) {
                min_col = 0;
            } else {
                min_col = col - 1;
            }
        }
        if (row + r_length + 1 > this->max_row) {
            max_row = row + r_length + 1;
        }
        if (row - 1 < this->min_row) {
            if (row >= 0 && row <= 1) {
                min_row = 0;
            } else {
                min_row = row - 1;
            }
        }
    }

    //This function decide whether to promote the i or the j according to the direction.
    void plusplus(unsigned int &i,unsigned int &j, ariel::Direction direction) {
        switch (direction) {
            case (Direction::Horizontal):
                j++;
                break;
            case (Direction::Vertical):
                i++;
                break;
        }
    }

    void Board::post(unsigned int  row, unsigned int  column, ariel::Direction direction, std::string message) {
        unsigned int i = 0;
        unsigned int j = 0;
        fix_proportion(row, column, message.size(), direction);
        for (unsigned int run = 0; run < message.size(); run++) {
            board[row + i][column + j] = message.at(run);
            plusplus(i, j, direction);
        }
    }


    std::string Board::read(unsigned int  row, unsigned int  column, ariel::Direction direction,unsigned int length) {
        std::string ans;
        unsigned int i = 0;
        unsigned int j = 0;
        for (unsigned int run = 0; run<length; run++) {
            try {
                char cur = board.at(row + i).at(column + j);
                ans += cur; //the char exist
            }
            catch (exception ex) { //the char doesn't exist
                ans += "_";
            }
            plusplus(i, j, direction);
        }
        return ans;
    }


    void Board::show() {
        unsigned int min_r = min_row;
        unsigned int min_c = min_col;
        unsigned int max_r = max_row;
        unsigned int max_c = max_col;
        // No posts were made.
        // Usage of the board's default proportions.
        if (this->min_col == std::numeric_limits<int>::max()) {
            min_r = default_min_row;
            min_c = default_min_col;
            max_r = default_max_row;
            max_c = default_max_col;
        }
        std::string ans;
        cout << "max_row: " <<max_row << endl;
        unsigned int num_of_rows = max_r - min_r;
        unsigned int num_of_cols = max_c - min_c;
        if (num_of_rows==1) {
            num_of_rows++;
        }
        for (unsigned int i = 0; i < num_of_rows; i++) {
            //sending to the read function each line (horizontal) as the number of the columns.
            ans += read(min_r + i, min_c, Direction::Horizontal, num_of_cols);
            ans += "\n";
        }
        std::cout << ans << endl;
        std::cout << ans << endl;
    }
}
