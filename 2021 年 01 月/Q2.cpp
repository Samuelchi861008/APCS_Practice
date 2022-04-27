/* 題目名稱：流量 */
/* 解題關鍵：必須瞭解城市之間資料傳輸關係並在計算的時候若超過 1000 則要特別處理，而且起點終點相同的傳輸流量需要相加再計算花費 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, m, k, MIN = LLONG_MAX;
	vector<vector<int> > Q;

    // 輸入 n m k
	cin >> n >> m >> k;

    // 根據 n m 建立 Q
	for(int i=0; i<n; i++) {
		vector<int> sub;
		for(int j=0; j<m; j++) {
			int flow;
			cin >> flow;
			sub.push_back(flow);
		}
		Q.push_back(sub);
	}

    // 輸入 k 種方案
	for(int i=0; i<k; i++) {
        // 花費
		int cost = 0;
        // 紀錄城市之間資料傳輸
		vector<vector<int> > cities(m, vector<int>(m, 0));
		for(int j=0; j<n; j++) {
			int c;
			cin >> c; // 輸入方案
            // 計算城市之間資料傳輸
			for(int l=0; l<m; l++) {
				cities[c][l] += Q[j][l];
			}
		}
        // 計算花費
		for(int u=0; u<m; u++) {
			for(int v=0; v<m; v++) {
				if(u == v) {
                    // 若 u 等於 v，每單位流量需要花 1 塊錢
					cost += cities[u][v];
				} else {
                    // 若 u 不等於 v，小於等於 1000 的流量每單位要 3 塊錢，大於 1000 的部份每單位 2 塊錢
					cost += (cities[u][v] <= 1000) ? (cities[u][v]*3) : (((cities[u][v]-1000)*2)+3000);
				}
			}
		}
        // 找最小花費
		MIN = min(MIN, cost);
	}

	cout << MIN << endl; // 輸出最小值

	return 0;
}