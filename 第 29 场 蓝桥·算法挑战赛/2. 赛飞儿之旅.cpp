/*
问题描述
失落的盗寇之都多洛斯，三百侠盗纵情游戏，横行无忌。
捷足的贼星赛法利娅，戏弄「诡计」火种的黄金裔，奔走吧。
愿你的谎言随风同行，吹遍此世大地

有一个环形跑道上，跑道被分为了n块区域，按照顺时针将区域编号为1,2,⋯,n，n 号区域与1号区域相邻。

赛飞儿初始在s号区域，他希望去往e号区域，但麻烦的是他只能顺时针向前移动。为了尽快到达目标区域，他还可以在开始移动前至多使用一次 "瞬间移动"。

"瞬间移动"：将当前位置向前移动d格区域或向后移动d格区域。

每次移动一个区域将会消耗一格体力，请问赛飞儿最少要花费多少体力可以到达目标区域。

注意："瞬间移动" 不会消耗赛飞儿体力。

输入格式
输入一行4个整数n,s,e,d(1≤n≤10^9 ,1≤s,e≤n,0≤d≤n)。

输出格式
输入一个整数表示答案。

样例输入1
5 1 5 2

样例输出
1

样例输入2
5 4 5 2

样例输出2
1

样例说明
对于样例1，可以使用 "瞬间移动" 至4号区域再移动。

对于样例2，不使用 "瞬间移动" 更好。*/
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, s, e, d;
    cin >> n >> s >> e >> d;

    // 不使用瞬间移动：直接顺时针移动的距离
    ll direct = (e - s + n) % n;

    // 使用向前瞬间移动：s1 = (s + d) mod n（转换为1-indexed）
    ll s1 = (s + d) % n;
    ll move_forward = (e - s1 + n) % n;

    // 使用向后瞬间移动：s2 = (s - d) mod n（转换为1-indexed）
    ll s2 = (s - d + n) % n;
    ll move_backward = (e - s2 + n) % n;

    // 取三种情况的最小值
    ll ans = min({ direct, move_forward, move_backward });
    cout << ans << '\n';
    return 0;
}