/* 題目名稱：秘密差 */
/* 解題關鍵：需特別注意輸入位數，並瞭解字串、字元、數字之間轉換關係，判斷奇偶數分別加總，最後輸出兩相減值 */

#include <iostream>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	string s;
	int A = 0, B = 0;

	cin >> s; // 由於輸入的值近 1000 位數，因此需使用字串處理

    	// 依序將每個字元位數拆開轉換成數字，並將奇偶數分別加總
	for(int i=0; i<s.length(); i++) {
		if(i%2) B += s[i] - '0';
		else A += s[i] - '0';
	}

    	// 輸出 A-B 之值，若為負數則改為正數
	cout << ((A - B < 0) ? ((A - B) * -1) : (A - B)) << endl;

	return 0;
}
