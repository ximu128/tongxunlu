#include"contact.h"
void initcontact(contact* ps)//ͨѶ¼��ʼ��
{
	ps->info=(peoinfo*)malloc(MAX * sizeof(peoinfo));//��̬�����ڴ�
	if (ps->info == NULL)//�ж��Ƿ񿪱ٳɹ�
	{
		printf("�������������\n");
		return;
	}
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
	ps->max = MAX;//���ó�ʼ�������
	//���ļ��б������Ϣ��ӵ�ͨѶ¼��
	lodecontact(ps);
}

void check(contact* ps);

void lodecontact(contact* ps)//������Ϣ
{
	peoinfo tmp = { 0 };
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)//�ļ���ʧ��
	{
		printf("In lodecontact: %s\n", strerror(errno));//���б���
		return;
	}
	else//��ʼ��ȡ�ļ�����ŵ�ͨѶ¼��
	{
		int i = 0;
		while(fread(&(tmp), sizeof(peoinfo), 1, pfread))	//ÿ�ζ�ȡһ�У��ŵ�tmp��
		{
			check(ps);//�������
			ps->info[ps->size] = tmp;//�ŵ�ͨѶ¼��
			ps->size++;//����Ԫ�ظ���
		}
	}
	fclose(pfread);//�ر��ļ�
	pfread = NULL;//ָ���ÿ�
}


void check(contact* ps)
{
	if (ps->size == ps->max)
	{
		//��������������
		peoinfo* ptr=realloc(ps->info, (ps->max + 2) * sizeof(peoinfo));//�������пռ��С
		if (ptr == NULL)//�ж��Ƿ񿪱ٳɹ�
		{
			printf("�������������\n");
			return;
		}
		else
		{
			ps->info = ptr;//����ָ��
			ps->max += 2;//��������
			//printf("���ݳɹ�\n");
		}
	}
	else
	{
		//δ�������Լ���ʹ��

	}
}
void addinfomation(contact* ps)//�����Ϣ
{
	check(ps);//�жϵ�ǰ�����Ƿ�����
	if (ps->size < ps->max)
	{
		int ret = 0;
		printf("�����������������绰�����䡢�Ա�סַ\n");
		ret = scanf("%s", ps->info[ps->size].name);
		ret = scanf("%s", ps->info[ps->size].tele);
		ret = scanf("%d", &(ps->info[ps->size].age));
		ret = scanf("%s", ps->info[ps->size].gender);
		ret = scanf("%s", ps->info[ps->size].address);
		ps->size++;
		printf("��Ϣ¼��ɹ�\n");
	}
	else
	{
		printf("�������㣬���������\n");
	}
}

static int judge(contact* ps,char name[10])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->info[i].name, name) == 0)
		{
			return i;//�ҵ��򷵻��±�
		}
	}
	return -1;//δ�ҵ�����-1
}
static void show1(contact* ps,int num)//���е��δ�ӡ
{
	printf("%-10s", "����");
	printf("%-15s", "�绰");
	printf("%-10s", "����");
	printf("%-10s", "�Ա�");
	printf("%-30s", "��ַ");
	printf("\n");
	printf("%-10s", ps->info[num].name);
	printf("%-15s", ps->info[num].tele);
	printf("%-10d", ps->info[num].age);
	printf("%-10s", ps->info[num].gender);
	printf("%-30s", ps->info[num].address);
	printf("\n");
}
void deletecontact(contact* ps)//ɾ��ͨѶ¼ָ����Ϣ
{
	char arr[10];
	int ret = 0;
	int ret1 = 0;//����scanf��������ֵ�Խ������
	int j = 0;
	printf("������Ҫɾ����Ա����:>");
	ret1=scanf("%s", arr);
	ret=judge(ps, arr);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("����ɾ������Ϣ����\n");

		show1(ps, ret);
		Sleep(2000);
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->info[j] = ps->info[j + 1];//�Ӻ���ǰ����ʵ��ɾ��
		}
		ps->size--;//��Ӧ�أ����±��һ

		printf("ɾ���ɹ�����\n");
	}
}

void seekcontact(contact* ps)//����ָ����Ϣ
{
	char name[10];
	int ret = 0;
	int ret1 = 0;
	printf("������ָ��������Ա����:>");
	ret1 = scanf("%s", name);
	ret=judge(ps, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("���ҽ�����¡���\n");
		show1(ps, ret);
		printf("\n");
	}
}

void changecontact(contact* ps)//����ָ����Ϣ
{
	char name[10];
	int ret = 0;
	int ret1 = 0;
	printf("������ָ��������Ա����:>");
	ret1 = scanf("%s", name);
	ret = judge(ps, name);
	if (ret == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("���ҽ�����¡���\n");
		show1(ps, ret);
		printf("������������ĺ���������绰�����䡢�Ա�סַ\n");
		ret1 = scanf("%s", ps->info[ret].name);
		ret1 = scanf("%s", ps->info[ret].tele);
		ret1 = scanf("%d", &(ps->info[ret].age));
		ret1 = scanf("%s", ps->info[ret].gender);
		ret1 = scanf("%s", ps->info[ret].address);
		show1(ps, ret);
		printf("��Ϣ���ĳɹ�\n");
	}

}

static void show2(contact* ps)//��ӡͨѶ¼ȫ������
{
	int i = 0;
	printf("%-10s", "����");
	printf("%-15s", "�绰");
	printf("%-10s", "����");
	printf("%-10s", "�Ա�");
	printf("%-30s", "��ַ");
	printf("\n");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-10s", ps->info[i].name);
		printf("%-15s", ps->info[i].tele);
		printf("%-10d", ps->info[i].age);
		printf("%-10s", ps->info[i].gender);
		printf("%-30s", ps->info[i].address);
		printf("\n");
	}
}

void showcontact(contact* ps)//��ʾͨѶ¼
{
	if (ps->size > 0)
	{
		show2(ps);
	}
	else
	{
		printf("��ͨѶ¼Ϊ��\n");
	}
}

static int compare(const void* p1, const void* p2)
{
	return (int)(*((peoinfo*)p1)->name) - (int)(*((peoinfo*)p2)->name);
}

void sortcontact(contact* ps)//��ͨѶ¼��������
{
	int sz = sizeof(ps->info[0]);
	printf("������������ĸ���򡭡�\n");
	qsort(ps->info, ps->size, sz, compare);
	show2(ps);
}

void distorycontact(contact* ps)//�ͷſ��ٵĶ�̬�ڴ�
{
	free(ps->info);//�ڴ��ͷ�
	ps->info = NULL;//ָ���ÿ�
}

void savecontact(contact* ps)//��ͨѶ¼���б���
{
	FILE* pf = fopen("contact.txt","wb");
	if (ps == NULL)
	{
		printf("In savecontact: %s\n", strerror(errno));//�ļ���ʧ��
		return;
	}
	else//������д���ļ���
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->info[i]), sizeof(peoinfo), 1, pf);//ÿ��д��һ��һ��ͨѶ¼��Ϣ
		}
	}
	printf("����ɹ�\n");
	fclose(pf);//�ر��ļ�
	pf = NULL;//ָ���ÿ�
}


