#include <stdio.h>

int main()
{
 int sum=0,n,i,x;
 (void)scanf("%d", &n);
 for(i=1;i<=n;i++)
 {
    (void)scanf("%d", &x);
    sum+=x*(-1);
 }
printf("%d", sum);
    return 0;
}
