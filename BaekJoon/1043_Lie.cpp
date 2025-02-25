#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1043

// 틀린 코드입니다!!

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
    printf("\n-----\n");*/
}

void checkParty() {
    int party_count = m;
    for (int i = 0; i < party_people.size(); i++) {
        for (int num : truth) {
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

    for (int i = 0; i < m; i++) {
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
}