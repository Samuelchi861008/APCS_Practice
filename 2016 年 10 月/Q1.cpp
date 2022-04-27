/* 題目名稱：三角形辨別 */
/* 解題關鍵：需將三邊長輸入後排序，並根據題意的公式運算進行判斷 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int a, b, c;
	vector<int> triangle;

    // 根據題意輸入 a b c 三邊長
	cin >> a >> b >> c;

    // 將三邊長進行儲存
	triangle.push_back(a);
	triangle.push_back(b);
	triangle.push_back(c);

    // 將三邊長排序
	sort(triangle.begin(), triangle.end());

    // 將排序後結果依序輸出
	cout << triangle[0] << " " << triangle[1] << " " << triangle[2] << endl;

    // 根據題意的公式運算判斷所屬三角形類型
	if(triangle[0] + triangle[1] <= triangle[2]) {
		cout << "No" << endl;
	} else if((((triangle[0]*triangle[0]) + (triangle[1]*triangle[1])) < (triangle[2] * triangle[2]))) {
		cout << "Obtuse" << endl;
	} else if((((triangle[0]*triangle[0]) + (triangle[1]*triangle[1])) == (triangle[2] * triangle[2]))) {
		cout << "Right" << endl;
	} else if((((triangle[0]*triangle[0]) + (triangle[1]*triangle[1])) > (triangle[2] * triangle[2]))) {
		cout << "Acute" << endl;
	}

	return 0;
}