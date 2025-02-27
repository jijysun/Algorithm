#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1043 // �Ϻ��� Union Find ����.

int n, m, truth, number; // ��� ��, ��Ƽ ��, ���� �ƴ� ���, �Է¿� ��ȣ ����
int parent[51]; // Union Find ����
vector<int> true_person; // ���� �ƴ� ��� ����
vector<vector<int>> party_people(50);

int find_parents(int u) { // �θ� ã�� �Լ�, ��� ����
    if (u == parent[u]) return u;
    return find_parents(parent[u]);
}

void merge(int u, int v) { // ��� ���� �Լ�. ������
    u = find_parents(u), v = find_parents(v);
    if (u == v) return;
    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> truth;

    for (int i = 0; i < truth; i++) { // �� �Է�
        cin >> number;
        true_person.push_back(number);
    }

    for (int i = 1; i <= n; i++) { // ��� �� ��ŭ �κ����� ����
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) { // ��Ƽ �� ��ŭ �ݺ�
        cin >> number; // �ش� ��Ƽ�� �ο� �� �Է�
        int num, prev;

        for (int j = 0; j < number; j++) {
            if (j >= 1) { // ù ���� ���� ��δ�
                prev = num;
                cin >> num;
                merge(prev, num); // ��� ���� ���տ� ���ϰԲ�
            }
            else {
                cin >> num;
            }
            party_people[i].push_back(num);
        }
    }

    for (vector<int>& party : party_people) { // ��Ƽ ��ŭ �ݺ�
        bool check = false;
        for (int& person : party) { // ��Ƽ �� �ο� ��ŭ �ݺ�
            if (check) {
                break;
            }
            for (int& t : true_person) { // ���� �ƴ� ��� ��ŭ �ݺ�
                if (find_parents(person) == find_parents(t)) { // �� ����� ������ �ƴ� ����� �θ� ���ٸ�?
                    check = true; // ������ ����� ������ �˰� �ǹǷ� BREAK;
                    break;
                }
            }
        }
        if (check) {
            m--;
        }
    }
    printf("%d\n", m);
    return 0;
}

/*
 *
// Ʋ�� �ڵ�
int n, m; // people, party

string true_person_size; // ������ �˰� �ִ� ��� ��

unordered_set<int> truth; // ������ �˰� �ִ� ���, �ߺ� x

vector<string> party_num; // �� ��Ƽ �� �� ��� ��ȣ

vector<vector<int> > party_people(51);

void addTruth() {
    for (int i = 0; i < m; i++) {
        // printf("%d �� ��Ƽ �˻�: ", i+1);
        for (int j : truth) {
            if (count(party_people[i].begin(), party_people[i].end(), j)) { // ���� ���� �Ǿ� �ִٸ�
                for (int k : party_people[i]) { // �������� ��� set �� ���� ��Ű��
                    truth.insert(k);
                }
            }
        }
        // printf("\n");
    }
    /*printf("�߰��� ���� �ο�: ");
    for (int i : truth) {
        printf("%d ", i);
    }
    printf("\n-----\n");#1#
}

void checkParty() {
    int party_count = m;
    for (int i = 0; i < party_people.size(); i++) {
        for (int num: truth) {
            if (find(party_people[i].begin(), party_people[i].end(), num) != party_people[i].end()) {
                // printf("cant go to %d party\n", i+1);
                party_count--;
                break;
            }
        }
    }
    printf("%d\n", party_count);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    cin.ignore();

    getline(cin, true_person_size);

    for (int i = 0; i<m; i++) {
        string s;
        getline(cin, s);
        party_num.push_back(s);
    }

    if (true_person_size[0] == '0') { // 0�̸� ��� ��Ƽ �湮 ����
        printf("%d\n", m);
        return 0;
    }

    for (int i = 1; i <= stoi(&true_person_size[0]); i++) {
        truth.insert(stoi(&true_person_size[i * 2]));
    }

    for (int i = 0; i < m; i++) { // ��Ƽ �� ��ŭ
        istringstream iss(party_num[i]); // ���ڿ� ���� ������ �Ľ�,
        string ps;

        iss >> ps; // ù ��°�� ��Ƽ�� �ִ� ��� ��
        int party_size = stoi(ps);

        for (int j = 0; j < party_size; j++) { // ��Ƽ�� �ִ� ����� ��ȣ ����
            string s1;
            iss >> s1;
            party_people[i].push_back(stoi(s1));
        }
        sort(party_people[i].begin(), party_people[i].end());
    }

    // �߰��� �ȵ� �� ���� ������?
    while (true) {
        int pre_size = truth.size();
        addTruth();
        if (pre_size == truth.size()) {
            break;
        }
    }

    checkParty();

    return 0;
}*/