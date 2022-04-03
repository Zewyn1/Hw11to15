#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define max(x,y,z) ((x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z)))
#define min(x,y,z) ((x)<(y)?((x)<(z)?(x):(z)):((y)<(z)?(y):(z)))
#define setbit(mask,bit) (mask|=(1<<bit))
#define clearbit(mask,bit) (mask&=~(1<<bit))
#define checkbit(mask,bit) (mask&(1<<bit))
#define inversebit(mask,bit) (mask^=(1<<bit))
#define swap(a,b) {int tmp=a;a=b;b=tmp;}
int main(){
    int x,y,z;
    printf("Enter three integers: ");
    scanf("%d %d %d",&x,&y,&z);
    printf("The biggest of the three is %d\n",max(x,y,z));
    printf("The smallest of the three is %d\n",min(x,y,z));
    int mask=0;
    setbit(mask,0);
    clearbit(mask,0);
    checkbit(mask,0);
    inversebit(mask,0);
    swap(x,y);
    printf("The swapped values are %d and %d\n",x,y);
    return 0;
}
