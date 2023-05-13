/*Read the numbers stored in the file,where the first number in the file indicates the number of elements to be fetched and sorted 
 and restored in the same file*/

#include<stdio.h>
void read(FILE *fp,int a[30],int n);
void sort(int a[30],int n);
main()
{FILE *fp;
 int a[30];
 int n;
 char c;
 fp=fopen("input.txt","r");
 while(!feof(fp))
 {
    c=fgetc(fp);
    if(c=='\n')
    {
        break;
    }
 }
 fscanf(fp,"%d",&n);
 int x=0;
 while(!feof(fp))
 {
    c=fgetc(fp);
    if(c=='\n')
    { x++;
      if(x==2)
      {
        break;
      }
    }

 }
 read(fp,a,n);
 fclose(fp);
 sort(a,n);
 fp=fopen("input.txt","a");
 fprintf(fp,"\nAfter sorting the elements are:\n");
 for(int i=0;i<n;i++)
 {
    fprintf(fp,"%d  ",a[i]);
 }
 fclose(fp);

}

void read(FILE *fp,int a[30],int n)
{
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    printf("The elements in the array are:\n");
     for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    
}

void sort(int a[30],int n)
{ int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            { temp=a[i];
              a[i]=a[j];
              a[j]=temp;
            }
        }
    }

    printf("after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}