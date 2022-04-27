/* 題目名稱：程式交易 */
/* 解題關鍵：第一個價格固定為買進，並要紀錄目前為買進與賣出的狀態 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, D, total = 0;
	vector<int> a;

	cin >> n >> D; // 輸入 n D

    // 輸入歷史價格
	for(int i=0; i<n; i++) {
		int price;
		cin >> price;
		a.push_back(price);
	}

    // 根據題意，第一個價格買進股票
	int currentPrice = a[0], haveStock = 1;
	for(int i=1; i<n; i++) {
		if(haveStock == 1) {
            // 若當下持有股票
			if(a[i] >= currentPrice + D) {
                // 轉得利潤
				total += a[i] - currentPrice;
				currentPrice = a[i];
				haveStock = 0; // 賣出股票
			}
		} else {
            // 若當下沒有持有股票
			if(a[i] <= currentPrice - D) {
				currentPrice = a[i];
				haveStock = 1; // 買進股票
			}
		}
	}

    // 輸出總利潤
	cout << total << endl;

	return 0;
}