#include<stdio.h>
int main(){
	int a[10],n,i,j,temp;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements:\n");
	for (i=0;i<n;i++)scanf("%d",&a[i]);
	printf("\nSorted Array: ");
	for (i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if (a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}		
		}
	}
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
