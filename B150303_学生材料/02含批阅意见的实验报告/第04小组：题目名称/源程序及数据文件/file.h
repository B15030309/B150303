#include <stdio.h>
#include <stdlib.h>
#include "zbhhospital.h"        
int  createFile(Doctor doc[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\zbhhospital.txt", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("c�޷����ļ���\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("�����ļ�zbhhospital����Ϣ��\n");
	n=readDoc(doc,NUM);                /*����zhbhospital.h�еĺ���������*/
fwrite(doc,sizeDoc,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(Doctor doc[ ] )                     /*���ļ��е����ݶ������ڽṹ������doc��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\zbhhospital.txt", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("�ļ������ڣ�����һ�����ļ�:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&doc[i],sizeDoc,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&doc[i],sizeDoc,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(Doctor doc[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\zbhhospital.txt", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("�޷����ļ� !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(doc,sizeDoc,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}