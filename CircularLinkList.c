#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *link;
};
struct node *head=NULL;
struct node *creatnode()
{
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
return(n);
};
void insertion(int x)
{
struct node *t,*p;
p=creatnode();
t=head;
p->data=x;

if(head!=NULL)
{
while(t->link!=head)
{
t=t->link;
}
t->link=p;
p->link=head;
}
else
{
p->link=p;
head=p;
}
}
void insertion_b(int x)
{
struct node *tem,*q;
q=creatnode();
tem=head;
q->data=x;
if(head!=NULL)
{
while(tem->link!=head)
{
tem=tem->link;
}
tem->link=q;
q->link=head;
head=q;
}
else
{
q->link=q;
head=q;
}
}
void display()
{
struct node *d;
d=head;
if(head!=NULL)
{
while(d->link!=head)
{
printf("->%d",d->data);
d=d->link;
}
printf("->%d->head",d->data);
}
else
printf("list empty");
}
void insert_in(int x)
{
int y,z;
struct node *pre,*post,*a;
a=creatnode();
a->data=x;
if(head==NULL)
{
a->link=a;
head=a;
}
else
{
pre=head;
post=pre->link;
printf("enter no. in between you want to insert = ");
scanf("%d%d",&y,&z);
while(pre->data!=y)
{
pre=pre->link;
}
pre->link=a;
a->link=post;
}
}
void deletion_front()
{
struct node *temp;
if(head==NULL)
{
printf("list is empty");
}
else if(head->link==head)
{
printf("deleted element is %d",head->data);
free(head);
head=NULL;
}
else
{
temp=head;
printf("element deleted is %d",temp->data);
while(temp->link!=head)
{
temp=temp->link;
}
head=head->link;
temp->link=head;
free(temp);
}
}
void deletion_rear()
{
struct node *tail,*pr,*t;
t=head;
while(t->link!=head)
{
t=t->link;
}
tail=t;
pr=tail;
while(pr->link!=tail)
{
pr=pr->link;
}
pr->link=tail->link;
printf("element deleted is %d",tail->data);
free(tail);
}
void main()
{
int x,ch;
clrscr();
for(;;)
{
printf("\n1:insertoion\n2:display\n3:exit\n4:inserion at beg\n5:insertion in between\n6:deletion at front\n7:deletion at rear");
printf("\nenter your choice =");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter no. ");
	scanf("%d",&x);
	insertion(x);
	break;
case 2:display();
	break;
case 3:exit(0);
	break;
case 4:printf("enter no. ");
	scanf("%d",&x);
	insertion_b(x);
	break;
case 5:printf("enter no. ");
	scanf("%d",&x);
	insert_in(x);
	break;
case 6:deletion_front();
	break;
case 7:deletion_rear();
	break;
}
getch();
}
}
