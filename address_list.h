
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

#define MAX 10
#define MAX_NAME 18
#define MAX_SEX 5
#define MAX_TELE 15
#define MAX_ADDR 40

enum option
{
	exit1,
	add,
	del,
	search,
	modify,
	show,
	sort
};
struct peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	int age;
};

struct contact
{
	struct peoinfo data[MAX];
	int size;
};

void initialize(struct contact* ps);
void addcontact(struct contact* ps);
void showcontact(const struct contact* ps);
void delcontact(struct contact* ps);
void searchcontact(struct contact* ps);
void modifycontact(struct contact* ps);
void sortcontact(struct contact* ps);