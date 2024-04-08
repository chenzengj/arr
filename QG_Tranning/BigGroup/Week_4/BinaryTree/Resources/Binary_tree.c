#include"Binary_tree.h"

//创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//开辟空间
    newNode->data = data;//新节点上的数据
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;//返回新节点
}

//插入节点
Node* insert(Node* root, int data) {
    if (root == NULL) {//若为空，则先创建节点
        return createNode(data);
    }
    
    if (data < root->data) {//根据节点值的大小递归选择插入位置，小的插入左子树
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {//大的插入右子树
        root->right = insert(root->right, data);
    }
    //如果值相等，则直接返回当前节点
    return root;//返回插入的节点位置
}
//递归版
//中序遍历
void InorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //先左子树，再自身，再右子树
    InorderTraversal(root->left);
    printf("%d ", root->data);
    InorderTraversal(root->right);
}

//先序遍历
void PreorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //从上到下，从左到右
    printf("%d ", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

//后序遍历
void PostorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //从左到右，从下到上
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ", root->data);
}
//创建新的栈
Stack* CreateStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));//开辟栈空间
    stack->top = NULL;
    return stack;
}

//入栈操作
void push(Stack* stack, Node* treeNode) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;//将树节点入栈
    newNode->next = stack->top;
    stack->top = newNode;//将栈顶指针重新指向新入栈的树节点
}

//出栈操作
Node* pop(Stack* stack) {
    if (stack->top == NULL) {//栈的判空操作
        return NULL;
    }

    StackNode* temp = stack->top;
    Node* TopNode = temp->treeNode;//取出栈顶节点
    stack->top = temp->next;//栈顶指针重新指向栈顶
    free(temp);
    return TopNode;//将取出的树节点返回
}

//查看栈顶元素（只查看不出栈）
Node* peek(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    return stack->top->treeNode;
}

//检查栈是否为空
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

//释放栈内存
void freeStack(Stack* stack) {
    StackNode* current = stack->top;
    StackNode* next;

    while (current != NULL) {//遍历栈
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}

//中序遍历非递归实现
void InorderNonRecursion(Node* root) {
    if (root == NULL) {//二叉树的判空操作
        return;
    }

    Node* current = root;
    Stack* stack = CreateStack();

    while (current != NULL || !isStackEmpty(stack)) {//栈不为空或树节点不为空
        while (current != NULL) {//将当前树节点的左子树全部入栈
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;//将不断出栈，直到遇到树节点存在右子树时将右子树节点入栈，且防止节点重新入栈
    }

    freeStack(stack);//销毁栈
}

//先序遍历非递归实现
void PreorderNonRecursion(Node* root) {
    if (root == NULL) {
        return;
    }

    Stack* stack = CreateStack();
    push(stack, root);//先将最牛逼的弄进去

    while (!isStackEmpty(stack)) {
        Node* current = pop(stack);
        printf("%d ", current->data);

        if (current->right) {//栈先进后出，所以先右后左
            push(stack, current->right);
        }
        if (current->left) {
            push(stack, current->left);
        }
    }

    freeStack(stack);//销毁栈
}

//后序遍历非递归实现
void PostorderNonRecursion(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* current = root;
    Node* pre = NULL;
    Stack* stack = CreateStack();

    while (current != NULL || !isStackEmpty(stack)) {
        while (current != NULL) {//先将当前节点所有左子树先入栈，后面则逐渐将右子树入栈
            push(stack, current);
            current = current->left;
        }

        current = peek(stack);//只是查看，栈顶元素仍不变

        if (current->right == NULL || current->right == pre) {
            printf("%d ", current->data);
            current = pop(stack);//此时才是将栈顶元素取出
            pre = current;//保证右子树取出后仍会取出栈顶元素
            current = NULL;
        }
        else {
            current = current->right;
        }
    }

    freeStack(stack);
}

//创建新的队列
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

//入队操作
void Enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;//指向当前树节点
    newNode->next = NULL;

    if (queue->rear == NULL) {//空队列的情况
        queue->front = newNode;//队列头指向的一直是第一个节点
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;//将新节点与队列连接起来
        queue->rear = newNode;//队尾变成新节点
    }
}

//出队操作
Node* Getqueue(Queue* queue) {
    if (queue->front == NULL) {//判空操作
        return NULL;
    }
    //取出队列头，并将队列头指向下一个节点
    QueueNode* temp = queue->front;
    Node* getqueuedNode = temp->treeNode;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return getqueuedNode;//返回取出的节点
}

//检查队列是否为空
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

//释放队列内存
void freeQueue(Queue* queue) {
    QueueNode* currrent = queue->front;
    QueueNode* next;

    while (currrent != NULL) {
        next = currrent->next;
        free(currrent);
        currrent = next;
    }

    free(queue);
}
//层序遍历实现
void Sequence(Node* root) {
    if (root == NULL) {//判空操作
        return;
    }

    Queue* queue = createQueue();
    Enqueue(queue, root);//先将母体入队

    while (!isQueueEmpty(queue)) {
        Node* currrent = Getqueue(queue);//出队
        printf("%d ", currrent->data);
        //出队的时候需要同时将左子树右子树入队
        if (currrent->left) {
            Enqueue(queue, currrent->left);
        }
        if (currrent->right) {
            Enqueue(queue, currrent->right);
        }
    }

    freeQueue(queue);
}

//搜索节点
Node* Search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;//找到或者为空均返回当前节点
    }

    if (data < root->data) {//根据节点值的大小判断是左子树还是右子树，递归查找
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

//找到最小节点
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// 删除节点
Node* DeleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    //如果数据小于当前节点,则去左子树删除
    if (data < root->data) {
        root->left = DeleteNode(root->left, data);
    }
    //如果数据大于当前节点,则去右子树删除
    else if (data > root->data) {
        root->right = DeleteNode(root->right, data);
    }
    //找到要删除的节点
    else {
        //叶节点直接删除
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        //节点只有一个孩子
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        //节点有两个孩子（直接后继替换删除节点）
        else {
            Node* temp = findMin(root->right);//找到右子树的最小节点
            root->data = temp->data;//替换被删除的节点
            root->right = DeleteNode(root->right, temp->data);//将替换的节点删除
        }
    }

    return root;
}
int main() {
    Node* root = NULL;
    Node* search = NULL;
    char data1[100] = "";
    int a = 0;
    int data = 0;
    while (1) {
        
        system("cls");
        printf("\n===============================\n");
        printf("0.退出程序\n");
        printf("1.插入节点\n");
        printf("2.查找节点\n");
        printf("3.删除节点\n");
        printf("4.先序遍历（递归版）\n");
        printf("5.中序遍历（递归版）\n");
        printf("6.后序遍历（递归版）\n");
        printf("7.先序遍历（非递归版）\n");
        printf("8.中序遍历（非递归版）\n");
        printf("9.后序排序（非递归版）\n");
        printf("10.层次排序\n");
        printf("请选择想要的功能（0-10）");
        scanf("%d", &a);
        switch (a) {
        case 1:
            data = 0;
            printf("请输入插入的数据：");
            scanf("%s", &data1);
            data = atoi(data1);
            if (data) {
                root = insert(root, data);
                printf("插入成功\n");
            }
            else
                printf("输入非法");
            break;
        case 2:
            data = 0;
            printf("请输入查找的数据：");
            scanf("%s", &data1);
            data = atoi(data1);
            if (data) {
                search = Search(root, data);
                if (search)
                    printf("找到了！\n");
                else
                    printf("未找到!\n");
            }
            else
                printf("输入非法");
            break;
        case 3:
            data = 0;
            printf("请输入删除的节点数据：");
            scanf("%s", &data1);
            data = atoi(data1);
            if(data)
            root = DeleteNode(root, data);
            else
                printf("输入非法");
            break;
        case 4:
            printf("先序遍历为：");
            PreorderTraversal(root);
            break;
        case 5:
            printf("中序遍历为：");
            InorderTraversal(root);
            break;
        case 6:
            printf("后序遍历为：");
            PostorderTraversal(root);
            break;
        case 7:
            printf("先序遍历为：");
            PreorderNonRecursion(root);

            break;
        case 8:
            printf("中序遍历为：");
            InorderNonRecursion(root);
            break;
        case 9:
            printf("后序遍历为;");
            PostorderNonRecursion(root);
            break;
        case 10:
            printf("层次遍历为：");
            Sequence(root);
            break;
        default:
            printf("输入错误，请重新输入；");
            break;
        }
        printf("\n");
        system("pause");
    }
    system("pause");
    return 0;
}