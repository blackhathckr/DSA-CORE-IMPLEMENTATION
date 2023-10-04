// DSA - Doubly Linked List Core Implementation

#include <iostream>
using namespace std;

class DoublyLinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node *prev, *next;
        Node(int node)
        {
            this->data = node;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node *createHead()
    {
        int node;
        cout << "Enter the Head of the Doubly Linked List" << endl;
        cin >> node;
        Node *head = new Node(node);
        cout << "Head of the Doubly Linked List Created" << endl;
        return head;
    }

    Node *insertAtHead(Node *&head)
    {
        int data;
        cout << "Enter the Node to Insert at Head" << endl;
        cin >> data;
        Node *node = new Node(data);
        if (head != NULL)
        {
            node->next = head;
            head->prev = node;
            head = node;
            cout << "Node " << data << " Inserted at Head" << endl;
        }
        else
        {
            cout << "Head is NULL" << endl;
        }
    }

    Node *insertAtPos(Node *&head)
    {
        Node *temp = head;
        int pos, data;
        cout << "Enter the Position to Insert Node at" << endl;
        cin >> pos;
        cout << "Enter the Node to Insert at Pos " << pos << endl;
        cin >> data;
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->next;
        }
        Node *node = new Node(data);
        node->next = temp->next;
        node->prev = temp;
        temp->next = node;
        cout << "Node " << data << " Inserted at Pos " << pos << endl;
    }

    Node *insertAtTail(Node *&head)
    {
        Node *temp = head;
        int data;
        cout << "Enter the Node to Insert at Tail" << endl;
        cin >> data;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *node = new Node(data);
        temp->next = node;
        node->prev = temp;
        node->next = NULL;
        cout << "Node " << data << " Inserted at Tail" << endl;
    }

    Node *deleteAtHead(Node *&head)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        cout << "Node at Head Deleted" << endl;
    }

    Node *deleteAtPos(Node *&head)
    {
        int pos;
        cout << "Enter the Position to Delete the Node at" << endl;
        cin >> pos;
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        curr->prev = nullptr;
        cout << "Node at Position " << pos << " Deleted" << endl;
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

    void reverseDoublyLinkedList(Node *&head)
    {
        Node *curr = head;
        Node *temp = nullptr;

        while (curr != nullptr)
        {
            // Swap prev and next pointers for the current node
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the next node
            curr = curr->prev; // Note the change here
        }

        // Update the head pointer to the last node (which is now the first)
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    void searchDoublyLinkedList(Node *&head)
    {
        int data, flag = 0;
        cout << "Enter the Node to Search for in the Doubly Linked List" << endl;
        cin >> data;
        Node *temp = head;
        while (temp != NULL)
        {
            if (data == temp->data)
            {
                cout << "Node " << data << " Found in the Doubly Linked List" << endl;
                flag++;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (flag == 0)
        {
            cout << "Node " << data << " Not Found in the Doubly Linked List" << endl;
        }
    }

    void doublyLinkedListElementsCount(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is Empty" << endl;
        }
        else
        {
            int count = 0;
            Node *temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            cout << "Doubly Linked List Elements Count: " << count << endl;
        }
    }

    void doublyLinkedListElements(Node *&head)
    {
        if (head == NULL)
        {
            cout << "Doubly Linked List is Empty" << endl;
        }
        else
        {
            Node *temp = head;
            cout << "Doubly Linked List Elements : " << endl;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    void clearDoublyLinkedList(Node *&head)
    {
        while (head != NULL)
        {
            deleteAtHead(head);
            head = head->next;
        }
        cout << "Doubly Linked List Cleared" << endl;
    }

    ~DoublyLinkedList()
    {
        cout<<"Doubly Linked List Destroyed by Destructor"<<endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    DoublyLinkedList::Node *head = dll.createHead();
    cout << "DSA - Doubly Linked List Core Implementation" << endl;
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
        cout << "7.Reverse Doubly Linked List" << endl;
        cout << "8.Search Doubly Linked List" << endl;
        cout << "9.Doubly Linked List Elements Count" << endl;
        cout << "10.Doubly Linked List Elements" << endl;
        cout << "11.Clear Doubly Linked List" << endl;
        cout << "12.Exit" << endl;
        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            dll.insertAtHead(head);
            break;

        case 2:
            dll.insertAtPos(head);
            break;

        case 3:
            dll.insertAtTail(head);
            break;

        case 4:
            dll.deleteAtHead(head);
            break;

        case 5:
            dll.deleteAtPos(head);
            break;

        case 6:
            dll.deleteAtTail(head);
            break;

        case 7:
            dll.reverseDoublyLinkedList(head);
            break;

        case 8:
            dll.searchDoublyLinkedList(head);
            break;

        case 9:
            dll.doublyLinkedListElementsCount(head);
            break;

        case 10:
            dll.doublyLinkedListElements(head);
            break;

        case 11:
            dll.clearDoublyLinkedList(head);
            break;

        case 12:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (op != 12);
}