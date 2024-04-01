#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
void BubbleSortOptimized1(int arr[], int n);//冒泡排序优化1
void BubbleSortOptimized2(int arr[], int n);//冒泡排序优化2
void BubbleSortOptimized3(int arr[], int n);//冒泡排序优化3
void InsertSort(int arr[], int n);//插入排序
void CountSort(int arr[], int n);//计数排序
int getMax(int arr[], int n);//获取最大值函数
//基数计数排序
void countingSort(int arr[], int n, int exp);
void RadixCountSort(int arr[], int n);

//快速排序递归版
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);

//快速排序递归版优化
//随机优化
int RandomizedPartition(int arr[], int left, int right);
void RandomizedQuickSort(int arr[], int left, int right);

//三枢轴优化
void InsertionSort(int arr[], int left, int right);
void ThreeWayPartition(int arr[], int left, int right, int* l, int* r);
void ThreeWayQuickSort(int arr[], int left, int right);

//快速排序非递归版
void QuickSortNonRecursive(int arr[], int n);

//归并排序
void Merge(int arr[], int left[], int leftSize, int right[], int rightSize);
void MergeSort(int arr[], int n);

void TestBigData();//测试大数据量
void TestSmallData();//测试小数据量
void GenerateData(int arr[], int n);//生成随机数函数
void GenerateDataToFile(int n);//生成测试数据保存到文件
int* SortFromFile();//从文件中读取测试数据并返回给数组接收
void PrintArray(int arr[], int n);//打印数组函数
void ColorSort();//应用题1，颜色排序
int QuickSelect(int arr[], int left, int right, int k);//快速选择，应用题2，选择第三大的数
void menu();//主菜单函数
void menu1(int arr[],int n);//菜单函数