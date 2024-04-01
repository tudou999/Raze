#define _CRT_SECURE_NO_WARNINGS
#include "Hsort.h"

//插入排序
void InsertSort(long * arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		//最开始，将数组第一个元素划分为有序数列，右边是无序数列
		//因此元素下标从1开始，于是i-1就变为有序数列的尾
		long number = arr[i];
		for (int j = i; j > 0; j--)
		{
			//如果数字比前一个大或等于前一个，直接插入
			if (number >= arr[j - 1])
				break;
			//如果比前一个小，则继续寻找
			else
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = number;
			}
		}
	}
}

//合并
void merge(long * arr,  long* tempArr, int left, int mid, int right)
{
	//左半区第一个未排序的元素
	int left_not1 = left;
	//右半区第一个未排序的元素
	int right_not1 = mid + 1;
	//临时数组元素下标
	int temp_subscript = left;

	//进行合并
	while (left_not1 <= mid && right_not1 <= right)
	{
		//如果左半区第一个元素更小
		if (arr[left_not1] < arr[right_not1])
			tempArr[temp_subscript++] = arr[left_not1++];

		//如果右半区第一个元素更小
		else
			tempArr[temp_subscript++] = arr[right_not1++];
	}

	//当有半区到达终点时循环停止，因此大概率有一个半区有剩余元素
	
	//合并左半区剩余元素
	while(left_not1 <= mid)
		tempArr[temp_subscript++] = arr[left_not1++];
	//合并右半区剩余元素
	while(right_not1 <= right)
		tempArr[temp_subscript++] = arr[right_not1++];

	//使用循环将原无序数组替换为有序数组
	for (; left <= right; left++)
		arr[left] = tempArr[left];
}

//拆分+合并
void Separate( long* arr,  long* tempArr, int left, int right)
{
	//如果左半区还有两个以上元素，定义中间点进行划分
	if (left < right)
	{
		int mid = (left + right) / 2;

		//递归划分左半区
		Separate(arr, tempArr, left, mid);

		//递归划分右半区
		Separate(arr, tempArr, mid + 1, right);
		//至此数组被完全拆分

		//进行合并操作
		merge(arr, tempArr, left, mid, right);
	}
}

//归并排序总函数
void MergeSort(long* arr, int n)
{
	//定义临时数组用于辅助
	long* tempArr = (long*)malloc(n * sizeof(long));

	Separate(arr, tempArr, 0, n - 1);
	free(tempArr);
}

//快速排序（填坑法）
void fillhole(long arr[], int left, int right)
{
	//定义头和尾
	int left_temp = left, right_temp = right;
	//定义中间数temp（选取数组的第一个数）
	int temp = arr[left_temp];
	int hole = left;

	//数组只有一个元素
	if (left >= right)
		return;

	//进行中轴数左右区域的划分
	while (left_temp < right_temp)
	{
		//如果尾数大于中轴数，尾数不动，尾下标向左移动一位
		while (left_temp < right_temp && arr[right_temp] >= temp)
			right_temp--;
		//找到异常后填坑
		arr[hole] = arr[right_temp];
		//坑位移动
		hole = right_temp;

		//如果头数小于中轴数，头数不动，头下标向右移动一位
		while (left_temp < right_temp && arr[left_temp] <= temp)
			left_temp++;
		//找到异常后填坑
		arr[hole] = arr[left_temp];
		//坑位移动
		hole = left_temp;
	}

	arr[hole] = temp;

	//对左右半区进行快速排序
	fillhole(arr, left, left_temp - 1);
	fillhole(arr, left_temp + 1, right);
}

//快速排序总函数
void QuickSort(long* arr, int n)
{
	fillhole(arr, 0, n - 1);
}

//计数排序
void CountSort(long* arr, int n)
{
	//首先找出最大值和最小值
	long max = arr[0],
		min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//计算范围
	long  range = max - min + 1;

	//动态开辟临时数组
	long* temp = (long*)calloc(range, sizeof(long));

	for (int i = 0; i < range; i++)
		temp[i] = 0;

	//统计数组a每个元素出现的次数
	for (int i = 0; i < n; i++)
		temp[arr[i] - min]++;

	for (int i = 0, j = 0; i < range; i++)
	{
		//判断temp数组该元素是否有计数
		while (temp[i])
		{
			//如果有就把该元素的下标值反映射至数组a，然后计数器-1
			arr[j++] = i + min;
			temp[i]--;
		}
	}

	//释放临时数组
	free(temp);
	temp = NULL;
}

//基数排序
void RadixCountSort(long* arr, int n)
{
	//因为最高位是决定性的，所以放最后进行比较（如果刚开始就比较，那么最低位就会影响排序）

	//找最大值
	long max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	//radix是最大数的位数
	int radix = 1;
	while (max >= 10)
	{
		max /= 10;
		++radix;
	}

	int digit = 1;

	long* temp = (long*)malloc(n * sizeof(long));

	for (int f = 0; f < radix; f++, digit *= 10)
	{
		//定义十个桶，存放每一轮排序对应位的个数
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[(arr[i] / digit) % 10]++;

		//依次累加桶里的元素，获得元素应该存放的位置
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];

		//将数字赋值到临时数组中
		for (int i = n - 1; i >= 0; i--)
		{
			temp[bucket[arr[i] / digit % 10] - 1] = arr[i];
			bucket[arr[i] / digit % 10]--;
		}

		//将排好序的数组赋值回arr
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}

	free(temp);
}

//颜色排序
void ColorSort(int* arr, int n)
{
	//p_zero用于控制0，p_two用来控制2，p用来遍历
	int p_zero = 0,
		p_two = n - 1,
		p = 0;

	//遍历，排序
	for (; p <= p_two;)
	{
		//p左边已经扫描过，所以直接+1
		if (arr[p] == 0)
		{
			int temp = arr[p];
			arr[p++] = arr[p_zero];
			arr[p_zero++] = temp;
		}

		//p左边没有扫描过，所以不变
		if (arr[p] == 2)
		{
			int temp = arr[p];
			arr[p] = arr[p_two];
			arr[p_two--] = temp;
		}

		if (arr[p] == 1)
			p++;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

//颜色排序总函数
void CS()
{
	//定义颜色数组a_color
	int a_color[6] = { 2,0,2,1,1,0 };

	//输出颜色数组
	for (int i = 0; i < sizeof(a_color) / sizeof(int); i++)
		printf("%d ", a_color[i]);
	printf("\n");

	ColorSort(a_color, 6);
}

//在一个无序序列中找到第K小的数
void search(int* arr, int left, int right, int k)
{
	//定义头和尾
	int left_temp = left, right_temp = right;
	//定义中间数temp（选取数组的第一个数）
	int temp = arr[left_temp];
	int hole = left;

	//数组只有一个元素
	if (left >= right)
		return;

	//进行中轴数左右区域的划分
	while (left_temp < right_temp)
	{
		//如果尾数大于中轴数，尾数不动，尾下标向左移动一位
		while (left_temp < right_temp && arr[right_temp] >= temp)
			right_temp--;
		//找到异常后填坑
		arr[hole] = arr[right_temp];
		//坑位移动
		hole = right_temp;

		//如果头数小于中轴数，头数不动，头下标向右移动一位
		while (left_temp < right_temp && arr[left_temp] <= temp)
			left_temp++;
		//找到异常后填坑
		arr[hole] = arr[left_temp];
		//坑位移动
		hole = left_temp;
	}

	arr[hole] = temp;

	if (hole == k)
	{
		printf("第k小的数为：%d\n", arr[hole]);
		return;
	}

	if (k < hole)
		search(arr, left, left_temp - 1, k);
	if (k > hole)
		search(arr, left_temp + 1, right, k);
}

//找K总函数
void Ksearch(int* arr, int n)
{
	//要找的位置
	int k;
	printf("请输入您要找第几小的元素：");
	scanf("%d", &k);

	while (k > n || k < 1)
	{
		printf("您输入的数据非法，请重新输入！\n");
		printf("请输入您要找第几小的元素：");
		scanf("%d", &k);
	}

	search(arr, 0, n - 1, k - 1);
}

//判断非法输入
int errorinput(char ch)
{
	if (ch < '1' || ch > '7')
		return 0;
	return 1;
}

//定义显示主菜单的函数
void DisplayMainMenu()
{
	//输出边界线
	printf("\n======================\n");

	//输出主体
	for (int i = 0; i < 6; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//不同大数据量
void BIG()
{
	clock_t start, diff;
	long a1[10], a2[50000], a3[200000];
	int n1 = 10, n2 = 50000, n3 = 200000;

	//利用for循环将随机数赋值给a
	for (int i = 0; i < n1; i++)
		a1[i] = rand() % 100 + 1;

	for (int i = 0; i < n2; i++)
		a2[i] = rand() % 100 + 1;
	
	for (int i = 0; i < n3; i++)
		a3[i] = rand() % 100 + 1;

	FILE* fp; 
	fp = fopen("./big.txt", "a");

	printf("数据量为10000时：\n");
	fprintf(fp, "数据量为10000时：\n");

	start = clock();
	InsertSort(a1, n1);
	diff = clock() - start;
	printf("插入排序总耗时为%d ms\n", diff);
	fprintf(fp, "插入排序总耗时为%d ms\n", diff);

	start = clock();
	MergeSort(a1, n1);
	diff = clock() - start;
	printf("归并排序总耗时为%d ms\n", diff);
	fprintf(fp, "归并排序总耗时为%d ms\n", diff);

	start = clock();
	QuickSort(a1, n1);	
	diff = clock() - start;
	printf("快速排序总耗时为%d ms\n", diff);
	fprintf(fp, "快速排序总耗时为%d ms\n", diff);

	start = clock();
	CountSort(a1, n1);	
	diff = clock() - start;
	printf("计数排序总耗时为%d ms\n", diff);
	fprintf(fp, "计数排序总耗时为%d ms\n", diff);

	start = clock();
	RadixCountSort(a1, n1);
	diff = clock() - start;
	printf("基数排序总耗时为%d ms\n", diff);
	printf("\n");
	fprintf(fp, "基数排序总耗时为%d ms\n", diff);
	fprintf(fp, "\n");

	printf("数据量为50000时：\n");
	fprintf(fp, "数据量为50000时：\n");

	start = clock();
	InsertSort(a2, n2);
	diff = clock() - start;
	printf("插入排序总耗时为%d ms\n", diff);
	fprintf(fp, "插入排序总耗时为%d ms\n", diff);

	start = clock();
	MergeSort(a2, n2);
	diff = clock() - start;
	printf("归并排序总耗时为%d ms\n", diff);
	fprintf(fp, "归并排序总耗时为%d ms\n", diff);

	start = clock();
	QuickSort(a2, n2);
	diff = clock() - start;
	printf("快速排序总耗时为%d ms\n", diff);
	fprintf(fp, "快速排序总耗时为%d ms\n", diff);

	start = clock();
	CountSort(a2, n2);
	diff = clock() - start;
	printf("计数排序总耗时为%d ms\n", diff);
	fprintf(fp, "计数排序总耗时为%d ms\n", diff);

	start = clock();
	RadixCountSort(a2, n2);
	diff = clock() - start;
	printf("基数排序总耗时为%d ms\n", diff);
	printf("\n");
	fprintf(fp, "基数排序总耗时为%d ms\n", diff);
	fprintf(fp, "\n");

	printf("数据量为200000时：\n");
	fprintf(fp, "数据量为200000时：\n");

	start = clock();
	InsertSort(a3, n3);
	diff = clock() - start;
	printf("插入排序总耗时为%d ms\n", diff);
	fprintf(fp, "插入排序总耗时为%d ms\n", diff);

	start = clock();
	MergeSort(a3, n3);
	diff = clock() - start;
	printf("归并排序总耗时为%d ms\n", diff);
	fprintf(fp, "归并排序总耗时为%d ms\n", diff);

	start = clock();
	QuickSort(a3, n3);
	diff = clock() - start;
	printf("快速排序总耗时为%d ms\n", diff);
	fprintf(fp, "快速排序总耗时为%d ms\n", diff);

	start = clock();
	CountSort(a3, n3);
	diff = clock() - start;
	printf("计数排序总耗时为%d ms\n", diff);
	fprintf(fp, "计数排序总耗时为%d ms\n", diff);

	start = clock();
	RadixCountSort(a3, n3);
	diff = clock() - start;
	printf("基数排序总耗时为%d ms\n", diff);
	fprintf(fp, "基数排序总耗时为%d ms\n", diff);

	printf("\n");
	fprintf(fp, "\n");
	fclose(fp);
}

//大量小数据量
void SMALL()
{
	clock_t start, diff;

	long a_small[100];
	int n = 100;

	FILE* fp;
	fp = fopen("./small.txt", "a");

	printf("大量小数据量的情况下：\n");
	fprintf(fp, "大量小数据量的情况下：\n");

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//利用for循环将随机数赋值给a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		InsertSort(a_small, n);
	}
	diff = clock() - start;
	printf("插入排序总耗时为%d ms\n", diff);
	fprintf(fp, "插入排序总耗时为%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//利用for循环将随机数赋值给a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		MergeSort(a_small, n);
	}
	diff = clock() - start;
	printf("归并排序总耗时为%d ms\n", diff);
	fprintf(fp, "归并排序总耗时为%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//利用for循环将随机数赋值给a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		QuickSort(a_small, n);
	}
	diff = clock() - start;
	printf("快速排序总耗时为%d ms\n", diff);
	fprintf(fp, "快速排序总耗时为%d ms\n", diff);


		
	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//利用for循环将随机数赋值给a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		CountSort(a_small, n);
	}
	diff = clock() - start;
	printf("计数排序总耗时为%d ms\n", diff);
	fprintf(fp, "计数排序总耗时为%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//利用for循环将随机数赋值给a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		RadixCountSort(a_small, n);
	}
	diff = clock() - start;
	printf("基数排序总耗时为%d ms\n", diff);
	fprintf(fp, "基数排序总耗时为%d ms\n", diff);
	fprintf(fp, "\n");

	fclose(fp);
}

//读取数据
void read()
{
	int a_read[100];
	int i = 0;

	FILE* fp;
	fp = fopen("./data.txt", "r");

	while (fscanf(fp, "%d", &a_read[i++]) != EOF);
	{}

	fclose(fp);

	for (int i = 0; i < 100; i++)
		printf("%d ", a_read[i]);
	printf("\n");

	//使用快速排序
	QuickSort(a_read, 100);

	for (int i = 0; i < 100; i++)
		printf("%d ", a_read[i]);

	printf("\n");
}


int main()
{
	int Knumbers[10];
	for (int i = 0; i < 10; i++)
		Knumbers[i] = rand();

	char number;
	DisplayMainMenu();
	while (1)
	{
		printf("请输入您想实现的功能（输入数字1-7）后点击回车：");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("您输入的数字不合规范，请重新输入！\n");
			printf("请输入您想实现的功能（输入数字1-7）后点击回车：");
			scanf("%s", &number);
		}

		switch (number - '0')
		{
		//不同大数据量
		case 1:
			BIG();
			break;
			
		//大量小数据量
		case 2:
			SMALL();
			break;

		//读取文件数据
		case 3:
			read();
			break;

		//颜色排序
		case 4:
			CS();
			break;

		//找出第k小的数
		case 5:
			for (int i = 0; i < 10; i++)
				printf("%d ", Knumbers[i]);
			printf("\n");
			Ksearch(Knumbers, 10);
			break;

		case 6:
			number = '0';
			return;
		}
	}
}
