#include<stdio.h>
#include<stdlib.h>
int visited[10];
int vv[10];
int a[10][10];
int q[10],front=-1,rear=-1;
int n;
void dfs(int i)
{
	printf("%d, ",vv[i]);
	visited[i]=1;
	for(int j=1;j<n;j++)
		if(a[i][j]==1&&visited[j]==0)
			dfs(j);
}
void pop()
{ int i=q[front];
 for(int j=0;j<n;j++)
   {
      if(a[i][j]==1&&visited[j]==0){
         q[++rear]=j;
         visited[j]=1;
       }
    }
  printf("%d, ",vv[i]);
  visited[q[i]]=1;
  if(front==rear)
     front=-1;
  else
  front++;
}
void bfs(int i)
{
  q[0]=i;
  front=rear=0;
 while(front!=-1)
{ 
    pop();
 }
}
int main()
{	
	for(int i=0;i<10;i++)
		visited[i]=0;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the value of the vertices : ");
	for(int i=0;i<n;i++)
		scanf("%d",&vv[i]);
	printf("Enter the links : ");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf(" Depth first search :");
	dfs(0);
	for(int i=0;i<10;i++)
		visited[i]=0;
	printf(" Breadth first search :");
	bfs(0);
	
}
	