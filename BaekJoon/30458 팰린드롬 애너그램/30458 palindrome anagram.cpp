#include <iostream>
#include <map>

using namespace std;

int n;
char palindrome [200001];
map<char, int> alpha;

int main() {

    cin >> n;

    for (int i = 0; i<n; i++) {
        cin >> palindrome[i];
        if (n%2 == 1 && i == n/2) {
            continue;
        }
        alpha[palindrome[i]] ++;
    }

    for (auto itr : alpha) {
        if (itr.second %2 != 0) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
    return 0;
}