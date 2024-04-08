#include"HeapAndTree.h"
//创建新的堆
BinaryHeap* createHeap() {
    BinaryHeap* heap = (BinaryHeap*)malloc(sizeof(BinaryHeap));//开辟空间
    heap->size = 0;//大小指向为0
    return heap;
}

//交换两个元素
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//上浮操作
void HeapUp(BinaryHeap* heap, int index) {
    int parentIndex = (index - 1) / 2;//父节点

    if (heap->arr[parentIndex] < heap->arr[index]) {//确保根节点的值是最大的，且父节点的值大于子节点
        swap(&heap->arr[parentIndex], &heap->arr[index]);
        HeapUp(heap, parentIndex);
    }
}

//下沉操作
void HeapDown(BinaryHeap* heap, int index) {
    int leftChildIndex = 2 * index + 1;//左子节点下标
    int rightChildIndex = 2 * index + 2;//右子节点的下标
    int largestIndex = index;//最大值节点
    //找出当前节点、左子节点和右子节点中的最大值所在的位置
    if (leftChildIndex < heap->size && heap->arr[leftChildIndex] > heap->arr[largestIndex]) {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < heap->size && heap->arr[rightChildIndex] > heap->arr[largestIndex]) {
        largestIndex = rightChildIndex;
    }
    //如果最大值不是当前节点，则与最大值交换位置，并继续向下下沉
    if (largestIndex != index) {
        swap(&heap->arr[index], &heap->arr[largestIndex]);
        HeapDown(heap, largestIndex);
    }
}

//插入元素
void InsertRoot(BinaryHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("堆已满\n");
        return;
    }

    heap->arr[heap->size] = value;//将插入元素放入
    HeapUp(heap, heap->size);//上浮操作
    heap->size++;
}

//删除根节点
int DeleteRoot(BinaryHeap* heap) {
    if (heap->size == 0) {
        printf("堆为空，无需删除\n");
        return -1;
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];//将根节点的值与最后的子节点值交换
    heap->size--;//起到删除根节点的作用
    HeapDown(heap, 0);//下沉操作

    return root;
}

//打印堆
void printHeap(BinaryHeap* heap) {
    
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}


//获取节点高度
int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

//获取平衡因子
int getBalanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

//右旋转
AVLNode* AVLrightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    //执行旋转
    x->right = y;
    y->left = T2;
    //更新节点高度
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    //返回新的根节点
    return x;
}

//左旋转
AVLNode* AVLleftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    //执行旋转
    y->left = x;
    x->right = T2;

    //更新节点高度
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    //返回新的根节点
    return y;
}

//插入节点
AVLNode* insertAVLNode(AVLNode* node, int data) {
    //递归插入
    if (node == NULL) {//开枝散叶
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->data = data;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    //左子树数据小于根节点
    if (data < node->data) {
        node->left = insertAVLNode(node->left, data);
    }//右子树数据大于根节点
    else if (data > node->data) {
        node->right = insertAVLNode(node->right, data);
    }
    else {
        //重复数据不插入
        return node;
    }
    //更新节点高度
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    //获取平衡因子
    int balanceFactor = getBalanceFactor(node);

    //左左情况
    if (balanceFactor > 1 && data < node->left->data) {
        return AVLrightRotate(node);
    }

    //右右情况
    if (balanceFactor < -1 && data > node->right->data) {
        return AVLleftRotate(node);
    }

    //左右情况
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = AVLleftRotate(node->left);
        return AVLrightRotate(node);
    }

    //右左情况
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = AVLrightRotate(node->right);
        return AVLleftRotate(node);
    }

    //返回新的根节点
    return node;
}

//查找节点
AVLNode* searchAVLNode(AVLNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    //遍历查找
    if (data < root->data) {
        return searchAVLNode(root->left, data);
    }
    else {
        return searchAVLNode(root->right, data);
    }
}

//获取最小值节点
AVLNode* getMinNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }//最小值在左子树的叶子上
    return current;
}

// 删除节点
AVLNode* deleteNode(AVLNode* root, int data) {
    // 递归查找并删除节点
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        //找到要删除的节点
        //没有子节点
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        //只有一个子节点
        else if (root->left == NULL) {
            AVLNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            AVLNode* temp = root->left;
            free(root);
            return temp;
        }

        // 有两个子节点
        else {
            AVLNode* minNode = getMinNode(root->right);//直接后继
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    //更新节点高度
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));
    //获取平衡因子
    int balanceFactor = getBalanceFactor(root);

    //左左情况
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return AVLrightRotate(root);
    }
    //左右情况
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = AVLleftRotate(root->left);
        return AVLrightRotate(root);
    }
    //右右情况
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return AVLleftRotate(root);
    }
    //右左情况
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = AVLrightRotate(root->right);
        return AVLleftRotate(root);
    }

    return root;
}

//中序遍历
void inorderAVLTraversal(AVLNode* root) {
    if (root == NULL) {
        return;
    }
    inorderAVLTraversal(root->left);
    printf("%d ", root->data);
    inorderAVLTraversal(root->right);
}

//创建新节点
RBNode* createNode(int data) {
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 左旋转
void RBleftRotate(RBNode** root, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// 右旋转
void RBrightRotate(RBNode** root, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

// 插入节点
void insertRBNode(RBNode** root, RBNode* node) {
    RBNode* y = NULL;
    RBNode* x = *root;
    //根据值的大小选择插入位置
    while (x != NULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    //将插入节点连接在树上
    node->parent = y;
    //树为空的情况
    if (y == NULL) {
        *root = node;
    }//根据大小选择连接位置
    else if (node->data < y->data) {
        y->left = node;
    }
    else {
        y->right = node;
    }

    node->left = NULL;
    node->right = NULL;
    node->color = RED;

    // 插入修复
    insertFixup(root, node);
}

// 插入修复
void insertFixup(RBNode** root, RBNode* node) {
    RBNode* parent;
    RBNode* grandparent;
    
    while ((parent = node->parent) && parent->color == RED) {
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                //父节点和叔叔节点都是红色
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            }
            else {
                if (node == parent->right) {
                    //节点是右孩子
                    RBleftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                //节点是左孩子
                RBrightRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                node = parent;
            }
        }
        else {
            RBNode* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                //父节点和叔叔节点都是红色
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            }
            else {
                if (node == parent->left) {
                    //节点是左孩子
                    RBrightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                //节点是右孩子
                RBleftRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                node = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

// 查找节点
RBNode* searchRBNode(RBNode* root, int data) {
    RBNode* current = root;
    //根据值的大小遍历查找位置
    while (current != NULL) {
        if (data == current->data) {
            return current;
        }
        else if (data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    return NULL;
}

// 中序遍历
void inorderRBTraversal(RBNode* root) {
    if (root == NULL) {
        return;
    }
    inorderRBTraversal(root->left);
    printf("%d ", root->data);
    inorderRBTraversal(root->right);
}


// 清屏函数
void clearScreen() {
    system("cls||clear"); 
}
int main() {
    int choice, data;
    RBNode* rbRoot = NULL;
    AVLNode* avlRoot = NULL;
    BinaryHeap* heapRoot = createHeap();

    while (1) {
        clearScreen(); // 清屏
        //printf("红黑树(1) / AVL树(2) / 堆(3) / 退出(0): ");
        printf("===========================================\n");
        printf("0.退出\n");
        printf("1.红黑树操作\n");
        printf("2.AVL树操作\n");
        printf("3.堆的操作\n");
        printf("请选择功能(0-3)");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("红黑树操作: \n");
            printf("1.插入\n");
            printf("2.遍历\n");
            printf("请选择功能(1-2)");

            scanf("%d", &choice);

            if (choice == 1) {
                printf("输入数据: ");
                scanf("%d", &data);
                insertRBNode(&rbRoot, createNode(data));
                printf("按Enter键继续...");
                getchar(); getchar(); // 等待用户输入
            }
         
            else if (choice == 2) {
                printf("红黑树中序遍历: ");
                inorderRBTraversal(rbRoot);
                printf("\n按Enter键继续...");
                getchar(); getchar();
            }
            break;

        case 2:
            printf("AVL树操作:\n");
            printf("1.插入\n");
            printf("2.删除\n");
            printf("3.遍历\n");
            printf("请选择功能(1-3)");

            scanf("%d", &choice);

            if (choice == 1) {
                printf("输入数据: ");
                scanf("%d", &data);
                avlRoot=insertAVLNode(avlRoot, data);
                printf("按Enter键继续...");
                getchar(); getchar();
            }
            else if (choice == 2) {
                printf("输入数据: ");
                scanf("%d", &data);
                avlRoot = deleteNode(avlRoot, data);
                
                printf("按Enter键继续...");
                getchar(); getchar();
            }
            else if (choice == 3) {
                printf("AVL树中序遍历: ");
                inorderAVLTraversal(avlRoot);
                printf("\n按Enter键继续...");
                getchar(); getchar();
            }
            break;

        case 3:
            printf("堆操作:\n");
            printf("1.插入\n");
            printf("2.删除根节点\n");
            printf("3.遍历\n");
            printf("请选择功能(1-3)");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("输入数据: ");
                scanf("%d", &data);
                InsertRoot(heapRoot, data);
                printf("按Enter键继续...");
                getchar(); getchar();
            }
            else if (choice == 2) {
               
                int i = DeleteRoot(heapRoot, data);
                printf("按Enter键继续...");
                getchar(); getchar();
            }
            else if (choice == 3) {
                printf("堆遍历: ");
                printHeap(heapRoot);
                printf("\n按Enter键继续...");
                getchar(); getchar();
            }
            break;

        case 0:
            exit(0);

        default:
            printf("无效选择!\n");
            printf("按Enter键继续...");
            getchar(); getchar();
        }
    }

    return 0;
}
