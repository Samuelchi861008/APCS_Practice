/* 題目名稱：修補圍籬 */
/* 解題關鍵：要特別注意圍籬若在頭尾的狀況，其餘皆取左右兩邊最小值即可 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int n, total = 0;
	vector<int> h;

	cin >> n; // 輸入 n

    	// 輸入每個圍籬的高度
	for(int i=0; i<n; i++) {
		int height;
		cin >> height;
		h.push_back(height);
	}

    	// 查看圍籬中何處有被吹斷 (即為 0)
	for(int i=0; i<h.size(); i++) {
		if(h[i] == 0) {
			if(i==0) {
                		// 如果圍籬斷在第一個，則以第二片圍籬高度為準
				total += h[i+1];
			} else if(i==h.size()-1) {
                		// 如果圍籬斷在最後一個，則以倒數第二片圍籬高度為準
				total += h[i-1];
			} else {
                		// 其他則以鄰左邊和右邊較小的圍籬高度為準
				total += min(h[i+1], h[i-1]);
			}
		}
	}

    	// 輸出所需圍籬長度總和
	cout << total << endl;

	return 0;
}
