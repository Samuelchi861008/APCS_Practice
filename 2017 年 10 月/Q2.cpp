/* 題目名稱：交錯字串 */
/* 解題關鍵：本題需多加思考和運用技巧，將字母換成 1 0 或許會更方便計算 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int k, total = 1;
	string s;
	vector<int> stored;

	cin >> k >> s; // 輸入 k 與 s

    // 將字串中每個字元，大寫字母改為 1 小寫字母改為 0
	for(int i=0; i<s.length(); i++) {
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? '1' : '0';
	}

    // 計算連續字母個數
	for(int i=1; i<s.length(); i++) {
		if((s[i] != s[i-1])) {
			stored.push_back(total);
			total = 1;
		} else {
			total++;
		}
		if(i==s.length()-1) {
			stored.push_back(total);
		}
	}

    // 判斷個數
	int lengthOfString = 0, MAX = 0;
	for(int i=0; i<stored.size(); i++) {
		if(stored[i] > k) {
            // 個數若大於 k 則表示必定包含 k 且交錯字串可能為兩頭
			lengthOfString += k;
			MAX = max(MAX, lengthOfString);
			lengthOfString = k;
		} else if(stored[i] == k) {
            // 個數若等於 k 則表示包含 k
			lengthOfString += k;
			MAX = max(MAX, lengthOfString);
		} else {
            // 個數若小於 k 則表示不包含 k 且需要重新計算交錯字串
			lengthOfString = 0;
			continue;
		}
	}

    // 假設 k 為 1 且只有單一字元，最大值則為 1
	if(k==1 && s.length()==1) MAX = s.length();

    // 輸出最大值
	cout << MAX << endl;

	return 0;
}