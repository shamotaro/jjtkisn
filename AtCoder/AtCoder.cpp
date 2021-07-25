#include <iostream>
#include <vector>
#include <string>

using namespace std;

// データ型の記載省略
using ll = long long;

// ABC042_D

// 外部関数のプロトタイプ宣言（extern は省略可）
// 提出する際は使った該当のソースコードを貼り付ける
extern int ctoi(char c);

// 縦：H、横：Wの帳票系の全経路探索パターンを求める
ll hwPhw(long h, long w, long mod)
{
    ll ans = 1;
    long n = h + w;

    long b = h, s = w;
    if (h < w)
    {
        b = w;
        s = h;
    }

    for (long i = n; i > b; i--) ans *= i % mod;
    for (long i = s; i > 0; i--) ans /= i % mod;

    if (ans < 0) ans += mod;

    return ans;
}


int main()
{
    
    // H*Wの長方形の全通り探索
    // 全通りの計算式：(H+W-2)!/(H-1)!/(W-1)!

    long MOD = 1000000007;

    long h, w, a, b;
    cin >> h >> w >> a >> b;

    ll allPtn = 0;
    
    if (a != 1 || b != 1)
    {
        ll sO = 0, X = 0, eO = 0;
        for (long i = 0; i < h-a; i++)
        {
            if (i == 0) sO = 1;
            else sO = hwPhw(i, b - 1, MOD);

            ll tmpPtn = 0;

            for (long j = 0; j < w-b; j++)
            {
                if (i == h - a - 1 || j == 0) X = 1;
                else X = hwPhw(h - a - i - 1, j, MOD);

                if (j == w-b-1) eO = 1;
                else eO = hwPhw(a - 1, w - b - j - 1, MOD);

                tmpPtn += X * eO % MOD;
                
            }
            allPtn += sO * tmpPtn % MOD;
        }
    }
    else
    {
        allPtn = hwPhw(h - 1, w - 1, MOD);
        allPtn -= 1;
    }

    if (allPtn < 0) allPtn += MOD;

    cout << allPtn;
}
