#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);


/*
 * Complete the 'countPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. INTEGER k
 */
int fun(void *ptr,void *ptr2)
{
    int *a=(int *)ptr;
    int *b=(int *)ptr2;
    return *a-*b;
}
int countPairs(int numbers_count, int* numbers, int k) {
    int i,j;
    qsort(numbers,numbers_count,sizeof(int),fun);
    for(i=0;i<numbers_count;i++)
    {
        if(numbers[i]!=-1)
        {
        for(j=i+1;j<numbers_count;j++)
        {
           if(numbers[i]==numbers[j])
           numbers[j]=-1; 
        }
        }
    }
    int count=0;
    for(i=0;i<numbers_count;i++)
    {
        if(numbers[i]!=-1)
        {
        for(j=(i+1);j<numbers_count;j++)
        {
            if((numbers[i]+k)==numbers[j])
            count++;
        }
        }
    }
    return count;

}

int main()