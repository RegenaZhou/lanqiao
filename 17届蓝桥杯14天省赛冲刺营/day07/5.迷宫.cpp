/*
题目描述
本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。

X 星球的一处迷宫游乐场建在某个小山坡上。它是由 10×10 相互连通的小房间组成的。

房间的地板上写着一个很大的字母。我们假设玩家是面朝上坡的方向站立，则：

L 表示走到左边的房间，R 表示走到右边的房间，U 表示走到上坡方向的房间，D 表示走到下坡方向的房间。
X 星球的居民有点懒，不愿意费力思考。他们更喜欢玩运气类的游戏。这个游戏也是如此！

开始的时候，直升机把 100 名玩家放入一个个小房间内。玩家一定要按照地上的字母移动。

迷宫地图如下：

UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR

请你计算一下，最后，有多少玩家会走出迷宫，而不是在里边兜圈子？

如果你还没明白游戏规则，可以参看下面一个简化的 4x4 迷宫的解说图：

图片描述*/
#include <iostream>
#include <cstring>
using namespace std;
char arr[12][12]=
{{'0','0','0','0','0','0','0','0','0','0','0','0'},
  {'0','U','D','D','L','U','U','L','R','U','L','0'},
  {'0','U','U','R','L','L','L','R','R','R','U','0'},
  {'0','R','R','U','U','R','L','D','L','R','D','0'},
  {'0','R','U','D','D','D','D','U','U','U','U','0'},
  {'0','U','R','U','D','L','L','R','R','U','U','0'},
  {'0','D','U','R','L','R','L','D','L','R','L','0'},
  {'0','U','L','L','U','R','L','L','R','D','U','0'},
  {'0','R','D','L','U','L','L','R','D','D','D','0'},
  {'0','U','U','D','D','U','D','U','D','L','L','0'},
  {'0','U','L','R','D','L','U','U','R','R','R','0'},
  {'0','0','0','0','0','0','0','0','0','0','0','0'}};
int vis[12][12];
int dfs(int x,int y)
{
  if(vis[x][y]!=-1)
  {
    return vis[x][y];
  }
  if(arr[x][y]=='U')
  {
    if(arr[x-1][y]=='0')
    {
      vis[x][y]=1;
    }
    else if(arr[x-1][y]=='D')
    {
      vis[x][y]=0;
    }
    else
    {
      vis[x][y]=dfs(x-1,y);
    }
  }
  else if(arr[x][y]=='D')
  {
    if(arr[x+1][y]=='0')
    {
      vis[x][y]=1;
    }
    else if(arr[x+1][y]=='U')
    {
      vis[x][y]=0;
    }
    else
    {
      vis[x][y]=dfs(x+1,y);
    }
  }
  else if(arr[x][y]=='L')
  {
    if(arr[x][y-1]=='0')
    {
      vis[x][y]=1;
    }
    else if(arr[x][y-1]=='R')
    {
      vis[x][y]=0;
    }
    else
    {
      vis[x][y]=dfs(x,y-1);
    }
  }
  else if(arr[x][y]=='R')
  {
    if(arr[x][y+1]=='0')
    {
      vis[x][y]=1;
    }
    else if(arr[x][y+1]=='L')
    {
      vis[x][y]=0;
    }
    else
    {
      vis[x][y]=dfs(x,y+1);
    }
  }
  return vis[x][y];
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  memset(vis,-1,sizeof(vis));
  int ans=0;
  for(int i=1;i<=10;i++)
  {
    for(int j=1;j<=10;j++)
    {
      ans+=dfs(i,j);
    }
  }
  cout<<ans<<'\n';//31
  return 0;
}
