#include"HeapAndTree.h"
//�����µĶ�
BinaryHeap* createHeap() {
    BinaryHeap* heap = (BinaryHeap*)malloc(sizeof(BinaryHeap));//���ٿռ�
    heap->size = 0;//��Сָ��Ϊ0
    return heap;
}

//��������Ԫ��
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//�ϸ�����
void HeapUp(BinaryHeap* heap, int index) {
    int parentIndex = (index - 1) / 2;//���ڵ�

    if (heap->arr[parentIndex] < heap->arr[index]) {//ȷ�����ڵ��ֵ�����ģ��Ҹ��ڵ��ֵ�����ӽڵ�
        swap(&heap->arr[parentIndex], &heap->arr[index]);
        HeapUp(heap, parentIndex);
    }
}

//�³�����
void HeapDown(BinaryHeap* heap, int index) {
    int leftChildIndex = 2 * index + 1;//���ӽڵ��±�
    int rightChildIndex = 2 * index + 2;//���ӽڵ���±�
    int largestIndex = index;//���ֵ�ڵ�
    //�ҳ���ǰ�ڵ㡢���ӽڵ�����ӽڵ��е����ֵ���ڵ�λ��
    if (leftChildIndex < heap->size && heap->arr[leftChildIndex] > heap->arr[largestIndex]) {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < heap->size && heap->arr[rightChildIndex] > heap->arr[largestIndex]) {
        largestIndex = rightChildIndex;
    }
    //������ֵ���ǵ�ǰ�ڵ㣬�������ֵ����λ�ã������������³�
    if (largestIndex != index) {
        swap(&heap->arr[index], &heap->arr[largestIndex]);
        HeapDown(heap, largestIndex);
    }
}

//����Ԫ��
void InsertRoot(BinaryHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("������\n");
        return;
    }

    heap->arr[heap->size] = value;//������Ԫ�ط���
    HeapUp(heap, heap->size);//�ϸ�����
    heap->size++;
}

//ɾ�����ڵ�
int DeleteRoot(BinaryHeap* heap) {
    if (heap->size == 0) {
        printf("��Ϊ�գ�����ɾ��\n");
        return -1;
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];//�����ڵ��ֵ�������ӽڵ�ֵ����
    heap->size--;//��ɾ�����ڵ������
    HeapDown(heap, 0);//�³�����

    return root;
}

//��ӡ��
void printHeap(BinaryHeap* heap) {
    
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}


//��ȡ�ڵ�߶�
int getHeight(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

//��ȡƽ������
int getBalanceFactor(AVLNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

//����ת
AVLNode* AVLrightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    //ִ����ת
    x->right = y;
    y->left = T2;
    //���½ڵ�߶�
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    //�����µĸ��ڵ�
    return x;
}

//����ת
AVLNode* AVLleftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    //ִ����ת
    y->left = x;
    x->right = T2;

    //���½ڵ�߶�
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    //�����µĸ��ڵ�
    return y;
}

//����ڵ�
AVLNode* insertAVLNode(AVLNode* node, int data) {
    //�ݹ����
    if (node == NULL) {//��֦ɢҶ
        AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
        newNode->data = data;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    //����������С�ڸ��ڵ�
    if (data < node->data) {
        node->left = insertAVLNode(node->left, data);
    }//���������ݴ��ڸ��ڵ�
    else if (data > node->data) {
        node->right = insertAVLNode(node->right, data);
    }
    else {
        //�ظ����ݲ�����
        return node;
    }
    //���½ڵ�߶�
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    //��ȡƽ������
    int balanceFactor = getBalanceFactor(node);

    //�������
    if (balanceFactor > 1 && data < node->left->data) {
        return AVLrightRotate(node);
    }

    //�������
    if (balanceFactor < -1 && data > node->right->data) {
        return AVLleftRotate(node);
    }

    //�������
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = AVLleftRotate(node->left);
        return AVLrightRotate(node);
    }

    //�������
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = AVLrightRotate(node->right);
        return AVLleftRotate(node);
    }

    //�����µĸ��ڵ�
    return node;
}

//���ҽڵ�
AVLNode* searchAVLNode(AVLNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    //��������
    if (data < root->data) {
        return searchAVLNode(root->left, data);
    }
    else {
        return searchAVLNode(root->right, data);
    }
}

//��ȡ��Сֵ�ڵ�
AVLNode* getMinNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }//��Сֵ����������Ҷ����
    return current;
}

// ɾ���ڵ�
AVLNode* deleteNode(AVLNode* root, int data) {
    // �ݹ���Ҳ�ɾ���ڵ�
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
        //�ҵ�Ҫɾ���Ľڵ�
        //û���ӽڵ�
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        //ֻ��һ���ӽڵ�
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

        // �������ӽڵ�
        else {
            AVLNode* minNode = getMinNode(root->right);//ֱ�Ӻ��
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }
    }
    //���½ڵ�߶�
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));
    //��ȡƽ������
    int balanceFactor = getBalanceFactor(root);

    //�������
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
        return AVLrightRotate(root);
    }
    //�������
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
        root->left = AVLleftRotate(root->left);
        return AVLrightRotate(root);
    }
    //�������
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
        return AVLleftRotate(root);
    }
    //�������
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
        root->right = AVLrightRotate(root->right);
        return AVLleftRotate(root);
    }

    return root;
}

//�������
void inorderAVLTraversal(AVLNode* root) {
    if (root == NULL) {
        return;
    }
    inorderAVLTraversal(root->left);
    printf("%d ", root->data);
    inorderAVLTraversal(root->right);
}

//�����½ڵ�
RBNode* createNode(int data) {
    RBNode* newNode = (RBNode*)malloc(sizeof(RBNode));
    newNode->data = data;
    newNode->color = RED;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ����ת
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

// ����ת
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

// ����ڵ�
void insertRBNode(RBNode** root, RBNode* node) {
    RBNode* y = NULL;
    RBNode* x = *root;
    //����ֵ�Ĵ�Сѡ�����λ��
    while (x != NULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    //������ڵ�����������
    node->parent = y;
    //��Ϊ�յ����
    if (y == NULL) {
        *root = node;
    }//���ݴ�Сѡ������λ��
    else if (node->data < y->data) {
        y->left = node;
    }
    else {
        y->right = node;
    }

    node->left = NULL;
    node->right = NULL;
    node->color = RED;

    // �����޸�
    insertFixup(root, node);
}

// �����޸�
void insertFixup(RBNode** root, RBNode* node) {
    RBNode* parent;
    RBNode* grandparent;
    
    while ((parent = node->parent) && parent->color == RED) {
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            RBNode* uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                //���ڵ������ڵ㶼�Ǻ�ɫ
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            }
            else {
                if (node == parent->right) {
                    //�ڵ����Һ���
                    RBleftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                //�ڵ�������
                RBrightRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                node = parent;
            }
        }
        else {
            RBNode* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                //���ڵ������ڵ㶼�Ǻ�ɫ
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            }
            else {
                if (node == parent->left) {
                    //�ڵ�������
                    RBrightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                //�ڵ����Һ���
                RBleftRotate(root, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
                node = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

// ���ҽڵ�
RBNode* searchRBNode(RBNode* root, int data) {
    RBNode* current = root;
    //����ֵ�Ĵ�С��������λ��
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

// �������
void inorderRBTraversal(RBNode* root) {
    if (root == NULL) {
        return;
    }
    inorderRBTraversal(root->left);
    printf("%d ", root->data);
    inorderRBTraversal(root->right);
}


// ��������
void clearScreen() {
    system("cls||clear"); 
}
int main() {
    int choice, data;
    RBNode* rbRoot = NULL;
    AVLNode* avlRoot = NULL;
    BinaryHeap* heapRoot = createHeap();

    while (1) {
        clearScreen(); // ����
        //printf("�����(1) / AVL��(2) / ��(3) / �˳�(0): ");
        printf("===========================================\n");
        printf("0.�˳�\n");
        printf("1.���������\n");
        printf("2.AVL������\n");
        printf("3.�ѵĲ���\n");
        printf("��ѡ����(0-3)");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("���������: \n");
            printf("1.����\n");
            printf("2.����\n");
            printf("��ѡ����(1-2)");

            scanf("%d", &choice);

            if (choice == 1) {
                printf("��������: ");
                scanf("%d", &data);
                insertRBNode(&rbRoot, createNode(data));
                printf("��Enter������...");
                getchar(); getchar(); // �ȴ��û�����
            }
         
            else if (choice == 2) {
                printf("������������: ");
                inorderRBTraversal(rbRoot);
                printf("\n��Enter������...");
                getchar(); getchar();
            }
            break;

        case 2:
            printf("AVL������:\n");
            printf("1.����\n");
            printf("2.ɾ��\n");
            printf("3.����\n");
            printf("��ѡ����(1-3)");

            scanf("%d", &choice);

            if (choice == 1) {
                printf("��������: ");
                scanf("%d", &data);
                avlRoot=insertAVLNode(avlRoot, data);
                printf("��Enter������...");
                getchar(); getchar();
            }
            else if (choice == 2) {
                printf("��������: ");
                scanf("%d", &data);
                avlRoot = deleteNode(avlRoot, data);
                
                printf("��Enter������...");
                getchar(); getchar();
            }
            else if (choice == 3) {
                printf("AVL���������: ");
                inorderAVLTraversal(avlRoot);
                printf("\n��Enter������...");
                getchar(); getchar();
            }
            break;

        case 3:
            printf("�Ѳ���:\n");
            printf("1.����\n");
            printf("2.ɾ�����ڵ�\n");
            printf("3.����\n");
            printf("��ѡ����(1-3)");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("��������: ");
                scanf("%d", &data);
                InsertRoot(heapRoot, data);
                printf("��Enter������...");
                getchar(); getchar();
            }
            else if (choice == 2) {
               
                int i = DeleteRoot(heapRoot, data);
                printf("��Enter������...");
                getchar(); getchar();
            }
            else if (choice == 3) {
                printf("�ѱ���: ");
                printHeap(heapRoot);
                printf("\n��Enter������...");
                getchar(); getchar();
            }
            break;

        case 0:
            exit(0);

        default:
            printf("��Чѡ��!\n");
            printf("��Enter������...");
            getchar(); getchar();
        }
    }

    return 0;
}
