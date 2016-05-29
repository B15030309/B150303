/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"zbhhospital.h"

void printHead1()
{
	printf("-----------------------医患信息-----------------------\n");
	printf("|%6s%6s%10s%6s%10s%6s%10s|\n","科室","工号","医生姓名","性别","病人姓名","性别","住院时间");
}
void printHead2()/*打印医生信息的表头*/
{
	printf("|%12s%12s%16s%12s%|\n","科室","工号","医生姓名","性别 ");
}

void menu()/*顶层菜单函数*/
{
	printf("++++++++++++++医患信息管理系统++++++++++++++\n");
    printf("+ 1.查看医患信息                           +\n");
	printf("+ 2.查看医生信息                           +\n");
	printf("+ 3.病患信息管理                           +\n");
	printf("+ 4.医患信息统计                           +\n");
	printf("+                                     退出 +\n");
	printf("+++++++++++++++++治不好医院+++++++++++++++++\n");
}
void menuInf()/*医患信息菜单函数*/
{
	printf("                                           \n ");
	printf("-----------------------医患信息-----------------------\n");
	printf("|     1.搜索 工号  2.搜索 医生姓名  3.搜索 患者姓名    |\n");
	printf(" ----------------------治不好医院----------------------\n");
	printf("                                            \n");
}
void menuDoc()/*医生信息菜单函数*/ 
{
	printf(" ----------------------医生信息----------------------\n");
	printf("|         1.搜索 工号         2.搜索 医生姓名        |\n");
    printf(" ---------------------治不好医院---------------------\n");
	printf("                                           \n ");
}
void menuAdm()/*医患信息管理菜单函数*/
{
	printf("================医患信息管理================\n");
	printf(" = 1.添加医患信息                           =\n");  
	printf(" = 2.删除医患信息                           =\n"); 
	printf(" = 3.修改医患信息                           =\n");
	printf(" = 4.返回上层菜单                           =\n");
	printf(" =================治不好医院=================\n");
}		
void menuCount()/*病患统计菜单函数*/
{
	printf("                                           \n ");
	printf("================医患信息统计================\n"); 
	printf(" = 1.医生治疗病患总数                       =\n"); 
	printf(" = 2.根据病患个数排名                       =\n"); 
	printf(" =================治不好医院=================\n");

}
int baseManage(Doctor doc[],int n)    	     /*该函数完成基本信息管理*/
/*按编号进行插入删除修改，编号不能重复*/
{  
		int choice,t,find[NUM];
		Doctor d;
do
	    {   
menuAdm( );                  /*显示对应的二级菜单*/
printf("选择一个你想进行的操作:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:readDoc(&d,1);       /*读入一条待插入的医患记录*/
					 n=insertDoc(doc,n,d);   /*调用函数插入医患记录*/
					 break;
			   case 2:  printf("输入你想删除的编号：\n");
					 scanf("%d",&d.num);  /*读入一个待删除的学生学号*/
					 n=deleteDoc(doc,n,d);   /*调用函数删除指定编号的医患记录*/
					 break;
			   case 3:  printf("输入你想修改的编号：\n");
					 scanf("%d",&d.num);  /*读入一个待修改的医患编号*/
				      t=searchDoc(doc,n,d,1,find) ; /*调用函数查找指定编号的医患记录*/
				      if (t)                 /*如果该编号的记录存在*/
					 {
						  readDoc(&d,1);   /*读入一条完整的医患记录信息*/
					      doc[find[0]]=d;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该编号的记录不存在*/ 
 printf("无该医患信息记录，无法修改。\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void messageCount(Doctor doc[],int n)          /*该函数完成病患统计菜单功能*/
{  
	int choice;
	do
	{
		menuCount( );                        /*显示对应的二级菜单*/
		printf("选择一个你想进行的操作:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   int calcuAmount(Doctor *doc,int n);         /*计算医生治疗的患者总数*/
				      break;
			case 2:	  void sortdoc(Doctor doc[],int n,int condition);       /*根据患者的个数对医生进行排序，允许并列*/
			case 0:   break;
		}
	}while(choice);
}


void searchInf(Doctor doc[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
	Doctor d;
	   do
{
			menuInf( );                         /*显示对应的二级菜单*/
			printf("选择一个你想进行的操作:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("输入一个你想查询的医生的工号:\n");
				      scanf("%d",&d.num);         /*输入待查询医生的工号*/
					  break;
				case 2:   printf("输入一个你想查询的医生的姓名:\n");
				      scanf("%s",d.name);	          /*输入待查询医生的姓名*/		  
				      break;   
				case 3:   printf("输入一个你想查询的患者的姓名:\n");
				      scanf("%s",d.patient_name);          /*输入待查询患者的姓名*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchDoc(doc,n,d,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead1( );                  /*打印表头1*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printDoc(&doc[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("记录不存在!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

void searchDoc(Doctor doc[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
	Doctor d;
	   do
{
			menuDoc( );                         /*显示对应的二级菜单*/
			printf("选择一个你想进行的操作:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("输入一个你想查询的医生的工号:\n");
				      scanf("%d",&d.num);         /*输入待查询医生的工号*/
					  break;
				case 2:   printf("输入一个你想查询的医生的姓名:\n");
				      scanf("%s",d.name);	          /*输入待查询医生的姓名*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchDoc(doc,n,d,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead2( );                  /*打印表头2*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printDoc(&doc[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("此记录不存在!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}


int runMain(Doctor doc[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead1( );           /* 1. 显示基本信息*/
				 sortdoc(doc,n,1);         /*按编号由小到大的顺序排序记录*/ 
          	 printInf(doc,n);          /*按编号由小到大的顺序输出所有记录*/
					break;
			case 2: printHead2( );           /* 1. 显示基本信息*/
				 sortdoc(doc,n,1);         /*按编号由小到大的顺序排序记录*/ 
          	 printDoc(doc,n);          /*按编号由小到大的顺序输出所有记录*/
					break;
			case 3: n=baseManage(doc,n);    /* 3. 病患信息管理*/
			   	     break;
			case 4: messageCount(doc,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int readDoc(Doctor *doc , int n)          /*读入记录条数，条数为0或读满规定条数记录时停止*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("编号:  ");
	     scanf("%d", &doc[i].num);
		if (doc[i].num==0) break;
		printf("工号: ");
		scanf("%ld",&doc[i].identifier);
		printf("科室:  ");
		scanf("%s",doc[i].office);
		printf("姓名:  ");
		scanf("%s",doc[i].name);
    	printf("性别:  ");
		scanf("%s",doc[i].sex);
		printf("患者姓名:  ");
		scanf("%s",doc[i].patient_name);
		printf("患者性别:  ");
		scanf("%s",doc[i].patient_sex);
	    printf("入院时间:  ");
		scanf("%d,%d,%d",&doc[i].time.year,&doc[i].time.month,&doc[i].time.day);
	}
	return i;
}

void printInf ( Doctor *doc , int n)       /*输出所有医患记录的值*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8d", doc[i].num);
		printf("%8ld", doc[i].identifier);
		printf("%8s", doc[i].name);
		printf("%8s",doc[i].sex);
		printf("%8s",doc[i].patient_name);
        printf("%8s",doc[i].patient_sex);
		printf("%8d,%8d,%8d",doc[i].time.year,doc[i].time.month,doc[i].time);
	}
}
void printDoc ( Doctor *doc , int n)       /*输出所有医生信息*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8d", doc[i].num);
		printf("%8ld", doc[i].identifier);
		printf("%8s", doc[i].name);
		printf("%8s",doc[i].sex);
	}
}
int calcuAmount (Doctor *doc,int n,int* ,int* ,int *)			/*计算病患的总数以及每个医生负责病患总数*/
{
	int i,r[2]={0};
	int *a=r,*b=r,*c=r;
	int Amount;
	for (i=0;i<n;i++)
	{
		if(doc[i].identifier==2323)
		{
			*a++;
		}
		else
		{
			if(doc[i].identifier==6666)
			{
				*b++;
			}
			else
			{
				*c++;
			}
		}
	}
	Amount=*a+*b+*c;
    return Amount;
}
int equal(Doctor d1,Doctor d2,int condition)  /*如何判断两个Doctor记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较编号*/
		return d1.num==d2.num;
 else if (condition==2)                /*如果参数condition的值为2，则比较治疗患者总数*/
	     return d1.amount==d2.amount;
 else if (condition==3)                /*如果参数condition的值为3，则比较工号*/
		return d1.identifier==d2.identifier;
	else return 1;                       /*其余情况返回1*/
}

int larger(Doctor d1,Doctor d2,int condition)  /*根据condition条件比较两个Doctor记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较工号*/
		return d1.identifier>d2.identifier;
	if (condition==2)                    /*如果参数condition的值为2，则比较治疗患者总数*/
		return d1.amount>d2.amount;
	else return 1; /*其余情况返回1*/
}

void sortdoc(Doctor doc[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Doctor d;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(doc[minpos],doc[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			d=doc[i];
			doc[i]=doc[minpos];
			doc[minpos]=d;
		}
	}
}

int searchDoc(Doctor doc[],int n,Doctor d,int condition,int f[ ])  /*在doc数组中依condition条件查找*/
/*与d相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(doc[i],d,condition))
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/
		}
	 return find;                                /*返回find，其值为0则表示没找到*/
}

int insertDoc(Doctor doc[],int n,Doctor d)              /*向doc数组中依工号递增插入一个元素d*/
{
	int i;
	sortdoc(doc,n,1);                              /*先按编号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(doc[i],d,1))                      /*编号相同不允许插入，保证编号的唯一性*/
		{
		    printf("记录不存在，请重新插入！\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按编号从小到大有序*/
	{
		if (!larger(doc[i],d,1))                    /*如果d大于当前元素doc[i]，则退出循环*/
		break;
		doc[i+1]=doc[i];                         /*否则元素doc[i]后移一个位置*/
	}
	doc[i+1]=d;                                /*在下标i+1处插入元素d*/
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteDoc(Doctor doc[],int n,Doctor d)            /*从数组中删除指定编号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(doc[i],d,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("记录不存在！\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(doc[i],d,3)成立*/
		doc[j]=doc[j+1];                       /*通过移动覆盖删除下标为i的元素*/

	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}


int main( )
{
		Doctor doc[NUM];                /*定义实参一维数组存储医患记录*/
      int choice,n;
	 n=readFile(doc);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(doc);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("请输入你的选择: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(doc,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("错误输入，请重新输入!\n");
	} while (choice);
	sortdoc(doc,n,1);                   /*存入文件前按学号由小到大排序*/ 
	     saveFile(doc,n);                   /*将结果存入文件*/
      return 0;
}
