/* 題目名稱：數字遊戲 */
/* 解題關鍵：找出眾數之個數，並將數字列出不重複倒序 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int MAX = INT_MIN;
	vector<int> count(10, 0), record;

	// 根據題意，輸入三數並統計後紀錄在 count 中
	for(int i=0; i<3; i++) {
		int num;
		cin >> num;
		count[num]++;
	}

	// 找出個數最多數的個數
	for(int i=0; i<count.size(); i++) {
		MAX = max(MAX, count[i]);
	}

	// 將有被紀錄的數字放入 record 中
	for(int i=0; i<count.size(); i++) {
		if(count[i] != 0) record.push_back(i);
	}

	// 倒序
	sort(record.rbegin(), record.rend());

	cout << MAX << " "; // 輸入個數最多數的個數

	// 依序輸出 record 中的值
	for(int i=0; i<record.size(); i++) {
		cout << record[i] << ((i==record.size()-1)?"\n":" ");
	}

	return 0;
}