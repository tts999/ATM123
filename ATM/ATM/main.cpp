#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Transaction
{
	char uesrname[100];
	time_t timestamp;
	int type;
	int amount;
	struct Transaction * next;
};
typedef struct Transaction Transaction;

struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char uesrname[100];
	char password[7];
	float money;
	struct Account *next;
};
typedef struct Account Account;

Account * head=NULL;
Account * tail=NULL;
Account * curAccount=NULL;//记录当期账户

void Load()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account));
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->uesrname,newNode->password);
			//添加结点到链表
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		printf("加载成功!\n");
		fclose(fp);
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s\n",curP->uesrname,curP->password);
			curP=curP->next;
		}
	}
	fclose(fp);
}

void signUp()
{
	//申请一块堆内存空间，将其地址赋值给指针newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("请输入姓名:\n");
	scanf("%s",newNodeP->name);

	printf("请输入身份证号:\n");
	scanf("%s",newNodeP->idCard);

	printf("请输入电话:\n");
	scanf("%s",newNodeP->tel);

	printf("请输入账号:\n");
	scanf("%s",newNodeP->uesrname);

	printf("请输入密码:\n");
	scanf("%s",newNodeP->password);

	newNodeP->money=0.0f;
	newNodeP->next=NULL;

	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	printf("创建成功!\n");
}

//找到返回1，否则返回0
int findAccount(Account a)
{
	Account * curp=head;
	while(curp!=NULL)
	{
		if((strcmp(curp->uesrname,a.uesrname)==0)&&(strcmp(curp->password,a.password)==0))
		{
			curAccount=curp;
			return 1;
		}
		curp=curp->next;
	}
	return 0;
}

void updatePassword()
{
	char formerPassword[100];
	printf("请输入旧密码：\n");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("请输入新密码：\n");
		scanf("%s",curAccount->password);
		printf("修改成功！\n");
	}
	else
	{
		printf("密码错误！不能修改！\n");
	}
}

void TheupdatePassword()
{
	char formerPassword[100];
	printf("please enter  your fomer password：");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("please enter your new password：");
		scanf("%s",curAccount->password);
		printf("Changed successfully！\n");
	}
	else
	{
		printf("The former password is wrong ,you can't change it！\n");
	}

}

void saveMoney()
{
	printf("请输入存款金额:\n");
	int money;
	scanf("%d",&money);
	if(money>=100 && money<=50000)
	{
		curAccount->money+=money;
		printf("存款成功！\n");
		//记录交易信息
	}
}

void ThesaveMoney()
{
	printf("please enter the deposit amount:\n");
	int money;
	scanf("%d",&money);
	if(money>=100 && money<=50000)
	{
		curAccount->money+=money;
		printf("Deposit succeeded！\n");
		//记录交易信息
	}
}

void drawMoney()
{
	printf("请输入取款金额:\n");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money)
	{
		printf("取款成功！\n");
		curAccount->money-=money;
		//记录交易信息
	}
	else
	{
		printf("余额不足，取款失败\n");
	}
}

void ThedrawMoney()
{
	printf("please enter the withdrawal amount:\n");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money)
	{
		printf("Withdrawal succeeded！\n");
		curAccount->money-=money;
		//记录交易信息
	}
	else
	{
		printf("Insufficient balance,withdrawal failed\n");
	}
}

void signIn()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("请输入账号:");
		scanf("%s",a.uesrname);

		printf("请输入密码:");
		scanf("%s",a.password);

		if(findAccount(a)==1)
		{
			printf("登陆成功！\n");
			break;
		}
		else
		{
			printf("登录失败！\n");
		}
	}
	printf("修改密码请输入1\n");
	printf("存款请输入2\n");
	printf("取款请输入3\n");
	int o;
	scanf("%d",&o);
	if(o==1)
	{
		updatePassword();
	}
	else if(o==2)
	{
		saveMoney();
	}
	else if(o==3)
	{
		drawMoney();
	}
}

int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account));
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->uesrname,newNode->password);
			//添加结点到链表
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;
			}
			else
			{
				tail->next=newNode;
				tail=newNode;
			}
		}
		return 1;
	}
}

void signtheUp()
{
    //申请一块堆内存空间，将其地址赋值给指针newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("please input your name:\n");
	scanf("%s",newNodeP->name);

	printf("please input your idCard:\n");
	scanf("%s",newNodeP->idCard);

	printf("please input your telphone:\n");
	scanf("%s",newNodeP->tel);

	printf("please input your username:\n");
	scanf("%s",newNodeP->uesrname);

	printf("please input your password:\n");
	scanf("%s",newNodeP->password);

	newNodeP->money=0.0f;
	newNodeP->next=NULL;

	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	printf("Created Successfully !\n");
}

void signtheIn()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("please input your account:");
		scanf("%s",a.uesrname);

		printf("please input your password:");
		scanf("%s",a.password);

		if(findAccount(a)==1)
		{
			printf("Login successful!\n");
			break;
		}
		else
		{
			printf("Login failed!\n");
		}
	}
	printf("Change the password please enter 1\n");
	printf("Save money please enter 2\n");
	printf("Draw money please enter 3\n");
	int o;
	scanf("%d",&o);
	if(o==1)
	{
		TheupdatePassword();
	}
	else if(o==2)
	{
		ThesaveMoney();
	}
	else if(o==3)
	{
		ThedrawMoney();
	}
}

void showMenu()
{
	printf("开户，按1\n");
	printf("登录，按2\n");
	int n;
	scanf("%d",&n);

	if(n==1)
	{
		signUp();
	}
	else if(n==2)
	{
		signIn();
	}
}

void showtheMenu()
{
	printf("open an account,please press 1\n");
	printf("signup，please press 2\n");
	int m;
	scanf("%d",&m);

	if(m==1)
	{
		signtheUp();
	}
	else if(m==2)
	{
		signtheIn();
	}
}

int main()
{
	printf("欢迎使用花开富贵银行\n");
	printf("welcome to Blossoming wealth bank\n");
	Load();
	int language;
	printf("中文，请按1\n");
	printf("English,please press 2\n");
	scanf("%d",&language);
	if(language==1)
	{
		showMenu();
	}
	else if(language==2)
	{
		showtheMenu();
	}

	int i=loadData();
	if(i==0)
	{
		printf("加载失败！\n");
	}
	else
	{
		printf("加载成功！\n");
	}

	printLinkedList();
	
	time_t timestamp = time(NULL);
	
	char *ct=ctime(&timestamp);
	printf("%s\n",ct);

	saveData();

	return 0;
}