#include<stdio.h>
#include<stdlib.h>
#include<string.h>///ͷ�ļ� 
#define N 10////#define N 20;����˼����bai����Ĵ�du���л���ִ��zhi����N����dao��֮ǰ��zhuanN�滻Ϊ20��
struct student
{
	long num;
	char name[20];
	char sex[10];
	int age;
	char bnote[40];
	struct student *next;///�ṹ�� structʵ�ַ����Ϻ�������һ����,��ÿһ����Ա�ķ�����ֱ��Ѱַ��ʽ
};
int i,j,n,num2,num3,age3,k,m;
char name3[20],sex3[20],bnote3[20],ch;
FILE *fp;///������������������ fp �� FILE��ָ�룬����ָdu��FILE���� ���ļ�zhi�ṹ��
int login()  //��½����
{
	char key[20];
	printf("\t    ********************������ϵͳ����********************\n");
	do
	{
	scanf("%s",key);
	if((strcmp("a",key))==0)
	{
		printf("\t               password correct ,welcome !\n");
		return 1;  //��������ȷʱ������1������ϵͳ
	}
	printf("\t               password incorrect,please input again!\n");
	}
	while(key[20]!=1);//������ֵ��Ϊ1ʱ�������������룬ֱ��������ȷΪֹ
	system("cls");
}
int menu()  //�˵�
{
	int c;
	printf("\t\t**********��ӭ����ͨѶ�ͻ��ˣ�************\n\n");
	printf("\t\t|����������1.¼��ѧ���Ļ�����Ϣ����������|\n");
	printf("\t\t|----------2.��ʾѧ���Ļ�����Ϣ----------|\n");
	printf("\t\t|----------3.����ѧ���Ļ�����Ϣ----------|\n");
	printf("\t\t|----------4.ɾ��ѧ���Ļ�����Ϣ----------|\n");
	printf("\t\t|----------5.�޸�ѧ���Ļ�����Ϣ----------|\n");
	printf("\t\t|----------6.��ѯѧ���Ļ�����Ϣ----------|\n");
	printf("\t\t|����������7.�˳�ϵͳ��������������������|\n");
	printf("\t\t��ѡ����Ҫ���еĹ���(0~7) ");
	scanf("%d",&c);
	return c;
}
struct student *creat() //¼����Ϣ����
{
	struct student *head,*p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(sizeof(struct student));///����һ���������������ռ���ڴ��ֽ���
	head=NULL;
	printf("������ѧ����Ϣѧ�ţ��������Ա����䣬��ע������ѧ��ѧ��Ϊ0ʱ������\n");
	while(1)  //Ϊ1���棬p2->next��Ϊ0��
	{
		scanf("%d",&p1->num);
		if(p1->num==0)  //�ж�ѧ����ѧ���Ƿ�Ϊ0�����Ϊ0��ֹͣ�������ݣ�
		{
			break;
		}
		scanf("%s%s%d%s",p1->name,p1->sex,&p1->age,p1->bnote);///p1->next��p1->num�ֱ���ͨ��ָ�������ýṹ���������Ա next��num!
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
void print(struct student *head)  //�����Ϣ����
{
	struct student *p;
	printf("\t\t������ %d ��ѧ����������Ϣ\n",n);
	p=head;
	if(head!=NULL)
	{
	do
	{
		printf("\t\tѧ��:%d\t����:%s\t�Ա�:%s\t����:%d\t��ע:%s\n",p->num,p->name,p->sex,p->age,p->bnote);
		p=p->next;
	}while(p!=NULL);
	}
	else
	{
		return ;
	}
	printf("\n");
}
int save(struct student *p) //������Ϣ����
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
	printf("\t\t\t����ɹ�!\n");
	fclose(fp);
	return 0;
}
struct student *del(struct student *head)
{
	struct student *p1,*p2;
	printf("\t\t������Ҫɾ��ѧ����ѧ��\n");
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
int mod(struct student *head); //�޸���Ϣ����
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
		printf("\t\t\t��������Ҫ���ĵ�ѧ��\n");
		scanf("%d",&num2);
		printf("\t\t\tѧ��\n");
		scanf("%d",&num3);
		printf("\t\t\t����\n");
		scanf("%s",name3);
		printf("\t\t\t�Ա�\n");
		scanf("%s",sex3);
		printf("\t\t\t����\n");
		scanf("%d",&age3);
		printf("\t\t\t��ע\n");
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
			printf("\t\t\t����ʧ��\n");
		}
		else
		{
			printf("\t\t\t���ĳɹ�\n");
		}
	}
	system("cls");
	mod(head);
}
int mod(struct student *head)
{
	printf("\t\t\t��ѡ��\n");
	printf("\t\t\t1:��ѧ���޸�ѧ����Ϣ\n");
	printf("\t\t\t2:����޸ĺ��ѧ����Ϣ\n");
	printf("\t\t\t3:�������˵�\n");
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
int find1(struct student *head)  //��ѧ�ŷ�ʽ����
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t��������Ҫ��ѯ��ѧ��ѧ��\n");
	scanf("%d",&num2);
	p1=head;
	while(p1!=NULL)
	{
		if(p1->num==num2)
		{
			k=1;
			printf("\t\t\tѧ��:%d\t����:%s\t�Ա�:%s\t����:%d\t��ע:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\tû�в�ѯ����Ҫ�ҵ�ѧ����Ϣ\n\n");
	}
	else
	{
		printf("\t\t\t�������Ҫ�ҵ�ѧ����Ϣ\n\n");
	}
	find(head);
}
int find2(struct student *head)  //��������ʽ����
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t��������Ҫ��ѯ��ѧ������\n");
	scanf("%s",name3);
	p1=head;
	while(p1!=NULL)
	{
		if((strcmp(p1->name,name3))==0)
		{
			k=1;
			printf("\t\t\tѧ��:%d\t����:%s\t�Ա�:%s\t����:%d\t��ע:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\tû���ҵ���ѧ����Ϣ\n\n");
	}
	else
	{
		printf("\t\t\t�������Ҫ��ѯ��ѧ����Ϣ\n\n");
	}
	find(head);
}
int find3(struct student *head)  //���Ա�ʽ����
{ 
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t��������Ҫ��ѯ��ѧ�����Ա�\n");
	scanf("%s",sex3);
	p1=head;
	while(p1!=NULL)
	{
		if((strcmp(p1->sex,sex3))==0)
		{
			k=1;
			printf("\t\t\tѧ��:%d\t����:%s\t�Ա�:%s\t����:%d\t��ע:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\tû���ҵ���ѧ����Ϣ\n\n");
	}
	else
	{
		printf("\t\t\t�������Ҫ��ѯ��ѧ������Ϣ\n\n");
	}
	find(head);
}
int find4(struct student *head)  //�����䷽ʽ����
{
	struct student *p1;
	p1=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t��������Ҫ��ѯ��ѧ��������\n");
	scanf("%d",&age3);
	p1=head;
	while(p1!=NULL)
	{
		if(p1->age==age3)
		{
			k=1;
			printf("\t\t\tѧ��:%d\t����:%s\t�Ա�:%s\t����:%d\t��ע:%s\n\n",p1->num,p1->name,p1->sex,p1->age,p1->bnote);
			break;
		}
		p1=p1->next;
	}
	if(k==0)
	{
		printf("\t\t\tû���ҵ���ѧ������Ϣ\n\n");
	}
	else
	{
		printf("\t\t\t�������Ҫ�ҵ�ѧ������Ϣ\n\n");
	}
	find(head);
}
int find(struct student *head)
{
	printf("\t\t\t��ѡ����Ҫ��ѯѧ����Ϣ�ķ�ʽ\n");
	printf("\t\t\t1:��ѧ��ѧ�Ų�ѯ\n");
	printf("\t\t\t2:��ѧ��������ѯ\n");
	printf("\t\t\t3:��ѧ���Ա��ѯ\n");
	printf("\t\t\t4:��ѧ�������ѯ\n");
	printf("\t\t\t5:�������˵�\n");
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
int main()  //������
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
		case 7:system("cls");printf("\t\t\t��ӭʹ�ã��ټ���\n");return 0;
		default:printf("\t\t\t�����д�����������\n");
		}
	}
}
