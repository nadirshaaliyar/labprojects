#include<stdio.h>
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

void binary_search(int list[], int lo, int hi, int key)

{
    int mid;
    if (lo > hi)
    {
      printf("Key not found\n");
      return;
    }

    mid =(lo + hi) / 2;
    if (list[mid] == key)
    {
     printf("%d found in %d\n",key,mid+1);
    }
    else if (list[mid] > key)
    {
     binary_search(list,lo,mid - 1,key);
    }
    else if (list[mid]<key)
    {
     binary_search(list,mid + 1,hi,key);
    }
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
sort(arr,n);
  printf("sorted array:\n");
  for (int i=0;i<n;i++)
   {
    printf("%d \t",arr[i]);
    }
  printf("\n");
  binary_search(arr,0,n,searchTerm);

}
