/* 題目名稱：七言對聯 */
/* 解題關鍵：需清楚瞭解題目規定七言對聯的三個限制 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

// 判斷是否違反規則 A
int A(vector<int> s1, vector<int> s2)
{
    // 規則 A : 二四不同二六同 (每一句第二、四個字必須不同平仄，而第二、六個字必須相同平仄)
	if(((s1[1] != s1[3]) && (s1[1] == s1[5])) && ((s2[1] != s2[3]) && (s2[1] == s2[5]))) {
		return 0;
	} else {
		return 1;
	}
}

// 判斷是否違反規則 B
int B(vector<int> s1, vector<int> s2)
{
    // 規則 B : 仄起平收 (第一句的結尾必須為仄聲，第二句的結尾必須為平聲)
	if((s1[6] == 1) && (s2[6] == 0)) {
		return 0;
	} else {
		return 1;
	}
}

// 判斷是否違反規則 C
int C(vector<int> s1, vector<int> s2)
{
    // 規則 C : 上下相對 (第一、二句的第二、四、六個字平仄必須不同)
	if(((s1[1] != s2[1]) && (s1[3] != s2[3]) && (s1[5] != s2[5]))) {
		return 0;
	} else {
		return 1;
	}
}

// 判斷是否皆符合規定
int ALL(vector<int> s1, vector<int> s2)
{
	if(((A(s1, s2) == 0) && (B(s1, s2) == 0) && (C(s1, s2) == 0))) {
		return 1;
	} else {
		return 0;
	}
}

signed main()
{
	int n;

	cin >> n; // 輸入 n

	for(int i=0; i<n; i++) {
		vector<int> s1, s2;
        // 輸入第一句對聯
		for(int j=0; j<7; j++) {
			int word;
			cin >> word;
			s1.push_back(word);
		}
        // 輸入第二句對聯
		for(int j=0; j<7; j++) {
			int word;
			cin >> word;
			s2.push_back(word);
		}
        // 若違反規則 A
		if(A(s1, s2)) cout << "A";
        // 若違反規則 A
		if(B(s1, s2)) cout << "B";
        // 若違反規則 A
		if(C(s1, s2)) cout << "C";
        // 若三個規則都遵守
		if(ALL(s1, s2)) cout << "None";

		cout << endl;
	}

	return 0;
}