/* 題目名稱：骰子 */
/* 解題關鍵：需知道如何進行交換，並且要知道骰子的每一面與其對面的那面相加必會是 7 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, m;
	vector<vector<int> > dices;

	cin >> n >> m; // 輸入 n m

    // 建立 n 顆骰子
	for(int i=0; i<n; i++) {
		vector<int> sub;
		sub.push_back(1); // 上方
		sub.push_back(4); // 前方
		sub.push_back(2); // 右方
		dices.push_back(sub);
	}

	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b; // 輸入 a b
		if(a > 0 && b > 0) {
            // 若 a, b 都是正整數，交換編號 a 與編號 b 的骰子的位置
			vector<int> temp = dices[a-1];
			dices[a-1] = dices[b-1];
			dices[b-1] = temp;
		} else if(b == -1) {
            // 若 b 為 −1，將編號 a 的骰子向前旋轉
			int temp = dices[a-1][1];
			dices[a-1][1] = dices[a-1][0];
			dices[a-1][0] = 7 - temp;
		} else if(b == -2) {
            // 若 b 為 −2，將編號 a 的骰子向右旋轉
			int temp = dices[a-1][2];
			dices[a-1][2] = dices[a-1][0];
			dices[a-1][0] = 7 - temp;
		}
	}

    // 輸出每顆骰子最上方的值
	for(int i=0; i<n; i++) {
		cout << dices[i][0] << ((i==n-1) ? "\n" : " ");
	}

	return 0;
}