/* 題目名稱：人口遷移 */
/* 解題關鍵：需要模擬多天，並需要注意邊界值，且需要注意 -1 皆不需處理 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int R, C, k, m;
	vector<vector<int> > ground;

	cin >> R >> C >> k >> m; // 輸入 R C k m

    // 根據 R C 建立各城市的人口
	for(int i=0; i<R; i++) {
		vector<int> sub;
		for(int j=0; j<C; j++) {
			int num;
			cin >> num;
			sub.push_back(num);
		}
		ground.push_back(sub);
	}

    // 進行 m 天
	for(int day=0; day<m; day++) {
        // 需建立一個暫時紀錄用的矩陣，並初始化為 0
		vector<vector<int> > temp(R, vector<int>(C, 0));
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(ground[i][j] != -1) {
                    // 判斷上方是否有值
					if(i-1 >= 0 && ground[i-1][j] != -1) {
						temp[i-1][j] += (ground[i][j] / k);
						temp[i][j] -= (ground[i][j] / k);
					}
                    // 判斷下方是否有值
					if(i+1 < R && ground[i+1][j] != -1) {
						temp[i+1][j] += (ground[i][j] / k);
						temp[i][j] -= (ground[i][j] / k);
					}
                    // 判斷左方是否有值
					if(j-1 >= 0 && ground[i][j-1] != -1) {
						temp[i][j-1] += (ground[i][j] / k);
						temp[i][j] -= (ground[i][j] / k);
					}
                    // 判斷右方是否有值
					if(j+1 < C && ground[i][j+1] != -1) {
						temp[i][j+1] += (ground[i][j] / k);
						temp[i][j] -= (ground[i][j] / k);	
					}
				}
			}
		}
        // 根據所記錄的內容更改原始的值
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(ground[i][j] != -1) {
					ground[i][j] += temp[i][j];
				}
			}
		}
	}

    // 從矩陣中找到最大最小值，記得略過 -1
	int MIN = LLONG_MAX, MAX = LLONG_MIN;
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(ground[i][j] != -1) {
				MIN = min(MIN, ground[i][j]);
				MAX = max(MAX, ground[i][j]);
			}
		}
	}

    // 輸出最小與最大值
	cout << MIN << "\n" << MAX << endl;

	return 0;
}