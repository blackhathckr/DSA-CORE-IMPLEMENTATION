// DSA - Stack Code Implementation

#include <iostream>
using namespace std;

class Stack
{
public:
    int top, capacity, size, stack[];
    Stack(int capacity)
    {
        this->top = -1;
        this->capacity = capacity;
        this->size = 0;
        this->stack[this->capacity];
        cout<<"Stack of Capacity: "<<this->capacity<<" Initialized"<<endl;
    }

    bool isOverflow()
    {
        if (size >= capacity)
        {
            cout << "Stack Overflow" << endl;
            return true;
        }
        else
        {
            cout << "No Stack Overflow" << endl;
            return false;
        }
    }

    bool isUnderflow()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return true;
        }
        else
        {
            cout << "No Stack Underflow" << endl;
            return false;
        }
    }

    void push()
    {
        if (isOverflow())
        {
            cout << "Stack Overflow. Push Operation not Possible. Increase the Capacity of the Stack" << endl;
        }
        else
        {
            int ele;
            cout << "Enter the Element to Push into the Stack" << endl;
            cin >> ele;
            stack[++top] = ele;
            size+=1;
            cout << "Element " << ele << " Pushed into the Stack" << endl;
        }
    }

    void pop()
    {
        if(isUnderflow())
        {
            cout<< "Stack Underflow. Pop Operation not Possible" << endl;
        }
        else 
        {
            int ele;
            ele=stack[top--];
            size-=1;
            cout<<"Element Popped is "<<ele<<endl;
        }
    }

    void peek()
    {
        if(isUnderflow())
        {
            cout<< "Stack Underflow. Peek not Possible" << endl;
        }
        else 
        {
            cout<<"Peek Element :"<<stack[top]<<endl;
        }
    }

    void reverseStack()
    {
        if(isUnderflow())
        {
            cout<< "Stack Underflow. Stack Reversal not Possible" << endl;
        }
        else 
        {
        int start=0;
        int end=size-1;
        while(start<=end)
        {
            int temp=stack[start];
            stack[start]=stack[end];
            stack[end]=temp;
            start++;
            end--;
        }
        cout<<"Stack Reversed"<<endl;
        }
    }

    void searchStack()
    {
        int ele,flag=0;
        cout<<"Enter the Element to Search for in the Stack"<<endl;
        cin>>ele;
        for(int i=top;i>=0;i--)
        {
            if(ele==stack[i])
            {
                cout<<"Element "<<ele<<" Found in the Stack"<<endl;
                flag++;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Element "<<ele<<" Not Found in the Stack"<<endl;
        }
    }

    void stackElementsCount()
    {
        if(isUnderflow())
        {
            cout<<"The Stack is Empty"<<endl;
        }
        else 
        {
            int count=0;
            for(int i=top;i>=0;i--)
            {
                count++;
            }
            cout<<"Stack Elements Count :"<<count<<endl;
        }
    }

    void stackElements()
    {
        if(isUnderflow())
        {
            cout<<"The Stack is Empty"<<endl;
        }
        else 
        {
            cout<<"Stack Elements :"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<endl;
            }
        }
    }

    void increaseStackCapacity()
    {
        int newCapacity;
        cout << "Enter the New Array Capacity" << endl;
        cin >> newCapacity;
        this->capacity = newCapacity;
        cout << "Updated Array Capacity: " << this->capacity << endl;
    }

    void clearStack()
    {
        for(int i=top;i>=0;i--)
        {
            pop();
        }
        cout<<"Stack Cleared"<<endl;
    }

    ~Stack()
    {
        cout<<"Stack Destroyed by Destructor"<<endl;
    }
};

int main()
{
    int capacity;
    cout<<"Enter the Capacity of the Stack"<<endl;
    cin>>capacity;
    Stack s(capacity);
    cout<<"DSA - Stack Core Implementation"<<endl;
    int op;
    do
    {
        cout<<endl;
        cout<<"Choose from the Following Options"<<endl;
        cout<<"1.isOverflow"<<endl;
        cout<<"2.isUnderflow"<<endl;
        cout<<"3.Push"<<endl;
        cout<<"4.Pop"<<endl;
        cout<<"5.Peek"<<endl;
        cout<<"6.Reverse Stack"<<endl;
        cout<<"7.Search Stack"<<endl;
        cout<<"8.Stack Elements Count"<<endl;
        cout<<"9.Stack Elements"<<endl;
        cout<<"10.Increase Stack Capacity"<<endl;
        cout<<"11.Clear Stack"<<endl;
        cout<<"12.Exit"<<endl;
        cout<<endl;
        cin>>op;
        switch (op)
        {
        case 1:s.isOverflow();
            break;

        case 2:s.isUnderflow();
            break;

        case 3:s.push();
            break;

        case 4:s.pop();
            break;

        case 5:s.peek();
            break;

        case 6:s.reverseStack();
            break;

        case 7:s.searchStack();
            break;

        case 8:s.stackElementsCount();
            break;

        case 9:s.stackElements();
            break;

        case 10:s.increaseStackCapacity();
            break;

        case 11:s.clearStack();
            break;

        case 12:
            break;
        
        default:cout<<"Invalid Option"<<endl;
            break;
        }
    } while (op!=12);
}