#include <iostream>
#include <vector>

using namespace std;


// 答えを２分探索していく
int ansSearch(int left, int right, vector<int> vi, int k)
{
    int ans = 0;
    int n = vi.size();

    while (left < right)
    {
        ans = (left + right) / 2;

        // ★おそらく処理内容も毎回違う★
        int sum = 0, cntk = 0;
        for (int i = 0; i < n; i++)
        {
            sum += vi[i];
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
