#include<stdio.h>
int main(){
  int a[10],n,i,j,temp,min,place;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  printf("\nEnter elements:\n");
  for (i=0;i<n;i++)scanf("%d",&a[i]);
  printf("\nSorted Array: ");
  for (i=0;i<n-1;i++){
    min=a[i];
    place=i;
    for (j=i+1;j<n;j++){
      if (a[j]<min){
	min=a[j];
	place=j;
      }
    }
    temp=a[i];
    a[i]=min;
    a[place]=temp;
  }
  for (i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
