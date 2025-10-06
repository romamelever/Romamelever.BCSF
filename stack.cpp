#include <iostream>
using namespace std;

class CustomStack {
private:
    vector<int> stack;
    vector<int> inc; // lazy increments
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc.push_back(0); // matching slot for increments
        }
    }

    int pop() {
        if (stack.empty()) return -1;

        int i = stack.size() - 1;
        int res = stack[i] + inc[i];

        if (i > 0) inc[i - 1] += inc[i]; // carry increment down
        stack.pop_back();
        inc.pop_back();

        return res;
    }

    void increment(int k, int val) {
        int i = min(k, (int)stack.size()) - 1;
        if (i >= 0) inc[i] += val;
    }
};

int main() {
    CustomStack cs(5);  // max size 5

    cs.push(1);
    cs.push(2);
    cout << cs.pop() << endl; // -> 2

    cs.push(2);
    cs.push(3);
    cs.push(4);

    cs.increment(5, 100); // add 100 to bottom 5 elements
    cs.increment(2, 100); // add 100 to bottom 2 elements

    cout << cs.pop() << endl; // -> 104
    cout << cs.pop() << endl; // -> 103
    cout << cs.pop() << endl; // -> 202
    cout << cs.pop() << endl; // -> 101
    cout << cs.pop() << endl; // -> -1 (stack empty)

    return 0;
}
