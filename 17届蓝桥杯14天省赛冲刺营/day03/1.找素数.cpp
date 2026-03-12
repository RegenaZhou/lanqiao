/*
题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

素数就是不能再进行等分的整数。比如：7，11。而 9 不是素数，因为它可以平分为 3 等份。一般认为最小的素数是 2，接着是 3，5，...

请问，第
100002
100002(十万零二)个素数是多少？

请注意：“2” 是第一素数，“3” 是第二个素数，依此类推。*/
#include <iostream>
using namespace std;
using ll = long long;
#define N 2000000
bool p[N] = { false };
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 2; i < N; i++)
    {
        for (int j = i * 2; j < N; j += i)
        {
            p[j] = true;
        }
    }
    int ans, cnt = 0, id = 2;
    while (id < N)
    {
        if (!p[id])
        {
            cnt++;
            if (cnt == 100002)
            {
                ans = id;
                break;
            }
        }
        id++;
    }
    cout << ans << '\n';//1299743
    return 0;
}
