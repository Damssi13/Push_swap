#include <stdio.h>

int main()
{
    int i;
    int *array;

    while(i < 10)
    {
        array[i] = i;
        i++;
    }
    for(int j = 0; j < 10;j++)
        printf("%d\n", array[j]);
}