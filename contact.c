#include"contact.h"
void initcontact(contact* ps)//通讯录初始化
{
	ps->info=(peoinfo*)malloc(MAX * sizeof(peoinfo));//动态开辟内存
	if (ps->info == NULL)//判断是否开辟成功
	{
		printf("程序错误，请重试\n");
		return;
	}
	ps->size = 0;//设置通讯录最初只有0个元素
	ps->max = MAX;//设置初始最大容量
	//将文件中保存的信息添加到通讯录中
	lodecontact(ps);
}

void check(contact* ps);

void lodecontact(contact* ps)//加载信息
{
	peoinfo tmp = { 0 };
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)//文件打开失败
	{
		printf("In lodecontact: %s\n", strerror(errno));//进行报错
		return;
	}
	else//开始读取文件并存放到通讯录中
	{
		int i = 0;
		while(fread(&(tmp), sizeof(peoinfo), 1, pfread))	//每次读取一行，放到tmp中
		{
			check(ps);//检测容量
			ps->info[ps->size] = tmp;//放到通讯录中
			ps->size++;//调整元素个数
		}
	}
	fclose(pfread);//关闭文件
	pfread = NULL;//指针置空
}


void check(contact* ps)
{
	if (ps->size == ps->max)
	{
		//已满，进行增容
		peoinfo* ptr=realloc(ps->info, (ps->max + 2) * sizeof(peoinfo));//调整现有空间大小
		if (ptr == NULL)//判断是否开辟成功
		{
			printf("程序错误，请重试\n");
			return;
		}
		else
		{
			ps->info = ptr;//传递指针
			ps->max += 2;//增加容量
			//printf("增容成功\n");
		}
	}
	else
	{
		//未满，可以继续使用

	}
}
void addinfomation(contact* ps)//添加信息
{
	check(ps);//判断当前容量是否被填满
	if (ps->size < ps->max)
	{
		int ret = 0;
		printf("请依次输入姓名、电话、年龄、性别、住址\n");
		ret = scanf("%s", ps->info[ps->size].name);
		ret = scanf("%s", ps->info[ps->size].tele);
		ret = scanf("%d", &(ps->info[ps->size].age));
		ret = scanf("%s", ps->info[ps->size].gender);
		ret = scanf("%s", ps->info[ps->size].address);
		ps->size++;
		printf("信息录入成功\n");
	}
	else
	{
		printf("容量不足，请进行扩容\n");
	}
}

static int judge(contact* ps,char name[10])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->info[i].name, name) == 0)
		{
			return i;//找到则返回下标
		}
	}
	return -1;//未找到返回-1
}
static void show1(contact* ps,int num)//进行单次打印
{
	printf("%-10s", "姓名");
	printf("%-15s", "电话");
	printf("%-10s", "年龄");
	printf("%-10s", "性别");
	printf("%-30s", "地址");
	printf("\n");
	printf("%-10s", ps->info[num].name);
	printf("%-15s", ps->info[num].tele);
	printf("%-10d", ps->info[num].age);
	printf("%-10s", ps->info[num].gender);
	printf("%-30s", ps->info[num].address);
	printf("\n");
}
void deletecontact(contact* ps)//删除通讯录指定信息
{
	char arr[10];
	int ret = 0;
	int ret1 = 0;//接收scanf函数返回值以解除警告
	int j = 0;
	printf("请输入要删除人员姓名:>");
	ret1=scanf("%s", arr);
	ret=judge(ps, arr);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("即将删除该信息……\n");

		show1(ps, ret);
		Sleep(2000);
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->info[j] = ps->info[j + 1];//从后向前覆盖实现删除
		}
		ps->size--;//相应地，总下标减一

		printf("删除成功……\n");
	}
}

void seekcontact(contact* ps)//查找指定信息
{
	char name[10];
	int ret = 0;
	int ret1 = 0;
	printf("请输入指定查找人员姓名:>");
	ret1 = scanf("%s", name);
	ret=judge(ps, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("查找结果如下……\n");
		show1(ps, ret);
		printf("\n");
	}
}

void changecontact(contact* ps)//更改指定信息
{
	char name[10];
	int ret = 0;
	int ret1 = 0;
	printf("请输入指定查找人员姓名:>");
	ret1 = scanf("%s", name);
	ret = judge(ps, name);
	if (ret == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("查找结果如下……\n");
		show1(ps, ret);
		printf("请依次输入更改后的姓名、电话、年龄、性别、住址\n");
		ret1 = scanf("%s", ps->info[ret].name);
		ret1 = scanf("%s", ps->info[ret].tele);
		ret1 = scanf("%d", &(ps->info[ret].age));
		ret1 = scanf("%s", ps->info[ret].gender);
		ret1 = scanf("%s", ps->info[ret].address);
		show1(ps, ret);
		printf("信息更改成功\n");
	}

}

static void show2(contact* ps)//打印通讯录全部内容
{
	int i = 0;
	printf("%-10s", "姓名");
	printf("%-15s", "电话");
	printf("%-10s", "年龄");
	printf("%-10s", "性别");
	printf("%-30s", "地址");
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

void showcontact(contact* ps)//显示通讯录
{
	if (ps->size > 0)
	{
		show2(ps);
	}
	else
	{
		printf("本通讯录为空\n");
	}
}

static int compare(const void* p1, const void* p2)
{
	return (int)(*((peoinfo*)p1)->name) - (int)(*((peoinfo*)p2)->name);
}

void sortcontact(contact* ps)//对通讯录进行排序
{
	int sz = sizeof(ps->info[0]);
	printf("按照姓名首字母排序……\n");
	qsort(ps->info, ps->size, sz, compare);
	show2(ps);
}

void distorycontact(contact* ps)//释放开辟的动态内存
{
	free(ps->info);//内存释放
	ps->info = NULL;//指针置空
}

void savecontact(contact* ps)//对通讯录进行保存
{
	FILE* pf = fopen("contact.txt","wb");
	if (ps == NULL)
	{
		printf("In savecontact: %s\n", strerror(errno));//文件打开失败
		return;
	}
	else//将数据写入文件中
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->info[i]), sizeof(peoinfo), 1, pf);//每次写入一个一行通讯录信息
		}
	}
	printf("保存成功\n");
	fclose(pf);//关闭文件
	pf = NULL;//指针置空
}


