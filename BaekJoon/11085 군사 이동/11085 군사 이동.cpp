#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int p, w, c, v;
int parent[1001];

class Tree {
public :
    int x, y, width;

public:
    bool operator <( const Tree t) const {
        return this->width > t.width; // 내림차순 정렬
    }
};

vector<Tree> tree_info;


int find(int child) {
    return parent[child] == child ? child : find(parent[child]); // 삼항 연산자
}

void union_group(int x, int y) {
    int x_parent = find(x), y_parent = find(y);
    if (x_parent != y_parent) {
        parent[x_parent] = y_parent;
    }
}

int main() {
    for (int i = 0; i < 1001; i++) {
        parent[i] = i; // kruskal Algorithm! 부모 = 자신을 통해, 어느 그룹, 집합에도 속하지 않게.
    }

    cin >> p >> w;
    cin >> c >> v;

    int p1, p2, width;
    for (int i = 0; i < w; i++) {
        cin >> p1 >> p2 >> width;
        tree_info.push_back({p1, p2, width});
    }
    sort(tree_info.begin(), tree_info.end());

    for (int i = 0; i < tree_info.size(); i++) {
        Tree t = tree_info[i];

        if (find(t.x) != find(t.y)) { // 부모가 다른 경우, 같은 그룹이 아닌 경우 union!
            union_group(t.x, t.y);
        }
        if (find(c) == find (v)) { // 사이클 검사
            cout << t.width << '\n';
            break;
        }
    }
    return 0;
}