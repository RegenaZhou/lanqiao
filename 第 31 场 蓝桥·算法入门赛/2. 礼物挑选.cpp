/*
��������
������ڼ������٣�С�����ڵ����ų�����ư�ٰ���һ�����ֵ���Ʒ��ѡ����ܹ��� N ����Ʒ�ɹ���ѡ�����е� i ����Ʒ�ļ�ֵΪ Ai��

С����������ͨ����ǩ�����������ѡ�ʸ񣬵������ֻ��ѡ�� X ����Ʒ������Щ��Ʒ�ļ�ֵ������ȫ��ͬ�����ʣ�С����ѡ������Ʒ�ܼ�ֵ����Ƕ��٣�

�����ʽ
��һ�а����������� N,X(1��X��N��10^5)���ֱ��ʾ��Ʒ����������ѡ������

�ڶ��а��� N ������ A1,A2,��,AN(1��Ai��N)����ʾÿ����Ʒ�ļ�ֵ��

�����ʽ
���һ����������ʾС����ѡ������Ʒ�ܼ�ֵ�����ֵ��

��������
5 2
1 2 2 3 4

�������
4*/
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x;
    ll ans = 0;
    cin >> n >> x;
    map<int, int> sz;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        sz[a]++;
    }
    for (auto const& pair : sz)
    {
        ll yx = 0;
        if (pair.second >= x) yx = pair.first * x;
        else yx = pair.first * pair.second;
        ans = max(ans, yx);
    }
    cout << ans << '\n';
    return 0;
}