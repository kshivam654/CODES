#include<stdio.h>
int Cellcompete(int *Cells, int day)
{
      int i,j;
      for(i=0;i<=day;i++)
      {
                      Cells[-1]=0;
                      Cells[8]=0;
                      int u[8], ii;
                      for(ii=-1;ii<9;ii++)
                      {
                                      u[ii]=Cells[ii];
                      }
                      for(j=0;j<8;j++)
                      {
                                      if(u[j-1]==u[j+1])
                                      {
                                                      Cells[j]=0;
                                      }
                                      else
                                   Cells[j]=1;
                      }
      }
      for(i=0;i<8;i++)
        printf("%d",Cells[i]);
}
int main()
{
      int cells[8],n,i;
      for(i=0;i<8;i++)
        scanf("%d",&cells[i]);
      scanf("%d",&n);
      Cellcompete(cells,n);
      return 0;
}