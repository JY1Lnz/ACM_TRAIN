#include<bits/stdc++.h>
using namespace std;
//�ⷨ2��Դ���·����
//����������������ķ����н��

int main()
{
    //ifstream cin ("test.in");
    int n,m;
    int x,y,d;
    cin>>n>>m;
    int data[n+1][n+1] = {0};
    int book[n+1] = {0};
    int num = 0;
    for (int i = 1;i<=n;i++)
        for (int j = 1;j<=n;j++)
        {
            if (i == j)
                data[i][j] = 0;
            else
                data[i][j] = 9999;
        }

    for (int i = 0;i<m;i++)
    {
        cin>>x>>y>>d;
        data[x][y] = d;
        data[y][x] = d;
    }

    int dis[n+1];
    for (int i = 1;i<=n;i++)
        dis[i] = data[1][i];

    book[1] = 1;
    num++;
    int sum = 0;
    while(num<n)
    {
        int small = 9999;
        int i,j;
        for (i = 1;i<=n;i++)
            if (book[i] == 0&&dis[i]<small)
            {
                small = dis[i];
                j = i;
            }
        //cout<<j<<endl;
        book[j] = 1;
        num++;
        sum += dis[j];
        //cout<<sum<<endl;
        for (int k = 1;k<=n;k++)//ÿ��dis�����ֵ����ÿ�������ڵ㵽
        {                       //�������Сֵ��ÿ����������һ���������Сֵ
            if (book[k] == 0&&dis[k]>data[j][k])
                dis[k] = data[j][k];
        }
    }
    cout<<sum<<endl;

    return 0;
}
