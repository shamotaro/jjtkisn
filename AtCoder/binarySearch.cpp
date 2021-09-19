#include <iostream>
#include <vector>

using namespace std;


// �������Q���T�����Ă���
int ansSearch(int left, int right, vector<int> vi, int k)
{
    int ans = 0;
    int n = vi.size();

    while (left < right)
    {
        ans = (left + right) / 2;

        // �������炭�������e������Ⴄ��
        int sum = 0, cntk = 0;
        for (int i = 0; i < n; i++)
        {
            sum += vi[i];
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
