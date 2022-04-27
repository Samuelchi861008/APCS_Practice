/* 題目名稱：小群體 */
/* 解題關鍵：清楚定義自己編號與好友編號，並確實紀錄是否已被分配到小群體之中 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int N, numOfGroups = 0;
	vector<int> friends;

	cin >> N; // 輸入團體中人數

    	// 依序輸入每個人的好友編號，矩陣的 index 為自己編號，內容為好友編號
	for(int i=0; i<N; i++) {
		int id;
		cin >> id;
		friends.push_back(id);
	}

	vector<int> hasGroup(N, 0); // 紀錄每個人是否有被分配到小群體之中
	for(int i=0; i<hasGroup.size(); i++) {
        	// 當有人未被分配到小群體之中則以他為起點進行分配，直到回到自己為一個小群體
		if(hasGroup[i] == 0) {
			int currentIndex = i;
			while(hasGroup[currentIndex] == 0) {
				hasGroup[currentIndex] = 1; // 紀錄該人已被分配
				currentIndex = friends[currentIndex]; // 下一個 index 為自己的朋友編號
			}
			numOfGroups++; // 小群體的個數加 1
		}
	}

    	// 輸出小群體個數
	cout << numOfGroups << endl;

	return 0;
}
