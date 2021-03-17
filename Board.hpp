#include <iostream>
#include <utility>
#include <unordered_map>
#include "Direction.hpp"

namespace ariel {
    class Board {
    private:
        int max_row, max_col, min_row, min_col;
        void horizontal_dimensions (int row, int col ,int length);
        void vertical_dimensions (int row, int col, int length);

    public:
        std::unordered_map<int, std::unordered_map<int, char>> board;

        Board();

        void post(int row, int column, ariel::Direction direction, std::string message);

        std::string read(int row, int column, ariel::Direction direction, int length);

        void show();
    };
}
