#include"contact.h"

void menu()
{
	printf("************************************************\n");
	printf("***********    1.ADD     2.DELETE    ***********\n");
	printf("***********    3.SEEK    4.CHANGE    ***********\n");
	printf("***********    5.SHOW    5.SORT      ***********\n");
	printf("***********    7.SAVE    0.EXIT      ***********\n");
	printf("************************************************\n");

}
int main()
{
	int input = 0;//���ڹ���ѡ��
	int ret = 0;//���պ�������ֵ
	contact mem;//����һ��ͨѶ¼
	initcontact(&mem);//ͨѶ¼��ʼ��
	do
	{
		menu();//չ���˵�
		printf("����й���ѡ��:>");
		ret=scanf("%d", &input);
		switch (input)
		{
		case ADD://������Ϣ
			addinfomation(&mem);
			break;
		case DEL://ɾ����Ϣ
			deletecontact(&mem);
			break;
		case SEEK://������Ϣ
			seekcontact(&mem);
			break;
		case CHANGE://�޸���Ϣ
			changecontact(&mem);
			break;
		case SHOW://��ʾ��Ϣ
			showcontact(&mem);
			break;
		case SORT://����Ϣ��������
			sortcontact(&mem);
			break;
		case SAVE://������Ϣ
			savecontact(&mem);
			break;
		case EXIT://�˳�����
			savecontact(&mem);//����
			printf("�˳�����\n");
			distorycontact(&mem);//����ͨѶ¼���ͷſ��ٵĶ�̬�ڴ�
			break;
		default:
			printf("ѡ����������½���ѡ��\n");
		}

	} while (input);
	return 0;
}