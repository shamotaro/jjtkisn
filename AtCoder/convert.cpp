#include <iostream>
#include <vector>

using namespace std;

// 0-9�܂ł�char��ϊ�����֐�
int ctoi_(char c)
{
    if (c >= '0' && c <= '9') return c - '0';

    return -1;
}

// ����L�[���[�h�ł̕����񕪊�
vector<string> split_(string str, string sepaKey)
{
    if (sepaKey == "") return { str };

    vector<string> result;
    str = str + sepaKey; // �Ō�̒��K���킹
    long len = str.length(), sepaLen = sepaKey.length();
    long pos = 0, prev = 0;

    while (pos < len && pos != string::npos)
    {
        pos = str.find(sepaKey, pos); // pos �ȍ~�ōŏ��� sepaKey �ƈ�v����ʒu��Ԃ�
        result.emplace_back(str, prev, pos - prev); // push_back�̏�݊��H
        prev = pos + sepaLen;
        pos++;
    }
    return result;
}


vector<string> mv90_(vector<string> vs)
{
    // 90�x��]������
    vector<string> tmp90;

    int h = vs.size();
    int w = vs[0].length();
    for (int i = 0; i < w; i++)
    {
        string tmp = "";
        for (int j = h - 1; j >= 0; j--)
        {
            tmp += vs[j][i];
        }
        tmp90.push_back(tmp);
    }
    return tmp90;
}



// �Q�����z�����]�����č��v���邩��r
// 0�x��]��r
bool cmpST0_(vector<string> s, vector<string> t)
{
    bool ans = true;
    int w = s[0].length();
    int h = s.size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != t[i][j])
            {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }
    return ans;
}

// 180�x��]��r
bool cmpST180_(vector<string> s, vector<string> t)
{
    bool ans = true;
    int w = s[0].length();
    int h = s.size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != t[h - 1 - i][w - 1 - j])
            {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }
    return ans;
}

// 90�x��]
bool cmpST90_(vector<string> s, vector<string> t)
{
    bool ans = true;
    int w = s[0].length();
    int h = s.size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != t[j][h - 1 - i])
            {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }
    return ans;
}

// 270�x��]
bool cmpST270_(vector<string> s, vector<string> t)
{
    bool ans = true;
    int w = s[0].length();
    int h = s.size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != t[w - 1 - j][i])
            {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }
    return ans;
}


// ���ʂȏ㉺�̕ӂ��폜
vector<string> delEdge_(vector<string> vs, string delStr)
{
    bool flg = false;
    int h = vs.size();
    vector<string> ans;

    for (int i = 0; i < h; i++)
    {
        if (vs[i] != delStr) flg = true;
        if (flg) ans.push_back(vs[i]);
    }

    h = ans.size();
    for (int i = h - 1; i >= 0; i--)
    {
        if (ans[i] == delStr) ans.pop_back();
        else break;
    }
    return ans;
}

