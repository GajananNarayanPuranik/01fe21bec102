//C program to genearte 100 random numbers and store it in file and sort the numbers stored in that file and display it in the same 
// file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

Node* insertend(FILE *fp,Node *head,int n);
void display(Node *head);
Node* sort(Node *head);
void resend (Node *head,FILE *fp);

     main()
{
    FILE *fp;
    Node *head;
    head=NULL;
    int n=100,b;
    int c=0;
    clock_t a,f;
    fp=fopen("abc.txt","w");
    fprintf(fp,"Elements in file are:\n");
    for(int j=0;j<n;j++)
    { 
      b=rand()%100;
      fprintf(fp,"%d  ",b);
      c++;
      if(c==25)
      { 
        c=0;
        fprintf(fp,"\n");
      }

    }
    fclose(fp);
    fp=fopen("abc.txt","r");
    char s;
    while(!feof(fp))
    {
        s=fgetc(fp);
        if(s=='\n')
        {
        break;
        }
    }
    head=insertend(fp,head,n);
    fclose(fp);
    printf("printing the elements\n");
    display(head);
    a=clock();
    head=sort(head);
    f=clock();
    printf("after sorting:\n");
    display(head);
    double time=((double)(f-a))/CLOCKS_PER_SEC;
    fp=fopen("abc.txt","a");
    fprintf(fp,"\nElements in the file after sorting:\n");
    resend(head,fp);
    fprintf(fp,"\nThe time taken to sort is %.9f\n",time);
    fclose(fp);
    printf("\n a=%f\n",a);
    printf("f=%f",f);
}
            

Node* insertend(FILE *fp,Node *head,int n)
{  for(int i=0;i<n;i++)
   { Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL)
    {
        printf("no space\n");
        exit(1);
    }
    newnode->next=newnode;
    fscanf(fp,"%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
    }
    else 
    {
        Node *temp;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
   }
   return head;
}


void display(Node *head)
{
    Node *temp;
    temp=head;
    while(temp->next!=head)
    {
        printf("data:%d\n",temp->data);
        temp=temp->next;
    }
    printf("data:%d\n",temp->data);
}

Node* sort(Node *head)
{
    Node *temp1;
    Node *temp2;
    temp1=head;
    int a;
    while(temp1->next!=head)
    {   temp2=temp1->next;
        while(temp2!=head)
        {  if(temp1->data>temp2->data)
          { a=temp1->data;
          temp1->data=temp2->data;
          temp2->data=a;
          }
          temp2=temp2->next;
       }
       temp1=temp1->next;
    }
    return head;
}

void resend (Node *head,FILE *fp)
{
    Node *temp;
    int c=0;
    temp=head;
    while(temp->next!=head)
    {  fprintf(fp,"%d ",temp->data);
       c++;
       if(c==25)
       {c=0;
        fprintf(fp,"\n");
       }
       temp=temp->next;
    }
    fprintf(fp,"%d ",temp->data);
}