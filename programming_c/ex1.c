#include <stdio.h>

struct A
{
    int x; int y; int z[10]; int v;
};

struct B
{
    int key; struct A data;
};

struct C
{
    int w; struct B arr[5];
};


struct A a =
{
    .x = 4, .z = {[2] = 5, [3] = 6}
};


int main(){
    printf("%d %d %d %d\n", a.x, a.y, a.z[0], a.z[3]);

    int w, x, y, z;
    int i = 3; int j = 4;
    {
        int i = 5;
        w = i + j;
    }
    x = i + j;
    {
        int j = 6; 
        i = 7;
        y = i + j;
    }
    
    z = i + j;  //i = 7, j = 4
    printf("%d %d %d %d\n", w, x, y, z);  // 9 7 13 11
}