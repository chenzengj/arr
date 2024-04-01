#include "sort.h"
int main() {
    menu();
    int *arr=(int*)malloc(400);//接收数组
    int arr1[] = { 5,2,8,4,3,7,6 };
    int n = 0, length = 0;
    int n1 = sizeof(arr1) / sizeof(arr1[0]),k=3;
    char a[1], b[] = "";
    char c[] = "";
    while (1) {
        printf("请输入选择的功能（0-6）：");
        scanf("%s", &a);
        if (strlen(a) > 1)
            goto d;
        switch (a[0]) {
        case '0':
            printf("退出程序成功\n");
            return 0;
        case '1':
            while (1) {
                int index = 0;
                printf("请输入存入文件的数据个数：");
                scanf("%s", c);
                for (int i = 0; i < strlen(c); i++) {
                    if (!isdigit(c[i])) {
                        printf("输入错误，请重新输入\n");
                        index = 1;
                        break;
                    }
                }
                if (!index)
                    break;    
            }
            n = atoi(c);
            GenerateDataToFile(n);
                printf("数据生成成功\n");
                break;
        case '2':
           SortFromFile();
           
           break;
        case '3':
            TestBigData();
            break;
        case '4':
            TestSmallData();
            break;
        case '5':
            ColorSort();
            break;
        case '6':
                k = 3; // 找第3大的数
                printf("原始序列: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr1[i]);
                }
                printf("\n");
                int point = QuickSelect(arr1, 0, n - 1, n - k + 1);
                printf("第%d大的数是: %d\n", k, point);
                // BubbleSortOptimized1(arr, n);
                //QuickSortNonRecursive(arr, n);
                 //ThreeWayQuickSort(arr, 0, n - 1);
                 //RandomizedQuickSort(arr, 0, n - 1);
              /*  BubbleSortOptimized3(arr, n);
                PrintArray(arr, n);*/
                break;
        default:
        d:
            printf("输入指令错误，请重新输入\n");
            break;
        }
    }
    system("pause");
    return 0;
    //int arr[] = { 5,2,8,4,3,7,6 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    //int k = 3; // 找第3大的数

    //printf("原始序列: ");
    //for (int i = 0; i < n; i++) {
    //    printf("%d ", arr[i]);
    //}
    //printf("\n");

    //int point = QuickSelect(arr, 0, n - 1, n - k + 1);
    //printf("第%d大的数是: %d\n", k, point);
    //// BubbleSortOptimized1(arr, n);
    ////QuickSortNonRecursive(arr, n);
    // //ThreeWayQuickSort(arr, 0, n - 1);
    // //RandomizedQuickSort(arr, 0, n - 1);
    //BubbleSortOptimized3(arr, n);
    //PrintArray(arr, n);
    
}
// 插入排序
void InsertSort(int arr[], int n) {//正序排序
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {//遍历比较当前值与已排序区域值的大小
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;//排序插入
    }
}

// 归并排序
void Merge(int arr[], int left[], int leftSize, int right[], int rightSize) {//排序
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {//比较大小
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void MergeSort(int arr[], int n) {
    if (n < 2) {//只有一个数字不用排序
        return;
    }
    int mid = n / 2;
    int* left = (int*)malloc(mid* sizeof(int));//数组大小需要常量表达式，故采用开辟空间的方法
    //以中间元素为轴，分为两个子数组
    int* right = (int*)malloc((n-mid) * sizeof(int));
    for (int i = 0; i < mid; i++) {//左半区元素
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {//右半区元素
        right[i - mid] = arr[i];
    }
    MergeSort(left, mid);//运用递归对两个子数组进行排序
    MergeSort(right, n - mid);
    Merge(arr, left, mid, right, n - mid);//合并两个子数组
}

// 快速排序(递归版)
int Partition(int arr[], int left, int right) {
    int key = arr[right];//设立基数
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= key) {//以key将数组分段
            i++;
            int temp = arr[i];//将小于key的放在左边，大于的放在右边
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];//将基数换到中间
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;//返回基数下标位置
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {//跳出递归条件
        int pi = Partition(arr, left, right);
        QuickSort(arr, left, pi - 1);//递归排序左侧子序列
        QuickSort(arr, pi + 1, right);//递归排序右侧子序列
    }
}

// 计数排序
void CountSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;
    int* count = (int*)malloc(range *sizeof(int));
    
    for (int i = 0; i < range; i++) {//全部重置为0
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]-min]++;//按大小将数组元素放入计数数组
    }
    for (int i = 1; i <range; i++) {
        count[i] += count[i - 1];//计算计数数组累积和
    }
    int* output = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        int index = count[arr[i] - min] - 1;
        output[index] = arr[i];//按顺序将arr数组中的元素放入output数组
        count[arr[i]-min]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];//将元素放回原数组，完成排序
    }
    free(count);
    free(output);
}

// 基数计数排序
int getMax(int arr[], int n) {//找到当前数组的最大值并返回
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = { 0 };//计数数组
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {//计算count数组累计和
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];//根据count数组将元素按顺序放入output数组
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];//按排好的顺序放入原数组
    }
}
void RadixCountSort(int arr[], int n) {
    int max = getMax(arr, n);//获取数组的最大值
    for (int exp = 1; max / exp > 0; exp *= 10) {//基数从1开始，渐渐增大基数
        countingSort(arr, n, exp);
    }
}
//随机数函数
void GenerateData(int arr[], int n) {
    srand((unsigned)time(NULL));//以系统时间初始化种子
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;//取随机数，最高到10000000-1
    }
   
}
//打印函数
void PrintArray(int arr[], int n) {
   // printf("排序后的数据为:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//测试大数据量
void TestBigData() {
    int sizes[] = { 10000, 50000, 200000 };
    clock_t start, end;//起始时间与结束时间
    double time_used;//花费时间

    for (int k = 0; k < 3; k++) {
        int n = sizes[k];
        int* arr = (int*)malloc(n * sizeof(int));//根据不同数据量开辟
       // GenerateData(arr, n);//生成随机数
        srand((unsigned)time(NULL));//以系统时间初始化种子
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000000;//取随机数，最高到10000000-1
        }
        int* copy1 = (int*)malloc(n * sizeof(int));
        int* copy2 = (int*)malloc(n * sizeof(int));
        int* copy3 = (int*)malloc(n * sizeof(int));
        int* copy4 = (int*)malloc(n * sizeof(int));
        int* copy5 = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            copy1[i] = copy2[i] = copy3[i] = copy4[i] = copy5[i] = arr[i];//生成五份相同数据用于测试时间
        }

        printf("当前数据量: %d\n", n);

        start = clock();//记录开始时间
        InsertSort(copy1, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("插入排序所花时间: %f\n", time_used);

        start = clock();
        MergeSort(copy2, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("归并排序所花时间: %f\n", time_used);

        start = clock();
        QuickSort(copy3, 0, n - 1);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("快速排序所花时间: %f\n", time_used);

        start = clock();
        CountSort(copy4, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("计数排序所花时间: %f\n", time_used);

        start = clock();
        RadixCountSort(copy5, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("基数计数排序花费时间: %f\n", time_used);
        free(arr);//释放空间，再重新开辟，防止内存泄露
        free(copy1);
        free(copy2);
        free(copy3);
        free(copy4);
        free(copy5);
    }
}
//测试大量小数据
void TestSmallData() {
    int n = 100;
    
    int* arr = (int*)malloc(n * sizeof(int));
    GenerateData(arr, n);//生成随机数

    int* copy1 = (int*)malloc(n * sizeof(int));
    int* copy2 = (int*)malloc(n * sizeof(int));
    int* copy3 = (int*)malloc(n * sizeof(int));
    int* copy4 = (int*)malloc(n * sizeof(int));
    int* copy5 = (int*)malloc(n * sizeof(int));

    clock_t start, end;
    double time_used;

    int rounds = 100000;//排序次数
    printf("%d个数据排序%d次:\n",n,rounds);

   
        for (int j = 0; j < n; j++) {
            copy1[j] = copy2[j] = copy3[j] = copy4[j] = copy5[j] = arr[j];
        }

        start = clock();
        for (int j = 0; j < rounds; j++) {
            InsertSort(copy1, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("插入排序所花时间: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            MergeSort(copy2, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("归并排序所花时间: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            QuickSort(copy3, 0, n - 1);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("快速排序所花时间: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            CountSort(copy4, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("计数排序所花时间: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            RadixCountSort(copy5, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("基数计数排序所花时间: %f\n", time_used);
    

    free(arr);
    free(copy1);
    free(copy2);
    free(copy3);
    free(copy4);
    free(copy5);
}
//生成测试数据保存到文件
void GenerateDataToFile(int n) {
    FILE *fp = fopen("data.txt", "w");//创建文件
    if (fp == NULL) {
        printf("无法创建文件\n");
        return;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    //int arr[] = { 0 };
 
    GenerateData(arr, n);//随机生成测试数据
    //srand((unsigned)time(NULL));//以系统时间初始化种子
    //for (int i = 0; i < n; i++) {
    //    arr[i] = rand() % 1000000;//取随机数，最高到10000000-1
    //}
    fprintf(fp, "%d\n", n);//将测试数据个数写入文件
    for (int i = 0; i < n; i++) {//将测试数据写入文件
        fprintf(fp, "%d ", arr[i]);
    }

    free(arr);
    fclose(fp);
}
//读取测试数据
int* SortFromFile() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("文件为空，请先生成测试数据.\n");
        return NULL;
    }

    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
  
    fclose(fp);
    menu1(arr, n);

    return NULL;
}
void ColorSort() {
    int arr[7] = { 1,2,1,0,2,0,0 };
    printf("排序前的颜色数组为：");
    PrintArray(arr, 7);
    int p0 = 0, p1 = 0, p2 = sizeof(arr) / sizeof(arr[0])-1;//设置索引
    for (p1; p1<=p2; p1++) {
        if (arr[p1] == 0) {
            int temp = arr[p1];
            arr[p1] = arr[p0];
            arr[p0] = temp;
            p0++;//交换后p0向后移动

        }
        else if (arr[p1] == 2) {
            int temp = arr[p2];
            arr[p2] = arr[p1];
            arr[p1] =temp;
            p2--;//交换后p2向前移动
            p1--;//p1回退
        }
    }
    printf("排序后的颜色数组为：");
    PrintArray(arr, 7);
}

// 快速选择算法（快排中的划分法）
 int QuickSelect(int arr[], int left, int right, int k)
{
    int index = Partition(arr, left, right);

    // 如果index等于k-1,直接返回第k大的数
    if (index == k - 1) {
        return arr[index];
    }

    // 如果index大于k-1,在左半部分继续搜索
    if (index > k - 1) {
        return QuickSelect(arr, left, index - 1, k);
    }

    // 如果index小于k-1,在右半部分继续搜索
    return QuickSelect(arr, index + 1, right, k - index - 1);
}
//快速排序非递归版
void QuickSortNonRecursive(int arr[], int n) {
    int* stack = (int*)malloc(n * sizeof(int));//模拟栈的作用
    int top = -1;

    stack[++top] = 0;//起始索引
    stack[++top] = n - 1;//结束索引

    while (top >= 0) {//栈为空
        int right = stack[top--];//类似于岀栈
        int left = stack[top--];

        int key = Partition(arr, left, right);//接收基准数下标

        if (key - 1 > left) {//基准数左侧仍有元素，则索引入栈
            stack[++top] = left;
            stack[++top] = key - 1;
        }

        if (key + 1 < right) {//基准数右侧仍有元素，索引入栈
            stack[++top] = key + 1;
            stack[++top] = right;
        }
    }
}
//快速排序递归版本的随机优化
int RandomizedPartition(int arr[], int left, int right) {
    int randomIndex = left + rand() % (right - left + 1);//设置随机枢纽
    int temp = arr[randomIndex];//将随机枢纽与最右边元素交换
    arr[randomIndex] = arr[right];
    arr[right] = temp;
    return Partition(arr, left, right);
}

void RandomizedQuickSort(int arr[], int left, int right) {
    if (left < right) {//递归实现
        int pi = RandomizedPartition(arr, left, right);
        RandomizedQuickSort(arr, left, pi - 1);
        RandomizedQuickSort(arr, pi + 1, right);
    }
}
//快速排序递归版三枢轴优化
void InsertionSort(int arr[], int left, int right) {//对arr数组从left到right元素范围内实现插入排序
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {//比较当前值与已排序序列的大小
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void ThreeWayPartition(int arr[], int left, int right, int* l, int* r) {
    if (right > left) {
        int pivot = arr[left];//以最左边元素为数轴
        *l = left;
        *r = right + 1;
        int i = left + 1;
        for (int j = i; j < *r; j++) {//遍历数组，将对应元素放入三个部分
            if (arr[j] < pivot) {//小于数轴的部分
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
            else if (arr[j] > pivot) {//大于数轴的部分
                int temp = arr[(*r) - 1];
                arr[(*r) - 1] = arr[j];
                arr[j] = temp;
                (*r)--;
                j--;//交换后回退继续判断
            }
        }
        int temp = arr[*l];
        arr[*l] = arr[i - 1];
        arr[i - 1] = temp;
        (*l)++;
        (*r)--;
    }
}

void ThreeWayQuickSort(int arr[], int left, int right) {
    if (right - left + 1 <= 16) {//数组长度小于等于16的时候则直接调用插入排序
        InsertionSort(arr, left, right);
    }
    else {
        int l, r;
        ThreeWayPartition(arr, left, right, &l, &r);//传入地址以改变l与r的值
        ThreeWayQuickSort(arr, left, l - 1);//递归排序小于数轴的部分
        ThreeWayQuickSort(arr, r + 1, right);//递归排序大于数轴的部分
    }
}
//冒泡排序三个优化
//优化1：加入一个标志位,记录是否发生交换,如果一趟下来没有发生交换,说明数组已经有序,可以直接退出
void BubbleSortOptimized1(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}
//优化2:记录最后一次交换的位置,以减少内层循环的次数
void BubbleSortOptimized2(int arr[], int n) {
    int lastSwappedIndex = n - 1;
    for (int i = 0; i < n - 1; i++) {
        int swappedIndex = 0;
        for (int j = 0; j < lastSwappedIndex; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swappedIndex = j;
            }
        }
        lastSwappedIndex = swappedIndex;//最后一次循环位置
        if (lastSwappedIndex == 0)//加入优化1的效果，双重优化，个人觉得很棒
            break;
    }
}
//优化3：双向冒泡排序
void BubbleSortOptimized3(int arr[], int n) {
    int lastSwappedIndex = n - 1;
    int left = 0;
   while(left<lastSwappedIndex){
        int swappedIndex = 0;
        for (int j = left; j < lastSwappedIndex; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swappedIndex = j;
            }
        }
        lastSwappedIndex = swappedIndex;//右边界
        if (swappedIndex == 0)//没有交换则提前结束循环
            break;
        swappedIndex = 0;
        for (int j = lastSwappedIndex; j > left; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                swappedIndex = j;
            }
            left = swappedIndex;//左边界
            if (swappedIndex == 0) {
                break;
            }
        }
    }
}
void menu() {
    printf("1.生成测试数据\n");
    printf("2.测试排序程序\n");
    printf("3.测试少量大数据\n");
    printf("4.测试大量小数据\n");
    printf("5.应用题1：颜色排序\n");
    printf("6.应用题2：找到第三大的数\n");
    printf("0：退出程序\n");
    

}
void menu1(int arr[],int n) {
    char choice[3] = "";
    
    int a = 0;
    printf("排序前的数组为:");
    PrintArray(arr, n);
    printf("可选排序方法如下\n");
    printf("1.插入排序\n");
    printf("2.归并排序\n");
    printf("3.计数排序\n");
    printf("4.基数计数排序\n");
    printf("5.快速排序非递归版\n");
    printf("6.快速排序递归版（普通版）\n");
    printf("7.快速排序递归随机优化版\n");
    printf("8.快速排序递归三枢轴优化版\n");
    printf("9.冒泡排序优化1\n");
    printf("10.冒泡排序优化2\n");
    printf("11.冒泡排序优化3\n");
    while (1) {
        printf("请选择排序方法（1-11）：");
        scanf("%s", choice);
        int index = 0;
        for (int i = 0; i < strlen(choice); i++) {
            if (!isdigit(choice[i])) {
                printf("输入错误，请重新输入\n");
                index = 1;
                break;
            }
           
        }
        if (!index)
            break;
    }
            
            a = atoi(choice);
            switch (a) {
            case 1:
                InsertSort(arr, n);
                break;
            case 2:
                MergeSort(arr, n);
                break;
            case 3:
                CountSort(arr, n);
                break;
            case 4:
                RadixCountSort(arr, n);
                break;
            case 5:
                QuickSortNonRecursive(arr, n);
                break;
            case 6:
                QuickSort(arr, 0, n - 1);
                break;
            case 7:
                RandomizedQuickSort(arr, 0, n - 1);
                break;
            case 8:
                ThreeWayQuickSort(arr, 0, n - 1);
                break;
            case 9:
                BubbleSortOptimized1(arr, n);
                break;
            case 10:
                BubbleSortOptimized2(arr, n);
                break;
            case 11:
                BubbleSortOptimized3(arr, n);
                break;
            default:
                printf("输入错误，请重新输入！\n");
                break;
            }
         
            
    printf("排序后的数组:");
    PrintArray(arr, n);
}
