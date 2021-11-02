
#include <iostream>
#include <vector>

using namespace std;

// ���o�u���\�[�g��
// �z��̍ŏ����珇�ɏ��Ԃ��t�̉ӏ����`�F�b�N
// �񐔂��d�˂邲�Ƃɖ����̃`�F�b�N�͕s�v
// ���Ԃ��P�x������ւ�炸�ɍŌ�܂Ń`�F�b�N���I���Ί���
vector<string> bblSort_(vector<string> vStr)
{
    int n = vStr.size();

    // �o�u���\�[�g�̍ő��
    for (int i = 0; i < n - 1; i++)
    {
        // ����ւ�������������false�ɕς���
        bool flg = true;

        // �擪����ǂ��܂Ń`�F�b�N�Ώۂ�
        for (int j = 0; j < n - i - 1; j++)
        {
            string s1, s2;
            s1 = vStr[j];
            s2 = vStr[j + 1];

            // �����^�ɂ�鉉�Z s1 - s2 �̌��ʂ������Ɠ���ւ�
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



// �ȈՃ��X�g�\��
vector<vector<long>> listStruct_(long n, long q)
{
    // n�Ԗڂ�first�F�d��n�̑O�Ɍ������Ă���d��
    // n�Ԗڂ�second�F�d��n�̌��Ɍ������Ă���d��
    // �l��-1�F�Ȃ����ĂȂ�
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


