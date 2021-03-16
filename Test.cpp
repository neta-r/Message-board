#include "doctest.h"
#include "Board.hpp"

using namespace ariel;

#include <string>

using namespace std;

ariel::Board board;

TEST_CASE ("I love cats") {
    board.post(0, 2, Direction::Horizontal, "I love cats");
            CHECK(board.read(0, 0, Direction::Horizontal, 6) == "__I lo");
            CHECK(board.read(0, 10, Direction::Horizontal, 15) == "ats____________");
}

TEST_CASE ("My cat is the best") {
    board.post(3, 4, Direction::Vertical, "My cat is the best");
            CHECK(board.read(2, 4, Direction::Vertical, 3) == "_My");
            CHECK(board.read(7, 2, Direction::Horizontal, 7) == "__a____");
}

TEST_CASE ("My sister's name is Michal") {
    board.post(3, 4, Direction::Horizontal, "My sister's name is Michal");
            CHECK(board.read(2, 4, Direction::Vertical, 3) == "_My");
            CHECK(board.read(2, 13, Direction::Vertical, 4) == "_'__");
}

TEST_CASE ("My fave artist is Eminem") {
    board.post(0, 10, Direction::Horizontal, "My fave artist is Eminem");
            CHECK(board.read(0, 6, Direction::Horizontal, 8) == "ve cMts_");
            CHECK(board.read(8, 1, Direction::Horizontal, 13) == "___t_____a___");
}

TEST_CASE ("Today is Tuesday") {
    board.post(7, 2, Direction::Horizontal, "Today is Tuesday");
            CHECK(board.read(6, 4, Direction::Vertical, 3) == "cdt");
            CHECK(board.read(8, 1, Direction::Horizontal, 0) == ""); //Trying to read 0 chars
}

TEST_CASE ("I have no money") {
    board.post(15, 0, Direction::Horizontal, "I have no money");
            CHECK(board.read(12, 4, Direction::Vertical, 10) == " thv best_");
            CHECK(board.read(9, 10, Direction::Vertical, 15) == "rtist ms Eminem");
}

TEST_CASE ("Tell me what to do") {
    board.post(2, 14, Direction::Vertical, "Tell me what to do");
            CHECK(board.read(12, 3, Direction::Vertical, 16) == "_ _____s___a_____");
            CHECK(board.read(100, 109, Direction::Vertical, 4) == "____"); //Trying to read where nothing was written- Vertical
}


TEST_CASE ("Popcorn") {
    board.post(3, 18, Direction::Horizontal, "Popcorn");
            CHECK(board.read(3, 0, Direction::Horizontal, 32) == "____My sisfe'e napopcornichal__");
            CHECK(board.read(100, 109, Direction::Horizontal, 4) == "____"); //Trying to read where nothing was written- Horizontal
}

TEST_CASE ("123456789") {
    board.post(22, 6, Direction::Horizontal, "123456789");
            CHECK(board.read(0, 12, Direction::Vertical, 25) == "s__r___u_______n______7__");
            CHECK(board.read(18, 10, Direction::Horizontal, 6) == "Emin5m");
}

TEST_CASE ("-)(&*%^#$$~") {
    board.post(15, 5, Direction::Horizontal, "-)(&*%^#$$~");
            CHECK(board.read(0, 10, Direction::Vertical, 23) == "My fave artist ^s Emin5m");
            CHECK(board.read(13, 14, Direction::Vertical, 6) == "t ~o d");
}
