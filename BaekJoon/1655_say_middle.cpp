#include <iostream>
#include <queue>
#include <regex>
#include <vector>
using namespace std;

vector <int> num, middle;

priority_queue<int> maxHeapQueue;
priority_queue<int, vector<int>, greater<int>> minHeapQueue;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    double s = clock();

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (maxHeapQueue.empty()) {
            maxHeapQueue.push(a);
        }
        else if (maxHeapQueue.size() == minHeapQueue.size()) {
            maxHeapQueue.push(a);
        }
        else {
            minHeapQueue.push(a);
        }

        if (!maxHeapQueue.empty() && !minHeapQueue.empty() && (maxHeapQueue.top() > minHeapQueue.top())) {
            int swap1 = maxHeapQueue.top(), swap2 = minHeapQueue.top();

            maxHeapQueue.pop(), minHeapQueue.pop();

            maxHeapQueue.push(swap2), minHeapQueue.push(swap1);
        }

        cout << maxHeapQueue.top() << '\n';
    }

    double e = clock();

    // printf("%f\n",(e-s)/CLOCKS_PER_SEC );

    return 0;
}