
#include <iostream>
#include <vector>

using namespace std;

// ★バブルソート★
// 配列の最初から順に順番が逆の箇所をチェック
// 回数を重ねるごとに末尾のチェックは不要
// 順番が１度も入れ替わらずに最後までチェックが終われば完了
vector<string> bblSort_(vector<string> vStr)
{
    int n = vStr.size();

    // バブルソートの最大回数
    for (int i = 0; i < n - 1; i++)
    {
        // 入れ替えが発生したらfalseに変える
        bool flg = true;

        // 先頭からどこまでチェック対象か
        for (int j = 0; j < n - i - 1; j++)
        {
            string s1, s2;
            s1 = vStr[j];
            s2 = vStr[j + 1];

            // 文字型による演算 s1 - s2 の結果が正だと入れ替え
            if (s1.compare(s2) > 0)
            {
                vStr[j] = s2;
                vStr[j + 1] = s1;
                flg = false;
            }
        }

        if (flg) break;
    }

    return vStr;
}



// 簡易リスト構造
vector<vector<long>> listStruct_(long n, long q)
{
    // n番目のfirst：電車nの前に結合している電車
    // n番目のsecond：電車nの後ろに結合している電車
    // 値が-1：つながってない
    vector<pair<long, long>> vpll(n + 1, pair<long, long>(-1, -1));

    vector<vector<long>> ansList;

    long cnt = 0;

    for (int i = 0; i < q; i++)
    {
        long q0;
        cin >> q0;
        if (q0 == 1)
        {
            long x, y;
            cin >> x >> y;
            vpll[x].second = y;
            vpll[y].first = x;

        }
        else if (q0 == 2)
        {
            long x, y;
            cin >> x >> y;
            vpll[x].second = -1;
            vpll[y].first = -1;

        }
        else if (q0 == 3)
        {
            long x;
            cin >> x;

            long front = vpll[x].first;
            long now = x;
            while (front != -1)
            {
                front = vpll[now].first;
                if (front != -1) now = front;
                else break;
            }

            vector<long> ans;
            long back = vpll[now].second;

            if (back == -1) ans.push_back(now);

            while (back != -1)
            {
                ans.push_back(now);
                back = vpll[now].second;
                if (back != -1) now = back;
                else break;

            }
            ansList.push_back(ans);
            cnt++;
        }

    }
    return ansList;
}


