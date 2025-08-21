#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class City {
public:
    long long cur;
    long long next;
    long long cost;
};

bool compare(City c1, City c2) {
    return c1.cost < c2.cost;
}

long long parent [100001];
vector<City> arr, kruskal_arr;

long long find_parent (long long child) {
    if (parent[child] == child)
        return child;

    return parent[child] = find_parent(parent[child]);
}

void union_child(long long c1, long long c2){
    c1 = find_parent(c1), c2 = find_parent(c2);

    if (c1 != c2)
        parent[c2] = c1;
}

long long n, m, total, kruskal;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        City c = City();
        cin >> c.cur >> c.next >> c.cost;
        arr.push_back(c), total += c.cost;
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 1; i<= n; i++)
        parent[i] = i;

    for (City c : arr) {
        if (find_parent(c.cur) != find_parent(c.next)) {
            union_child(c.cur, c.next);
            kruskal+=c.cost;
            kruskal_arr.push_back(c);
        }
    }

    if (kruskal_arr.size() == n-1) {
        cout << total - kruskal << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
