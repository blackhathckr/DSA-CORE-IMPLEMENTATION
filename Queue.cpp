// DSA - Queue Core Implementation

#include <iostream>
using namespace std;

class Queue
{
public:
    int front, rear, capacity, size, queue[];
    Queue(int capacity)
    {
        this->front = 0;
        this->capacity = capacity;
        this->rear = capacity - 1;
        this->size = 0;
        this->queue[this->capacity];
        cout<<"Queue of Capacity: "<<this->capacity<<" Initialized"<<endl;
    }

    bool isFull()
    {
        if (size >= capacity-1)
        {
            cout << "Queue is Full!" << endl;
            return true;
        }
        else
        {
            cout << "Queue is not Full!" << endl;
            return false;
        }
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return true;
        }
        else
        {
            cout << "Queue is not Empty!" << endl;
            return false;
        }
    }

    void enqueue()
    {
        if (isFull())
        {
            cout << endl;
        }
        else
        {
            int ele;
            cout << "Enter the Element to Enqueue" << endl;
            cin >> ele;
            rear = (rear + 1) % capacity;
            queue[rear] = ele;
            size += 1;
            cout << "Element " << ele << " Enqueued" << endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            int ele;
            ele = queue[front];
            cout << "Element " << ele << " Dequeued" << endl;
            front = (front + 1) % capacity;
            size -= 1;
        }
    }

    void Front()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            cout << "Queue Front : " << queue[front] << endl;
        }
    }

    void reverseQueue()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            int start = front;
            int end = size - 1;
            while (start <= end)
            {
                int temp = queue[start];
                queue[start] = queue[end];
                queue[end] = temp;
                start++;
                end--;
            }
            cout << "Queue Reversed" << endl;
        }
    }

    void searchQueue()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            int ele, flag = 0;
            cout << "Enter the Element to Search for in the Queue" << endl;
            cin >> ele;
            for (int i = front; i <= rear; i++)
            {
                if (ele == queue[i])
                {
                    cout << "Element " << ele << " Found in the Queue" << endl;
                    flag++;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Element " << ele << " Not Found in the Queue" << endl;
            }
        }
    }

    void queueElementsCount()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            int count = 0;
            for (int i = front; i <= rear; i++)
            {
                count++;
            }
            cout << "Queue Elements Count : " << count << endl;
        }
    }

    void queueElements()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            cout<<"Queue Elements"<<endl;
            int count = 0;
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
        }
    }

    void increaseQueueCapacity()
    {
        int newCapacity;
        cout << "Enter the New Queue Capacity" << endl;
        cin >> newCapacity;
        this->capacity = newCapacity;
        cout << "New Queue Max Capacity : " << this->capacity << endl;
    }

    void clearQueue()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                dequeue();
            }
        }
    }

    ~Queue()
    {
        cout << "Queue Destroyed by Destructor" << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the Capacity of the Queue" << endl;
    cin >> capacity;
    Queue q(capacity);
    cout << "DSA - Queue Core Implementation" << endl;
    int op;
    do
    {
        cout << endl;
        cout << "Choose from the Following Options" << endl;
        cout << "1.isFull" << endl;
        cout << "2.isEmpty" << endl;
        cout << "3.Enqueue" << endl;
        cout << "4.Dequeue" << endl;
        cout << "5.Front" << endl;
        cout << "6.Reverse Queue" << endl;
        cout << "7.Search Queue" << endl;
        cout << "8.Queue Elements Count" << endl;
        cout << "9.Queue Elements" << endl;
        cout << "10.Increase Queue Capacity" << endl;
        cout << "11.Clear Queue" << endl;
        cout << "12.Exit" << endl;
        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            q.isFull();
            break;

        case 2:
            q.isEmpty();
            break;

        case 3:
            q.enqueue();
            break;

        case 4:
            q.dequeue();
            break;

        case 5:
            q.Front();
            break;

        case 6:
            q.reverseQueue();
            break;

        case 7:
            q.searchQueue();
            break;

        case 8:
            q.queueElementsCount();
            break;

        case 9:
            q.queueElements();
            break;

        case 10:
            q.increaseQueueCapacity();
            break;

        case 11:
            q.clearQueue();
            break;

        case 12:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (op != 12);
}