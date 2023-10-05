// DSA - Circular Queue Core Implementation

#include <iostream>
using namespace std;

class Circular_Queue
{
public:
    int front, rear, capacity, size, queue[];
    Circular_Queue(int capacity)
    {
        this->front = 0;
        this->capacity = capacity;
        this->rear = capacity- 1;
        this->size = 0;
        this->queue[this->capacity];
        cout<<"Circular Queue of Capacity: "<<this->capacity<<" Initialized"<<endl;
    }

    bool isFull()
    {
        if (size >= capacity-1)
        {
            cout << "Circular Queue is Full!" << endl;
            return true;
        }
        else
        {
            cout << "Circular Queue is not Full!" << endl;
            return false;
        }
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            cout << "Circular Queue is Empty!" << endl;
            return true;
        }
        else
        {
            cout << "Circular Queue is not Empty!" << endl;
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

    void reverseCircularQueue()
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
            cout << "Circular Queue Reversed" << endl;
        }
    }

    void searchCircularQueue()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            int ele, flag = 0;
            cout << "Enter the Element to Search for in the Circular Queue" << endl;
            cin >> ele;
            for (int i = front; i <= rear; i++)
            {
                if (ele == queue[i])
                {
                    cout << "Element " << ele << " Found in the Circular Queue" << endl;
                    flag++;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Element " << ele << " Not Found in the Circular Queue" << endl;
            }
        }
    }

    void circularQueueElementsCount()
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
            cout << "Circular Queue Elements Count : " << count << endl;
        }
    }

    void circularQueueElements()
    {
        if (isEmpty())
        {
            cout << endl;
        }
        else
        {
            cout<<"Circular Queue Elements"<<endl;
            int count = 0;
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
        }
    }

    void increaseCircularQueueCapacity()
    {
        int newCapacity;
        cout << "Enter the New Circular Queue Capacity" << endl;
        cin >> newCapacity;
        this->capacity = newCapacity;
        cout << "New Circular Queue Max Capacity : " << this->capacity << endl;
    }

    void clearCircularQueue()
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

    ~Circular_Queue()
    {
        cout << "Circular Queue Destroyed by Destructor" << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the Capacity of the Circular Queue" << endl;
    cin >> capacity;
    Circular_Queue cq(capacity);
    cout << "DSA - Circular Queue Core Implementation" << endl;
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
        cout << "6.Reverse Circular Queue" << endl;
        cout << "7.Search Circular Queue" << endl;
        cout << "8.Circular Queue Elements Count" << endl;
        cout << "9.Circular Queue Elements" << endl;
        cout << "10.Increase Circular Queue Capacity" << endl;
        cout << "11.Clear Circular Queue" << endl;
        cout << "12.Exit" << endl;
        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cq.isFull();
            break;

        case 2:
            cq.isEmpty();
            break;

        case 3:
            cq.enqueue();
            break;

        case 4:
            cq.dequeue();
            break;

        case 5:
            cq.Front();
            break;

        case 6:
            cq.reverseCircularQueue();
            break;

        case 7:
            cq.searchCircularQueue();
            break;

        case 8:
            cq.circularQueueElementsCount();
            break;

        case 9:
            cq.circularQueueElements();
            break;

        case 10:
            cq.increaseCircularQueueCapacity();
            break;

        case 11:
            cq.clearCircularQueue();
            break;

        case 12:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (op != 12);
}