#include <stdio.h>
#include <math.h>

int main()
{
 int sum=0,n,i,x;
 (void)scanf("%d", &n);
 for(i=1;i<=n;i++)
 {
      (void)scanf("%d", &x);
      if(i%2!=0)
      {
        sum+=pow((double)x,2);
      
      }
 }
printf("%d", sum);
    return 0;
}
