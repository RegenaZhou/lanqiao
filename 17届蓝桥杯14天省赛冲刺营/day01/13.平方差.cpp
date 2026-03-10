/*
题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

2021 是一个非常特殊的数，它可以表示成两个非负整数的平方差，2021=45∗45−2∗2。

2025 也是同样特殊的数，它可以表示成 2025=45∗45−0∗0。

请问，在 1 到 2021 中有多少个这样的数？

请注意，有的数有多种表示方法，例如 9=3∗3−0∗0=5∗5−4∗4，在算答案时只算一次。*/
#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 1; i <= 2021; i++)
    {
        if (i % 2 == 1) ans++;
        else if (i % 4 == 0) ans++;
    }
    cout << ans << '\n';//1516
    return 0;
}
/*n=a*a-b*b=(a+b)(a-b)=x1*x2
x1=a+b x2=a-b
a=(x1+x2)/2
b=(x1-x2)/2
x1>x2
x1 x2 奇偶性相同
1.x1 x2 为奇数
x2=1 x1=n n为奇数必定可以
2.x1 x2 为偶数
n%4==0*/