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
	int input = 0;//用于功能选择
	int ret = 0;//接收函数返回值
	contact mem;//创建一个通讯录
	initcontact(&mem);//通讯录初始化
	do
	{
		menu();//展开菜单
		printf("请进行功能选择:>");
		ret=scanf("%d", &input);
		switch (input)
		{
		case ADD://增加信息
			addinfomation(&mem);
			break;
		case DEL://删除信息
			deletecontact(&mem);
			break;
		case SEEK://查找信息
			seekcontact(&mem);
			break;
		case CHANGE://修改信息
			changecontact(&mem);
			break;
		case SHOW://显示信息
			showcontact(&mem);
			break;
		case SORT://对信息进行排序
			sortcontact(&mem);
			break;
		case SAVE://保存信息
			savecontact(&mem);
			break;
		case EXIT://退出程序
			savecontact(&mem);//保存
			printf("退出程序\n");
			distorycontact(&mem);//销毁通讯录，释放开辟的动态内存
			break;
		default:
			printf("选择错误，请重新进行选择\n");
		}

	} while (input);
	return 0;
}