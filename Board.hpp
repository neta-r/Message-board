#include <iostream>
#include <utility>
#include <unordered_map>
#include "Direction.hpp"

namespace ariel {
    class Board {
    private:
        int default_min_row = 0 ,default_max_row = 10 , default_min_col = 0 , default_max_col = 10;
        int max_row, max_col, min_row, min_col;
        void fix_proportion(int row, int col, int length, ariel::Direction direction);

    public:
        std::unordered_map<int, std::unordered_map<int, char>> board;

        Board();

        void post(unsigned int  row, unsigned int  column, ariel::Direction direction, std::string message);

        std::string read(unsigned int  row, unsigned int  column, ariel::Direction direction, int length);

        void show();
    };
}
