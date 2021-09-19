#include <iostream>
#include <vector>
#include <string>

using namespace std;

// データ型の記載省略
typedef long long ll;


// 外部関数のプロトタイプ宣言（extern は省略可）
// 提出する際は使った該当のソースコードを貼り付ける
// extern int ctoi(char c);
// extern vector<string> bblSort(vector<string> vStr);
extern int ansSearch(int left, int right, vector<int> vi, int k);


long MOD = 1000000007;


int main()
{

    int n, l, k;
    vector<int> va;
    cin >> n >> l;
    cin >> k;

    // 配列に全切れ目の間隔を格納
    int a0 = 0, a1;
    for (int i = 0; i < n; i++)
    {
        cin >> a1;
        va.push_back(a1 - a0);
        a0 = a1;
    }
    va.push_back(l - a0);

    // 答えを２分探索していく
    int ans = ansSearch(0, l, va, k);

    std::cout << ans;

}
