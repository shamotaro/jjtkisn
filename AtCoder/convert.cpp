#include <iostream>
#include <vector>

using namespace std;

// 0-9�܂ł�char��ϊ�����֐�
int ctoi_(char c)
{
    if (c >= '0' && c <= '9') return c - '0';

    return -1;
}


