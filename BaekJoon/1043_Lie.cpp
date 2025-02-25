#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1043

// Ʋ�� �ڵ��Դϴ�!!

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
}