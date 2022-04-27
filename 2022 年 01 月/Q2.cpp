/* 題目名稱：贏家預測 */
/* 解題關鍵：當兩兩一組進行配對競賽，有烙單要額外處理，且所有人競賽完重新排序要注意順序 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, m;
	vector<int> S, T, idx;

	cin >> n >> m; // 輸入 n m

    	// 輸入戰力值
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		S.push_back(num);
	}

    // 輸入應變力值
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		T.push_back(num);
	}

    // 輸入初始排列順序
	for(int i=0; i<n; i++) {
		int id;
		cin >> id;
		idx.push_back(id);
	}

    	// 紀錄失敗次數
	vector<int> gameover(n, 0);
    	// 不斷進行比賽，直到剩下一位玩家
	while(idx.size() > 1) {
        	// 紀錄贏家、輸家、暫時順序
		vector<int> win, lose, temp;
        	// 兩兩一組進行配對競賽
		for(int i=0; i<idx.size()-1; i+=2) {
            		// 第一個人的戰力為 a 應變力為 b，第二個人的戰力為 c 應變力為 d
			int a = S[idx[i]-1], b = T[idx[i]-1], c = S[idx[i+1]-1], d = T[idx[i+1]-1];
			if(a*b >= c*d) {
                		// 第一個人獲勝、第二個人失敗
				S[idx[i]-1] = a + ((c * d) / (2 * b));
				T[idx[i]-1] = b + ((c * d) / (2 * a));
				S[idx[i+1]-1] = c + (c / 2);
				T[idx[i+1]-1] = d + (d / 2);
				win.push_back(idx[i]);
				lose.push_back(idx[i+1]);
				gameover[idx[i+1]-1]++;
			} else {
                		// 第一個人失敗、第二個人獲勝
				S[idx[i+1]-1] = c + ((a * b) / (2 * d));
				T[idx[i+1]-1] = d + ((a * b) / (2 * c));
				S[idx[i]-1] = a + (a / 2);
				T[idx[i]-1] = b + (b / 2);
				win.push_back(idx[i+1]);
				lose.push_back(idx[i]);
				gameover[idx[i]-1]++;
			}
		}
        	// 贏家優先排序
		for(int i=0; i<win.size(); i++) {
			temp.push_back(win[i]);
		}
        	// 烙單的人直接晉級
		if(idx.size()%2) {
			temp.push_back(idx[idx.size()-1]);
		}
        	// 輸家如果尚未淘汰則進入排序
		for(int i=0; i<lose.size(); i++) {
			if(gameover[lose[i]-1] < m) {
				temp.push_back(lose[i]);
			}
		}
        	// 重新更改排序
		idx = temp;
	}

    	// 輸出最後贏家
	cout << idx[0] << endl;

	return 0;
}
