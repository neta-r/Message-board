#include "Board.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
using namespace ariel;
using namespace std;

int main() {
    ariel::Board board;
    board.post(0, 2, Direction::Horizontal, "I love cats");
    board.show();
    cout << endl;
    board.post(3, 4, Direction::Vertical, "My cat is the best");
    board.show();
    cout << endl;
    board.post(3, 4, Direction::Horizontal, "My sister's name is Michal");
    board.show();
    cout << endl;
    board.post(0, 10, Direction::Vertical, "My fave artist is Eminem");
    board.show();
    cout << endl;
    board.post(7, 2, Direction::Horizontal, "Today is Tuesday");
    board.show();
    cout << endl;
    board.post(15, 0, Direction::Horizontal, "I have no money");
    board.show();
    cout << endl;
    board.post(2, 14, Direction::Vertical, "Tell me what to do");
    board.show();
    cout << endl;
    board.post(3, 18, Direction::Horizontal, "Popcorn");
    board.show();
    cout << endl;
    board.post(22, 6, Direction::Horizontal, "123456789");
    board.show();
    cout << endl;
    board.post(15, 5, Direction::Horizontal, "-)(&*%^#$$~");
    board.show();
    cout << endl;
}