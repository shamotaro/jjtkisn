#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair?

using namespace std;

// データ型の記載省略
typedef long long ll;


// 外部ファイルから関数をコピーするときは末尾の"_"を消す
vector<string> split(string str, string sepaKey)
{
    if (sepaKey == "") return { str };

    vector<string> result;
    str = str + sepaKey; // 最後の帳尻合わせ
    long len = str.length(), sepaLen = sepaKey.length();
    long pos = 0, prev = 0;

    while (pos < len && pos != string::npos)
    {
        pos = str.find(sepaKey, pos); // pos 以降で最初に sepaKey と一致する位置を返す
        result.emplace_back(str, prev, pos - prev); // push_backの上互換？
        prev = pos + sepaLen;
        pos++;
    }
    return result;
}

long MOD = 998244353;

int main()
{
    string str;
    cin >> str;

    vector<string> tmp;
    tmp = split(str, ".");

    string x = tmp[0];
    int y = stoi(tmp[1]);

    string add;
    if (y >= 7)  add = "+";
    else if(y >= 3) add = "";
    else if (y >= 0) add = "-";

    string ans = x + add;
    cout << ans;

}
