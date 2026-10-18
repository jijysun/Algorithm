# SWEA 20019, 회문의 회문 (성공?)

# 문제 소개

[문제 사이트 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&problemLevel=4&problemLevel=5&contestProbId=AY2hjCWKbykDFATh&categoryId=AY2hjCWKbykDFATh&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=5&pageSize=10&pageIndex=7)

어떤 문자열 S가 회문(palindrome)이라는 것은, 이 문자열을 앞에서부터 뒤로 읽은 것과 뒤에서부터 앞으로 읽은 것이 동일하다는 것을 의미한다. 예를 들어 “samsung”, “hello”는 회문이 아니지만, “abcba”, “asdffdsa”는 회문이다.

길이가 홀수 N인 어떤 문자열 S가 회문의 회문이라는 것은, 이 문자열이 아래 조건을 만족한다는 것을 의미한다.

- S는 회문이다.
- S의 처음 (N-1)/2글자가 회문이다.
- S의 마지막 (N-1)/2글자가 회문이다.
- 주어진 문자열이 회문의 회문인지 판별하는 프로그램을 작성하라.

**입력**

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스는 한 개의 줄로 이루어진다. 각 줄에는 길이가 3 이상 99 이하인, 알파벳 소문자(a-z)로만 이루어진 문자열 S가 주어진다.

**출력**

각 테스트 케이스마다, S가 회문의 회문이면 YES를, 그렇지 않다면 NO를 출력한다.

---

# 풀이 과정

- 처음에 **"문자열 내부의 모든 부분문자열이 회문이어야 한다"** 고 과하게 해석해서 시간을 날렸다. 지문의
    - 조건은 그게 아니라 **전체 + 앞 절반 + 뒤 절반** 세 구간뿐이다.
- 회문 판정은 재귀로 작성. `s[0] == s[n-1]` 이면 양 끝을 떼고 가운데를 재귀.
    - 종료 조건은 `length() <= 1`.
- 자르기를 `substr` 로 하려니 `(pos, count)` 의 count 가 **끝 인덱스가 아니라 길이**라 계속 헷갈렸다.
    - 결국 뺄셈 연산으로 전환.

```cpp

bool pel (string s) {

	// cout << s  << ", " << s[0] << ", " << s[s.length()-1]  << ", "<< s.length()<< '\n';
	if (s.length() <= 1) {
		return true;
	}

	if (s[0] == s[s.length() - 1]) {
		return pel(s.substr(1, s.size()-2));
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	// vec.assign(T, "");

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;
		// vec[test_case-1] = s;

		// 함수를 그냥 병합 정렬 하듯이 하면 되는 거 아닌가?
		// cout << pel(s) << endl;

		 // 5 -> 0~2, 2~4 (5/2 = 2)-> 0~1, 1~2 , 2~3, 2~4 (2/2 = 1)
		bool flag = false;

		bool b1 = pel(s);
		bool b2 = pel(s.substr(0, s.length()/2));
		bool b3 = pel(s.substr(s.length()/2+1, s.length()-1));

		// cout << b1 << " " << b2 << " " << b3 << endl;
		/*for (int i = s.length()-1; i >0; i=i/2) {
			// i=5 -> pel(0,4)
			// i=2 -> pel(0,2), (2,4)
			// i=1 -> pel(0,1), (1,2), (2,3), (3,4)

			if (flag) break;

			for (int j = 0; j<s.length()-1; j+=i) {

				cout << j << " " << j+i << endl;
				if (flag) {
					break;
				}
				if (pel(s.substr(j, i+1)) == false) {
					flag = true;
				}
			}
		}*/

		if (b1 == true && b2 == true && b3 == true) {
			flag = false;
		}
		else {
			flag = true;
		}

		if (flag) cout << "#" << test_case << " NO" << '\n' ;
		else cout << "#" << test_case << " YES" << '\n' ;

	}

	/*
	 * 회문의 회문
	 * - S = 회문
	 * - S의 처음 (N-1)/2 글자가 회문 + S의 마지막 (N-1)/2글자가 회문
	 *
	 * 6분 pel 기본 함수 동작 확인 완료.
	 * 15분 구현 완료 -> 인덱싱 오류로 수정중 (pel 함수의 return pel(s.substr(1, s.length() - 2)); 가 잘못되었음)
	 */
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```

---

# 결과 & 근거

- 고쳐야 하는 점 : 앞/뒤 절반의 길이가 짝수 길이에서 다르다.
- 

```cpp
#include <iostream>
#include <string>
using namespace std;

/*
 * 1. 제한
 * - S.size() <= 99, 소문자만
 * 2. 연산량 = T x O(n) = 매우 작음. 통과 O
 * 3. 조건 (지문) : S 가 회문  AND  S 의 처음 h 글자가 회문  AND  마지막 h 글자가 회문
 *                 (h = (n-1)/2)
 * 4. 예제 손검증 : O
 * 5. 코드 친 후 대조 : n 홀수 1개 + 짝수 1개로 범위 확인  <-- 반드시
 */

/* 투 포인터 회문 판정.
   문자열을 자르지 않고 "검사할 구간 [l, r]" 만 넘긴다.
   -> substr 의 (pos, count) 혼동이 구조적으로 발생하지 않는다.
   -> 문자열 복사가 없어 O(n). substr 재귀는 매번 새 string 을 만들어 O(n^2) 다.  */
bool isPal(const string& s, int l, int r) {
    while (l < r) {                  // 양 끝에서 안쪽으로 좁힌다
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;                     // l >= r 이면 가운데 도달 = 회문
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string s; cin >> s;
        int n = s.size();
        int h = (n - 1) / 2;         // ★ 지문에 적힌 길이를 변수 하나로 고정한다
                                     //   이렇게 해두면 앞/뒤를 "같은 h" 로 쓸 수밖에 없어
                                     //   짝수 길이에서 비대칭이 생길 여지가 없다

        bool ok = isPal(s, 0, n - 1);                        // 전체가 회문인가
        if (ok && h > 0) ok = isPal(s, 0, h - 1);            // 앞에서 h 글자  [0, h-1]
        if (ok && h > 0) ok = isPal(s, n - h, n - 1);        // 뒤에서 h 글자  [n-h, n-1]
                                     //   ↑ 전체가 회문이면 이 검사는 위 검사와 동치라
                                     //     수학적으로 중복이지만, O(n) 이고 보험이 된다

        cout << "#" << tc << " " << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
```

### 알고리즘 분류

- 문자열
- 투 포인터
- 재귀 / 분할 정복