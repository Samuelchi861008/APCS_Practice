/* 題目名稱：魔王迷宮 */
/* 解題關鍵：每一回合所有魔王皆是同時進行，因此必須先記錄行為後再進行炸彈的拆放，並且要瞭解如何會走超出盤面 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, m, k, numOfGameover = 0, numOfbomb = 0;

	cin >> n >> m >> k; // 輸入 n m k

	vector<vector<int> > master, ground(n, vector<int>(m, 0));

    // 建立每個魔王的 r c s t，並將每個魔王的起始點都先放炸彈
	for(int i=0; i<k; i++) {
		vector<int> sub;
		int r, c, s, t;

		cin >> r >> c >> s >> t;

		sub.push_back(r);
		sub.push_back(c);
		sub.push_back(s);
		sub.push_back(t);

		master.push_back(sub);
		ground[r][c] = -1;
	}

    // 直到所有魔王都出局才結束所有回合，而每次也都要紀錄哪個魔王出局
	vector<int> gameover(k, 0);
	while(numOfGameover < k) {
		vector<vector<int> > actions;
		for(int i=0; i<k; i++) {
			if(gameover[i] == 0) {
				int nextR = master[i][0] + master[i][2]; // 下一步的 r
				int nextC = master[i][1] + master[i][3]; // 下一步的 c
				if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) {
                    // 如果走超出盤面，該魔王就出局
					gameover[i] = 1;
					numOfGameover++;
				} else {
                    // 如果沒有走超出盤面的時候，判斷下一步踩到炸彈
					if(ground[nextR][nextC] == -1) {
                        // 如果踩到炸彈則紀錄該格的炸彈拆掉，且該魔王出局
						vector<int> sub;
						sub.push_back(0);
						sub.push_back(nextR);
						sub.push_back(nextC);
						actions.push_back(sub);
						gameover[i] = 1;
						numOfGameover++;
					} else {
                        // 如果沒有踩到炸彈則紀錄該格安裝炸彈，並將魔王確實移動到該位置
						vector<int> sub;
						sub.push_back(-1);
						sub.push_back(nextR);
						sub.push_back(nextC);
						actions.push_back(sub);
						master[i][0] += master[i][2];
						master[i][1] += master[i][3];
					}
				}
			}
		}
        // 將紀錄炸彈拆除與安裝炸彈實際放入盤面
		for(int i=0; i<actions.size(); i++) {
			ground[actions[i][1]][actions[i][2]] = actions[i][0];
		}
	}

    // 走訪盤面計算炸彈數量
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(ground[i][j] == -1) numOfbomb++;
		}
	}

    // 輸出炸彈數量
	cout << numOfbomb << endl;

	return 0;
}