#include "sort.h"
int main() {
    menu();
    int *arr=(int*)malloc(400);//��������
    int arr1[] = { 5,2,8,4,3,7,6 };
    int n = 0, length = 0;
    int n1 = sizeof(arr1) / sizeof(arr1[0]),k=3;
    char a[1], b[] = "";
    char c[] = "";
    while (1) {
        printf("������ѡ��Ĺ��ܣ�0-6����");
        scanf("%s", &a);
        if (strlen(a) > 1)
            goto d;
        switch (a[0]) {
        case '0':
            printf("�˳�����ɹ�\n");
            return 0;
        case '1':
            while (1) {
                int index = 0;
                printf("����������ļ������ݸ�����");
                scanf("%s", c);
                for (int i = 0; i < strlen(c); i++) {
                    if (!isdigit(c[i])) {
                        printf("�����������������\n");
                        index = 1;
                        break;
                    }
                }
                if (!index)
                    break;    
            }
            n = atoi(c);
            GenerateDataToFile(n);
                printf("�������ɳɹ�\n");
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
                k = 3; // �ҵ�3�����
                printf("ԭʼ����: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr1[i]);
                }
                printf("\n");
                int point = QuickSelect(arr1, 0, n - 1, n - k + 1);
                printf("��%d�������: %d\n", k, point);
                // BubbleSortOptimized1(arr, n);
                //QuickSortNonRecursive(arr, n);
                 //ThreeWayQuickSort(arr, 0, n - 1);
                 //RandomizedQuickSort(arr, 0, n - 1);
              /*  BubbleSortOptimized3(arr, n);
                PrintArray(arr, n);*/
                break;
        default:
        d:
            printf("����ָ���������������\n");
            break;
        }
    }
    system("pause");
    return 0;
    //int arr[] = { 5,2,8,4,3,7,6 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    //int k = 3; // �ҵ�3�����

    //printf("ԭʼ����: ");
    //for (int i = 0; i < n; i++) {
    //    printf("%d ", arr[i]);
    //}
    //printf("\n");

    //int point = QuickSelect(arr, 0, n - 1, n - k + 1);
    //printf("��%d�������: %d\n", k, point);
    //// BubbleSortOptimized1(arr, n);
    ////QuickSortNonRecursive(arr, n);
    // //ThreeWayQuickSort(arr, 0, n - 1);
    // //RandomizedQuickSort(arr, 0, n - 1);
    //BubbleSortOptimized3(arr, n);
    //PrintArray(arr, n);
    
}
// ��������
void InsertSort(int arr[], int n) {//��������
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {//�����Ƚϵ�ǰֵ������������ֵ�Ĵ�С
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;//�������
    }
}

// �鲢����
void Merge(int arr[], int left[], int leftSize, int right[], int rightSize) {//����
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {//�Ƚϴ�С
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
    if (n < 2) {//ֻ��һ�����ֲ�������
        return;
    }
    int mid = n / 2;
    int* left = (int*)malloc(mid* sizeof(int));//�����С��Ҫ�������ʽ���ʲ��ÿ��ٿռ�ķ���
    //���м�Ԫ��Ϊ�ᣬ��Ϊ����������
    int* right = (int*)malloc((n-mid) * sizeof(int));
    for (int i = 0; i < mid; i++) {//�����Ԫ��
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {//�Ұ���Ԫ��
        right[i - mid] = arr[i];
    }
    MergeSort(left, mid);//���õݹ�������������������
    MergeSort(right, n - mid);
    Merge(arr, left, mid, right, n - mid);//�ϲ�����������
}

// ��������(�ݹ��)
int Partition(int arr[], int left, int right) {
    int key = arr[right];//��������
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= key) {//��key������ֶ�
            i++;
            int temp = arr[i];//��С��key�ķ�����ߣ����ڵķ����ұ�
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];//�����������м�
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;//���ػ����±�λ��
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {//�����ݹ�����
        int pi = Partition(arr, left, right);
        QuickSort(arr, left, pi - 1);//�ݹ��������������
        QuickSort(arr, pi + 1, right);//�ݹ������Ҳ�������
    }
}

// ��������
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
    
    for (int i = 0; i < range; i++) {//ȫ������Ϊ0
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]-min]++;//����С������Ԫ�ط����������
    }
    for (int i = 1; i <range; i++) {
        count[i] += count[i - 1];//������������ۻ���
    }
    int* output = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        int index = count[arr[i] - min] - 1;
        output[index] = arr[i];//��˳��arr�����е�Ԫ�ط���output����
        count[arr[i]-min]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];//��Ԫ�طŻ�ԭ���飬�������
    }
    free(count);
    free(output);
}

// ������������
int getMax(int arr[], int n) {//�ҵ���ǰ��������ֵ������
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
    int count[10] = { 0 };//��������
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {//����count�����ۼƺ�
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];//����count���齫Ԫ�ذ�˳�����output����
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];//���źõ�˳�����ԭ����
    }
}
void RadixCountSort(int arr[], int n) {
    int max = getMax(arr, n);//��ȡ��������ֵ
    for (int exp = 1; max / exp > 0; exp *= 10) {//������1��ʼ�������������
        countingSort(arr, n, exp);
    }
}
//���������
void GenerateData(int arr[], int n) {
    srand((unsigned)time(NULL));//��ϵͳʱ���ʼ������
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;//ȡ���������ߵ�10000000-1
    }
   
}
//��ӡ����
void PrintArray(int arr[], int n) {
   // printf("����������Ϊ:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//���Դ�������
void TestBigData() {
    int sizes[] = { 10000, 50000, 200000 };
    clock_t start, end;//��ʼʱ�������ʱ��
    double time_used;//����ʱ��

    for (int k = 0; k < 3; k++) {
        int n = sizes[k];
        int* arr = (int*)malloc(n * sizeof(int));//���ݲ�ͬ����������
       // GenerateData(arr, n);//���������
        srand((unsigned)time(NULL));//��ϵͳʱ���ʼ������
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000000;//ȡ���������ߵ�10000000-1
        }
        int* copy1 = (int*)malloc(n * sizeof(int));
        int* copy2 = (int*)malloc(n * sizeof(int));
        int* copy3 = (int*)malloc(n * sizeof(int));
        int* copy4 = (int*)malloc(n * sizeof(int));
        int* copy5 = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            copy1[i] = copy2[i] = copy3[i] = copy4[i] = copy5[i] = arr[i];//���������ͬ�������ڲ���ʱ��
        }

        printf("��ǰ������: %d\n", n);

        start = clock();//��¼��ʼʱ��
        InsertSort(copy1, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        MergeSort(copy2, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�鲢��������ʱ��: %f\n", time_used);

        start = clock();
        QuickSort(copy3, 0, n - 1);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        CountSort(copy4, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        RadixCountSort(copy5, n);
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�����������򻨷�ʱ��: %f\n", time_used);
        free(arr);//�ͷſռ䣬�����¿��٣���ֹ�ڴ�й¶
        free(copy1);
        free(copy2);
        free(copy3);
        free(copy4);
        free(copy5);
    }
}
//���Դ���С����
void TestSmallData() {
    int n = 100;
    
    int* arr = (int*)malloc(n * sizeof(int));
    GenerateData(arr, n);//���������

    int* copy1 = (int*)malloc(n * sizeof(int));
    int* copy2 = (int*)malloc(n * sizeof(int));
    int* copy3 = (int*)malloc(n * sizeof(int));
    int* copy4 = (int*)malloc(n * sizeof(int));
    int* copy5 = (int*)malloc(n * sizeof(int));

    clock_t start, end;
    double time_used;

    int rounds = 100000;//�������
    printf("%d����������%d��:\n",n,rounds);

   
        for (int j = 0; j < n; j++) {
            copy1[j] = copy2[j] = copy3[j] = copy4[j] = copy5[j] = arr[j];
        }

        start = clock();
        for (int j = 0; j < rounds; j++) {
            InsertSort(copy1, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            MergeSort(copy2, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�鲢��������ʱ��: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            QuickSort(copy3, 0, n - 1);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            CountSort(copy4, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("������������ʱ��: %f\n", time_used);

        start = clock();
        for (int j = 0; j < rounds; j++) {
            RadixCountSort(copy5, n);
        }
        end = clock();
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("����������������ʱ��: %f\n", time_used);
    

    free(arr);
    free(copy1);
    free(copy2);
    free(copy3);
    free(copy4);
    free(copy5);
}
//���ɲ������ݱ��浽�ļ�
void GenerateDataToFile(int n) {
    FILE *fp = fopen("data.txt", "w");//�����ļ�
    if (fp == NULL) {
        printf("�޷������ļ�\n");
        return;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    //int arr[] = { 0 };
 
    GenerateData(arr, n);//������ɲ�������
    //srand((unsigned)time(NULL));//��ϵͳʱ���ʼ������
    //for (int i = 0; i < n; i++) {
    //    arr[i] = rand() % 1000000;//ȡ���������ߵ�10000000-1
    //}
    fprintf(fp, "%d\n", n);//���������ݸ���д���ļ�
    for (int i = 0; i < n; i++) {//����������д���ļ�
        fprintf(fp, "%d ", arr[i]);
    }

    free(arr);
    fclose(fp);
}
//��ȡ��������
int* SortFromFile() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("�ļ�Ϊ�գ��������ɲ�������.\n");
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
    printf("����ǰ����ɫ����Ϊ��");
    PrintArray(arr, 7);
    int p0 = 0, p1 = 0, p2 = sizeof(arr) / sizeof(arr[0])-1;//��������
    for (p1; p1<=p2; p1++) {
        if (arr[p1] == 0) {
            int temp = arr[p1];
            arr[p1] = arr[p0];
            arr[p0] = temp;
            p0++;//������p0����ƶ�

        }
        else if (arr[p1] == 2) {
            int temp = arr[p2];
            arr[p2] = arr[p1];
            arr[p1] =temp;
            p2--;//������p2��ǰ�ƶ�
            p1--;//p1����
        }
    }
    printf("��������ɫ����Ϊ��");
    PrintArray(arr, 7);
}

// ����ѡ���㷨�������еĻ��ַ���
 int QuickSelect(int arr[], int left, int right, int k)
{
    int index = Partition(arr, left, right);

    // ���index����k-1,ֱ�ӷ��ص�k�����
    if (index == k - 1) {
        return arr[index];
    }

    // ���index����k-1,����벿�ּ�������
    if (index > k - 1) {
        return QuickSelect(arr, left, index - 1, k);
    }

    // ���indexС��k-1,���Ұ벿�ּ�������
    return QuickSelect(arr, index + 1, right, k - index - 1);
}
//��������ǵݹ��
void QuickSortNonRecursive(int arr[], int n) {
    int* stack = (int*)malloc(n * sizeof(int));//ģ��ջ������
    int top = -1;

    stack[++top] = 0;//��ʼ����
    stack[++top] = n - 1;//��������

    while (top >= 0) {//ջΪ��
        int right = stack[top--];//�����ڌ�ջ
        int left = stack[top--];

        int key = Partition(arr, left, right);//���ջ�׼���±�

        if (key - 1 > left) {//��׼���������Ԫ�أ���������ջ
            stack[++top] = left;
            stack[++top] = key - 1;
        }

        if (key + 1 < right) {//��׼���Ҳ�����Ԫ�أ�������ջ
            stack[++top] = key + 1;
            stack[++top] = right;
        }
    }
}
//��������ݹ�汾������Ż�
int RandomizedPartition(int arr[], int left, int right) {
    int randomIndex = left + rand() % (right - left + 1);//���������Ŧ
    int temp = arr[randomIndex];//�������Ŧ�����ұ�Ԫ�ؽ���
    arr[randomIndex] = arr[right];
    arr[right] = temp;
    return Partition(arr, left, right);
}

void RandomizedQuickSort(int arr[], int left, int right) {
    if (left < right) {//�ݹ�ʵ��
        int pi = RandomizedPartition(arr, left, right);
        RandomizedQuickSort(arr, left, pi - 1);
        RandomizedQuickSort(arr, pi + 1, right);
    }
}
//��������ݹ���������Ż�
void InsertionSort(int arr[], int left, int right) {//��arr�����left��rightԪ�ط�Χ��ʵ�ֲ�������
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {//�Ƚϵ�ǰֵ�����������еĴ�С
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void ThreeWayPartition(int arr[], int left, int right, int* l, int* r) {
    if (right > left) {
        int pivot = arr[left];//�������Ԫ��Ϊ����
        *l = left;
        *r = right + 1;
        int i = left + 1;
        for (int j = i; j < *r; j++) {//�������飬����ӦԪ�ط�����������
            if (arr[j] < pivot) {//С������Ĳ���
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }
            else if (arr[j] > pivot) {//��������Ĳ���
                int temp = arr[(*r) - 1];
                arr[(*r) - 1] = arr[j];
                arr[j] = temp;
                (*r)--;
                j--;//��������˼����ж�
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
    if (right - left + 1 <= 16) {//���鳤��С�ڵ���16��ʱ����ֱ�ӵ��ò�������
        InsertionSort(arr, left, right);
    }
    else {
        int l, r;
        ThreeWayPartition(arr, left, right, &l, &r);//�����ַ�Ըı�l��r��ֵ
        ThreeWayQuickSort(arr, left, l - 1);//�ݹ�����С������Ĳ���
        ThreeWayQuickSort(arr, r + 1, right);//�ݹ������������Ĳ���
    }
}
//ð�����������Ż�
//�Ż�1������һ����־λ,��¼�Ƿ�������,���һ������û�з�������,˵�������Ѿ�����,����ֱ���˳�
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
//�Ż�2:��¼���һ�ν�����λ��,�Լ����ڲ�ѭ���Ĵ���
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
        lastSwappedIndex = swappedIndex;//���һ��ѭ��λ��
        if (lastSwappedIndex == 0)//�����Ż�1��Ч����˫���Ż������˾��úܰ�
            break;
    }
}
//�Ż�3��˫��ð������
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
        lastSwappedIndex = swappedIndex;//�ұ߽�
        if (swappedIndex == 0)//û�н�������ǰ����ѭ��
            break;
        swappedIndex = 0;
        for (int j = lastSwappedIndex; j > left; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                swappedIndex = j;
            }
            left = swappedIndex;//��߽�
            if (swappedIndex == 0) {
                break;
            }
        }
    }
}
void menu() {
    printf("1.���ɲ�������\n");
    printf("2.�����������\n");
    printf("3.��������������\n");
    printf("4.���Դ���С����\n");
    printf("5.Ӧ����1����ɫ����\n");
    printf("6.Ӧ����2���ҵ����������\n");
    printf("0���˳�����\n");
    

}
void menu1(int arr[],int n) {
    char choice[3] = "";
    
    int a = 0;
    printf("����ǰ������Ϊ:");
    PrintArray(arr, n);
    printf("��ѡ���򷽷�����\n");
    printf("1.��������\n");
    printf("2.�鲢����\n");
    printf("3.��������\n");
    printf("4.������������\n");
    printf("5.��������ǵݹ��\n");
    printf("6.��������ݹ�棨��ͨ�棩\n");
    printf("7.��������ݹ�����Ż���\n");
    printf("8.��������ݹ��������Ż���\n");
    printf("9.ð�������Ż�1\n");
    printf("10.ð�������Ż�2\n");
    printf("11.ð�������Ż�3\n");
    while (1) {
        printf("��ѡ�����򷽷���1-11����");
        scanf("%s", choice);
        int index = 0;
        for (int i = 0; i < strlen(choice); i++) {
            if (!isdigit(choice[i])) {
                printf("�����������������\n");
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
                printf("����������������룡\n");
                break;
            }
         
            
    printf("����������:");
    PrintArray(arr, n);
}
