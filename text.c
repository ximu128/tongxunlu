#define _CRT_SECURE_NO_WARNINGS 
#include"address_list.h"
void menu()
{
	printf("***************************************\n");
	printf("*******    1.add       2.del    *******\n");
	printf("*******    3.search    4.modify *******\n");
	printf("*******    5.show      6.sort   *******\n");
	printf("*******    0.exit1               *******\n");
	printf("***************************************\n");
}
int main()
{
	int input = 0;
	//����һ��ͨѶ¼
	struct contact con;
	//ͨѶ¼��ʼ��
	initialize(&con);
	do
	{
		int cx = 0;
		menu();
		printf("����й���ѡ��->");
		cx=scanf("%d", &input);
		switch (input)
		{
			case add:
				addcontact(&con);//��ͨѶ¼�����Ϣ
				break;
			case del:
				delcontact(&con);//ɾ��ָ����Ա����Ϣ
				break;
			case search:
				searchcontact(&con);//����ָ����Ա��Ϣ
				break;
			case modify:
				modifycontact(&con);
				break;
			case show:
				showcontact(&con);//��ʾͨѶ¼
				break;
			case sort:
				sortcontact(&con);
				break;
			case exit1:
				printf("�˳�ͨѶ¼\n");
				break;
			default:
				printf("ѡ����Ч��������ѡ��\n");
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}