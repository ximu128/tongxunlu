#define _CRT_SECURE_NO_WARNINGS 1

#include"address_list.h"

void initialize(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录最初只有0个元素
}

void addcontact(struct contact* ps)
{
	int i = 0;
	if (ps->size == MAX)
	{
		printf("通讯录已满，请进行充值扩容\n");
	}
	else
	{
		printf("请输入姓名->");
		i=scanf("%s", &(ps->data[ps->size].name));
		printf("请输入性别->");
		i=scanf("%s", &(ps->data[ps->size].sex));		
		printf("请输入电话->");
		i=scanf("%s", &(ps->data[ps->size].tele));		
		printf("请输入住址->");
		i=scanf("%s", &(ps->data[ps->size].addr));		
		printf("请输入年龄->");
		i=scanf("%d", &(ps->data[ps->size].age));
		ps->size++;
		printf("录入成功\n");
	}
}

static void show1(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s%-10s%-15s%-20s%-3s\n", "姓名", "性别", "电话", "住址", "年龄");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s%-10s%-15s%-20s%-3d\n", ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr,
				ps->data[i].age);
		}
	}
}
void showcontact(const struct contact* ps)
{
	show1(ps);
}

static int find(struct contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;//找到并返回下标
		}
	}
	return -1;//找不到
}

void delcontact(struct contact* ps)
{
	int num = 0;
	char name[MAX_NAME];
	printf("请输入要删除人员姓名->");
	num=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos ==-1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-10s%-10s%-15s%-20s%-3s\n", "姓名", "性别", "电话", "住址", "年龄");
		printf("%-10s%-10s%-15s%-20s%-3d\n",
			    ps->data[pos].name,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr,
				ps->data[pos].age);
		num=getchar();
		printf("是否删除该信息—>	Y/N\n");
		static char input = 0;
		num=scanf("%c", &input);
		if (input == 'N')
		{
			goto out;
		}
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
out: 
	printf("不进行删除并返回\n");
}

void searchcontact(struct contact* ps)
{
	int co = 0;
	char name[MAX_NAME];
	printf("请输入要查找人员姓名->");
	co=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-10s%-10s%-15s%-20s%-3s\n", "姓名", "性别", "电话", "住址", "年龄");
		printf("%-10s%-10s%-15s%-20s%-3d\n",
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr,
			ps->data[pos].age);
	}
}

void modifycontact(struct contact* ps)
{
	int co = 0;
	char name[MAX_NAME];
	printf("请输入要修改人员姓名->");
	co=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		int i = 0;
		printf("请输入姓名->");
		i = scanf("%s", &(ps->data[pos].name));
		printf("请输入性别->");
		i = scanf("%s", &(ps->data[pos].sex));
		printf("请输入电话->");
		i = scanf("%s", &(ps->data[pos].tele));
		printf("请输入住址->");
		i = scanf("%s", &(ps->data[pos].addr));
		printf("请输入年龄->");
		i = scanf("%d", &(ps->data[pos].age));
		printf("修改成功\n");
	}
}
static int compare(const void* ps1, const void* ps2)
{
	struct contact* a = (struct contact*)ps1;
	struct contact* b = (struct contact*)ps2;
	return *a->data->name - *b->data->name;
}

void sortcontact(struct contact* ps)
{
	printf("以姓名首字母进行排序\n");
	qsort(ps->data , ps->size, sizeof(ps->data[0]), compare);
	show1(ps);
}