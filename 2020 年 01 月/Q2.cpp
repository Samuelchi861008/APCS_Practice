/* 題目名稱：矩陣總和 */
/* 解題關鍵：需要了解兩個矩陣疊加在一起如何去掃描子矩陣，並且知道如何比較最小值 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int s, t, n, m, r, numOfDiff = 0, MIN = LLONG_MAX;
	vector<vector<int> > A, B;

	cin >> s >> t >> n >> m >> r; // 根據題意輸入 s t n m r

    // 依照 s t 建立矩陣 A 之內容
	for(int i=0; i<s; i++) {
		vector<int> sub;
		for(int j=0; j<t; j++) {
			int num;
			cin >> num;
			sub.push_back(num);
		}
		A.push_back(sub);
	}

    // 依照 n m 建立矩陣 B 之內容
	for(int i=0; i<n; i++) {
		vector<int> sub;
		for(int j=0; j<m; j++) {
			int num;
			cin >> num;
			sub.push_back(num);
		}
		B.push_back(sub);
	}

    // 將兩個矩陣疊起來，並整個掃一遍
	for(int i=0; i<=n-s; i++) {
		for(int j=0; j<=m-t; j++) {
			int diff = 0, totalOfA = 0, totalOfB = 0;
			for(int k=0; k<s; k++) {
				for(int l=0; l<t; l++) {
                    // 計算子矩陣有多少值與矩陣A不一樣，同時將矩陣A與子矩陣加總
					if(B[i+k][j+l] != A[k][l]) diff++;
					totalOfA += A[k][l];
					totalOfB += B[i+k][j+l];
				}
			}
            // 若子矩陣與矩陣A距離不超過 r 則計算兩相減後並比較最小值，並且計算有多少子矩陣
			if(diff <= r) {
				int total = (totalOfA - totalOfB < 0) ? ((totalOfA - totalOfB) * -1) : (totalOfA - totalOfB);
				MIN = min(MIN, total);
				numOfDiff++;
			}
		}
	}

    // 最後輸出符合條件的子矩陣個數與最小值
	cout << numOfDiff << "\n" << ((MIN==LLONG_MAX) ? -1 : MIN) << endl;

	return 0;
}