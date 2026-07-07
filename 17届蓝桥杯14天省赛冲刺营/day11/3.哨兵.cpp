/*
问题描述
小蓝是一位国王，他的王国有 n 座城市，通过 n−1 条路来连通。他想在城市中部署三组哨兵 A、B、C，每组哨兵部署在一个城市里面，一个城市可以部署多组哨兵。
其中 A 到 B 的距离需要和 A 到 C 的距离相同。小蓝想知道 B 到 C 的距离最大是多少。

输入格式
输入的第一行包含一个正整数 n。

接下来 n−1 行，每行包含两个正整数 ui,vi，用一个空格分隔，表示城市 ui 和城市 vi 之间有一条路。

输出格式
输出一行包含一个整数表示答案。

样例输入
8
1 2
1 3
1 4
4 5
4 6
6 7
7 8

样例输出
4

样例说明
其中一种方案：A 部署在 5，B 部署在 3，C 部署在 7。

评测用例规模与约定
对于 20% 的评测用例，1⩽n⩽500；

对于所有评测用例，1⩽n⩽5000，1⩽ui,vi⩽n。*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e3+5;
const ll M=2e18+5;
ll n,m,k;
vector<ll>work[N];
ll d[N];
void bfs(ll st){//bfs
  queue<ll>sun;
  d[st]=0;
  sun.push(st);
  while(sun.size()){
    ll id=sun.front();
    sun.pop();
    for(auto&p:work[id]){
      if(d[id]+1<d[p]){
        d[p]=d[id]+1;
        sun.push(p);
      }
    }
  }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n-1;i++){
      ll u,v;cin>>u>>v;
      work[u].push_back(v);
      work[v].push_back(u);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){//枚举b或者c
      for(ll j=1;j<=n;j++)d[j]=M;//每次初始化
      bfs(i);
      ll s=0;
      for(ll j=1;j<=n;j++){
        if(d[j]%2)s=max(s,d[j]-1);//如果距离是奇数那么显然没有中间点可以当a，故减去1，即把c往前移一位
        else s=max(s,d[j]);//偶数中间那个当a即可
      }
      ans=max(s,ans);
    }
    cout<<ans;
    return 0;
}
