/* 題目名稱：人力分配 */
/* 解題關鍵：用迴圈將值進行拆解並依序計算 */

#include <iostream>
#include <climits>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int A1, A2, B1, B2, C1, C2, n, MAX = LLONG_MIN;

    	// 根據題意依序輸入所有值
	cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2 >> n;

    	// 將 n 進行拆解，依序用迴圈計算並比較最大值
	for(int i=0; i<=n; i++) {
		int y1 = (A1 * (i * i)) + (B1 * i) + C1;
		int y2 = (A2 * ((n-i) * (n-i))) + (B2 * (n-i)) + C2;
		MAX = max(MAX, (y1 + y2));
	}

	cout << MAX << endl; // 輸出最大值

	return 0;
}
