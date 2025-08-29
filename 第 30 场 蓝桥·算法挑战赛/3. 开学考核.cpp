/*
问题描述
蓝桥学院的算法开学考核正在进行中。作为专门考察算法基本功的测试题，新生小明被分配了一个包含 N 个整数的数组
A：[A₁,A₂,...,AN]。

小明必须进行正好 K 次减法操作。在每次操作中，小明可以选择任意一个元素 Ai ，将其改为 Ai−X（X 为一个正整数）。
操作的元素 i 不必相同。

小明希望通过这些操作，使数组中最大元素的最终值尽可能小。请帮助小明计算这个最小可能的数组最大值。

输入格式
输入的第一行包含三个正整数 N,K,X(1≤N≤10^5 ,1≤K,X≤10^9 )，用空格分隔。

第二行包含 N 个正整数 A1,A2,…,AN(0≤Ai≤10^9)，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数，表示通过正好 K 次减法操作后，数组最大值的最小可能值。

样例输入 1
3 2 1
5 3 4

样例输出 1
4

样例说明 1
对最大元素 5 减 1 两次，数组变为 [3,3,4]，最大值为 4。

样例输入 2
2 2 2
2 2

样例输出 2
0

样例说明2
两个元素均操作一次减去 2，数组变为 [0,0]，最大值为 0。*/
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, x;
    ll num;
    cin >> n >> k >> x;
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        st.insert(num);
    }
    while (k--)
    {
        auto last = prev(st.end());
        num = *last;
        st.erase(last);
        num -= x;
        st.insert(num);
    }
    cout << *prev(st.end()) << '\n';
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> sz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sz[i];
    }
    ll left = -1e18, right = *max_element(sz.begin(), sz.end());
    ll ans = right;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll zczs = 0; //总操作数
        for (int i = 0; i < n; i++)
        {
            if (sz[i] > mid)
            {
                zczs += (sz[i] - mid + x - 1) / x;
                if (zczs > k) break;
            }
        }
        if (zczs <= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans << '\n';
    return 0;

}
