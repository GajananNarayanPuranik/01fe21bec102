#include<stdio.h>
#define max 25
int top=-1;
int stack[max];
void push(int a);
int isfull();
int pop();
int isempty();
void display();

main()
{
    int n=25;
    FILE *fp;//to generate random numbers in file.
    fp=fopen("inputfile2.txt","w");
    for(int i=1;i<=n;i++)
    {
        int t=rand()%77;
        fprintf(fp,"%d\t",t);
    }
    fclose(fp);
    fp=fopen("inputfile2.txt","r");

    FILE *displayf;//to clear the content of display file.
    displayf=fopen("display_stack.txt","w");
    fclose(displayf);

    FILE *popf;// to clear the content of pop file.
    popf=fopen("pop.txt","w");;
    fclose(popf);

    FILE *pushf;//to clear the content of push file.
    pushf=fopen("push.txt","w");
    fclose(pushf);

    FILE *op;//file having name stack operation performed.
    op=fopen("Stack_operation.txt","w");
    int choice,a;
    while(1)
    {
        printf("Enter 1:push\n 2:pop\n 3:display\n 4:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:fscanf(fp,"%d",&a);
                   push(a);
                   fprintf(op,"Push()\n");
                   break;
            case 2:popf=fopen("pop.txt","a");
                   a=pop();
                   if(a==0)
                   {
                       printf("stack underflow\n");
                       fprintf(popf,"stack overflow\n");
                   }
                   else
                   {
                       printf("The pop out element is %d\n",a);
                       fprintf(popf,"The pop out element is %d\n",a);
                   }
                   fclose(popf);
                   fprintf(op,"Pop()\n");
                   break;
            case 3:display(displayf);
                   fprintf(op,"Display()\n");
                   break;
            case 4:exit(0);
                   break;
            default:printf("Enter a valid choice\n");
        }
    }
    fclose(op);
    fclose(fp);
}

void push(int a)
{ FILE *pushf;
  pushf=fopen("push.txt","a");
    if(isfull())
    {
      fprintf(pushf,"Stack is full\n");
      printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top]=a;
        fprintf(pushf,"%d element is pushed\n",a);
        printf("%d element is push\n",a);
    }
    fclose(pushf);

}

int isfull()
{
    if(top==max-1)
    {
        return 1;
    }
    else
    {
      return 0;
    }
}

int pop()
{
    if(isempty())
    {
        return 0;
    }
    else
    {
        int c=stack[top];
        top--;
        return c;
    }
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{   FILE *displayf;
    displayf=fopen("display_stack.txt","a");
    if(isempty())
    {
        printf("The stack is empty\n");
        fprintf(displayf,"The stack is empty\n");
    }
    else
    {
        int i;
        printf("The stack elements are:\n");
        fprintf(displayf,"The stack elements are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
            fprintf(displayf,"%d\t",stack[i]);
        }
        printf("\n");
        fprintf(displayf,"\n");
    }
    fclose(displayf);
}
