#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int size;
    int* arr;
};

struct queue* createQueue(int size);
void enqueue(struct queue* q, int item);
int dequeue(struct queue* q);
int isqempty(struct queue* q);

int main()
{
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int adjacencyMatrix[numNodes][numNodes];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    int* visited = (int*)malloc(numNodes * sizeof(int));
    for (int i = 0; i < numNodes; i++)
        {
        visited[i] = 0;
    }

    struct queue* q = createQueue(numNodes);
    printf("%d ", start);
    visited[start] = 1;
    enqueue(q, start);

    while (!isqempty(q))
        {
        int u = dequeue(q);
        for (int j = 0; j < numNodes; j++)
         {
            if (adjacencyMatrix[u][j] == 1 && visited[j] == 0)
             {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    free(visited);
    free(q->arr);
    free(q);
    return 0;
}

struct queue* createQueue(int size)
 {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct queue* q, int item)
{
    if (q->rear == q->size - 1)
        {
        printf("Queue is full\n");
    }
    else
     {
        q->rear++;
        q->arr[q->rear] = item;
        if (q->front == -1)
        {
            q->front = 0;
        }
    }
}

int dequeue(struct queue* q)
 {
    if (q->front == -1 || q->front > q->rear)
        {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->arr[q->front];
        q->front++;
        return item;
    }
}

int isqempty(struct queue* q)
{
    if (q->front == -1 || q->front > q->rear)
        {
        return 1;
    }
    else
    {
        return 0;
    }
}
