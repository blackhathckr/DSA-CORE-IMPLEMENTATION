// DSA - Singly LinkedList Core Implementation

#include <iostream>
using namespace std;

class LinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        ~Node()
        {
            cout<<"Node Destroyed by Destructor"<<endl;
        }
    };

    Node* createHead()
    {
        int node;
        cout<<"Enter the Head of the Linked List"<<endl;
        cin>>node;
        Node* head=new Node(node);
        cout<<"Head of the Linked List Created"<<endl;
        return head;
    }

    Node *insertAtHead(Node *&head)
    {
        int data;
        cout << "Enter the Data for the New Node " << endl;
        cin >> data;
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }

    Node *insertAtPos(Node *&head)
    {
        Node *temp = head;
        int pos, data, count = 1;
        cout << "Enter the Position for the New Node " << endl;
        cin >> pos;
        cout << "Enter the Data for the New Node " << endl;
        cin >> data;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *node = new Node(data);
        node->next = temp->next;
        temp->next = node;
    }

    Node *insertAtTail(Node *&head)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        int data;
        cout << "Enter the Data for the New Node" << endl;
        cin >> data;
        Node *node = new Node(data);
        temp->next = node;
        node->next = NULL;
    }

    Node *deleteAtHead(Node *&head)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
    }

    Node *deleteAtPos(Node *&head)
    {
        Node *temp = head;
        Node *prev = NULL;
        Node *curr = head;
        int pos, count = 1;
        cout << "Enter the Position to Delete the Node at" << endl;
        cin >> pos;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
    }

    Node *deleteAtTail(Node *&head)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void reverseLinkedList(Node *&head)
    {
        Node *curr = head;
        Node *prev=NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout<<"Linked List Reversed"<<endl;
    }

    void searchLinkedList(Node *&head)
    {
        Node* temp=head;
        int node, flag = 0, position = 1;
        cout << "Enter the Node Data to Search for in the Linked List" << endl;
        cin >> node;
        while (temp != NULL)
        {
            if (temp->data == node)
            {
                cout << "Node Data " << node << " Found in Linked List"
                     << " at Position " << position << endl;
                flag++;
                break;
            }
            else
            {
                temp = temp->next;
                position++;
            }
        }
        if (flag == 0)
        {
            cout << "Node Data not Found" << endl;
        }
    }

    void linkedListElementsCount(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            int count = 0;
            Node* temp=head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            cout << "Linked List Node Count : " << count << endl;
        }
    }

    void linkedListElements(Node *&head)
    {
        Node *temp = head;
        cout << "Linked list Elements " << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void clearLinkedList(Node *&head)
    {
        while(head!=NULL)
        {
            Node *temp = head;
            head=head->next;
            temp->next=nullptr;
        }
        cout<<"Linked List Cleared"<<endl;
    }

    ~LinkedList()
    {
        cout << "Singly Linked List Destroyed by Destructor" << endl;
    }
};

int main()
{
    LinkedList ll;
    LinkedList::Node *head = ll.createHead();
    cout << "DSA - Singly Linked List Core Implementation" << endl;
    int op;
    do
    {
        cout << endl;
        cout << "Choose from the Following Options:" << endl;
        cout << "1.Insert at Head" << endl;
        cout << "2.Insert at Position" << endl;
        cout << "3.Insert at Tail" << endl;
        cout << "4.Delete at Head" << endl;
        cout << "5.Delete at Position" << endl;
        cout << "6.Delete at Tail" << endl;
        cout << "7.Reverse Linked List" << endl;
        cout << "8.Search Linked List" << endl;
        cout << "9.Linked List Elements Count" << endl;
        cout << "10.Linked List Elements" << endl;
        cout << "11.Clear Linked List" << endl;
        cout << "12.Exit" << endl;
        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            ll.insertAtHead(head);
            break;

        case 2:
            ll.insertAtPos(head);
            break;

        case 3:
            ll.insertAtTail(head);
            break;

        case 4:
            ll.deleteAtHead(head);
            break;

        case 5:
            ll.deleteAtPos(head);
            break;

        case 6:
            ll.deleteAtTail(head);
            break;

        case 7:
            ll.reverseLinkedList(head);
            break;

        case 8:
            ll.searchLinkedList(head);
            break;

        case 9:
            ll.linkedListElementsCount(head);
            break;

        case 10:
            ll.linkedListElements(head);
            break;

        case 11:ll.clearLinkedList(head);
            break;

        case 12:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (op != 12);
}