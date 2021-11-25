#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair?
#include <numeric> // accumulate
#include <cmath> // pow,round
#include <iomanip> // setprecision

using namespace std;

// データ型の記載省略
typedef long long ll;


// 外部ファイルから関数をコピーするときは末尾の"_"を消す



long MOD = 998244353;


int main()
{

    // N=2^20 項からなる数列 A があり、はじめは全ての要素は −1 である。 
    // Q 個のクエリを順番に処理

    long N = 1048576; // 2^20

    vector<long> a(N, -1);
    UnionFind uf(N);

    long q, t, x;
    cin >> q;

    vector<long> ans;

    for (long i = 0; i < q; i++)
    {
        cin >> t >> x;

        if (t == 1)
        {
            long h = x % N;
            
            if (uf.root(h) == (h)) // (x mod N) 番目の配列の値が未使用
            {
                // 値を入れて次の集合と結合
                a[h] = x;
                uf.unite(h + 1, h); // 未使用を親にするため、h+1の集合を親に
                
            }
            else // 使用されていた
            {
                h = uf.root(h); // 親には未使用の値が入っている
                a[h] = x;
                uf.unite(h + 1, h);
            }

        }
        else if (t == 2)
        {
            ans.push_back(a[x % N]);
        }
    }

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

}
