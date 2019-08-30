#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*
 * Complete the function below.
 * Please store the size of the int array to be returned in result_size pointer. For example,
 * int a[3] = {1, 2, 3};
 * *result_size = 3;
 * return a;
 * 
 */
 int fun(void *ptr1,void *ptr2)
 {
     int *a=(int *)ptr1;
     int *b=(int *)ptr2;
     return *a-*b;
 }
 int upper_limit(int *scores,int n,int upper)
 {
     if(scores[n-1]<=upper)
     return n;
     int l=0,r=(n-1),mid=0;
     while(l<r)
     {
       mid=(l+r)/2;
       if(scores[mid]<=upper)
       l=mid+1;
       else  
       r=mid;
     }
     if(l==r)
     return l;
     else  
     return mid;
 }
 int lower_limit(int *scores,int n,int lower)
 {
     
     
     int l=0,r=(n),mid=0;
     while(l<r)
     {
       mid=(l+r)/2;
       if(scores[mid]<lower)
       l=mid+1;
       else  
       r=mid;
     }
     if(l==r)
     return l;
     else  
     return mid;
 }
 int* jobOffers(int scores_size, int* scores, int lower_size, int* lowerLimits, int upper_size, int* upperLimits, int* result_size) 
 {
    qsort(scores,scores_size,sizeof(int),fun);
    int *res=(int *)malloc(sizeof(int)*lower_size);
    int i;
    for(i=0;i<lower_size;i++)
    {
       int a=upper_limit(scores,scores_size,upperLimits[i]);
       int b=lower_limit(scores,scores_size,lowerLimits[i]);
       res[i]=(a-b);
    }
   *result_size=lower_size;
    return res;

}
int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int* res;
int res_size;
    int scores_size = 0;
    scanf("%d\n", &scores_size);

    int scores[scores_size];
    for(int i = 0; i < scores_size; i++) {
        int scores_item;
        scanf("%d", &scores_item);
        scores[i] = scores_item;
    }

    int lowerLimits_size = 0;
    scanf("%d\n", &lowerLimits_size);

    int lowerLimits[lowerLimits_size];
    for(int i = 0; i < lowerLimits_size; i++) {
        int lowerLimits_item;
        scanf("%d", &lowerLimits_item);
        lowerLimits[i] = lowerLimits_item;
    }

    int upperLimits_size = 0;
    scanf("%d\n", &upperLimits_size);

    int upperLimits[upperLimits_size];
    for(int i = 0; i < upperLimits_size; i++) {
        int upperLimits_item;
        scanf("%d", &upperLimits_item);
        upperLimits[i] = upperLimits_item;
    }

    res = jobOffers(scores_size, scores, lowerLimits_size, lowerLimits, upperLimits_size, upperLimits, &res_size);
    for (int res_i = 0; res_i < res_size; res_i++) {

        fprintf(f, "%d\n", res[res_i]);

    }


    fclose(f);
    return 0;
}
