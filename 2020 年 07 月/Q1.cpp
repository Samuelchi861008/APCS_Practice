/* 題目名稱：購物車 */
/* 解題關鍵：需知道警示值迴圈的運用 */

#include <iostream>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int a, b, n, p = 0;

	cin >> a >> b >> n; // 輸入 a b n

    // 輸入 n 行
	for(int i=0; i<n; i++) {
        // 持續輸入直到輸入值為 0
		int x, hasA = 0, hasB = 0;
		cin >> x;
		while(x) {
			if(x==a) hasA++;
			if(x==b) hasB++;
			if(x==(a*-1)) hasA--;
			if(x==(b*-1)) hasB--;
			cin >> x;
		}
        // 假設 a 與 b 同時都擁有的時候，人數加 1
		if(hasA > 0 && hasB > 0) p++;
	}

    // 輸出人數
	cout << p << endl;

	return 0;
}