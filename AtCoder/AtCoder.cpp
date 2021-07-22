#include <iostream>
#include <vector>


using namespace std;

// ABC042

int main()
{
    // 入力に5が2個、7が1個あればOK
    
    int n = 3;
    int aSum = 5 + 5 + 7;

    // 標準入力からデータ読み込み
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        // 5 or 7 の場合は引く
        if (tmp == 5 || tmp == 7) aSum -= tmp;
    }
    
    // 5と7しか存在せず、合計が17となったら正解
    if (aSum == 0) cout << "YES";
    else cout << "NO";


}
