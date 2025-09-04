/*
问题描述
暑假到了，小蓝在日记中写到：

漫长的暑假终于来临，我决定告别城市的喧嚣，踏上一段随心所欲的旅程，去寻找那份属于自己的宁静。

我选择了一个滨海小镇作为我此行的目的地。我将抵达小镇的这一天，作为我假期的第一天。以此为起点，我开始规划接下来的日子。为了能更深度地体验当地的风土人情，我打听到了几个特别的体验项目：

首先，有一趟沿海观光巴士。它的发车日很有规律：仅在假期的第 x 天、第 2x 天、第 3x 天……即天数是 x 的倍数时，才会发车。
其次，小镇附近的海域是海豚的活跃区。为了保护海洋生态，观鲸船也遵循着同样的规律：仅在假期的第 y 天、第 2y 天、第 3y 天……即天数是 y 的倍数时，才会出海。
最后，在小镇的中心广场，会举办一场盛大的集市。它仅在假期的第 z 天、第 2z 天、第 3z 天……即天数是 z 的倍数时，才会开放。
我的假期很长，所以我并不急于求成。我摊开日历，把所有这些能参加活动的日子——无论是搭乘观光巴士、出海观鲸还是闲逛集市——都圈了出来。
这些被圈出的日子，就是我的“活动日”。我决定，不追赶第一次机会，而是悠然地等待第 k 个“活动日”的到来…

请问，小蓝所等待的第 k 个“活动日”，是在他假期中的第几天呢？

输入格式
第一行包含一个整数 T（1≤T≤10^3），表示测试数据的组数。

接下来 T 行，每行包含一组测试数据，包括四个整数 x,y,z,k：

x（1≤x≤10^6）表示观光巴士发车的规律。
y（1≤y≤10^6）表示观鲸船出海的规律。
z（1≤z≤10^6）表示集市开放的规律。
k（1≤k≤10^9）表示小蓝等待的第k 个“活动日”。
输出格式
对每组测试数据，输出一个整数，表示第 k 个“活动日”对应的假期中的天数。

样例输入
2
3 4 5 3
2 3 6 5

样例输出
5
8

样例说明
用例 1：
观光巴士在第 3 天、第 6 天、……发车。
观鲸船在第 4 天、第 8 天、……出海。
集市在第 5 天、第 10 天、……开放。
活动日为：3,4,5,6,8,9,10,…，第 3 个活动日是 5。

用例 2：
观光巴士在第 2 天、第 4 天、……发车。
观鲸船在第 3 天、第 6 天、……出海。
集市在第 6 天、第 12 天、……开放。
活动日为： 2,3,4,6,8,9,10,12,…，第 5 个活动日是 8。*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll days(ll day,ll x,ll y,ll z)
{
  ll lcm_xy=x/gcd(x,y)*y;
  ll lcm_xz=x/gcd(x,z)*z;
  ll lcm_yz=y/gcd(y,z)*z;
  ll lcm_xyz=lcm_xy/gcd(lcm_xy,z)*z;
  ll result;
  result=day/x+day/y+day/z-day/lcm_xy-day/lcm_xz-day/lcm_yz+day/lcm_xyz;
  return result;
}
void solve()
{
  ll x,y,z,k,left=1,right;
  cin>>x>>y>>z>>k;
  right=x;
  if(y<right) right=y;
  if(z<right) right=z;
  right*=k;
  ll ans=right;
  while(left<=right)
  {
    ll mid=left+(right-left)/2;
    ll day=days(mid,x,y,z);
    if(day>=k)
    {
      ans=mid;
      right=mid-1;
    }
    else left=mid+1;
  }
  cout<<ans<<'\n';
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}


