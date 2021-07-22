#include <iostream>
#include <vector>

using namespace std;

// ABC042_C

// 外部関数のプロトタイプ宣言（extern は省略可）
// 提出する際は該当のソースコードを貼り付ける
extern vector<string> bblSort(vector<string> vStr); 


int main()
{
    
    // 文字列の長さは全てl、かつ半角英数字

    // 辞書が小さい順に文字列を並び変えた文字列を作ればOK
    // 問題はそのソート方法→今回はバブルソート使ってみる
    // おそらく計算量は最大データ数が100のため度のソートを使っても大丈夫そう

    int l, n;
    cin >> n;
    cin >> l;

    vector<string> vStr(n);
    
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vStr[i] = str;
    }
    

    vector<string> vAnsStr = bblSort(vStr);

    string ansStr = "";
    for (int i = 0; i < n; i++) ansStr += vAnsStr[i];

    cout << ansStr;

}
