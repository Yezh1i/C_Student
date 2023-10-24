#include<stdio.h>
#include<stdlib.h>
#include<string.h>///头文件 
#define N 10////#define N 20;的意思就是bai在你的代du码中会在执行zhi含有N的语dao句之前将zhuanN替换为20。
struct student
{
	long num;
	char name[20];
	char sex[10];
	int age;
	char bnote[40];
	struct student *next;///结构体 struct实现方法上和数组是一样的,即每一个成员的访问是直接寻址方式
};
int i,j,n,num2,num3,age3,k,m;
char name3[20],sex3[20],bnote3[20],ch;
FILE *fp;///变量类型声明。声明 fp 是 FILE型指针，用于指du向FILE类型 （文件zhi结构）
int login()  //登陆函数
{
	char key[20];
	printf("\t    ********************请输入系统密码********************\n");
	do
	{
	scanf("%s",key);
	if((strcmp("a",key))==0)
	{
		printf("\t               password correct ,welcome !\n");
		return 1;  //当密码正确时，返回1，进入系统
	}
	printf("\t               password incorrect,please input again!\n");
	}
	while(key[20]!=1);//当返回值不为1时，重新输入密码，直到输入真确为止
	system("cls");
}
int menu()  //菜单
{
	int c;
	printf("\t\t**********欢迎进入通讯客户端！************\n\n");
	printf("\t\t|—————1.录入学生的基本信息—————|\n");
	printf("\t\t|----------2.显示学生的基本信息----------|\n");
	printf("\t\t|----------3.保存学生的基本信息----------|\n");
	printf("\t\t|----------4.删除学生的基本信息----------|\n");
	printf("\t\t|----------5.修改学生的基本信息----------|\n");
	printf("\t\t|----------6.查询学生的基本信息----------|\n");
	printf("\t\t|—————7.退出系统——————————|\n");
	printf("\t\t请选择您要进行的功能(0~7) ");
	scanf("%d",&c);
	return c;
}
struct student *creat() //录入信息函数
{
	struct student *head,*p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(sizeof(struct student));///返回一个对象或者类型所占的内存字节数
	head=NULL;
	printf("请输入学生信息学号，姓名，性别，年龄，备注（键入学生学号为0时结束）\n");
	while(1)  //为1表真，p2->next不为0；
	{
		scanf("%d",&p1->num);
		if(p1->num==0)  //判断学生的学号是否为0，如果为0则停止输入数据；
		{
			break;
		}
		scanf("%s%s%d%s",p1->name,p1->sex,&p1->age,p1->bnote);///p1->next和p1->num分别是通过指针来引用结构体的两个成员 next和num!
		n=n+1;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct student *)malloc(sizeof(struct student));
	}
	p2->next=NULL;
	system("cls");
	return(head);
}
void print(struct student *head)  //输出信息函数
{
	struct student *p;
	printf("\t\t这里有 %d 个学生的数据信息\n",n);
	p=head;
	if(head!=NULL)
	{
	do
	{
		printf("\t\t学号:%d\t姓名:%s\t性别:%s\t年龄:%d\t备注:%s\n",p->num,p->name,p->sex,p->age,p->bnote);
		p=p->next;
	}while(p!=NULL);
	}
	else
	{
		return ;
	}
	printf("\n");
}
int save(struct student *p) //保存信息函数
{
	FILE *fp;
	if((fp=fopen("keshe.txt","wb"))==NULL)
	{
		printf("open file fail\n");
	}
	fp=fopen("stud","wb");
	do
	{
		fwrite(p,sizeof(struct student),1,fp);
		p=p->next;
	}while(p!=NULL);
	printf("\t\t\t保存成功!\n");
	fclose(fp);
	return 0;
}
struct student *del(struct student *head)
{
	struct student *p1,*p2;
	printf("\t\t请输入要删除学生的学号\n");
	scanf("%d",&num2);
	p1=head;
	if(head->num==num2)
	{
		head=head->next;
		free(p1);
		n--;
	}
	else
	{
		
		p2=head;
		while(p2->num!=num2&&p2->next!=NULL)
		{
			p1=p2;
			p2=p2->next;
		}
		if(p2->num==num2)
		{
			p1->next=p2->next;
			n--;
		}
		printf("delete:%ld\n",num2);
	}
	return (head);
}
int mod(struct student *head); //修改信息函数
struct student *modify(struct student *head)
{
	if(login()==0)
	{
		return 0;
	}
	else
	{
		struct student *p1;
		j=0;
		p1=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t请输入你要更改的学号\n");
		scanf("%d",&num2);
		printf("\t\t\t学号\n");
		scanf("%d",&num3);
		printf("\t\t\t姓名\n");
		scanf("%s",name3);
		printf("\t\t\t性别\n");
		scanf("%s",sex3);
		printf("\t\t\t年龄\n");
		scanf("%d",&age3);
		printf("\t\t\t备注\n");
		scanf("%s",bnote3);
		p1=head;
		if(head->num==num2)
		{
			head->num=num3;
			strcpy(head->name,name3);
			strcpy(head->sex,sex3);
			head->age=age3;
			strcpy(head->bnote,bnote3);
			j=1;
		}
		else
		{
			p1=head->next;
			if(p1!=NULL)
			{
				while(p1->num!=num2)
				{
					p1=p1->next;
				}
				p1->num=num2;
				strcpy(p1->name,name3);
				strcpy(p1->sex,sex3);
				p1->age=age3;
				strcpy(p1->bnote,bnote3);
				j=1;
			}
		}
		if(j==0)
		{
			printf("\t\t\t更改失败\n");
		}
		else
		{
			printf("\t\t\t更改成功\n");
		}
	}
	system("cls");
	mod(head);
}
int mod(struct student *head)
{
	printf("\t\t\t请选择\n");
	printf("\t\t\t1:按学号修改学生信息\n");
	printf("\t\t\t2:输出修改后的学生信息\n");
	printf("\t\t\t3:返回主菜单\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1:head=modify(head);break;
	case 2:print(head);break;
	case 3:menu();break;
	default:printf("\t\t\tinput error!\n");
	mod(head);
	}
}
int find(struct student *head);
int find1(struct student *head)  //以学号方式查找
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t请输入你要查询的学生学号\n");
	scanf("%d",&num2);
	p1=head;
	while(p1!=NULL)
	{
		if(p1->num==num2)
		{
			k=1;
			printf("\t\t\t学号:%d\t姓名:%s\t性别:%s\t年龄:%d\t备注:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\t没有查询到您要找的学生信息\n\n");
	}
	else
	{
		printf("\t\t\t这就是您要找的学生信息\n\n");
	}
	find(head);
}
int find2(struct student *head)  //以姓名方式查找
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t请输入您要查询的学生姓名\n");
	scanf("%s",name3);
	p1=head;
	while(p1!=NULL)
	{
		if((strcmp(p1->name,name3))==0)
		{
			k=1;
			printf("\t\t\t学号:%d\t姓名:%s\t性别:%s\t年龄:%d\t备注:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\t没有找到该学生信息\n\n");
	}
	else
	{
		printf("\t\t\t这就是您要查询的学生信息\n\n");
	}
	find(head);
}
int find3(struct student *head)  //以性别方式查找
{ 
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t请输入你要查询的学生的性别\n");
	scanf("%s",sex3);
	p1=head;
	while(p1!=NULL)
	{
		if((strcmp(p1->sex,sex3))==0)
		{
			k=1;
			printf("\t\t\t学号:%d\t姓名:%s\t性别:%s\t年龄:%d\t备注:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\t没有找到该学生信息\n\n");
	}
	else
	{
		printf("\t\t\t这就是您要查询的学生的信息\n\n");
	}
	find(head);
}
int find4(struct student *head)  //以年龄方式查找
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t请输入您要查询的学生的年龄\n");
	scanf("%d",&age3);
	p1=head;
	while(p1!=NULL)
	{
		if(p1->age==age3)
		{
			k=1;
			printf("\t\t\t学号:%d\t姓名:%s\t性别:%s\t年龄:%d\t备注:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\t没有找到该学生的信息\n\n");
	}
	else
	{
		printf("\t\t\t这就是您要找的学生的信息\n\n");
	}
	find(head);
}
int find(struct student *head)
{
	printf("\t\t\t请选择您要查询学生信息的方式\n");
	printf("\t\t\t1:按学生学号查询\n");
	printf("\t\t\t2:按学生姓名查询\n");
	printf("\t\t\t3:按学生性别查询\n");
	printf("\t\t\t4:按学生年龄查询\n");
	printf("\t\t\t5:返回主菜单\n");
	scanf("%d",&m);
	switch(m)
	{
	case 1:find1(head);break;
	case 2:find2(head);break;
	case 3:find3(head);break;
	case 4:find4(head);break;
	case 5:system("cls");menu();break;
	default:printf("\t\t\tinput error,please input again\n");
	}
}
int main()  //主函数
{
	struct student *phead;
	if(login()==0)
	{
		return 0;
	}
 
	printf("\n");
	while(1)
	{
		switch(menu())
		{
		case 1:system("cls");phead=creat();break;
		case 2:system("cls");print(phead);break;
		case 3:system("cls");save(phead);break;
		case 4:system("cls");phead=del(phead);break;
		case 5:system("cls");mod(phead);break;
		case 6:system("cls");find(phead);break;
		case 7:system("cls");printf("\t\t\t欢迎使用，再见！\n");return 0;
		default:printf("\t\t\t输入有错，请重新输入\n");
		}
	}
}
