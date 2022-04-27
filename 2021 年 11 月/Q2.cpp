/* 題目名稱：動線安排 */
/* 解題關鍵：加入和移除木樁皆需上下左右走訪，而移除木樁還需要考慮不同方向同時連線而交會的狀況，不可直接拆線 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int m, n, h, total, MAX = LLONG_MIN;

	cin >> m >> n >> h; // 輸入 m n h

    // 根據 m n 建立空場地
	vector<vector<int> > ground(m, vector<int>(n, 0));

    // h 次的操作
	for(int i=0; i<h; i++) {
		int r, c, t;

		cin >> r >> c >> t; // 輸入 r c t

		if(t == 0) {
            // 如果 t 是 0 為加入木樁
			ground[r][c] = -1; // 在場地中以 -1 表示木樁
			if(r-1 > 0) {
                // 只要該木樁不在上邊界，則往上尋找是否有木樁
				for(int j=r-1; j>=0; j--) {
					if(ground[j][c] == -1) {
                        // 若找到有木樁，將兩木樁中間都加 1
						for(int k=r-1; k>j; k--) {
							ground[k][c]++;
						}
						break;
					}
				}
			}
			if(r+1 < m-1) {
                // 只要該木樁不在下邊界，則往下尋找是否有木樁
				for(int j=r+1; j<m; j++) {
					if(ground[j][c] == -1) {
                        // 若找到有木樁，將兩木樁中間都加 1
						for(int k=r+1; k<j; k++) {
							ground[k][c]++;
						}
						break;
					}
				}
			}
			if(c-1 > 0) {
                // 只要該木樁不在左邊界，則往左尋找是否有木樁
				for(int j=c-1; j>=0; j--) {
					if(ground[r][j] == -1) {
                        // 若找到有木樁，將兩木樁中間都加 1
						for(int k=c-1; k>j; k--) {
							ground[r][k]++;
						}
						break;
					}
				}
			}
			if(c+1 < n-1) {
                // 只要該木樁不在右邊界，則往右尋找是否有木樁
				for(int j=c+1; j<n; j++) {
					if(ground[r][j] == -1) {
                        // 若找到有木樁，將兩木樁中間都加 1
						for(int k=c+1; k<j; k++) {
							ground[r][k]++;
						}
						break;
					}
				}
			}
		} else {
            // 如果 t 是 1 為移除木樁
			ground[r][c] = 0; // 木樁位置改為 0
			if(r-1 > 0) {
                // 只要該木樁不在上邊界，則往上尋找是否有木樁
				for(int j=r-1; j>=0; j--) {
					if(ground[j][c] == -1) {
						for(int k=r-1; k>j; k--) {
                            // 若找到有木樁，且該位置不在邊界，而值超過 1，可能是橫向連線，因此減 1 就好，否則改為 0
							if(c-1 >= 0 && c+1 <= n-1 && ground[k][c] > 1 && ground[k][c-1] != 0 && ground[k][c+1] != 0) {
								ground[k][c]--;
							} else {
								ground[k][c] = 0;
							}
						}
						break;
					}
				}
			}
			if(r+1 < m-1) {
                // 只要該木樁不在下邊界，則往下尋找是否有木樁
				for(int j=r+1; j<m; j++) {
					if(ground[j][c] == -1) {
						for(int k=r+1; k<j; k++) {
                            // 若找到有木樁，且該位置不在邊界，而值超過 1，可能是橫向連線，因此減 1 就好，否則改為 0
							if(c-1 >= 0 && c+1 <= n-1 && ground[k][c] > 1 && ground[k][c-1] != 0 && ground[k][c+1] != 0) {
								ground[k][c]--;
							} else {
								ground[k][c] = 0;
							}
						}
						break;
					}
				}
			}
			if(c-1 > 0) {
                // 只要該木樁不在左邊界，則往左尋找是否有木樁
				for(int j=c-1; j>=0; j--) {
					if(ground[r][j] == -1) {
						for(int k=c-1; k>j; k--) {
                            // 若找到有木樁，且該位置不在邊界，而值超過 1，可能是縱向連線，因此減 1 就好，否則改為 0
							if(r-1 >= 0 && r+1 <= m-1 && ground[r][k] > 1 && ground[r-1][k] != 0 && ground[r+1][k] != 0) {
								ground[r][k]--;
							} else {
								ground[r][k] = 0;
							}
						}
						break;
					}
				}
			}
			if(c+1 < n-1) {
                // 只要該木樁不在右邊界，則往右尋找是否有木樁
				for(int j=c+1; j<n; j++) {
					if(ground[r][j] == -1) {
						for(int k=c+1; k<j; k++) {
                            // 若找到有木樁，且該位置不在邊界，而值超過 1，可能是縱向連線，因此減 1 就好，否則改為 0
							if(r-1 >= 0 && r+1 <= m-1 && ground[r][k] > 1 && ground[r-1][k] != 0 && ground[r+1][k] != 0) {
								ground[r][k]--;
							} else {
								ground[r][k] = 0;
							}
						}
						break;
					}
				}
			}
		}
        // 計算線和木樁佔據空間的面積，並找最大值
		total = 0;
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				if(ground[j][k] != 0) total++;
			}
		}
		MAX = max(MAX, total);
	}

    // 輸出最大值與操作結束後線和木樁佔據空間
	cout << MAX << "\n" << total << endl;

	return 0;
}