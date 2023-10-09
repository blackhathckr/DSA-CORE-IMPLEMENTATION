// DSA - Priority Queue Core Implementation
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 1000

bool isFull();
bool isEmpty();
void enqueue();
int peek();
void dequeue();
void priorityQueueElementsCount();
void priorityQueueElements();

struct PriorityQueue
{
    int element;
    int priority;
};
struct PriorityQueue pq[MAX];
int size=0;
int main()
{
   int op;
   printf("DSA - Priority Queue Core Implementation \n");
   do
   {
    printf("\n");
    printf("Choose from the Following Options \n");
    printf("1.isEmpty\n");
    printf("2.isEmpty\n");
    printf("3.Enqueue\n");
    printf("4.Dequeue\n");
    printf("5.Priority Queue Elements Count\n");
    printf("6.Priority Queue Elements\n");
    printf("7.Exit\n");
    printf("\n");
    scanf("%d",&op);
    printf("\n");
    switch (op)
    {
    case 1:isFull();
        break;

    case 2:isEmpty();
        break;

    case 3:enqueue();
        break;

    case 4:dequeue();
        break;

    case 5:priorityQueueElementsCount();
        break;

    case 6:priorityQueueElements();
        break;

    case 7:
        break;
    
    default:printf("Invalid op %d\n",op);
        break;
    }
   } while (op!=7);
}

bool isFull()
{
    if(size>=MAX)
    {
        printf("Priority Queue is Full\n");
        return true;
    }
    else 
    {
        printf("Priority Queue is Not Full\n");
        return false;
    }
}

bool isEmpty()
{
    if(size==0)
    {
        printf("Priority Queue is Empty\n");
        return true;
    }
    else 
    {
        printf("Priority Queue is Not Empty\n");
        return false;
    }
}

void enqueue()
{
    int element,priority;
    size++;
    printf("Enter the Element to Enqueue \n");
    scanf("%d",&element);
    printf("Enter the Priority of the Element %d \n",element);
    scanf("%d",&priority);
    pq[size].element=element;
    pq[size].priority=priority;
    printf("Element %d of Priority %d Enqueued \n",element,priority);
}

int peek()
{
    int highest_priority=INT_MIN;
    int ind=-1;
    for(int i=0;i<=MAX;i++)
    {
        if(highest_priority==pq[i].priority && ind==-1 && pq[ind].element<pq[i].element)
        {
            highest_priority=pq[i].priority;
            ind=i;
        }
        else if(highest_priority<pq[i].priority)
        {
            highest_priority=pq[i].priority;
            ind=i;
        }
    }
    return ind;
}

void dequeue()
{
    if(isEmpty()) printf("\n");
    if(size==0) return;
    int ind=peek();
    printf("Element %d of Priority %d Dequeued\n",pq[ind].element,pq[ind].priority);
    for(int i=ind;i<MAX;i++)
    {
        pq[i]=pq[i+1];
    }
    size--;
}

void priorityQueueElementsCount()
{
    printf("Priority Queue Elements Count : %d \n",size);
}

void priorityQueueElements()
{
    if(isEmpty()) printf("\n");
    if(size==0) return; 
    printf("Priority Queue Elements : \n");
    for(int i=1;i<=size;i++)
    {
        printf("%d \n",pq[i].element);
    }
}