#include <iostream>
#include "Direction.hpp"

namespace ariel {
    class Board {
    public:
        Board(/*arguments*/);

        void post(int row, int column, ariel::Direction direction, std::string message);

        std::string read(int row, int column, ariel::Direction direction, int length);

        void show();
    };
}
