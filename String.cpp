// DSA String Core Implementation

#include<iostream>
#include<typeinfo>

using namespace std;

class String
{
    public:
    int capacity,len;
    string str;
    String()
    {
        this->str="";
        this->capacity=20;
        this->len=0;
        cout<<"String of Capacity: "<<this->capacity<<" Initialized"<<endl;
    }

    void initializeString()
    {
        cout<<"Enter the String"<<endl;
        cin>>str;
        while(str[len]!='\0')
        {
            len++;
        }
        cout<<"String Initialized"<<endl;
    }

    void stringMetaData()
    {
        cout<<"DataType: "<<typeid(str).name()<<endl;
        displayString();
        cout<<endl;
        stringLength();
    }

    void displayString()
    {
        cout<<"String :"<<endl;
        int pos=0;
        while(str[pos]!='\0')
        {
            cout<<str[pos];
            pos++;
        }
        cout<<endl;
    }

    void stringLength()
    {
        int length=0;
        while(str[length]!='\0')
        {
            length++;
        }
        cout<<"Length of String :"<<length<<endl;
    }

    void concatenateString()
    {
        string str;
        cout<<"Enter the String to Concatenate"<<endl;
        cin >> str;
        this->str=this->str+str;
        cout<<"Concatenated"<<endl;
    }

    void subString()
    {
        int start,end;
        cout<<"Enter the Start Index "<<endl;
        cin>>start;
        cout<<"Enter the End Index "<<endl;
        cin>>end;
        for(int i=start;i<end;i++)
        {
            cout<<str[i];
        }
        cout<<endl;
    }

    void characterAtIndex()
    {
        int ind;
        cout<<"Enter the Index"<<endl;
        cin>>ind;
        cout<<"Character at Index "<<ind<<": "<<str[ind]<<endl;
    }

    void compareString()
    {
        string str;
        cout<<"Enter the String"<<endl;
        cin>>str;
        if(this->str==str)
        {
            cout<<"String Equality: True"<<endl;
        }
        else 
        {
            cout<<"String Equality: False"<<endl;
        }
    }

    void reverseString()
    {
        int start=0;
        int end=str.length()-1;
        while(start<=end)
        {
            char temp=str[start];
            str[start]=str[end];
            str[end]=temp;
            start++;
            end--;
        }
        cout<<"String Reversed"<<endl;
    }

    void palindrome()
    {
        string str=this->str;
        int start=0;
        int end=str.length()-1;
        while(start<=end)
        {
            char temp=str[start];
            str[start]=str[end];
            str[end]=str[start];
            start++;
            end--;
        }
        if(str==this->str)
        {
            cout<<"Palindrome"<<endl;
        }
        else 
        {
            cout<<"Not a Palindrome"<<endl;
        }
    }

    void searchStringForChar()
    {
        char c;
        cout<<"Enter the Character to Search for in the String"<<endl;
        cin>>c;
        int start=0;
        int count=0;
        while(str[start]!='\0')
        {
            if(str[start]==c)
            {
                count++;
            }
            start++;
        }
        if(count==0)
        {
            cout<<"Character Not Found"<<endl;
        }
        else
        {
            cout<<"Character "<<c<<" Found . Instances : "<<count<<endl;
        }
    }

    void insertAtPosition()
    {
        int pos;
        char c;
        cout<<"Enter the Position to Insert at"<<endl;
        cin>>pos;
        cout<<"Enter the Character"<<endl;
        cin>>c;
        for(int i=capacity-1;i>=pos-1;i--)
        {
            str[i+1]=str[i];
        }
        str[pos-1]=c;
        len+=1;
        cout<<"Inserted Character "<<c<<" at Position "<<pos<<endl;
    }

    void deleteAtPosition()
    {
        int pos;
        cout<<"Enter the Position to Delete at"<<endl;
        cin>>pos;
        for(int i=pos-1;i<capacity;i++)
        {
            str[i]=str[i+1];
        }
        len-=1;
        cout<<"Deleted Character at Position "<<pos<<endl;
    }

    void insertAtIndex()
    {
        int ind;
        char c;
        cout<<"Enter the Index to Insert at"<<endl;
        cin>>ind;
        cout<<"Enter the Character"<<endl;
        cin>>c;
        for(int i=capacity;i>=ind;i--)
        {
            str[i+1]=str[i];
        }
        str[ind]=c;
        len+=1;
        cout<<"Inserted Character "<<c<<" at Index "<<ind<<endl;
    }

    void deleteAtIndex()
    {
        int ind;
        cout<<"Enter the Index to Delete at"<<endl;
        cin>>ind;
        for(int i=ind;i<capacity;i++)
        {
            str[i]=str[i+1];
        }
        len-=1;
        cout<<"Deleted Character at Index "<<ind<<endl;
    }

    void updateAtPosition()
    {
        int pos;
        char c;
        cout<<"Enter the Position to Update at"<<endl;
        cin>>pos;
        cout<<"Enter the Character"<<endl;
        cin>>c;
        str[pos-1]=c;
        cout<<"Position "<<pos<<" Updated with Element "<<c<<endl; 
    }

    void updateAtIndex()
    {
        int ind;
        char c;
        cout<<"Enter the Index to Update at"<<endl;
        cin>>ind;
        cout<<"Enter the Character"<<endl;
        cin>>c;
        str[ind]=c;
        cout<<"Index "<<ind<<" Updated with Element "<<c<<endl;
    }

    void updateWithSubString()
    {
        int start,end;
        char c;
        cout<<"Enter the Start Index"<<endl;
        cin>>start;
        cout<<"Enter the End Index"<<endl;
        cin>>end;
        for(int i=start;i<end;i++)
        {
            cout<<"Enter the Character "<<endl;
            cin>>c;
            str[i]=c;
        }
        cout<<"String Updated"<<endl;
    }

    ~String()
    {
        cout<<"String Destroyed by Destructor"<<endl;
    }
};

int main()
{
    string str;
    cout<<"DSA - String Core Implementation"<<endl;
    String s;
    int op;
    do
    {
        cout<<endl;
        cout<<"Choose an Option"<<endl;
        cout<<"1.Initialize String"<<endl;
        cout<<"2.String MetaData"<<endl;
        cout<<"3.Display String"<<endl;
        cout<<"4.String Length"<<endl;
        cout<<"5.Concatenate"<<endl;
        cout<<"6.SubString"<<endl;
        cout<<"7.Character At Index"<<endl;
        cout<<"8.Compare String"<<endl;
        cout<<"9.Reverse String"<<endl;
        cout<<"10.Palindrome"<<endl;
        cout<<"11.Search String for Char"<<endl;
        cout<<"12.Insert Character at Position"<<endl;
        cout<<"13.Delete Character at Position"<<endl;
        cout<<"14.Insert Character at Index"<<endl;
        cout<<"15.Delete Character at Index"<<endl;
        cout<<"16.Update Character at Position"<<endl;
        cout<<"17.Update Character at Index"<<endl;
        cout<<"18.Update with a Sub-String"<<endl;
        cout<<"19.Exit"<<endl;
        cout<<endl;
        cin>>op;
        switch (op)
        {
        case 1:s.initializeString();
            break;

        case 2:s.stringMetaData();
            break;

        case 3:s.displayString();
            break;

        case 4:s.stringLength();
            break;

        case 5:s.concatenateString();
            break;

        case 6:s.subString();
            break;

        case 7:s.characterAtIndex();
            break;

        case 8:s.compareString();
            break;

        case 9:s.reverseString();
            break;

        case 10:s.palindrome();
            break;

        case 11:s.searchStringForChar();
            break;

        case 12:s.insertAtPosition();
            break;

        case 13:s.deleteAtPosition();
            break;

        case 14:s.insertAtIndex();
            break;

        case 15:s.deleteAtIndex();
            break;

        case 16:s.updateAtPosition();
            break;

        case 17:s.updateAtIndex();
            break;

        case 18:s.updateWithSubString();
            break;

        case 19:
            break;
        
        default:cout<<"Invalid Option"<<endl;
            break;
        }
    } while (op!=19);
}