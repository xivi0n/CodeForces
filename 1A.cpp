//math

#include <stdio.h>
#include <math.h>

using namespace std;

void calc(unsigned int x,unsigned int y,int k)
{
    if ((x!=0))
    {
        unsigned int pom = x%10*y+k;
        calc(x/10,y,pom/10);
        printf("%d",pom%10);
    } 
    else if (k!=0)
    {
        printf("%d",k);
    }
}

int main()
{
    unsigned int n,m,a,x,y;
    scanf("%d %d %d",&n,&m,&a);
    x = n/a + (n % a!=0);
    y = m/a + (m % a!=0);
    calc(x,y,0);
    return 0;
}