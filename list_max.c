long listMax(int n, int rows, int cols, int** A) 
{
  long int * arr=(long int *)calloc((n+2),sizeof(long int));
  int i=0,j=0;
  for(i=0;i<rows;i++)
  {
      int l=0,r=0,val=0;
      for(j=0;j<cols;j++)
      {
          if(j==0)l=A[i][j];
          if(j==1)r=A[i][j]+1;
          if(j==2)val=A[i][j];
      }
      arr[l]+=val;
      arr[r]-=val;
  }
 long int prev=0,max=0;
  for(i=0;i<n+1;i++)
  {
      printf("%d\n",arr[i]);
    arr[i]+=prev;
    prev=arr[i];
    max=max>arr[i] ? max : arr[i];
  }
  return max;
}
