#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // Check overflow before it happens
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution s;
    int x;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "Reversed: " << s.reverse(x) << endl;
    return 0;
}

