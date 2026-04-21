/*
问题描述
"在五子棋的对弈中，友谊的小船说翻就翻？" 不！对小蓝和小桥来说，五子棋不仅是棋盘上的较量，更是心与心之间的沟通。这两位挚友秉承着"友谊第一，比赛第二"的宗旨，
决定在一块 5×5 的棋盘上，用黑白两色的棋子来决出胜负。但他们又都不忍心让对方失落，于是决定用一场和棋（平局）作为彼此友谊的见证。

比赛遵循以下规则：

棋盘规模：比赛在一个 5×5 的方格棋盘上进行，共有 25 个格子供下棋使用。
棋子类型：两种棋子，黑棋与白棋，代表双方。小蓝持白棋，小桥持黑棋。
先手规则：白棋（小蓝）具有先手优势，即在棋盘空白时率先落子（下棋）。
轮流落子：玩家们交替在棋盘上放置各自的棋子，每次仅放置一枚。
胜利条件：率先在横线、竖线或斜线上形成连续的五个同色棋子的一方获胜。
平局条件：当所有 25 个棋盘格都被下满棋子，而未决出胜负时，游戏以平局告终。
在这一设定下，小蓝和小桥想知道，有多少种不同的棋局情况，既确保棋盘下满又保证比赛结果为平局。

答案提交
这是一道结果填空题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。*/
#include <iostream>
using namespace std;
int arr[6][6] = { 0 }; // 1代表白棋，0代表黑棋
int white = 0, black = 0;
int cont = 0;
bool check()
{
    for (int j = 1; j <= 5; j++)
    {
        int sum = 0;
        for (int i = 1; i <= 5; i++)
        {
            sum += arr[i][j];
        }
        if (sum == 5 || sum == 0)
        {
            return false;
        }
    }

    int d1 = arr[1][1] + arr[2][2] + arr[3][3] + arr[4][4] + arr[5][5];
    if (d1 == 5 || d1 == 0)
    {
        return false;
    }

    int d2 = arr[1][5] + arr[2][4] + arr[3][3] + arr[4][2] + arr[5][1];
    if (d2 == 5 || d2 == 0)
    {
        return false;
    }

    return true;
}

void dfs(int x)
{
    if (white > 13 || black > 12)
    {
        return;
    }

    int hang = (x - 1) / 5 + 1;
    int lie = (x - 1) % 5 + 1;

    if (x > 1 && (x - 1) % 5 == 0)
    {
        int prev = (x - 1) / 5;
        int sum = 0;
        for (int j = 1; j <= 5; j++)
        {
            sum += arr[prev][j];
        }
        if (sum == 5 || sum == 0)
        {
            return;
        }
    }

    if (x == 26)
    {
        if (check())
        {
            cont++;
        }
        return;
    }

    arr[hang][lie] = 1;
    white++;
    dfs(x + 1);
    white--;

    arr[hang][lie] = 0;
    black++;
    dfs(x + 1);
    black--;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    dfs(1);
    cout << cont << endl;
    return 0;
}
