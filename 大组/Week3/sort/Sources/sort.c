#define _CRT_SECURE_NO_WARNINGS
#include "Hsort.h"

//��������
void InsertSort(long * arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		//�ʼ���������һ��Ԫ�ػ���Ϊ�������У��ұ�����������
		//���Ԫ���±��1��ʼ������i-1�ͱ�Ϊ�������е�β
		long number = arr[i];
		for (int j = i; j > 0; j--)
		{
			//������ֱ�ǰһ��������ǰһ����ֱ�Ӳ���
			if (number >= arr[j - 1])
				break;
			//�����ǰһ��С�������Ѱ��
			else
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = number;
			}
		}
	}
}

//�ϲ�
void merge(long * arr,  long* tempArr, int left, int mid, int right)
{
	//�������һ��δ�����Ԫ��
	int left_not1 = left;
	//�Ұ�����һ��δ�����Ԫ��
	int right_not1 = mid + 1;
	//��ʱ����Ԫ���±�
	int temp_subscript = left;

	//���кϲ�
	while (left_not1 <= mid && right_not1 <= right)
	{
		//����������һ��Ԫ�ظ�С
		if (arr[left_not1] < arr[right_not1])
			tempArr[temp_subscript++] = arr[left_not1++];

		//����Ұ�����һ��Ԫ�ظ�С
		else
			tempArr[temp_subscript++] = arr[right_not1++];
	}

	//���а��������յ�ʱѭ��ֹͣ����˴������һ��������ʣ��Ԫ��
	
	//�ϲ������ʣ��Ԫ��
	while(left_not1 <= mid)
		tempArr[temp_subscript++] = arr[left_not1++];
	//�ϲ��Ұ���ʣ��Ԫ��
	while(right_not1 <= right)
		tempArr[temp_subscript++] = arr[right_not1++];

	//ʹ��ѭ����ԭ���������滻Ϊ��������
	for (; left <= right; left++)
		arr[left] = tempArr[left];
}

//���+�ϲ�
void Separate( long* arr,  long* tempArr, int left, int right)
{
	//��������������������Ԫ�أ������м����л���
	if (left < right)
	{
		int mid = (left + right) / 2;

		//�ݹ黮�������
		Separate(arr, tempArr, left, mid);

		//�ݹ黮���Ұ���
		Separate(arr, tempArr, mid + 1, right);
		//�������鱻��ȫ���

		//���кϲ�����
		merge(arr, tempArr, left, mid, right);
	}
}

//�鲢�����ܺ���
void MergeSort(long* arr, int n)
{
	//������ʱ�������ڸ���
	long* tempArr = (long*)malloc(n * sizeof(long));

	Separate(arr, tempArr, 0, n - 1);
	free(tempArr);
}

//����������ӷ���
void fillhole(long arr[], int left, int right)
{
	//����ͷ��β
	int left_temp = left, right_temp = right;
	//�����м���temp��ѡȡ����ĵ�һ������
	int temp = arr[left_temp];
	int hole = left;

	//����ֻ��һ��Ԫ��
	if (left >= right)
		return;

	//������������������Ļ���
	while (left_temp < right_temp)
	{
		//���β��������������β��������β�±������ƶ�һλ
		while (left_temp < right_temp && arr[right_temp] >= temp)
			right_temp--;
		//�ҵ��쳣�����
		arr[hole] = arr[right_temp];
		//��λ�ƶ�
		hole = right_temp;

		//���ͷ��С����������ͷ��������ͷ�±������ƶ�һλ
		while (left_temp < right_temp && arr[left_temp] <= temp)
			left_temp++;
		//�ҵ��쳣�����
		arr[hole] = arr[left_temp];
		//��λ�ƶ�
		hole = left_temp;
	}

	arr[hole] = temp;

	//�����Ұ������п�������
	fillhole(arr, left, left_temp - 1);
	fillhole(arr, left_temp + 1, right);
}

//���������ܺ���
void QuickSort(long* arr, int n)
{
	fillhole(arr, 0, n - 1);
}

//��������
void CountSort(long* arr, int n)
{
	//�����ҳ����ֵ����Сֵ
	long max = arr[0],
		min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//���㷶Χ
	long  range = max - min + 1;

	//��̬������ʱ����
	long* temp = (long*)calloc(range, sizeof(long));

	for (int i = 0; i < range; i++)
		temp[i] = 0;

	//ͳ������aÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < n; i++)
		temp[arr[i] - min]++;

	for (int i = 0, j = 0; i < range; i++)
	{
		//�ж�temp�����Ԫ���Ƿ��м���
		while (temp[i])
		{
			//����оͰѸ�Ԫ�ص��±�ֵ��ӳ��������a��Ȼ�������-1
			arr[j++] = i + min;
			temp[i]--;
		}
	}

	//�ͷ���ʱ����
	free(temp);
	temp = NULL;
}

//��������
void RadixCountSort(long* arr, int n)
{
	//��Ϊ���λ�Ǿ����Եģ����Է������бȽϣ�����տ�ʼ�ͱȽϣ���ô���λ�ͻ�Ӱ������

	//�����ֵ
	long max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	//radix���������λ��
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
		//����ʮ��Ͱ�����ÿһ�������Ӧλ�ĸ���
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[(arr[i] / digit) % 10]++;

		//�����ۼ�Ͱ���Ԫ�أ����Ԫ��Ӧ�ô�ŵ�λ��
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];

		//�����ָ�ֵ����ʱ������
		for (int i = n - 1; i >= 0; i--)
		{
			temp[bucket[arr[i] / digit % 10] - 1] = arr[i];
			bucket[arr[i] / digit % 10]--;
		}

		//���ź�������鸳ֵ��arr
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}

	free(temp);
}

//��ɫ����
void ColorSort(int* arr, int n)
{
	//p_zero���ڿ���0��p_two��������2��p��������
	int p_zero = 0,
		p_two = n - 1,
		p = 0;

	//����������
	for (; p <= p_two;)
	{
		//p����Ѿ�ɨ���������ֱ��+1
		if (arr[p] == 0)
		{
			int temp = arr[p];
			arr[p++] = arr[p_zero];
			arr[p_zero++] = temp;
		}

		//p���û��ɨ��������Բ���
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

//��ɫ�����ܺ���
void CS()
{
	//������ɫ����a_color
	int a_color[6] = { 2,0,2,1,1,0 };

	//�����ɫ����
	for (int i = 0; i < sizeof(a_color) / sizeof(int); i++)
		printf("%d ", a_color[i]);
	printf("\n");

	ColorSort(a_color, 6);
}

//��һ�������������ҵ���KС����
void search(int* arr, int left, int right, int k)
{
	//����ͷ��β
	int left_temp = left, right_temp = right;
	//�����м���temp��ѡȡ����ĵ�һ������
	int temp = arr[left_temp];
	int hole = left;

	//����ֻ��һ��Ԫ��
	if (left >= right)
		return;

	//������������������Ļ���
	while (left_temp < right_temp)
	{
		//���β��������������β��������β�±������ƶ�һλ
		while (left_temp < right_temp && arr[right_temp] >= temp)
			right_temp--;
		//�ҵ��쳣�����
		arr[hole] = arr[right_temp];
		//��λ�ƶ�
		hole = right_temp;

		//���ͷ��С����������ͷ��������ͷ�±������ƶ�һλ
		while (left_temp < right_temp && arr[left_temp] <= temp)
			left_temp++;
		//�ҵ��쳣�����
		arr[hole] = arr[left_temp];
		//��λ�ƶ�
		hole = left_temp;
	}

	arr[hole] = temp;

	if (hole == k)
	{
		printf("��kС����Ϊ��%d\n", arr[hole]);
		return;
	}

	if (k < hole)
		search(arr, left, left_temp - 1, k);
	if (k > hole)
		search(arr, left_temp + 1, right, k);
}

//��K�ܺ���
void Ksearch(int* arr, int n)
{
	//Ҫ�ҵ�λ��
	int k;
	printf("��������Ҫ�ҵڼ�С��Ԫ�أ�");
	scanf("%d", &k);

	while (k > n || k < 1)
	{
		printf("����������ݷǷ������������룡\n");
		printf("��������Ҫ�ҵڼ�С��Ԫ�أ�");
		scanf("%d", &k);
	}

	search(arr, 0, n - 1, k - 1);
}

//�жϷǷ�����
int errorinput(char ch)
{
	if (ch < '1' || ch > '7')
		return 0;
	return 1;
}

//������ʾ���˵��ĺ���
void DisplayMainMenu()
{
	//����߽���
	printf("\n======================\n");

	//�������
	for (int i = 0; i < 6; i++)
		printf("%s\n", MainMenu[i]);

	printf("======================\n");
}

//��ͬ��������
void BIG()
{
	clock_t start, diff;
	long a1[10], a2[50000], a3[200000];
	int n1 = 10, n2 = 50000, n3 = 200000;

	//����forѭ�����������ֵ��a
	for (int i = 0; i < n1; i++)
		a1[i] = rand() % 100 + 1;

	for (int i = 0; i < n2; i++)
		a2[i] = rand() % 100 + 1;
	
	for (int i = 0; i < n3; i++)
		a3[i] = rand() % 100 + 1;

	FILE* fp; 
	fp = fopen("E:/text1.txt", "a");

	printf("������Ϊ10000ʱ��\n");
	fprintf(fp, "������Ϊ10000ʱ��\n");

	start = clock();
	InsertSort(a1, n1);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	MergeSort(a1, n1);
	diff = clock() - start;
	printf("�鲢�����ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "�鲢�����ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	QuickSort(a1, n1);	
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	CountSort(a1, n1);	
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	RadixCountSort(a1, n1);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	printf("\n");
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "\n");

	printf("������Ϊ50000ʱ��\n");
	fprintf(fp, "������Ϊ50000ʱ��\n");

	start = clock();
	InsertSort(a2, n2);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	MergeSort(a2, n2);
	diff = clock() - start;
	printf("�鲢�����ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "�鲢�����ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	QuickSort(a2, n2);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	CountSort(a2, n2);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	RadixCountSort(a2, n2);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	printf("\n");
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "\n");

	printf("������Ϊ200000ʱ��\n");
	fprintf(fp, "������Ϊ200000ʱ��\n");

	start = clock();
	InsertSort(a3, n3);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	MergeSort(a3, n3);
	diff = clock() - start;
	printf("�鲢�����ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "�鲢�����ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	QuickSort(a3, n3);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	CountSort(a3, n3);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	RadixCountSort(a3, n3);
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	printf("\n");
	fprintf(fp, "\n");
	fclose(fp);
}

//����С������
void SMALL()
{
	clock_t start, diff;

	long a_small[100];
	int n = 100;

	FILE* fp;
	fp = fopen("E:/text2.txt", "a");

	printf("����С������������£�\n");
	fprintf(fp, "����С������������£�\n");

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//����forѭ�����������ֵ��a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		InsertSort(a_small, n);
	}
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//����forѭ�����������ֵ��a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		MergeSort(a_small, n);
	}
	diff = clock() - start;
	printf("�鲢�����ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "�鲢�����ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//����forѭ�����������ֵ��a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		QuickSort(a_small, n);
	}
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);


		
	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//����forѭ�����������ֵ��a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		CountSort(a_small, n);
	}
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		//����forѭ�����������ֵ��a
		for (int j = 0; j < n; j++)
			a_small[j] = rand() % 100 + 1;

		RadixCountSort(a_small, n);
	}
	diff = clock() - start;
	printf("���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "���������ܺ�ʱΪ%d ms\n", diff);
	fprintf(fp, "\n");

	fclose(fp);
}

//��ȡ����
void read()
{
	int a_read[100];
	int i = 0;
	//for (int i = 0; i < 100; i++)
	//	number[i] = rand();

	FILE* fp;
	fp = fopen("E:/data.txt", "r");

	//for (int i = 0; i < 100; i++)
	//	fprintf(fp, "%d ", number[i]);
	while (fscanf(fp, "%d", &a_read[i++]) != EOF);
	{}

	fclose(fp);

	for (int i = 0; i < 100; i++)
		printf("%d ", a_read[i]);
	printf("\n");

	//ʹ�ÿ�������
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
		printf("����������ʵ�ֵĹ��ܣ���������1-7�������س���");
		scanf("%s", &number);

		while (errorinput(number) == 0)
		{
			printf("����������ֲ��Ϲ淶�����������룡\n");
			printf("����������ʵ�ֵĹ��ܣ���������1-7�������س���");
			scanf("%s", &number);
		}

		switch (number - '0')
		{
		//��ͬ��������
		case 1:
			BIG();
			break;
			
		//����С������
		case 2:
			SMALL();
			break;

		//��ȡ�ļ�����
		case 3:
			read();
			break;

		//��ɫ����
		case 4:
			CS();
			break;

		//�ҳ���kС����
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