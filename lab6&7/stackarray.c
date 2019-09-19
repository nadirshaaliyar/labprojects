#include<stdio.h>
#include<stdlib.h>
int stack[100],ch,n,top,x,i;
void push(void){
  if (top>n-1){
     printf("stack overflow");
   }else{
     printf("Enter the value to be pushed");
     scanf("%d",&x);
     top++;
     stack[top]=x;
   }
 }
     
void pop(void){
 if(top<0){
   printf("stack is underflow");
  }else{
    printf("The popped element is %d\t",stack[top]);
    top--;
   }
}

void display(void){
  if(top>0){
   for(i=top;i<=0;i--){
      printf("\n%d",stack[i]);
    }
 } else{
   printf("stack is empty"); 
 }
} 
void main()
{
 top=-1;
 while(1)
 {
  printf("\nStack Menu");
  printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.exit");
  printf("\nEnter the choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:push();
          break;
   case 2:pop();
          break;
   case 3:display();
          break;
   case 4:exit(0);
   default:printf("\nInvalid Choice");
  }
 }
}
