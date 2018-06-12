#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char firstname[100];
    char lastname[100];
    int id;
    char subject[100];
    char degree[100];
}teacher;

void display(int n,teacher t[])
{
    int i;
    for(i=0;i<n;i++)
    printf("name:%s %s\nid:%d\nsubject:%s\ndegree:%s\n\n",t[i].firstname,t[i].lastname,t[i].id,t[i].subject,t[i].degree);

}
void search(char firstname[],char lastname[],int n,teacher t[])
{
    int i;
    int found=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(firstname,t[i].firstname)==0)
           {
               if(strcmp(lastname,t[i].lastname)==0)
               {
                   printf("\nname:%s %s\nsubject:%s\ndegree:%s\n\n*THE ID IS : %d\n\n",t[i].firstname,t[i].lastname,t[i].subject,t[i].degree,t[i].id);
                   found=1;
               }

           }

    }
    if(found==0)
    {
         printf("This name is not found");
    }

}
void salary(int id,int n,teacher t[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(id==t[i].id)
        {
         printf("\nThe name : %s %s\nThe subject : %s\n\nTHE DEGREE IS : %s\n\n",t[i].firstname,t[i].lastname,t[i].subject,t[i].degree);
         if(strcmp(t[i].degree,"supervisor")==0)
            printf("ACCORDIND TO THE DEGREE:\n\nThe no of lessons(per week): 5\nThe salary: 3000\n");
         if(strcmp(t[i].degree,"teacher")==0)
            printf("ACCORDIND TO THE DEGREE:\n\n\nThe no of lessons(per week): 10\nThe salary: 2000\n");
         if(strcmp(t[i].degree,"assistant")==0)
            printf("ACCORDIND TO THE DEGREE:\n\n\nThe no of lessons(per week): 15\nThe salary: 1000\n");


        }
    }

}
void subjectstaff(char subj[],int n,teacher t[])
{
    int i;
    for(i=0;i<n;i++)
    {
       if(strcmp(t[i].subject,subj)==0)
       {
            if(strcmp(t[i].degree,"supervisor")==0)
        printf("The supervisor is : %s %s (id:%d}\n",t[i].firstname,t[i].lastname,t[i].id);

        if(strcmp(t[i].degree,"teacher")==0)
            printf("The teacher is : %s %s (id:%d)\n",t[i].firstname,t[i].lastname,t[i].id);

        if(strcmp(t[i].degree,"assistant")==0)
            printf("The assistant is : %s %s (id:%d)\n",t[i].firstname,t[i].lastname,t[i].id);
       }
    }
}
void printmenu2()
{
printf("\n\n*PLEASE CHOOSE ONE OF THE FOLLOWING OPTIONS BY ENTERING ITS NO*\n\n");
printf("#1 TO DISPLAY THE DATA AND GET THE ID\n");
printf("#2 TO DISPLAY NO OF LESSONS AND THE SALARY ACCORDING TO DEGREE\n");
printf("#3 TO DISPLAY THE STAFF OF A CERTAIN SUBJECT\n\n");
printf("your choice is:");
}
void printmenu1(int *flag,int n,int *menu,teacher t[])
{
    int c;
printf("\n\nplease choose:\n#1 to display the whole database\n#2 to display the menu\n#3 to end the program\n\n");
printf("your choice is :");
scanf("%d",&c);

if(c==1)
{
    printf("\n\n**DATABASE**\n\n");
    display(n,t);
}
else if(c==2)
{

printmenu2();
scanf("%d",menu);

}
else if(c==3)
{
    *flag=1;
    printf("\n\nTHANK YOU\n\n");
}
else
    printf("incorrect entry");

}



int main()
{
printf("\n      ** THIS PROGRAM IS A DATABASE FOR TEACHERS WORKING AT A SCHOOL **\n");

teacher t[100];
int n=0;

 FILE *f;
f=fopen("database.txt","r");
if(f==NULL)
  printf("error");

while(!feof(f))
    {
        fscanf(f,"%[^,],%[^,],%d,%[^,],%s\n",t[n].firstname,t[n].lastname,&t[n].id,t[n].subject,t[n].degree);
        n++;
    }
printf("                       (note:file is already loaded)\n\n");



int menu=0;
int flag=0;
int i;
for(i=0;i<100;i++)
{
printmenu1(&flag,n,&menu,t);
if (flag==1)
break;

if(menu==1)
{
printf("you have chosen #1\n\n*IN ORDER TO DISPLAY THE DATA AND GET THE ID:\n\n");
char firstname[100];
char lastname[100];
printf("please enter first name (lower or upper case):");
scanf("%s",firstname);
strlwr(firstname);
printf("please enter last name (lower or upper case):");
scanf("%s",lastname);
strlwr(lastname);
search(firstname,lastname,n,t);
}


else if(menu==2)
{
printf("you have chosen #2\n\n*IN ORDER TO DISPLAY NO OF LESSONS AND THE SALARY:\n\n");
int id;
printf("please enter id (no bet 2901 and 2915):");
scanf("%d",&id);
if(id<2901||id>2915)
{
     printf("incorrect id\n");

}
salary(id,n,t);

}


else if(menu==3)
{
printf("you have chosen #3\n\n*IN ORDER TO DISPLAY THE STAFF OF A CERTAIN SUBJECT:\n\n");
int sub;
printf("please choose one of the following subjects by entering its no:\n\n");
printf("1)maths\n2)science\n3)arabic\n4)english\n5)french\n\n");
printf("your choice is:");
scanf("%d",&sub);
if(sub<1||sub>5)
    printf("incorrect entry");

char subj[10];
switch(sub)
{
    case 1:strcpy(subj,"maths");
    printf("you have chosen %s\n\n",subj);
    break;
    case 2:strcpy(subj,"science");
     printf("you have chosen %s\n\n",subj);
     break;
    case 3:strcpy(subj,"arabic");
     printf("you have chosen %s\n\n",subj);
     break;
    case 4:strcpy(subj,"english");
     printf("you have chosen %s\n\n",subj);
     break;
    case 5:strcpy(subj,"french");
     printf("you have chosen %s\n\n",subj);
     break;

}
subjectstaff(subj,n,t);
}
else if(menu!=0)
    printf("incorrect entry");
}

return 0;
}
