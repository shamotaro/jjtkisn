
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


