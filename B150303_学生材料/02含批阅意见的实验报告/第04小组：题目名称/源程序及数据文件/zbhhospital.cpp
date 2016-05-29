/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"zbhhospital.h"

void printHead1()
{
	printf("-----------------------ҽ����Ϣ-----------------------\n");
	printf("|%6s%6s%10s%6s%10s%6s%10s|\n","����","����","ҽ������","�Ա�","��������","�Ա�","סԺʱ��");
}
void printHead2()/*��ӡҽ����Ϣ�ı�ͷ*/
{
	printf("|%12s%12s%16s%12s%|\n","����","����","ҽ������","�Ա� ");
}

void menu()/*����˵�����*/
{
	printf("++++++++++++++ҽ����Ϣ����ϵͳ++++++++++++++\n");
    printf("+ 1.�鿴ҽ����Ϣ                           +\n");
	printf("+ 2.�鿴ҽ����Ϣ                           +\n");
	printf("+ 3.������Ϣ����                           +\n");
	printf("+ 4.ҽ����Ϣͳ��                           +\n");
	printf("+                                     �˳� +\n");
	printf("+++++++++++++++++�β���ҽԺ+++++++++++++++++\n");
}
void menuInf()/*ҽ����Ϣ�˵�����*/
{
	printf("                                           \n ");
	printf("-----------------------ҽ����Ϣ-----------------------\n");
	printf("|     1.���� ����  2.���� ҽ������  3.���� ��������    |\n");
	printf(" ----------------------�β���ҽԺ----------------------\n");
	printf("                                            \n");
}
void menuDoc()/*ҽ����Ϣ�˵�����*/ 
{
	printf(" ----------------------ҽ����Ϣ----------------------\n");
	printf("|         1.���� ����         2.���� ҽ������        |\n");
    printf(" ---------------------�β���ҽԺ---------------------\n");
	printf("                                           \n ");
}
void menuAdm()/*ҽ����Ϣ����˵�����*/
{
	printf("================ҽ����Ϣ����================\n");
	printf(" = 1.���ҽ����Ϣ                           =\n");  
	printf(" = 2.ɾ��ҽ����Ϣ                           =\n"); 
	printf(" = 3.�޸�ҽ����Ϣ                           =\n");
	printf(" = 4.�����ϲ�˵�                           =\n");
	printf(" =================�β���ҽԺ=================\n");
}		
void menuCount()/*����ͳ�Ʋ˵�����*/
{
	printf("                                           \n ");
	printf("================ҽ����Ϣͳ��================\n"); 
	printf(" = 1.ҽ�����Ʋ�������                       =\n"); 
	printf(" = 2.���ݲ�����������                       =\n"); 
	printf(" =================�β���ҽԺ=================\n");

}
int baseManage(Doctor doc[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		int choice,t,find[NUM];
		Doctor d;
do
	    {   
menuAdm( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("ѡ��һ��������еĲ���:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:readDoc(&d,1);       /*����һ���������ҽ����¼*/
					 n=insertDoc(doc,n,d);   /*���ú�������ҽ����¼*/
					 break;
			   case 2:  printf("��������ɾ���ı�ţ�\n");
					 scanf("%d",&d.num);  /*����һ����ɾ����ѧ��ѧ��*/
					 n=deleteDoc(doc,n,d);   /*���ú���ɾ��ָ����ŵ�ҽ����¼*/
					 break;
			   case 3:  printf("���������޸ĵı�ţ�\n");
					 scanf("%d",&d.num);  /*����һ�����޸ĵ�ҽ�����*/
				      t=searchDoc(doc,n,d,1,find) ; /*���ú�������ָ����ŵ�ҽ����¼*/
				      if (t)                 /*����ñ�ŵļ�¼����*/
					 {
						  readDoc(&d,1);   /*����һ��������ҽ����¼��Ϣ*/
					      doc[find[0]]=d;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
 printf("�޸�ҽ����Ϣ��¼���޷��޸ġ�\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void messageCount(Doctor doc[],int n)          /*�ú�����ɲ���ͳ�Ʋ˵�����*/
{  
	int choice;
	do
	{
		menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("ѡ��һ��������еĲ���:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   int calcuAmount(Doctor *doc,int n);         /*����ҽ�����ƵĻ�������*/
				      break;
			case 2:	  void sortdoc(Doctor doc[],int n,int condition);       /*���ݻ��ߵĸ�����ҽ����������������*/
			case 0:   break;
		}
	}while(choice);
}


void searchInf(Doctor doc[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
	Doctor d;
	   do
{
			menuInf( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("ѡ��һ��������еĲ���:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("����һ�������ѯ��ҽ���Ĺ���:\n");
				      scanf("%d",&d.num);         /*�������ѯҽ���Ĺ���*/
					  break;
				case 2:   printf("����һ�������ѯ��ҽ��������:\n");
				      scanf("%s",d.name);	          /*�������ѯҽ��������*/		  
				      break;   
				case 3:   printf("����һ�������ѯ�Ļ��ߵ�����:\n");
				      scanf("%s",d.patient_name);          /*�������ѯ���ߵ�����*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchDoc(doc,n,d,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead1( );                  /*��ӡ��ͷ1*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printDoc(&doc[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("��¼������!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

void searchDoc(Doctor doc[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
	Doctor d;
	   do
{
			menuDoc( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("ѡ��һ��������еĲ���:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("����һ�������ѯ��ҽ���Ĺ���:\n");
				      scanf("%d",&d.num);         /*�������ѯҽ���Ĺ���*/
					  break;
				case 2:   printf("����һ�������ѯ��ҽ��������:\n");
				      scanf("%s",d.name);	          /*�������ѯҽ��������*/		  
				      break;   
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchDoc(doc,n,d,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead2( );                  /*��ӡ��ͷ2*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printDoc(&doc[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("�˼�¼������!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}


int runMain(Doctor doc[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead1( );           /* 1. ��ʾ������Ϣ*/
				 sortdoc(doc,n,1);         /*�������С�����˳�������¼*/ 
          	 printInf(doc,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: printHead2( );           /* 1. ��ʾ������Ϣ*/
				 sortdoc(doc,n,1);         /*�������С�����˳�������¼*/ 
          	 printDoc(doc,n);          /*�������С�����˳��������м�¼*/
					break;
			case 3: n=baseManage(doc,n);    /* 3. ������Ϣ����*/
			   	     break;
			case 4: messageCount(doc,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int readDoc(Doctor *doc , int n)          /*�����¼����������Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("���:  ");
	     scanf("%d", &doc[i].num);
		if (doc[i].num==0) break;
		printf("����: ");
		scanf("%ld",&doc[i].identifier);
		printf("����:  ");
		scanf("%s",doc[i].office);
		printf("����:  ");
		scanf("%s",doc[i].name);
    	printf("�Ա�:  ");
		scanf("%s",doc[i].sex);
		printf("��������:  ");
		scanf("%s",doc[i].patient_name);
		printf("�����Ա�:  ");
		scanf("%s",doc[i].patient_sex);
	    printf("��Ժʱ��:  ");
		scanf("%d,%d,%d",&doc[i].time.year,&doc[i].time.month,&doc[i].time.day);
	}
	return i;
}

void printInf ( Doctor *doc , int n)       /*�������ҽ����¼��ֵ*/
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
void printDoc ( Doctor *doc , int n)       /*�������ҽ����Ϣ*/
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
int calcuAmount (Doctor *doc,int n,int* ,int* ,int *)			/*���㲡���������Լ�ÿ��ҽ�����𲡻�����*/
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
int equal(Doctor d1,Doctor d2,int condition)  /*����ж�����Doctor��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return d1.num==d2.num;
 else if (condition==2)                /*�������condition��ֵΪ2����Ƚ����ƻ�������*/
	     return d1.amount==d2.amount;
 else if (condition==3)                /*�������condition��ֵΪ3����ȽϹ���*/
		return d1.identifier==d2.identifier;
	else return 1;                       /*�����������1*/
}

int larger(Doctor d1,Doctor d2,int condition)  /*����condition�����Ƚ�����Doctor��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����ȽϹ���*/
		return d1.identifier>d2.identifier;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ����ƻ�������*/
		return d1.amount>d2.amount;
	else return 1; /*�����������1*/
}

void sortdoc(Doctor doc[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Doctor d;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(doc[minpos],doc[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			d=doc[i];
			doc[i]=doc[minpos];
			doc[minpos]=d;
		}
	}
}

int searchDoc(Doctor doc[],int n,Doctor d,int condition,int f[ ])  /*��doc��������condition��������*/
/*��d��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(doc[i],d,condition))
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/
}

int insertDoc(Doctor doc[],int n,Doctor d)              /*��doc�����������ŵ�������һ��Ԫ��d*/
{
	int i;
	sortdoc(doc,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(doc[i],d,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		{
		    printf("��¼�����ڣ������²��룡\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(doc[i],d,1))                    /*���d���ڵ�ǰԪ��doc[i]�����˳�ѭ��*/
		break;
		doc[i+1]=doc[i];                         /*����Ԫ��doc[i]����һ��λ��*/
	}
	doc[i+1]=d;                                /*���±�i+1������Ԫ��d*/
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteDoc(Doctor doc[],int n,Doctor d)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(doc[i],d,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("��¼�����ڣ�\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(doc[i],d,3)����*/
		doc[j]=doc[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/

	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}


int main( )
{
		Doctor doc[NUM];                /*����ʵ��һά����洢ҽ����¼*/
      int choice,n;
	 n=readFile(doc);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(doc);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("���������ѡ��: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(doc,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("�������룬����������!\n");
	} while (choice);
	sortdoc(doc,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
	     saveFile(doc,n);                   /*����������ļ�*/
      return 0;
}
