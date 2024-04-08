#include"Binary_tree.h"

//�����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//���ٿռ�
    newNode->data = data;//�½ڵ��ϵ�����
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;//�����½ڵ�
}

//����ڵ�
Node* insert(Node* root, int data) {
    if (root == NULL) {//��Ϊ�գ����ȴ����ڵ�
        return createNode(data);
    }
    
    if (data < root->data) {//���ݽڵ�ֵ�Ĵ�С�ݹ�ѡ�����λ�ã�С�Ĳ���������
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {//��Ĳ���������
        root->right = insert(root->right, data);
    }
    //���ֵ��ȣ���ֱ�ӷ��ص�ǰ�ڵ�
    return root;//���ز���Ľڵ�λ��
}
//�ݹ��
//�������
void InorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //������������������������
    InorderTraversal(root->left);
    printf("%d ", root->data);
    InorderTraversal(root->right);
}

//�������
void PreorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //���ϵ��£�������
    printf("%d ", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

//�������
void PostorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    //�����ң����µ���
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ", root->data);
}
//�����µ�ջ
Stack* CreateStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));//����ջ�ռ�
    stack->top = NULL;
    return stack;
}

//��ջ����
void push(Stack* stack, Node* treeNode) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;//�����ڵ���ջ
    newNode->next = stack->top;
    stack->top = newNode;//��ջ��ָ������ָ������ջ�����ڵ�
}

//��ջ����
Node* pop(Stack* stack) {
    if (stack->top == NULL) {//ջ���пղ���
        return NULL;
    }

    StackNode* temp = stack->top;
    Node* TopNode = temp->treeNode;//ȡ��ջ���ڵ�
    stack->top = temp->next;//ջ��ָ������ָ��ջ��
    free(temp);
    return TopNode;//��ȡ�������ڵ㷵��
}

//�鿴ջ��Ԫ�أ�ֻ�鿴����ջ��
Node* peek(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }

    return stack->top->treeNode;
}

//���ջ�Ƿ�Ϊ��
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

//�ͷ�ջ�ڴ�
void freeStack(Stack* stack) {
    StackNode* current = stack->top;
    StackNode* next;

    while (current != NULL) {//����ջ
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}

//��������ǵݹ�ʵ��
void InorderNonRecursion(Node* root) {
    if (root == NULL) {//���������пղ���
        return;
    }

    Node* current = root;
    Stack* stack = CreateStack();

    while (current != NULL || !isStackEmpty(stack)) {//ջ��Ϊ�ջ����ڵ㲻Ϊ��
        while (current != NULL) {//����ǰ���ڵ��������ȫ����ջ
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;//�����ϳ�ջ��ֱ���������ڵ����������ʱ���������ڵ���ջ���ҷ�ֹ�ڵ�������ջ
    }

    freeStack(stack);//����ջ
}

//��������ǵݹ�ʵ��
void PreorderNonRecursion(Node* root) {
    if (root == NULL) {
        return;
    }

    Stack* stack = CreateStack();
    push(stack, root);//�Ƚ���ţ�Ƶ�Ū��ȥ

    while (!isStackEmpty(stack)) {
        Node* current = pop(stack);
        printf("%d ", current->data);

        if (current->right) {//ջ�Ƚ�������������Һ���
            push(stack, current->right);
        }
        if (current->left) {
            push(stack, current->left);
        }
    }

    freeStack(stack);//����ջ
}

//��������ǵݹ�ʵ��
void PostorderNonRecursion(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* current = root;
    Node* pre = NULL;
    Stack* stack = CreateStack();

    while (current != NULL || !isStackEmpty(stack)) {
        while (current != NULL) {//�Ƚ���ǰ�ڵ���������������ջ���������𽥽���������ջ
            push(stack, current);
            current = current->left;
        }

        current = peek(stack);//ֻ�ǲ鿴��ջ��Ԫ���Բ���

        if (current->right == NULL || current->right == pre) {
            printf("%d ", current->data);
            current = pop(stack);//��ʱ���ǽ�ջ��Ԫ��ȡ��
            pre = current;//��֤������ȡ�����Ի�ȡ��ջ��Ԫ��
            current = NULL;
        }
        else {
            current = current->right;
        }
    }

    freeStack(stack);
}

//�����µĶ���
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

//��Ӳ���
void Enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;//ָ��ǰ���ڵ�
    newNode->next = NULL;

    if (queue->rear == NULL) {//�ն��е����
        queue->front = newNode;//����ͷָ���һֱ�ǵ�һ���ڵ�
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;//���½ڵ��������������
        queue->rear = newNode;//��β����½ڵ�
    }
}

//���Ӳ���
Node* Getqueue(Queue* queue) {
    if (queue->front == NULL) {//�пղ���
        return NULL;
    }
    //ȡ������ͷ����������ͷָ����һ���ڵ�
    QueueNode* temp = queue->front;
    Node* getqueuedNode = temp->treeNode;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return getqueuedNode;//����ȡ���Ľڵ�
}

//�������Ƿ�Ϊ��
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

//�ͷŶ����ڴ�
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
//�������ʵ��
void Sequence(Node* root) {
    if (root == NULL) {//�пղ���
        return;
    }

    Queue* queue = createQueue();
    Enqueue(queue, root);//�Ƚ�ĸ�����

    while (!isQueueEmpty(queue)) {
        Node* currrent = Getqueue(queue);//����
        printf("%d ", currrent->data);
        //���ӵ�ʱ����Ҫͬʱ�����������������
        if (currrent->left) {
            Enqueue(queue, currrent->left);
        }
        if (currrent->right) {
            Enqueue(queue, currrent->right);
        }
    }

    freeQueue(queue);
}

//�����ڵ�
Node* Search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;//�ҵ�����Ϊ�վ����ص�ǰ�ڵ�
    }

    if (data < root->data) {//���ݽڵ�ֵ�Ĵ�С�ж����������������������ݹ����
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

//�ҵ���С�ڵ�
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// ɾ���ڵ�
Node* DeleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    //�������С�ڵ�ǰ�ڵ�,��ȥ������ɾ��
    if (data < root->data) {
        root->left = DeleteNode(root->left, data);
    }
    //������ݴ��ڵ�ǰ�ڵ�,��ȥ������ɾ��
    else if (data > root->data) {
        root->right = DeleteNode(root->right, data);
    }
    //�ҵ�Ҫɾ���Ľڵ�
    else {
        //Ҷ�ڵ�ֱ��ɾ��
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        //�ڵ�ֻ��һ������
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
        //�ڵ����������ӣ�ֱ�Ӻ���滻ɾ���ڵ㣩
        else {
            Node* temp = findMin(root->right);//�ҵ�����������С�ڵ�
            root->data = temp->data;//�滻��ɾ���Ľڵ�
            root->right = DeleteNode(root->right, temp->data);//���滻�Ľڵ�ɾ��
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
        printf("0.�˳�����\n");
        printf("1.����ڵ�\n");
        printf("2.���ҽڵ�\n");
        printf("3.ɾ���ڵ�\n");
        printf("4.����������ݹ�棩\n");
        printf("5.����������ݹ�棩\n");
        printf("6.����������ݹ�棩\n");
        printf("7.����������ǵݹ�棩\n");
        printf("8.����������ǵݹ�棩\n");
        printf("9.�������򣨷ǵݹ�棩\n");
        printf("10.�������\n");
        printf("��ѡ����Ҫ�Ĺ��ܣ�0-10��");
        scanf("%d", &a);
        switch (a) {
        case 1:
            data = 0;
            printf("�������������ݣ�");
            scanf("%s", &data1);
            data = atoi(data1);
            if (data) {
                root = insert(root, data);
                printf("����ɹ�\n");
            }
            else
                printf("����Ƿ�");
            break;
        case 2:
            data = 0;
            printf("��������ҵ����ݣ�");
            scanf("%s", &data1);
            data = atoi(data1);
            if (data) {
                search = Search(root, data);
                if (search)
                    printf("�ҵ��ˣ�\n");
                else
                    printf("δ�ҵ�!\n");
            }
            else
                printf("����Ƿ�");
            break;
        case 3:
            data = 0;
            printf("������ɾ���Ľڵ����ݣ�");
            scanf("%s", &data1);
            data = atoi(data1);
            if(data)
            root = DeleteNode(root, data);
            else
                printf("����Ƿ�");
            break;
        case 4:
            printf("�������Ϊ��");
            PreorderTraversal(root);
            break;
        case 5:
            printf("�������Ϊ��");
            InorderTraversal(root);
            break;
        case 6:
            printf("�������Ϊ��");
            PostorderTraversal(root);
            break;
        case 7:
            printf("�������Ϊ��");
            PreorderNonRecursion(root);

            break;
        case 8:
            printf("�������Ϊ��");
            InorderNonRecursion(root);
            break;
        case 9:
            printf("�������Ϊ;");
            PostorderNonRecursion(root);
            break;
        case 10:
            printf("��α���Ϊ��");
            Sequence(root);
            break;
        default:
            printf("����������������룻");
            break;
        }
        printf("\n");
        system("pause");
    }
    system("pause");
    return 0;
}