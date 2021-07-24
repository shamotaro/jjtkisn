#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ABC042_C

// 外部関数のプロトタイプ宣言（extern は省略可）
// 提出する際は使った該当のソースコードを貼り付ける
extern int ctoi(char c);


int main()
{
    
    // D[k]の数字が出現しない支払金額にする

    // Nより大きくて嫌いな数字の入っていない最小金額を求める
    // 最上位の桁から順に見ていく
    // 上の桁がピッタリの場合とそうでない場合で分岐する
    // 下の桁全てが上の数字を使えない場合は、最上位桁を繰り上げる

    string n;
    int k;
    cin >> n;
    cin >> k;

    // 0-9の中で使える数字はtrue
    vector<bool> vd(10, true);
    
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        vd[tmp] = false;
    }

    // 使える最小の数字
    int minN;
    for (int i = 0; i < 10; i++)
    {
        if (vd[i])
        {
            minN = i;
            break;
        }
    }
    
    int nLen = n.length();
    bool topFlg = true; // (現時点の)最上桁の数字でぴったがOKな場合True

    string ansStr = "";
    for (int i = 0; i < nLen; i++)
    {
        int tmpN = ctoi(n[i]);
        if (topFlg)
        {
            // (現時点の)最上桁の数字を使用できない場合
            if (!vd[tmpN])
            {
                topFlg = false;
                for (int j = tmpN + 1; j < 10; j++)
                {
                    if (vd[j])
                    {
                        ansStr += to_string(j);
                        break;
                    }
                }
            }
            else
            {
                ansStr += n[i];
            }
        }
        else
        {
            // 使用できる１番小さい数字を選ぶ
            ansStr += to_string(minN);
        }
    }

    // 最上位桁の繰り上げ考慮が必要な場合
    if (ansStr.compare(n) < 0)
    {
        int tmpN = ctoi(n[0]);
        ansStr = "";

        for (int i = tmpN+1; i < 10; i++)
        {
            if (vd[i])
            {
                ansStr += to_string(i);
                break;
            }
        }

        // 桁を増やす考慮が必要な場合
        if (ansStr == "")
        {
            for (int i = 1; i < 10; i++)
            {
                if (vd[i])
                {
                    ansStr += to_string(i);
                    ansStr += to_string(minN);
                    break;
                }
            }
        }

        for (int i = 1; i < nLen; i++)
        {
            ansStr += to_string(minN);
        }
    }
    
    cout << ansStr;
}
