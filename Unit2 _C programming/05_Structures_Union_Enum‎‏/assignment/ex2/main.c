#include "stdio.h"
#include "stdlib.h"

struct SDistance{
    int feet;
    float inch;
};

struct SDistance read(void);
struct SDistance add(struct SDistance , struct SDistance);
int main(){
    struct SDistance dist1;
    struct SDistance dist2;
    
    printf("Enter information for 1st distance\n");
    dist1 = read();
    
    printf("\nEnter information for 2nd distance\n");
    dist2 = read();
    
    struct SDistance result = add(dist1, dist2 );

    printf("\nSum of distances = %d'-%.1f\"\n",result.feet, result.inch);
    system("pause");
    return 0;
}

struct SDistance read(void){
    struct SDistance dist;
    printf("Enter feet: ");
    scanf("%d",&dist.feet);

    printf("Enter inch: ");
    scanf("%f",&dist.inch);
    return dist;
}

struct SDistance add(struct SDistance dist1, struct SDistance dist2){
    struct SDistance res;
    res.feet = dist1.feet + dist2.feet;
    res.inch = dist1.inch + dist2.inch;
    /*1 feet = 12 inch*/
    if(res.inch > 12.0f){
        res.inch -= 12.0;
        res.feet++;
    }
    return res;
}
