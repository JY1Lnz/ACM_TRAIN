#include <iostream>
using namespace std;

int a[] = {-1,6,1,2,7,9,3,4,5,10,8};

void swap(int *p,int *q)
{
    int t = *q;
    *q = *p;
    *p = t;
}

void Quick_Sort(int l,int r)
{
    if (l>r)
        return;
    int key = a[l];
    int x = l,y = r;
    while(x != y)
    {
        while(a[y] >= key&&x<y)
            y--;
        while(a[x] <= key&&x<y)
            x++;
        if (x<y)
            swap(&a[x],&a[y]);
    }
    swap(&a[l],&a[x]);
    Quick_Sort(l,x-1);
    Quick_Sort(x+1,r);
    return;
}

int main()
{
    Quick_Sort(1,10);
    for (int i = 1;i<=10;i++)
        cout<<a[i]<<' ';

    return 0;
}
