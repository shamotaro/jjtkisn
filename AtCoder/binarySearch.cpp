#include <iostream>
#include <vector>

using namespace std;


// �������Q���T�����Ă���
int ansSearch_(int left, int right, vector<int> vInt, int k)
{
    int ans = 0;
    int n = vInt.size();

    while (left < right)
    {
        ans = (left + right) / 2;

        // �������炭�������e�͖���Ⴄ��
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

        // �����̉\���������߂Ă�����1�ɂȂ�Γ������o�Ă�
        if ((right - left) == 1) break;

        // �������̉\���������߂遚���ߕ��̔���͖���ς���
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

    // ���I�v��@��N�Ԗڂ̕���(����)���狁�߂�
    // ���̐���������b�̒l�����狁�߂�
    vector<long> dp(MAX + 1, 0); // �Y�����ƍ��킹�邽�߂Ɂ{�P
    int an = a[n - 1];
    int bn = b[n - 1];

    // N�Ԗڂ������Ƃ���ƁA���g�̐����݂̂łP�ʂ�
    for (long i = an; i <= bn; i++) dp[i] = 1;

    long sum = 0;

    for (long i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (long j = bn; j >= a[i]; j--)
        {
            sum += dp[j];
            sum %= MOD;

            // ���݂�i�Ԗڂ͂����܂ł�i�ȏ�̒l�̍��v�l(�p�^�[��)
            // bi���傫��dpi�͍���g�����Ƃ��Ȃ�����0�ɂ���
            if (j <= b[i]) dp[j] = sum;
            else dp[j] = 0;
        }
    }

    sum = 0;
    for (int i = 0; i <= bn; i++)  sum += dp[i];

    sum += MOD;
    cout << sum % MOD;
}


// �f�����f�[�^�\��
struct UnionFind
{
    vector<int> par; // �e
    vector<int> rank; // �v�f��

    // �R���X�g���N�^
    // �ŏ��͑S�Ă̗v�f���Ɨ����Ă���W�������
    UnionFind(int n)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i; // ���߂̓m�[�h�P�̖؂Ȃ̂ō��͎��g
            rank[i] = 1;
        }
    }

    // �v�f�̍��̒l�����߂�
    int root(int x)
    {
        if (par[x] == x) return x; // ���g���e������
        else return par[x] = root(par[x]); // ���g���e�ƂȂ�v�f�܂ōċA�Ăяo��
    }

    // �Q�̗v�f�������؂ɑ����邩�𔻒�
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    // �v�f���m����������(�Y���̗v�f���W���̈ꕔ�̏ꍇ�͏W���̌���)
    void unite(int x, int y)
    {
        // �܂��͌����̂��߂ɂ��ꂼ��̍������߂�
        x = root(x);
        y = root(y);

        // ���������؂ɑ����Ă����牽�����Ȃ�
        if (x == y) return;

        // �����傫���؂ɏ�������(�W��)������������
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        rank[x] += rank[y];
    }

    //�A������Ԃ�
    int size(int x)
    {
        return rank[root(x)];
    }
};
