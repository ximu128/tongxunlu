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
	//创建一个通讯录
	struct contact con;
	//通讯录初始化
	initialize(&con);
	do
	{
		int cx = 0;
		menu();
		printf("请进行功能选择->");
		cx=scanf("%d", &input);
		switch (input)
		{
			case add:
				addcontact(&con);//向通讯录添加信息
				break;
			case del:
				delcontact(&con);//删除指定人员的信息
				break;
			case search:
				searchcontact(&con);//查找指定人员信息
				break;
			case modify:
				modifycontact(&con);
				break;
			case show:
				showcontact(&con);//显示通讯录
				break;
			case sort:
				sortcontact(&con);
				break;
			case exit1:
				printf("退出通讯录\n");
				break;
			default:
				printf("选择无效，请重新选择\n");
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}