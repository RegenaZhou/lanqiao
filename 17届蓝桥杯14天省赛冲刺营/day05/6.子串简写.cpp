/*
问题描述
程序猿圈子里正在流行一种很新的简写方法：对于一个字符串，只保留首尾字符，将首尾字符之间的所有字符用这部分的长度代替。
例如 internation-alization 简写成 i18n，Kubernetes （注意连字符不是字符串的一部分）简写成 K8s, Lanqiao 简写成 L5o 等。

在本题中，我们规定长度大于等于 K 的字符串都可以采用这种简写方法（长度小于 K 的字符串不配使用这种简写）。

给定一个字符串 S 和两个字符 c1 和 c2 ，请你计算 S 有多少个以 c1 开头 c2 结尾的子串可以采用这种简写？

输入格式
第一行包含一个整数 K。

第二行包含一个字符串 S 和两个字符 c1 和 c2 。

输出格式
一个整数代表答案。

样例输入
4
abababdb a b

样例输出
6

样例说明
符合条件的子串如下所示，中括号内是该子串：
[abab]abdb
[ababab]db
[abababdb]
ab[abab]db
ab[ababdb]
abab[abdb]

评测用例规模与约定
对于 20 的数据，2≤K≤∣S∣≤10000。

对于 100 的数据，2≤K≤∣S∣≤5×10^5 。S 只包含小写字母。 c1 和 c2 都是小写字母。

∣S∣ 代表字符串 S 的长度。*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    string s;
    char c1, c2;

    cin >> k;
    cin >> s >> c1 >> c2;
    vector<int> a, b;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c1)
        {
            a.push_back(i);
        }
        if (s[i] == c2)
        {
            b.push_back(i);
        }
    }

    ll ans = 0;
    int lena = a.size(), lenb = b.size();
    int i = 0, j = 0;
    while (i < lena)
    {
        while (b[j] - a[i] < k - 1 && j < lenb)
        {
            j++;
        }
        ans += lenb - j;
        i++;
    }

    cout << ans << '\n';

    return 0;
}