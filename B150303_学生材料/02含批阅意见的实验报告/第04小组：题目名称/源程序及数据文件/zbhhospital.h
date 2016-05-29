/* zbhhospital.h文件的完整内容 */
#ifndef _DOCTOR             /*条件编译，防止重复包含的错误*/
#define _DOCTOR
#define NUM 20
#include <string.h>
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;
struct Doctor                   /*医患信息记录的数据域*/
{
	int num;
	long identifier;
	char office[30];	
	char name[20];
	char sex[10];
	int amount;
	char patient_name[20];
	char patient_sex[10];
	Date time;
};
typedef struct Doctor Doctor;
#define sizeDoc sizeof(Doctor)      /*一个医患记录所需要的内存空间大小*/
int readDoc(Doctor *doc,int n);       /*读入记录条数，条数为0或读满规定条数记录时停止*/
void printInf(Doctor  *doc,int n);
void printDoc(Doctor  *doc,int n);
int equal(Doctor d1,Doctor d2,int condition);  /*根据condition条件判断两个Doctor类型数据相等否*/
int larger(Doctor d1,Doctor s2,int condition);  /*根据condition比较Dcotor类型数据大小*/
int calcuAmount(Doctor *doc,int n);
void sortdoc(Doctor doc[],int n,int condition);   /*按病人总数，选择法从小到大排序*/
int searchDoc(Doctor doc[],int n,Doctor d,int condition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
int insertDoc(Doctor doc[],int n,Doctor d);                   /*向数组中插入一个元素按编号有序*/
int deleteDoc(Doctor doc[],int n,Doctor d);                   /*从数组中删除一个指定编号的元素*/
#endif
