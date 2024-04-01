#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
void BubbleSortOptimized1(int arr[], int n);//ð�������Ż�1
void BubbleSortOptimized2(int arr[], int n);//ð�������Ż�2
void BubbleSortOptimized3(int arr[], int n);//ð�������Ż�3
void InsertSort(int arr[], int n);//��������
void CountSort(int arr[], int n);//��������
int getMax(int arr[], int n);//��ȡ���ֵ����
//������������
void countingSort(int arr[], int n, int exp);
void RadixCountSort(int arr[], int n);

//��������ݹ��
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);

//��������ݹ���Ż�
//����Ż�
int RandomizedPartition(int arr[], int left, int right);
void RandomizedQuickSort(int arr[], int left, int right);

//�������Ż�
void InsertionSort(int arr[], int left, int right);
void ThreeWayPartition(int arr[], int left, int right, int* l, int* r);
void ThreeWayQuickSort(int arr[], int left, int right);

//��������ǵݹ��
void QuickSortNonRecursive(int arr[], int n);

//�鲢����
void Merge(int arr[], int left[], int leftSize, int right[], int rightSize);
void MergeSort(int arr[], int n);

void TestBigData();//���Դ�������
void TestSmallData();//����С������
void GenerateData(int arr[], int n);//�������������
void GenerateDataToFile(int n);//���ɲ������ݱ��浽�ļ�
int* SortFromFile();//���ļ��ж�ȡ�������ݲ����ظ��������
void PrintArray(int arr[], int n);//��ӡ���麯��
void ColorSort();//Ӧ����1����ɫ����
int QuickSelect(int arr[], int left, int right, int k);//����ѡ��Ӧ����2��ѡ����������
void menu();//���˵�����
void menu1(int arr[],int n);//�˵�����