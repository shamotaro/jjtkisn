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

