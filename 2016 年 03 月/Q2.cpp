/* 題目名稱：矩陣轉換 */
/* 解題關鍵：需了解矩陣的旋轉與翻轉，並從結果矩陣反推回初始矩陣 */

#include <iostream>
#include <vector>
using namespace std;

// 定義程式中的 int 改為 long long 型態
#define int long long

signed main()
{
	int R, C, M;
	vector<vector<int> > B;
	vector<int> actions;

    // 根據題意依序輸入 R C M
	cin >> R >> C >> M;

    // 根據所輸入的 R C 建立矩陣 B 的內容
	for(int i=0; i<R; i++) {
		vector<int> sub;
		for(int j=0; j<C; j++) {
			int num;
			cin >> num;
			sub.push_back(num);
		}
		B.push_back(sub);
	}

    // 根據所輸入的 M 將操作順序紀錄起來
	for(int i=0; i<M; i++) {
		int num;
		cin >> num;
		actions.push_back(num);
	}

    // 由於題意是希望將結果矩陣反推回初始矩陣，因此操作順序由後往前
	for(int i=actions.size()-1; i>=0; i--) {
        // 若操作為 0 則表示旋轉，若操作為 1 則表示翻轉
		if(actions[i] == 0) {
            // 旋轉規則：將矩陣以順時針方向轉 90 度
            // 由於本題是將結果反推回初始，因此旋轉應以逆時針方向來思考撰寫
			vector<vector<int> > temp;
			for(int j=B[0].size()-1; j>=0; j--) {
				vector<int> sub;
				for(int k=0; k<B.size(); k++) {
					sub.push_back(B[k][j]);
				}
				temp.push_back(sub);
			}
			B = temp;
		} else {
            // 翻轉規則：將第一列與最後一列交換，將第二列與倒數第二列交換...以此類推
            // 矩陣翻轉的操作只需做一半即可完成全部矩陣的翻轉，否則最後又會變回未翻轉時的樣子
			for(int j=0; j<B.size()/2; j++) {
				vector<int> temp = B[j];
				B[j] = B[B.size()-1-j];
				B[B.size()-1-j] = temp;
			}
		}
	}

    // 輸出初始矩陣的列數和行數
	cout << B.size() << " " << B[0].size() << endl;

    // 依序輸出初始矩陣的所有內容
	for(int i=0; i<B.size(); i++) {
		for(int j=0; j<B[i].size(); j++) {
			cout << B[i][j] << ((j==B[i].size()-1) ? "\n" : " ");
		}
	}

	return 0;
}