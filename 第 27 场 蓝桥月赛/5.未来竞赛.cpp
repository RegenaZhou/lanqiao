#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
const int mood = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, d;
    ll ans = 1;
    cin >> n >> d;
    vector<int> sz(n + 1);
    map<int, vector<int>> mp1;
    map<int, ll> mp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> sz[i];
        mp1[sz[i]].push_back(i);
        mp2[sz[i]] += 1;//监控1人
    }
    for (const auto& pair : mp1)
    {
        ll key = pair.first;
        mp2[key]++;//监控0人
        const vector<int>& values = pair.second;
        for (int i = 0; i < values.size(); i++)
        {
            mp2[key] += upper_bound(values.begin(), values.end(), values[i] + d) - values.begin() - i - 1;
        }
    }
    for (const auto& pair : mp2)
    {
        ans = ans * pair.second % mood;
    }
    ans--;//不能不选
    cout << ans << '\n';
    return 0;
}