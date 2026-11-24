/*
问题描述
小蓝用 AI 生成了 N 张图片，并按顺序放入相册。每张图片属于以下三种类型之一：A 表示写实图，B 表示卡通图，S 表示过渡图。

小蓝希望相册中的写实图与卡通图不会直接相邻。如果这两类图片之间有过渡图，则不受限制。也就是说，相册中不能出现相邻的 AB 或 BA，其他相邻类型均允许。

为了整理相册，小蓝可以删除一些图片，但不能改变剩余图片的相对顺序。第 i 张图片的分数为 Ci，删除这张图片会损失 Ci 分。
删除后，原本不相邻的图片可能变得相邻；允许删除全部图片，此时也符合要求。

整理过程中，小蓝还会替换相册中的图片。每次替换时，他会指定位置 P，将该位置改为一张类型为 X、分数为 W 的新图片。相册会保留每次替换后的结果。

现在，请你帮助小蓝，在每次替换后，计算使相册符合要求至少需要损失多少分。

每次只计算所需的最小损失，不实际删除图片。因此，后续替换时相册仍有 N 张图片，位置编号始终为 1,2,…,N。

输入格式
第一行包含两个整数 N,Q（1≤N,Q≤5×10^4），分别表示图片数量和替换次数。

第二行包含一个长度为 N 的字符串，依次表示相册中各图片的类型。字符串只包含 A、B、S。

第三行包含 N 个整数 C1,C2,…,CN（1≤Ci≤10^9），其中 Ci 表示第 i 张图片的分数。

接下来 Q 行，每行包含一个整数 P、一个字符 X 和一个整数 W（1≤P≤N，1≤W≤10^9，X 为 A、B、S 之一），表示将第 P 张图片替换为类型为 X、分数为 W 的图片。

输出格式
对于每次替换，输出一行一个整数，表示使当前相册符合要求所需的最小损失。

样例输入
5 3
ABSAB
5 2 7 4 6
3 A 7
2 S 2
5 S 6

样例输出
8
6
0

样例说明
三次替换后，相册的整理方案如下：

第几次替换	替换后的类型	  一种最优删除方案				      最小损失
1			    ABAAB			    删除第 2,5 张图片，剩下 AAA		2+6=8
2		    	ASAAB		     	删除第 5 张图片，剩下 ASAA		6
3		    	ASAAS			    无需删除						          0
删除方案不会影响下一次替换。例如，第一次计算中删去的图片，在第二次替换时仍保留在相册中。*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 使用足够小的负数表示不可达

// 定义 4x4 矩阵节点
struct Node {
    long long M[4][4];
    Node() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                M[i][j] = -INF;
    }
};

// 广义矩阵乘法合并
Node merge(const Node& A, const Node& B) {
    Node C;
    for (int i = 0; i < 4; ++i) {
        for (int k = 0; k < 4; ++k) {
            if (A.M[i][k] == -INF) continue;
            for (int j = 0; j < 4; ++j) {
                if (B.M[k][j] == -INF) continue;
                C.M[i][j] = max(C.M[i][j], A.M[i][k] + B.M[k][j]);
            }
        }
    }
    return C;
}

const int MAXN = 50005;
Node tree[MAXN * 4];
char types[MAXN];
long long scores[MAXN];

// 根据单张图片生成转移矩阵
Node get_node(char t, long long v) {
    Node node;
    int type_t;
    if (t == 'A') type_t = 0;
    else if (t == 'B') type_t = 1;
    else type_t = 2; // 'S'
    
    for (int u = 0; u < 4; ++u) {
        node.M[u][u] = 0; // 选择不保留该图，状态不变，加分 0
        
        // 选择保留该图
        bool ok = true;
        if ((u == 0 && type_t == 1) || (u == 1 && type_t == 0)) {
            ok = false; // 不能出现相邻的 AB 或 BA
        }
        if (ok) {
            node.M[u][type_t] = max(node.M[u][type_t], v);
        }
    }
    return node;
}

// 建树
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = get_node(types[l], scores[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

// 单点修改
void update(int node, int l, int r, int idx, char t, long long v) {
    if (l == r) {
        tree[node] = get_node(t, v);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, t, v);
    else update(node * 2 + 1, mid + 1, r, idx, t, v);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    string s;
    cin >> s;
    long long total_sum = 0;
    
    for (int i = 1; i <= n; ++i) {
        types[i] = s[i - 1];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> scores[i];
        total_sum += scores[i];
    }
    
    build(1, 1, n);
    
    for (int i = 0; i < q; ++i) {
        int p;
        char x;
        long long w;
        cin >> p >> x >> w;
        
        // 更新总分
        total_sum = total_sum - scores[p] + w;
        scores[p] = w;
        
        // 更新线段树
        update(1, 1, n, p, x, w);
        
        // 在根节点中查找从状态 3（空）出发的最大保留分数
        long long max_score = 0; 
        for (int j = 0; j < 4; ++j) {
            max_score = max(max_score, tree[1].M[3][j]);
        }
        
        // 最小损失 = 总分 - 最大保留分数
        cout << total_sum - max_score << "\n";
    }
    
    return 0;
}
