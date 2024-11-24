#include <iostream>

using namespace std;

struct Chain{
        string color;
        Chain* next;
};

Chain* createChain(string color) {
        Chain* newChain = new Chain;
        newChain->color = color;
        newChain->next = nullptr;
        return newChain;
}

void append(Chain* one, Chain* two) {
        one->next = *&two;
}

class ChainLink {
    private:
      string color;

    public:
      ChainLink(string color) {
        this->color = color;
      }

      string get_color() {
        return this->color;
      }
};

void print(Chain* head) {
        if(head != nullptr) {
                cout << head->color << " ";
                print(head->next);
        }
}

int main() {
        ChainLink one = ChainLink("red");
        Chain* cOne = createChain(one.get_color());
        ChainLink two = ChainLink("blue");

        Chain* cTwo = createChain(two.get_color());
        append(cOne, cTwo);
        ChainLink three = ChainLink("green");
        Chain* cThree = createChain(three.get_color());
        append(cTwo, cThree);
        print(cOne);

        return 0;
}
