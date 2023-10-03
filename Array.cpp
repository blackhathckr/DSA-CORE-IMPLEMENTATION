// DSA - Array Core Implementation

#include <iostream>
#include<typeinfo>
using namespace std;

class Array
{
public:
    int capacity, size, arr[];
    Array(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        arr[this->capacity];
        cout<<"Array of Capacity: "<<this->capacity<<" Initialized"<<endl;
    }

    void createArray()
    {
        int ele;
        cout << "Enter the Number of Elements in the Array" << endl;
        cin >> size;
        cout << "Enter the " << size << " Elements" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> ele;
            arr[i] = ele;
        }
        cout << "Array Created" << endl;
        arrayMetaData();
    }

    void arrayMetaData()
    {
        cout<<"Datatype "<<typeid(arr).name()<<endl;
        cout<<"Capacity "<<capacity<<endl;
        cout<<"Size "<<size<<endl;
        cout<<capacity-size<<" Storage Capacity left"<<endl;
    }

    void isArrayFull()
    {
        if(size>=capacity)
        {
            arrayMetaData();
            cout<<"Array is Full"<<endl;
        }
        else 
        {
            arrayMetaData();
        }
    }

    void isArrayEmpty()
    {
        if(size==0)
        {
            arrayMetaData();
            cout<<"Array is Empty"<<endl;
        }
        else 
        {
            arrayMetaData();
        }
    }

    void appendElement()
    {
        int ele;
        cout<<"Enter the Element to Append"<<endl;
        cin>>ele;
        arr[size]=ele;
        size+=1;
        cout<<"Element "<<ele<<" Appened"<<endl;
    }

    void insertAtPosition()
    {
        if (size == capacity)
        {
            cout << "Array Max Capacity Reached. Insertion Not possible. Increase the Capacity. " << endl;
        }
        else
        {
            int pos, ele;
            cout << "Enter the Position to Insert at" << endl;
            cin >> pos;
            cout << "Enter the Element to Insert" << endl;
            cin >> ele;
            for (int i = capacity - 1; i >= pos - 1; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[pos - 1] = ele;
            size += 1;
            cout << "Element " << ele << " Inserted at Position " << pos << endl;
        }
    }

    void deleteAtPosition()
    {
        int pos;
        cout << "Enter the Position to Delete at" << endl;
        cin >> pos;
        for (int i = pos - 1; i < capacity; i++)
        {
            arr[i] = arr[i + 1];
        }
        size -= 1;
        cout << "Element Deleted at Position " << pos << endl;
    }

    void insertAtIndex()
    {
        if (size == capacity)
        {
            cout << "Array Max Capacity Reached. Insertion Not possible. Increase the Capacity. " << endl;
        }
        else
        {
            int ind, ele;
            cout << "Enter the Index to Insert at" << endl;
            cin >> ind;
            cout << "Enter the Element to Insert" << endl;
            cin >> ele;
            for (int i = capacity; i >= ind; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[ind] = ele;
            size += 1;
            cout << "Element " << ele << " Inserted at Index " << ind << endl;
        }
    }

    void deleteAtIndex()
    {
        int ind;
        cout << "Enter the Position to Delete at" << endl;
        cin >> ind;
        for (int i = ind; i < capacity; i++)
        {
            arr[i] = arr[i + 1];
        }
        size -= 1;
        cout << "Element Deleted at Index " << ind << endl;
    }

    void updateAtPosition()
    {
        int pos,ele;
        cout << "Enter the Position to Update at" << endl;
        cin>>pos;
        cout<<"Enter the Element "<<endl;
        cin>>ele;
        arr[pos-1]=ele;
        cout<<"Element Updated at Position "<<pos<<endl;
    }

    void updateAtIndex()
    {
        int ind,ele;
        cout << "Enter the Index to Update at" << endl;
        cin>>ind;
        cout<<"Enter the Element "<<endl;
        cin>>ele;
        arr[ind]=ele;
        cout<<"Element Updated at Index "<<ind<<endl;
    }

    void linearSearch()
    {
        int ele, flag = 0;
        cout << "Enter the Element to Linear Search for in the Array" << endl;
        cin >> ele;
        for (int i = 0; i < size; i++)
        {
            if (ele == arr[i])
            {
                cout << "Element " << ele << " Found at Position " << i + 1 << " & Index " << i << endl;
                flag++;
                break;
            }
            else
            {
                continue;
            }
        }
        if (flag == 0)
        {
            cout << "Element " << ele << " Not Found" << endl;
        }
    }

    void sortArray()
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<size-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        cout<<"Array Sorted"<<endl;
    }

    void binarySearch()
    {
        sortArray();
        int ele, flag = 0;
        cout << "Enter the Element to Binary Search for in the Array" << endl;
        cin >> ele;
        int start = 0, end = size - 1;
        int mid = (start + end) / 2;
        while (start <= end)
        {
            if (ele == arr[mid])
            {
                cout << "Element " << ele << " Found at Position " << mid + 1 << " & Index " << mid << endl;
                flag++;
                break;
            }
            else if (ele > mid)
            {
                start = mid + 1;
            }
            else if (ele < mid)
            {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        if (flag == 0)
        {
            cout << "Element " << ele << " Not Found" << endl;
        }
    }

    void reverseArray()
    {
        int start = 0;
        int end = size - 1;
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start += 1;
            end -= 1;
        }
        cout << "Array Reversed " << endl;
    }

    void arrayElementsCount()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            count++;
        }
        cout << "Array Elements Count: " << count << endl;
    }

    void arrayTraversal()
    {
        cout << "Array elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void increaseArrayCapacity()
    {
        int newCapacity;
        cout << "Enter the New Array Capacity" << endl;
        cin >> newCapacity;
        this->capacity = newCapacity;
        cout << "Updated Array Capacity: " << this->capacity << endl;
    }

    ~Array()
    {
        cout<<"Array Destroyed by Destructor"<< endl;
    }
};

int main()
{
    int capacity, n;
    cout << "Enter the Max Capacity of the Array" << endl;
    cin >> capacity;
    cout << "DSA - Array Core Implementation: " << endl;
    Array a(capacity);
    int op;
    do
    {
        cout << endl;
        cout << "Choose an Option: " << endl;
        cout << "1.Create Array" << endl;
        cout << "2.Array MetaData" << endl;
        cout << "3.isArrayFull" << endl;
        cout << "4.isArrayEmpty" << endl;
        cout << "5.Append Element" <<endl;
        cout << "6.Insert Element at Position " << endl;
        cout << "7.Delete Element at Postion" << endl;
        cout << "8.Insert Element at Index" << endl;
        cout << "9.Delete Element at Index" << endl;
        cout << "10.Update Element at Postion" << endl;
        cout << "11.Update Element at Index" << endl;
        cout << "12.Linear Search" << endl;
        cout<<  "13.Sort Array" << endl;
        cout << "14.Binary Search" << endl;
        cout << "15.Reverse Array" << endl;
        cout << "16.Array Elements Count" << endl;
        cout << "17.Array Traversal" << endl;
        cout << "18.Increase Array Capacity" << endl;
        cout << "19.Exit" << endl;
        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            a.createArray();
            break;

        case 2:
            a.arrayMetaData();
            break;
        
        case 3:
            a.isArrayFull();
            break;

        case 4:
            a.isArrayEmpty();
            break;

        case 5:
            a.appendElement();
            break;

        case 6:
            a.insertAtPosition();
            break;

        case 7:
            a.deleteAtPosition();
            break;

        case 8:
            a.insertAtIndex();
            break;

        case 9:
            a.deleteAtIndex();
            break;

        case 10:
            a.updateAtPosition();
            break;

        case 11:
            a.updateAtIndex();
            break;

        case 12:
            a.linearSearch();
            break;

        case 13:
            a.sortArray();
            break;

        case 14:
            a.binarySearch();
            break;

        case 15:
            a.reverseArray();
            break;

        case 16:
            a.arrayElementsCount();
            break;

        case 17:
            a.arrayTraversal();
            break;

        case 18:
            a.increaseArrayCapacity();
            break;

        case 19:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (op != 19);
}