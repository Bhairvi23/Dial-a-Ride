void dijkstras(int arr[5][5], int n, int s)
{
    int i, j, start;
    start=s;
    int visited[n]={0};
    long long int weight[n]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    weight[s]=0;
    visited[s]=1;
    for(int index=0;index<n-1;index++)
    {
       for(i=0;i<n;i++)
       {
           if(arr[s][i]+weight[s]<weight[i]&&visited[i]==0&&arr[s][i]>0)
           {
               weight[i]=arr[s][i]+weight[s];
           }
       }
       int min=INT_MAX, mini;
       for(i=0;i<n;i++)
       {
          if(weight[i]<min&&visited[i]==0)
          {
              min=weight[i];
              mini=i;
          }
        }
        s=mini;
        visited[s]=1;
    }
    for(i=0;i<n;i++)
    {
        arr[start][i]=weight[i];
    }
}
