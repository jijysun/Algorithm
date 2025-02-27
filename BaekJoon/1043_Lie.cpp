#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1043 // 완벽한 Union Find 문제.

int n, m, truth, number; // 사람 수, 파티 수, 진실 아는 사람, 입력용 번호 변수
int parent[51]; // Union Find 집합
vector<int> true_person; // 진실 아는 사람 벡터
vector<vector<int>> party_people(50);

int find_parents(int u) { // 부모를 찾는 함수, 경로 압축
    if (u == parent[u]) return u;
    return find_parents(parent[u]);
}

void merge(int u, int v) { // 노드 연결 함수. 합집합
    u = find_parents(u), v = find_parents(v);
    if (u == v) return;
    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> truth;

    for (int i = 0; i < truth; i++) { // 각 입력
        cin >> number;
        true_person.push_back(number);
    }

    for (int i = 1; i <= n; i++) { // 사람 수 만큼 부분집합 생성
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) { // 파티 수 만큼 반복
        cin >> number; // 해당 파티의 인원 수 입력
        int num, prev;

        for (int j = 0; j < number; j++) {
            if (j >= 1) { // 첫 원소 제외 모두는
                prev = num;
                cin >> num;
                merge(prev, num); // 모두 같은 집합에 속하게끔
            }
            else {
                cin >> num;
            }
            party_people[i].push_back(num);
        }
    }

    for (vector<int>& party : party_people) { // 파티 만큼 반복
        bool check = false;
        for (int& person : party) { // 파티 내 인원 만큼 반복
            if (check) {
                break;
            }
            for (int& t : true_person) { // 진실 아는 사람 만큼 반복
                if (find_parents(person) == find_parents(t)) { // 현 사람과 진실을 아는 사람의 부모가 같다면?
                    check = true; // 몰랐던 사람도 진실을 알게 되므로 BREAK;
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
// 틀린 코드
int n, m; // people, party

string true_person_size; // 진실을 알고 있는 사람 수

unordered_set<int> truth; // 진실을 알고 있는 사람, 중복 x

vector<string> party_num; // 각 파티 별 온 사람 번호

vector<vector<int> > party_people(51);

void addTruth() {
    for (int i = 0; i < m; i++) {
        // printf("%d 번 파티 검사: ", i+1);
        for (int j : truth) {
            if (count(party_people[i].begin(), party_people[i].end(), j)) { // 만약 포함 되어 있다면
                for (int k : party_people[i]) { // 나머지들 모두 set 에 저장 시키기
                    truth.insert(k);
                }
            }
        }
        // printf("\n");
    }
    /*printf("추가된 진실 인원: ");
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

    if (true_person_size[0] == '0') { // 0이면 모든 파티 방문 가능
        printf("%d\n", m);
        return 0;
    }

    for (int i = 1; i <= stoi(&true_person_size[0]); i++) {
        truth.insert(stoi(&true_person_size[i * 2]));
    }

    for (int i = 0; i < m; i++) { // 파티 수 만큼
        istringstream iss(party_num[i]); // 문자열 공백 단위로 파싱,
        string ps;

        iss >> ps; // 첫 번째는 파티에 있는 사람 수
        int party_size = stoi(ps);

        for (int j = 0; j < party_size; j++) { // 파티에 있는 사람의 번호 저장
            string s1;
            iss >> s1;
            party_people[i].push_back(stoi(s1));
        }
        sort(party_people[i].begin(), party_people[i].end());
    }

    // 추가가 안될 때 까지 돌리기?
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