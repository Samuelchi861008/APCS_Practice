/* 題目名稱：最大和 */
/* 解題關鍵：找出每一群的最大值並加總與儲存，最後再拿總和分別除以每一群的最大值，但要注意完全不被整除的狀況 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int N, M, total = 0;
	vector<int> S;

	cin >> N >> M; // 輸入 N M

    // 根據 N M 輸入值，每 M 個值為一群，每一群中找到最大值並加總與儲存 
	for(int i=0; i<N; i++) {
		int MAX = -1;
		for(int j=0; j<M; j++) {
			int num;
			cin >> num;
			MAX = max(MAX, num);
		}
		total += MAX;
		S.push_back(MAX);
	}

    // 輸出總和
	cout << total << endl;

    // 將總和分別除以每一群的最大值，若整除則存進 canMod 中
	vector<int> canMod;
	for(int i=0; i<S.size(); i++) {
		if(total % S[i] == 0) {
			canMod.push_back(S[i]);
		}
	}

    // 假設 canMod 沒有任何值表示所有數字都不能整除則輸出 -1，否則依序輸出
	if(canMod.size() == 0) {
        cout << -1 << endl;
    } else {
		for(int i=0; i<canMod.size(); i++) {
			cout << canMod[i] << ((i==canMod.size()-1) ? "\n" : " ");
		}
	}

	return 0;
}