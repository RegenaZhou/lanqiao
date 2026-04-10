/*
题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

小蓝要为一条街的住户制作门牌号。

这条街一共有 2020 位住户，门牌号从 1 到 2020 编号。

小蓝制作门牌的方法是先制作 0 到 9 这几个数字字符，最后根据需要将字符粘贴到门牌上，例如门牌 1017 需要依次粘贴字符 1、0、1、7，即需要 1 个字符 0，2 个字符 1，1 个字符 7。

请问要制作所有的 1 到 2020 号门牌，总共需要多少个字符 2？*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 2; i <= 2020; i++)
    {
        int cpi = i;
        while (cpi)
        {
            if (cpi % 10 == 2) ans++;
            cpi /= 10;
        }
    }
    cout << ans << '\n';//624
    return 0;
}
