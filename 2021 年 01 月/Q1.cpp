/* 題目名稱：購買力 */
/* 解題關鍵：找最大最小值以及計算平均 */

#include <iostream>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, d, numOfProduct = 0, total = 0;

	cin >> n >> d; // 輸入 n d

	for(int i=0; i<n; i++) {
		int day1, day2, day3;

        	// 輸入 3 天的價格
		cin >> day1 >> day2 >> day3;

        	// 找出三天價格的最高與最低值
		int MAX = max(day1, max(day2, day3)); 
		int MIN = min(day1, min(day2, day3));

        	// 判斷最高與最低差異是否至少大於 d
		if(MAX - MIN >= d) {
            		// 計算 3 天的價格的平均值
			total += (day1 + day2 + day3) / 3;
            		// 商品數量加 1
			numOfProduct++;
		}
	}

    // 輸出商品數量以及總共的花費
	cout << numOfProduct << " " << total << endl;

	return 0;
}
