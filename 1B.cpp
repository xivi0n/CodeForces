//implementation
//math

#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int isChar(char k)
{
    if ((int)k<58 && ((int)k>47)) return 0;
    return 1;
}

void print(unsigned int k)
{
    if (k!=0)
    {
        print((k-1)/26);
        printf("%c",65+(k-1)%26);
    }
}

int main()
{
    int n,i,j;
    unsigned int k;
    static char str[16];
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%s",str);
        k = 0;
        for(j=0;j<strlen(str)-1;++j)
        {
            if ((isChar(str[j])) && !(isChar(str[j+1])))
            {
                ++k;
            }
        }
        if (k==1)
        {
            k = 0;
            for(j=0;isChar(str[j]);++j) k = 26*k + (int)str[j]-64;
            printf("R");
            for(j=j;j<strlen(str);++j) printf("%c",str[j]);
            printf("C%d\n",k);
        }
        else
        {
            char pom[16];
            k = 0;
            for(j=1;!isChar(str[j]);++j) pom[j-1] = str[j];
            pom[j-1] = '\0';
            k = stoi(pom);
            unsigned int z=0;
            for(j=j+1;j<strlen(str);++j) pom[z++] = str[j];
            pom[z] = '\0';
            z = stoi(pom);
            print(z);
            printf("%d\n",k);
        }
    }
    return 0;
}