#include<stdio.h>
void linearSearch(int arr[],int search,int n){
int temp=0;
for(int i=0;i<n;i++){
	if(arr[i]==search){
		temp=arr[i];
		printf("%d found in the %d position\n",search,i+1);
		break;
		}
			}
if(temp==0){
printf("item not found\n");
}
}

int sort(int arr[],int n)
{
 int temp;
 for (int i=0;i<n;i++)
 {
  for (int j=0;j<n-1;j++)
  {
   if (arr[j+1]<arr[j])
   {
   temp=arr[j];
   arr[j]=arr[j+1];
   arr[j+1]=temp;
  }
  }
 }
}
  
int binary_search(int sorted_list[],int element,int n)
{   
    int low=0,high;
    high=n-1; 
    int middle;
    while (low <= high)
    {
        middle = low + (high - low)/2;
        if (element > sorted_list[middle])
            low = middle + 1;
        else if (element < sorted_list[middle])
            high = middle - 1;
        else
            return middle;
    }
    return -1;
}    
void main()
{
int arr[50],searchTerm,n,opt,bin;
printf("enter the number of array elements:\n");
scanf("%d",&n);
printf("Enter the array\n");
for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}

printf("enter the number to be searched:\n");
scanf("%d",&searchTerm);
printf("\nSelect the option\n1:Linear Search\n2:Binary Search");
scanf("%d",&opt);
if (opt==1)
{
linearSearch(arr,searchTerm,n);
}else if(opt==2)
 {
  sort(arr,n);
  printf("sorted array:\n");
  for (int i=0;i<n;i++)
   {
    printf("%d \t",arr[i]);
    }
  printf("\n");
  bin=binary_search(arr,searchTerm,n);
  if (bin>=0){
  printf("%d found %d",searchTerm,bin+1);
  }else{
    printf("not found");
  }
 }else{ 
       printf("invalid click");
       }

}	
