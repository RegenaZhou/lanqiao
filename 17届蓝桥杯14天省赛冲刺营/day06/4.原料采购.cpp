/*
问题描述
小蓝负责一家工厂的原料采购。

工厂有一辆运货卡车，其容量为 m。

工厂附近的采购点都在同一条路的同一方向上，共 n 个，每个采购点与工厂的距离各不相同。其中，第 i 个采购点的价格为 ai ，库存为 bi ，距离为 ci 。

卡车每行驶一单位长度需要额外花费 o（返程没有花费，也可以认为 o 是行驶两单位长度的花费）。

请计算将卡车装满所需的最小花费，若无法装满则输出 −1.

输入格式
输入的第一行包含三个正整数 n,m,o，相邻整数之间使用一个空格分隔。

接下来 n 行，每行包含三个正整数 ai,bi,ci ，表示一个采购点，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数，表示装满卡车所需的最小花费。

样例输入
3 5 1
99 9 1
3 4 99
1 2 190

样例输出
201

评测用例规模与约定
对于 40% 的评测用例，n≤5000, m≤50000;

对于 60% 的评测用例，m≤10^5 ;

对于所有评测用例，1≤n≤10^5 , 1≤m,o≤10^9 , 1≤ai,bi,ci≤10^9 ，保证对于 i>1，一定有 ci−1<ci .*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll=long long;
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  ll n,m,o,ans=-1,money=0,cntv=0;
  cin>>n>>m>>o;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>> pq;
  for(int i=0;i<n;i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    pq.push({a,b});
    money+=a*b;
    cntv+=b;
    while(cntv>m)
    {
      pair<ll,ll> top=pq.top();
      pq.pop();
      if(cntv-top.second>=m)
      {
        cntv-=top.second;
        money-=top.first*top.second;
      }
      else
      {
        ll temp=cntv-m;
        cntv-=temp;
        money-=top.first*temp;
        pq.push({top.first,top.second-temp});
      }
    }
    if(cntv==m)
    {
      if(ans==-1 || money+c*o<ans)
      {
        ans=money+c*o;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
