#define _CRT_SECURE_NO_WARNINGS

#define MAX 3
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<errno.h>

enum
{
	EXIT,
	ADD,
	DEL,
	SEEK,
	CHANGE,
	SHOW,
	SORT,
	SAVE
};
typedef struct peoinfo
{
	char name[20];
	char tele[15];
	char gender[6];
	char address[50];
	int age;
}peoinfo;
typedef struct contact
{
	peoinfo* info;
	int size;//记录当前元素个数
	int max;//刻画最大容量
}contact;

void initcontact(contact* ps);
void addinfomation(contact* ps);
void showcontact(contact* ps);
void deletecontact(contact* ps);
void seekcontact(contact* ps);
void changecontact(contact* ps);
void sortcontact(contact* ps);
void distorycontact(contact* ps);
void savecontact(contact* ps);
void lodecontact(contact* ps);






