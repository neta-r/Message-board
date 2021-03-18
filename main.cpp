#include "Board.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;

int main() {
    ariel::Board board;
    int num = 0;
    cout << "please enter the number of messages you want to write: " << endl;
    cin >> num;
    for (int i=0; i<num; i++){
        string message;
        int col , row, direction;
        cout << "please enter the message you want to write: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline (cin, message);
        cout << "press 0 to a horizontal message and 1 to a vertical message: " << endl;
        cin >> direction;
        if (direction!=0 && direction!=1){
            cout << "You entered invalid number, Bye-Bye!" << endl;
            break;
        }
        cout << "please enter the row: " << endl;
        cin >> row;
        cout << "please enter the column: " << endl;
        cin >> col;
        board.post(row,col,ariel::Direction(direction), message);
        board.show();
    }
}