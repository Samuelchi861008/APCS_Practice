/* 題目名稱：成績指標 */
/* 解題關鍵：依序輸入成績後，進行排序，並找到最高不及格與最低及格 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n;
	vector<int> classroom, notPass, pass;

	cin >> n; // 輸入學生人數

	// 根據學生人數依序輸入成績
	for(int i=0; i<n; i++) {
		int score;
		cin >> score;
		classroom.push_back(score);
	}

	// 將分數進行排序
	sort(classroom.begin(), classroom.end());

	// 將排序後的成績依序輸出，同時將及格與不及格做區分
	for(int i=0; i<classroom.size(); i++) {
		cout << classroom[i] << ((i==classroom.size()-1)? "\n" : " ");
		if(classroom[i] >= 60) pass.push_back(classroom[i]);
		else notPass.push_back(classroom[i]);
	}

	// 判斷是否有不及格的人，若有則輸出最高不及格者，若無則輸出 best case
	if(notPass.size()) cout << notPass[notPass.size()-1] << endl;
	else cout << "best case" << endl;

	// 判斷是否有及格的人，若有則輸出最低及格者，若無則輸出 worst case
	if(pass.size()) cout << pass[0] << endl;
	else cout << "worst case" << endl;

	return 0;
}