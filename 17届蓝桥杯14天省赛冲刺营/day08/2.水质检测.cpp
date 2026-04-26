/*
问题描述
小明需要在一条 2×n 的河床上铺设水质检测器。在他铺设之前，河床上已经存在一些检测器。如果两个检测器上下或左右相邻，那么这两个检测器就是互相连通的。

连通具有传递性，即如果 A 和 B 连通，B 和 C 连通，那么 A 和 C 也连通。现在他需要在河床上增加铺设一些检测器，使得所有检测器都互相连通。他想知道最少需要增加铺设多少个检测器？

输入格式
输入共两行，表示一个 2×n 的河床。

每行一个长度为 n 的字符串，仅包含 # 和 ., 其中 # 表示已经存在的检测器，. 表示空白。

输出格式
输出共 1 行，一个整数，表示最少需要增加的检测器数量。

样例输入
.##.....#
.#.#.#...

样例输出
5

样例说明
其中一种方案： ###....# .#.######

增加了 5 个检测器。

评测用例规模与约定
对于 100% 的评测用例，保证 n≤1000000。*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s1,s2;
  cin>>s1>>s2;
  int id1=0,id2=s1.size()-1,n=s1.size();
  while(id1<n && s1[id1]=='.' && s2[id1]=='.')
  {
    id1++;
  }
  if(id1==n)
  {
    cout<<"0\n";
    return 0;
  }
  
  while(id2>=0 && s1[id2]=='.' && s2[id2]=='.')
  {
    id2--;
  }
  
  s1=s1.substr(id1,id2-id1+1);
  s2=s2.substr(id1,id2-id1+1);

  int choice=0;
  int ans=0;
  if(s1[0]=='#' && s2[0]=='.') choice=1;
  else if(s1[0]=='.' && s2[0]=='#') choice=2;
  for(int i=1;i<s1.size();i++)
  {
    if(s1[i]=='#' && s2[i]=='#')
    {
      choice=0;
    }
    else if(s1[i]=='#' && s2[i]=='.')
    {
      if(choice==2)
      {
        ans++;
        choice=0;
      }
      else choice=1;
    }
    else if(s1[i]=='.' && s2[i]=='#')
    {
      if(choice==1)
      {
        ans++;
        choice=0;
      }
      else choice=2;
    }
    else if(s1[i]=='.' && s2[i]=='.')
    {
      ans++;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
