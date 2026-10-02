# 프로그래머스, 충돌위험 찾기 (실패)

# 문제 소개

[문제 사이트 링크](https://school.programmers.co.kr/learn/courses/30/lessons/340211)

#### **문제 설명**

어떤 물류 센터는 로봇을 이용한 자동 운송 시스템을 운영합니다. 운송 시스템이 작동하는 규칙은 다음과 같습니다.

1. 물류 센터에는 (r, c)와 같이 2차원 좌표로 나타낼 수 있는 `n`개의 포인트가 존재합니다. 각 포인트는 1~`n`까지의 서로 다른 번호를 가집니다.
2. 로봇마다 정해진 운송 경로가 존재합니다. 운송 경로는 `m`개의 포인트로 구성되고 로봇은 첫 포인트에서 시작해 할당된 포인트를 순서대로 방문합니다.
3. 운송 시스템에 사용되는 로봇은 `x`대이고, 모든 로봇은 0초에 동시에 출발합니다. 로봇은 1초마다 r 좌표와 c 좌표 중 하나가 1만큼 감소하거나 증가한 좌표로 이동할 수 있습니다.
4. 다음 포인트로 이동할 때는 항상 최단 경로로 이동하며 최단 경로가 여러 가지일 경우, r 좌표가 변하는 이동을 c 좌표가 변하는 이동보다 먼저 합니다.
5. 마지막 포인트에 도착한 로봇은 운송을 마치고 물류 센터를 벗어납니다. 로봇이 물류 센터를 벗어나는 경로는 고려하지 않습니다.

**이동 중 같은 좌표에 로봇이 2대 이상 모인다면 충돌할 가능성이 있는 위험 상황으로 판단합니다.** 관리자인 당신은 현재 설정대로 로봇이 움직일 때 위험한 상황이 총 몇 번 일어나는지 알고 싶습니다. 만약 어떤 시간에 여러 좌표에서 위험 상황이 발생한다면 그 횟수를 모두 더합니다.

운송 포인트 `n`개의 좌표를 담은 2차원 정수 배열 `points`와 로봇 `x`대의 운송 경로를 담은 2차원 정수 배열 `routes`가 매개변수로 주어집니다. 이때 모든 로봇이 운송을 마칠 때까지 발생하는 위험한 상황의 횟수를 return 하도록 solution 함수를 완성해 주세요.

---

#### 제한사항

- 2 ≤ `points`의 길이 = `n` ≤ 100
    - `points[i]`는 `i + 1`번 포인트의 [`r 좌표`, `c 좌표`]를 나타내는 길이가 2인 정수 배열입니다.
    - 1 ≤ `r` ≤ 100
    - 1 ≤ `c` ≤ 100
    - 같은 좌표에 여러 포인트가 존재하는 입력은 주어지지 않습니다.
- 2 ≤ `routes`의 길이 = 로봇의 수 = `x` ≤ 100
    - 2 ≤ `routes[i]`의 길이 = `m` ≤ 100
    - `routes[i]`는 `i + 1`번째 로봇의 운송경로를 나타냅니다. `routes[i]`의 길이는 모두 같습니다.
    - `routes[i][j]`는 `i + 1`번째 로봇이 `j + 1`번째로 방문하는 포인트 번호를 나타냅니다.
    - 같은 포인트를 연속으로 방문하는 입력은 주어지지 않습니다.
    - 1 ≤ `routes[i][j]` ≤ `n`

---

#### 입출력 예

| points | routes | result |
| --- | --- | --- |
| [[3, 2], [6, 4], [4, 7], [1, 4]] | [[4, 2], [1, 3], [2, 4]] | 1 |
| [[3, 2], [6, 4], [4, 7], [1, 4]] | [[4, 2], [1, 3], [4, 2], [4, 3]] | 9 |
| [[2, 2], [2, 3], [2, 7], [6, 6], [5, 2]] | [[2, 3, 4, 5], [1, 3, 4, 5]] | 0 |

---

#### 입출력 예 설명

**입출력 예 #1**

![충돌위험1.gif](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/43dea513-36b0-493b-bb52-ac5d9dc49bf4/%E1%84%8E%E1%85%AE%E1%86%BC%E1%84%83%E1%85%A9%E1%86%AF%E1%84%8B%E1%85%B1%E1%84%92%E1%85%A5%E1%86%B71.gif)

그림처럼 로봇들이 움직입니다. 3초가 지났을 때 1번 로봇과 2번 로봇이 (4, 4)에서 충돌할 위험이 있습니다. 따라서 1을 return 해야 합니다.

**입출력 예 #2**

![충돌위험2.gif](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/b1b127d3-679b-4d54-ac3f-1e3131e7a6fa/%E1%84%8E%E1%85%AE%E1%86%BC%E1%84%83%E1%85%A9%E1%86%AF%E1%84%8B%E1%85%B1%E1%84%92%E1%85%A5%E1%86%B72.gif)

그림처럼 로봇들이 움직입니다. 1, 3, 4번 로봇의 경로가 같아 이동하는 0 ~ 2초 내내 충돌 위험이 존재합니다. 3초에는 1, 2, 3, 4번 로봇이 모두 (4, 4)를 지나지만 위험 상황은 한 번만 발생합니다.

4 ~ 5초에는 1, 3번과 2, 4번 로봇의 경로가 각각 같아 위험 상황이 매 초 2번씩 발생합니다. 6초에 2, 4번 로봇의 충돌 위험이 발생합니다. 따라서 9를 return 해야 합니다.

**입출력 예 #3**

![충돌위험3.gif](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/eb0fe259-fe92-44fc-bddb-c55afac4e12f/%E1%84%8E%E1%85%AE%E1%86%BC%E1%84%83%E1%85%A9%E1%86%AF%E1%84%8B%E1%85%B1%E1%84%92%E1%85%A5%E1%86%B73.gif)

그림처럼 로봇들이 움직입니다. 두 로봇의 경로는 같지만 한 칸 간격으로 움직이고 2번 로봇이 5번 포인트에 도착할 때 1번 로봇은 운송을 완료하고 센터를 벗어나 충돌 위험이 없습니다. 따라서 0을 return 해야 합니다.

---

# 풀이 과정

- 문제 이해에 약 15분을 소요했다.
- 로봇이 2차원 좌표에서 시간 단위로 이동하고, 같은 시간·위치에 2대 이상이 겹치면 위험 상황으로 카운트한다는 것은 파악했다.
- 접근 방식: ‘시뮬레이션 방식’
    - 초기 위치 확인 후, 1초마다 로봇을 이동시키고 충돌을 체크하는 while 루프를 구성했다.
    - r 이동 → c 이동 순서의 최단 경로 이동 로직은 구현했다.
    - 충돌 체크는 visited 배열로 같은 좌표의 중복 카운트를 막으려 했다.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[101][101] = {0};
int visited[101][101] = {0};
vector<vector<int>> new_route;

// 3분 시작
vector<pair<int, int>> robot;
int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;

    // 2차원 좌표, 1~n개의 포인트.
    // 운송 경로: m개의 포인트, 시작~순서대로 방문
    // 운송 시스템 로봇 x개. 0초 출발 -> 1초마다 r, c 좌표가 1감소하거나 증가
    // 다음 포인트로 이동:항상 최단 경로 이동. 여러 최단 경로 일 경우, r 변화 -> c 변화 순
    // 이렇게 같은 좌표에 2대 이상 로봇이 모임 = 충돌! 위험 상황 과연 이게 몇번 일어날까???????

    // 할당 포인트 p1 -> p2

    for (int i = 0; i < points.size(); i++)
    {
        int r = points[i][0];
        int c = points[i][1];
        arr[r][c] = i + 1; // 포인트 찍기
    }

    for (int i = 0; i < routes.size(); i++)
    {
        robot.push_back({points[routes[i][0] - 1][0], points[routes[i][0] - 1][1]});
    }
    // 맨처음부터도 검사 해야 함!

    for (int i = 0; i < robot.size(); i++)
    {
        cout << robot[i].first << " " << robot[i].second << endl;
    }
    for (int i = 0; i < robot.size(); i++)
    {
        // 그냥 다른 로봇이랑 비교?
        for (int j = 0; j < robot.size(); j++)
        {
            if (j == i)
            {
                continue;
            }
            if (robot[i].first == robot[j].first && robot[i].second == robot[j].second && visited[robot[i].first][
                robot[i].second] == 0)
            {
                // 이미 체크된 곳이라면 스킵?

                cout << robot[i].first << " " << robot[i].second << endl;
                visited[robot[i].first][robot[i].second] = 1;
                answer++;
                break;
            }
        }
    }
    cout << "처음 부터 겹친 거: " << answer << endl;
    cout << "----------" << '\n';

    while (true)
    {
        // 로봇 개수는 최대 100개.
        // 매번 할당 및 운송 마친 로봇은 not push_back

        // 먼저 경로 이동 -> r 이후 c 이동,
        vector<pair<int, int>> new_robot;
        int check = 0; // 로봇이 운송 포인트 도달했는지, routes.size() 만큼 되면 다 도착한 거.
        for (int i = 0; i < robot.size(); i++)
        {
            int des_r = points[routes[i][1] - 1][0];
            int des_c = points[routes[i][1] - 1][1];

            // 이동하는 경우, 이전 좌표 0 표시, 현 좌표를 로봇 번호로 표시?
            if (robot[i].first < des_r)
            {
                robot[i].first++;
                new_robot.push_back({robot[i].first, robot[i].second});
            }
            else if (robot[i].first > des_r)
            {
                robot[i].first--;
                new_robot.push_back({robot[i].first, robot[i].second});
            }
            else if (robot[i].second < des_c)
            {
                // r좌표는 같은 경우
                robot[i].second++;
                new_robot.push_back({robot[i].first, robot[i].second});
            }
            else if (robot[i].second > des_c)
            {
                robot[i].second--;
                new_robot.push_back({robot[i].first, robot[i].second});
            }
            else if (robot[i].first == des_r && robot[i].second == des_c)
            {
                check++;
                // 이 로봇은 겹친 거에 빼야 함.

            }
        }

        // 다시 로봇 검사, 위험 상황 판단. 한 곳에 2대 이상 몰릴 수 있음. 한 상황에 2번 이상의 위험 상황 발생 가능.
        // 여러 위험 상황 처리는 어떻게? -> 그냥 곂치기만 하면 무조건 counting
        for (int i = 0; i < robot.size(); i++)
        {
            // 그냥 다른 로봇이랑 비교?
            for (int j = 0; j < robot.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (robot[i].first == robot[j].first && robot[i].second == robot[j].second && visited[robot[i].first][
                    robot[i].second] == 0)
                {
                    // 이미 체크된 곳이라면 스킵?

                    cout << robot[i].first << " " << robot[i].second << endl;
                    visited[robot[i].first][robot[i].second] = 1;
                    answer++;
                    break;
                }
            }
        }
        robot = new_robot;

        if (check == routes.size() || robot.size() == 0)
        {
            // 모든 운송이 완료되면?
            break;
        }
    }

    return answer;
}

int main()
{
    pair<int, int> p1 = {1, 2};
    p1.first = 5;
    p1.second = 6;
    return 0;
}

```

---

# 결과 & 근거

- 실패 (포기)
    - `routes[i][1]`만을 목적지로 사용했다. 로봇이 여러 경유지를 순차적으로 방문해야 한다는 점을 코드에 반영하지 못했다.
    - visited 배열로 같은 좌표에서의 충돌을 중복 차단했다. 같은 좌표라도 다른 시간에 발생한 충돌은 별도로 카운트해야 한다.
- 다중 경유지(`routes[i]` 전체 순회) 처리 누락으로 설계 자체가 틀렸다.
    - visited 기반 충돌 감지 방식도 시간 차원의 충돌을 잘못 차단했다.
- 정석 풀이는 각 로봇의 시간별 위치를 사전에 전부 계산한 뒤, 시간 단위로 충돌 여부를 체크하는 방식이다.
- 시뮬레이션과 충돌 감지를 분리하면 코드가 훨씬 단순해진다.

### 알고리즘 분류

- 시뮬레이션, 구현