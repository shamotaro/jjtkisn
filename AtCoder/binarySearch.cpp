#include <iostream>
#include <vector>

using namespace std;


// 答えを２分探索していく
int ansSearch_(int left, int right, vector<int> vInt, int k)
{
    int ans = 0;
    int n = vInt.size();

    while (left < right)
    {
        ans = (left + right) / 2;

        // ★おそらく処理内容は毎回違う★
        int sum = 0, cntk = 0;
        for (int i = 0; i < n; i++)
        {
            sum += vInt[i];
            if (sum >= ans)
            {
                cntk++;
                sum = 0;
            }
        }

        // 答えの可能性幅を狭めていって1になれば答えが出てる
        if ((right - left) == 1) break;

        // ★答えの可能性幅を狭める★狭め方の判定は毎回変える
        if (cntk > k) left = ans;
        else right = ans;
    }

    return ans;
}



void dp_(long MOD)
{

    int MAX = 3000;

    long n;
    cin >> n;

    vector<int> a;
    vector<int> b;
    for (long i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for (long i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    // 動的計画法でN番目の部分(末尾)から求める
    // 数の制限があるbの値側から求める
    vector<long> dp(MAX + 1, 0); // 添え字と合わせるために＋１
    int an = a[n - 1];
    int bn = b[n - 1];

    // N番目だけだとすると、自身の数字のみで１通り
    for (long i = an; i <= bn; i++) dp[i] = 1;

    long sum = 0;

    for (long i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (long j = bn; j >= a[i]; j--)
        {
            sum += dp[j];
            sum %= MOD;

            // 現在のi番目はここまでのi以上の値の合計値(パターン)
            // biより大きいdpiは今後使うことがないため0にする
            if (j <= b[i]) dp[j] = sum;
            else dp[j] = 0;
        }
    }

    sum = 0;
    for (int i = 0; i <= bn; i++)  sum += dp[i];

    sum += MOD;
    cout << sum % MOD;
}


// 素結合データ構造
struct UnionFind
{
    vector<int> par; // 親
    vector<int> rank; // 要素数

    // コンストラクタ
    // 最初は全ての要素が独立している集合を作る
    UnionFind(int n)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i; // 初めはノード１個の木なので根は自身
            rank[i] = 1;
        }
    }

    // 要素の根の値を求める
    int root(int x)
    {
        if (par[x] == x) return x; // 自身が親だった
        else return par[x] = root(par[x]); // 自身が親となる要素まで再帰呼び出し
    }

    // ２つの要素が同じ木に属するかを判定
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    // 要素同士を結合する(該当の要素が集合の一部の場合は集合の結合)
    void unite(int x, int y)
    {
        // まずは結合のためにそれぞれの根を求める
        x = root(x);
        y = root(y);

        // もし同じ木に属していたら何もしない
        if (x == y) return;

        // 数が大きい木に小さい木(集合)を結合させる
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        rank[x] += rank[y];
    }

    //連結数を返す
    int size(int x)
    {
        return rank[root(x)];
    }
};
