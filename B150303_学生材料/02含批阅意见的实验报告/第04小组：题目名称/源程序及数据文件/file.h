#include <stdio.h>
#include <stdlib.h>
#include "zbhhospital.h"        
int  createFile(Doctor doc[ ])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\zbhhospital.txt", "wb")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("c无法打开文件！\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    	}
	printf("输入文件zbhhospital的信息：\n");
	n=readDoc(doc,NUM);                /*调用zhbhospital.h中的函数读数据*/
fwrite(doc,sizeDoc,n,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);                             /*关闭文件*/
	 return n;
}

int readFile(Doctor doc[ ] )                     /*将文件中的内容读出置于结构体数组doc中*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\zbhhospital.txt", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("文件不存在，建立一个新文件:\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}	 
    	fread(&doc[i],sizeDoc,1,fp);                   /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
	    	fread(&doc[i],sizeDoc,1,fp);              /*再读出下一条记录*/
     }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}

void saveFile(Doctor doc[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\zbhhospital.txt", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("无法打开文件 !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(doc,sizeDoc,n,fp);        
	fclose(fp);                              /*关闭文件*/
}