/* 題目名稱：猜拳 */
/* 解題關鍵：比較哥哥與妹妹的出拳，且平手的時候需要多加考慮判斷 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

// 判斷哥哥出拳對妹妹出拳狀態
int status(int brother, int sister)
{
	if(brother == sister) {
		return 0; // 哥哥與妹妹平手
	} else if((brother==0 && sister==2) || (brother==2 && sister==5) || (brother==5 && sister==0)) {
		return 1; // 哥哥贏妹妹
	} else {
		return -1; // 哥哥輸妹妹
	}
}

signed main()
{
	int F, N;
	vector<int> sister;

	cin >> F >> N; // 輸入 F N

    	// 根據 N 輸入妹妹出拳
	for(int i=0; i<N; i++) {
		int y;
		cin >> y;
		sister.push_back(y);
	}

    	// 依序判斷哥哥與妹妹出拳狀態
	for(int i=0; i<sister.size(); i++) {
		cout << F << " "; // 輸出哥哥所出的拳
		if(status(F, sister[i]) == 1) {
            		// 若哥哥贏，則輸出贏在第幾輪，並結束
			cout << ": Won at round " << i+1 << endl;
			break;
		} else if(status(F, sister[i]) == -1) {
            		// 若哥哥輸，則輸出輸在第幾輪，並結束
			cout << ": Lost at round " << i+1 << endl;
			break;
		} else {
            		// 若平手且為最後一輪，則輸出平手，若妹妹連續兩輪出了一樣的拳，哥哥下一輪會出打敗前兩輪的拳，否則下一輪會出一樣的拳
			if(i==sister.size()-1) {
				cout << ": Drew at round " << i+1 << endl;
			} else if(i!=0 && sister[i-1] == sister[i]) {
				F = (sister[i]==0) ? 5 : (sister[i]==5) ? 2 : 0;
			} else {
				F = sister[i];
			}
		}
	}

	return 0;
}
