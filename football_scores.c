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
 * Complete the 'counts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY teamA
 *  2. INTEGER_ARRAY teamB
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
 int fun(void *ptr1,void *ptr2)
 {
     int *a=(int *)ptr1;
     int *b=(int *)ptr2;
     return *a-*b;
 }
int* counts(int teamA_count, int* teamA, int teamB_count, int* teamB, int* result_count) 
{
   qsort(teamA,teamA_count,sizeof(int),fun);
int *res=(int *)malloc(sizeof(int)*teamB_count);
int i,j;
for(i=0;i<teamB_count;i++)
{
    if(teamA[teamA_count-1]<=teamB[i])
    res[i]= teamA_count;
    else 
    {
    int l=0,r=(teamA_count-1);
    int mid=0;
    while(l<r)
    {
        mid=(l+r)/2;
        if(teamA[mid]<=teamB[i])
        l=mid+1;
        else  
        r=mid;
    }
    if(l==r)
    res[i]=(l);
    else 
    res[i]=mid+1;
}
}
*result_count=teamB_count;
return res;
}

int main()