#include <iostream>
#include <string>

using namespace std;

bool isUglyNumber(int s, int n) {
    string str = to_string(s);

    if ((int)str.size() != n)
        return false;

    for (char c : str) {
        int digit = c - '0';

        if (digit == 0) return false;
        
        if (s % digit == 0) return false;
    }

    return true;
}

int main() {
    int numberOfTests;
    cin >> numberOfTests;

    for (int i = 0; i < numberOfTests; i++) {
        int n;
        cin >> n;

        int sStart = 1;
        for (int j = 1; j < n; j++) {
            sStart *= 10;
        }

        int sFinal = sStart * 10 - 1;
        bool found = false;

        for (int s = sStart; s <= sFinal; ++s) {
            if (isUglyNumber(s, n)) {
                cout << s << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
