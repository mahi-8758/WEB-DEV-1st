#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Queue {
    int arr[MAX];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue *q, int data) {
    if(q->rear >= MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    if(q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(struct Queue *q) {
    if(q->front < 0 || q->front > q->rear)
        return -1;
    return q->arr[q->front++];
}

int isEmpty(struct Queue *q) {
    return (q->front < 0 || q->front > q->rear);
}

void bfs(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};
    struct Queue *q = createQueue();
    
    visited[start] = 1;
    enqueue(q, start);
    
    printf("BFS Traversal: ");
    while(!isEmpty(q)) {
        int vertex = dequeue(q);
        printf("%d ", vertex);
        
        for(int i = 0; i < vertices; i++) {
            if(graph[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(q);
}

void dfs(int graph[MAX][MAX], int vertices, int start, int visited[MAX]) {
    visited[start] = 1;
    printf("%d ", start);
    
    for(int i = 0; i < vertices; i++) {
        if(graph[start][i] == 1 && !visited[i]) {
            dfs(graph, vertices, i, visited);
        }
    }
}

void dfsTraversal(int graph[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfs(graph, vertices, start, visited);
    printf("\n");
}

void displayGraph(int graph[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

struct AVLNode *root = NULL;

int getHeight(struct AVLNode *node) {
    if(node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct AVLNode *node) {
    if(node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct AVLNode* createNode(int data) {
    struct AVLNode *node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    
    return x;
}

struct AVLNode* rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    
    return y;
}

struct AVLNode* insert(struct AVLNode *node, int data) {
    if(node == NULL) {
        printf("Inserted: %d\n", data);
        return createNode(data);
    }
    
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    else {
        printf("Duplicate value\n");
        return node;
    }
    
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    
    int balance = getBalance(node);
    
    if(balance > 1 && data < node->left->data)
        return rotateRight(node);
    
    if(balance < -1 && data > node->right->data)
        return rotateLeft(node);
    
    if(balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    if(balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

struct AVLNode* findMin(struct AVLNode *node) {
    while(node->left != NULL)
        node = node->left;
    return node;
}

struct AVLNode* deleteNode(struct AVLNode *node, int data) {
    if(node == NULL)
        return NULL;
    
    if(data < node->data)
        node->left = deleteNode(node->left, data);
    else if(data > node->data)
        node->right = deleteNode(node->right, data);
    else {
        if(node->left == NULL && node->right == NULL) {
            free(node);
            printf("Deleted: %d\n", data);
            return NULL;
        }
        else if(node->left == NULL) {
            struct AVLNode *temp = node->right;
            free(node);
            printf("Deleted: %d\n", data);
            return temp;
        }
        else if(node->right == NULL) {
            struct AVLNode *temp = node->left;
            free(node);
            printf("Deleted: %d\n", data);
            return temp;
        }
        else {
            struct AVLNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    
    if(node == NULL)
        return NULL;
    
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    
    int balance = getBalance(node);
    
    if(balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);
    
    if(balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    if(balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);
    
    if(balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

void inorder(struct AVLNode *node) {
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void display(struct AVLNode *root) {
    if(root == NULL) {
        printf("AVL Tree is empty\n");
        return;
    }
    printf("AVL Tree (Inorder): ");
    inorder(root);
    printf("\n");
}

int main() {
    int vertices, choice, start, u, v;
    int graph[MAX][MAX] = {0};
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    if(vertices > MAX) {
        printf("Number of vertices exceeds maximum\n");
        return 0;
    }
    
    while(1) {
        printf("\n=== Graph Traversal ===\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. BFS Traversal\n");
        printf("4. DFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter source vertex (0-%d): ", vertices-1);
                scanf("%d", &u);
                printf("Enter destination vertex (0-%d): ", vertices-1);
                scanf("%d", &v);
                
                if(u >= 0 && u < vertices && v >= 0 && v < vertices) {
                    graph[u][v] = 1;
                    graph[v][u] = 1;
                    printf("Edge added: %d - %d\n", u, v);
                } else {
                    printf("Invalid vertices\n");
                }
                break;
            case 2:
                displayGraph(graph, vertices);
                break;
            case 3:
                printf("Enter starting vertex (0-%d): ", vertices-1);
                scanf("%d", &start);
                if(start >= 0 && start < vertices) {
                    bfs(graph, vertices, start);
                } else {
                    printf("Invalid vertex\n");
                }
                break;
            case 4:
                printf("Enter starting vertex (0-%d): ", vertices-1);
                scanf("%d", &start);
                if(start >= 0 && start < vertices) {
                    dfsTraversal(graph, vertices, start);
                } else {
                    printf("Invalid vertex\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}