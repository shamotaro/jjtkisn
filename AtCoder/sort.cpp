
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


