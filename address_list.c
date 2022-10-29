#define _CRT_SECURE_NO_WARNINGS 1

#include"address_list.h"

void initialize(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

void addcontact(struct contact* ps)
{
	int i = 0;
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����������г�ֵ����\n");
	}
	else
	{
		printf("����������->");
		i=scanf("%s", &(ps->data[ps->size].name));
		printf("�������Ա�->");
		i=scanf("%s", &(ps->data[ps->size].sex));		
		printf("������绰->");
		i=scanf("%s", &(ps->data[ps->size].tele));		
		printf("������סַ->");
		i=scanf("%s", &(ps->data[ps->size].addr));		
		printf("����������->");
		i=scanf("%d", &(ps->data[ps->size].age));
		ps->size++;
		printf("¼��ɹ�\n");
	}
}

static void show1(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s%-10s%-15s%-20s%-3s\n", "����", "�Ա�", "�绰", "סַ", "����");
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
			return i;//�ҵ��������±�
		}
	}
	return -1;//�Ҳ���
}

void delcontact(struct contact* ps)
{
	int num = 0;
	char name[MAX_NAME];
	printf("������Ҫɾ����Ա����->");
	num=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos ==-1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-10s%-10s%-15s%-20s%-3s\n", "����", "�Ա�", "�绰", "סַ", "����");
		printf("%-10s%-10s%-15s%-20s%-3d\n",
			    ps->data[pos].name,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr,
				ps->data[pos].age);
		num=getchar();
		printf("�Ƿ�ɾ������Ϣ��>	Y/N\n");
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
		printf("ɾ���ɹ�\n");
	}
out: 
	printf("������ɾ��������\n");
}

void searchcontact(struct contact* ps)
{
	int co = 0;
	char name[MAX_NAME];
	printf("������Ҫ������Ա����->");
	co=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%-10s%-10s%-15s%-20s%-3s\n", "����", "�Ա�", "�绰", "סַ", "����");
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
	printf("������Ҫ�޸���Ա����->");
	co=scanf("%s", &name);
	int pos = find(ps, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		int i = 0;
		printf("����������->");
		i = scanf("%s", &(ps->data[pos].name));
		printf("�������Ա�->");
		i = scanf("%s", &(ps->data[pos].sex));
		printf("������绰->");
		i = scanf("%s", &(ps->data[pos].tele));
		printf("������סַ->");
		i = scanf("%s", &(ps->data[pos].addr));
		printf("����������->");
		i = scanf("%d", &(ps->data[pos].age));
		printf("�޸ĳɹ�\n");
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
	printf("����������ĸ��������\n");
	qsort(ps->data , ps->size, sizeof(ps->data[0]), compare);
	show1(ps);
}