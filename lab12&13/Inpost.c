#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 50
int Res=0;
struct Stack{
 char a;
 struct Stack*link;
 };
struct Stack2{
 int num;
 struct Stack2*link;
};
struct Stack*top=NULL;
struct Stack2*top1=NULL;
char Q[MAX],P[MAX],A[MAX] ;
void Insert(char x)
{
 struct Stack*newnode;
 newnode=(struct Stack*)malloc(sizeof(struct Stack));
 newnode->a=x;
 if(top==NULL)
 {
  
  newnode->link=NULL;
 }
 else
 {
  newnode->link=top;
 
 }
  top=newnode;
}
int pop()
{
 char c;
 struct Stack*temp;
 if(top==NULL)
 {
   return '0';
 }
 else
 {
  c=top->a;
  temp=top;
  top=top->link;
  free(temp);
  return c;
 }
}
int prec(char c)
{
  if(c=='+'||c=='-')
    return 1;
  else if(c=='*'||c=='/')
    return 2;
  else if(c=='^')
    return 3;
}
void Post_fix()
{
  int n,j=0;
 char x;
 n=strlen(Q);
 Insert('(');
 Q[n]=')';
 for(int i=0;i<=n;++i)
 {
   if(isalpha(Q[i]))
       {
         P[j]=Q[i];
         j++;
        }
     
  else
   {
     if(prec(top->a)>prec(Q[i])&&top->a!='(')
       {
        while(prec(top->a)>prec(Q[i]))
        {
	 x=pop();
	 if(x=='0'||x=='(')
	   break;
	 else
	   {
	   P[j]=x;
	   j++;
	   }
        }
        Insert(Q[i]);
       }
   
     else if(Q[i]==')')
       {
        while(1)
	 {
	  x=pop();
	  if(x=='0'||x=='(')
	    break;
	  else
	   {
	   P[j]=x;
	   j++;
	   }
	 }
       }
     else
       Insert(Q[i]);
    
   }
 
 }
 P[j]='\0';
 while(x!='0')
   x=pop();
 }
int operation(char x,char y,char z)
{
  int R;
  switch(z)
    {
    case '+':R=y+x;break;
    case'-':R=y-x;break;
    case'*':R=y*x;break;
    case'/':R=y/x;break;
    case'^':R=pow(y,x);break;
	}
  return R;
}
void eval()
{
  int n1,R,x1,x2;
  struct Stack2*temp;
  for(int i=0;i<strlen(P);++i)
   {
     
      struct Stack2*newnode;
     if(isalpha(P[i]))
       {
	 getchar();
	 printf("\nEnter value for %c: ",P[i]);
         scanf("%d",&n1);
         newnode=(struct Stack2*)malloc(sizeof(struct Stack2));
	 newnode->num=n1;
	 newnode->link=top1;
	 top1=newnode;
       }
     
     else
       {
	 temp=top1;
	 x1=top1->num;
	 top1=top1->link;
	 free(temp);
	 temp=top1;
	 x2=top1->num;
	 top1=top1->link;
	 free(temp);
	 R=operation(x1,x2,P[i]);
	 newnode=(struct Stack2*)malloc(sizeof(struct Stack2));
	 newnode->num=R;
	 newnode->link=top1;
	 top1=newnode;
        }
   }
      temp=top1;
      Res=top1->num;
      free(top1);
}
  
  

	 

int main(void)
{

 printf("\nEnter infix expression: ");
 scanf("%s",Q);
 Post_fix();
 printf("\nPOSTFIX expression is: %s",P);

 
 eval();
 printf("\nRESULT IS: %d",Res);
}
      
