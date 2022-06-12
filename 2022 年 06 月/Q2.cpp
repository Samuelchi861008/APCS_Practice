/* 題目名稱：字串解碼 */
/* 解題關鍵：需了解矩陣順序調換，並拆分前半段與後半段並對調 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int m, n;
	vector<string> e;

	// 根據題意輸入 m 與 n
	cin >> m >> n;

	// 輸入 e
	for(int i=0; i<m; i++) {
		string sub;
		cin >> sub;
		e.push_back(sub);
	}

	// 輸入 s
	vector<char> s;
	for(int i=0; i<n; i++) {
		char word;
		cin >> word;
		s.push_back(word);
	}

	// 從 e 的後面依序往前解碼
	for(int i=e.size()-1; i>=0; i--) {
		// 矩陣對調
		int left = 0, right = e[i].length()-1, current = 0;
		vector<char> temp_1(n, ' ');
		for(int j=0; j<e[i].length(); j++) {
			// 若是 0 往前放；若是 1 往後放
			if(e[i][j] == '0') {
				temp_1[left++] = s[current++];
			} else {
				temp_1[right--] = s[current++];
			}
		}
		s = temp_1;

		// 計算 1 的個數
		int count = 0;
		
		for(int j=0; j<e[i].length(); j++) {
			if(e[i][j] == '1') count++;
		}

		// 若 1 的個數為奇數，拆分前半段與後半段並對調，須考慮中間值
		vector<char> temp_2;
		if(count%2) {
			// 判斷字串為奇數與偶數，拆分方式不同
			if(e[i].length()%2) {
				// 後半段
				for(int j=s.size()/2+1; j<s.size(); j++) {
					temp_2.push_back(s[j]);
				}
				// 中間值
				temp_2.push_back(s[s.size()/2]);
				// 前半段
				for(int j=0; j<s.size()/2; j++) {
					temp_2.push_back(s[j]);
				}
			} else {
				// 後半段
				for(int j=s.size()/2; j<s.size(); j++) {
					temp_2.push_back(s[j]);
				}
				// 前半段
				for(int j=0; j<s.size()/2; j++) {
					temp_2.push_back(s[j]);
				}
			}
			s = temp_2;
		}
	}

	// 輸出 s
	for(int i=0; i<s.size(); i++) {
		cout << s[i] << ((i==s.size()-1)?"\n":"");
	}

	return 0;
}