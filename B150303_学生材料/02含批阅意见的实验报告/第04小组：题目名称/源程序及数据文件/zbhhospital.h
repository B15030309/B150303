/* zbhhospital.h�ļ����������� */
#ifndef _DOCTOR             /*�������룬��ֹ�ظ������Ĵ���*/
#define _DOCTOR
#define NUM 20
#include <string.h>
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;
struct Doctor                   /*ҽ����Ϣ��¼��������*/
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
#define sizeDoc sizeof(Doctor)      /*һ��ҽ����¼����Ҫ���ڴ�ռ��С*/
int readDoc(Doctor *doc,int n);       /*�����¼����������Ϊ0������涨������¼ʱֹͣ*/
void printInf(Doctor  *doc,int n);
void printDoc(Doctor  *doc,int n);
int equal(Doctor d1,Doctor d2,int condition);  /*����condition�����ж�����Doctor����������ȷ�*/
int larger(Doctor d1,Doctor s2,int condition);  /*����condition�Ƚ�Dcotor�������ݴ�С*/
int calcuAmount(Doctor *doc,int n);
void sortdoc(Doctor doc[],int n,int condition);   /*������������ѡ�񷨴�С��������*/
int searchDoc(Doctor doc[],int n,Doctor d,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertDoc(Doctor doc[],int n,Doctor d);                   /*�������в���һ��Ԫ�ذ��������*/
int deleteDoc(Doctor doc[],int n,Doctor d);                   /*��������ɾ��һ��ָ����ŵ�Ԫ��*/
#endif
