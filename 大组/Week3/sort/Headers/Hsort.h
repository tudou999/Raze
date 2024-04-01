#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

char MainMenu[6][50] =
{
		"1.��ͬ��������",
		"2.����С������",
		"3.��ȡ�ļ����ݲ�����",
		"4.��ɫ����",
		"5.��һ�������������ҵ���KС����",
		"6.�˳�",
};

struct time
{
	char sentence[100];
	int time;
};

void InsertSort(long* arr, int n);
void merge(long* arr, long* tempArr, int left, int mid, int right);
void Separate(long* arr, long* tempArr, int left, int right);
void MergeSort(long* arr, int n);
void fillhole(long arr[], int left, int right);
void QuickSort(long* arr, int n);
void CountSort(long* arr, int n);
void RadixCountSort(long* arr, int n);
void ColorSort(int* arr, int n);
void search(int* arr, int left, int right, int k);
void Ksearch(int* arr, int n);
int errorinput(char ch);
void DisplayMainMenu();
void BIG();
void SMALL();
void read();
