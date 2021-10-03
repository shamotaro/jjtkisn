#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair?

using namespace std;

// データ型の記載省略
typedef long long ll;


// 外部ファイルから関数をコピーするときは末尾の"_"を消す
int ctoi(char c)
{
    if (c >= '0' && c <= '9') return c - '0';

    return -1;
}



long MOD = 1000000007;


int main()
{

    int n;
    cin >> n;

    int pCnt = 200000;
    
    // 入力を受け取るpair
    // ログイン日、ログイン最終日をキー(左)に入れる
    // 値(右)にログイン日の場合は１、最終日の場合は-1を入れる
    vector<pair<int, int>> vpii;
    vector<int> vAns(pCnt, 0);

    int st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> st >> en;
        vpii.push_back(make_pair(st, 1));
        vpii.push_back(make_pair(st+en, -1));
    }

    // pairのキーをもとに昇順に並べる
    sort(vpii.begin(), vpii.end());

    // まずは最初のログイン者１人、cntに1を代入
    // その後は以下の処理を繰り返す
    // 誰でもいいからログイン開始日が出てきたらcnt++
    // 誰でもいいからログイン終了日が出てきたらcnt--
    // cntの値が変わったとき、vAns[cnt]+=(cntが変わらなかった期間)
    int tmp = vpii[0].first;
    int cnt = 1;
    for (int i = 1; i < 2*n; i++)
    {
        vAns[cnt] += vpii[i].first - tmp;
        tmp = vpii[i].first;
        cnt += vpii[i].second;
    }

    for (int i = 1; i < n; i++) cout << vAns[i] << " ";
    cout << vAns[n] << endl;

}
