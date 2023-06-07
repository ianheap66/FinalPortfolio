#include <iostream>
#include <string>

#include <vector>
#include <algorithm>

class OrderBoard {

    std::vector<int> boardDisplay;
    int n;

    //DLList<int> boardDisplay;


public: 

    OrderBoard() {
        n = 0;
    }

    ~OrderBoard() {}

    void addOrder(int x) {
        int num = x % 100;
        boardDisplay.push_back(num);
        n++;
        display();
    }

    void removeOrder(int x) {
        if(n == 1){
            boardDisplay.erase(boardDisplay.begin());
        }
        else{
            for (int i = 0; i < n; i++) {
                if(boardDisplay[i] == x){
                    boardDisplay.erase(boardDisplay.begin() + i);
                    n--;
                }
            }
        }
        display();
        
    }


    void display() {

        std::sort(boardDisplay.begin(), boardDisplay.end());

        for (int i = 0; i < n; i++) {
            std::cout << boardDisplay[i] << " ";
        }
        std::cout << std::endl;
    }

    int getN() {
        return n;
    }

};

int main() {

    OrderBoard kaplanBoard;

    // add and remove an order 
    kaplanBoard.addOrder(5555520);
    kaplanBoard.addOrder(5555515);
    kaplanBoard.removeOrder(20);

    // add several orders in a row before removing one from the middle
    kaplanBoard.addOrder(5555515);
    kaplanBoard.addOrder(5555599);
    kaplanBoard.addOrder(5555512);
    kaplanBoard.removeOrder(99);

    // add some more orders
    kaplanBoard.addOrder(5555521);
    kaplanBoard.addOrder(5555520);

    // remove another few orders
    kaplanBoard.removeOrder(21);
    kaplanBoard.removeOrder(12); 
    kaplanBoard.removeOrder(15);
}