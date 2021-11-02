#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair?
#include <numeric> // accumulate
#include <cmath> // pow

using namespace std;

// データ型の記載省略
typedef long long ll;


// 外部ファイルから関数をコピーするときは末尾の"_"を消す



long MOD = 998244353;

int main()
{
    long a, b;
    cin >> a >> b;

    int ans = pow(a, b);

    cout << ans;
    
}
