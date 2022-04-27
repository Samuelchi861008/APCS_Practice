/* 題目名稱：邏輯運算子 */
/* 解題關鍵：將題目定義轉換成程式判斷，建議將三者分別寫成三個簡單函式 */

#include <iostream>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

// AND 函式
int AND(int a, int b) {
	// 根據題目定義，若 a 不為 0 且 b 不為 0 則輸出 1，否則輸出 0
	return (a != 0 && b != 0) ? 1 : 0;
}

// OR 函式
int OR(int a, int b) {
	// 根據題目定義，若 a 為 0 且 b 為 0 則輸出 0，否則輸出 1
	return (a == 0 && b == 0) ? 0 : 1;
}

// XOR 函式
int XOR(int a, int b) {
	// 根據題目定義，若 a 為 0 且 b 為 0 或是 a 不為 0 且 b 不為 0 輸出 0，否則輸出 1
	return ((a == 0 && b == 0) || (a != 0 && b != 0)) ? 0 : 1;
}

signed main()
{
	int a, b, ans;

	cin >> a >> b >> ans; // 輸入 a b ans

	// 分別呼叫函式判斷是否符合
	if(AND(a, b) == ans) cout << "AND" << endl;
	if(OR(a, b) == ans) cout << "OR" << endl;
	if(XOR(a, b) == ans) cout << "XOR" << endl;
	// 三者皆不符合則輸出 IMPOSSIBLE
	if((AND(a, b) != ans) && (OR(a, b) != ans) && (XOR(a, b) != ans)) cout << "IMPOSSIBLE" << endl;

	return 0;
}