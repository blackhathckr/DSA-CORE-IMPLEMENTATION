// DSA - Tree Core Implementation

#include <iostream>
using namespace std;

class Tree
{
public:
    int nodes=0;
    class Node
    {
    public:
        int data;
        Node *left, *right;
        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        ~Node()
        {
            cout << "Node Destroyed by Destructor" << endl;
        }
    };

    Node *createRoot()
    {
        int node;
        cout << "Enter the Root Node of the Tree" << endl;
        cin >> node;
        Node *root = new Node(node);
        nodes++;
        cout<<"Root Node Created" << endl;
        return root;
    }

    Node *insertNode(Node *&root, int node)
    {
        if (root == NULL)
        {
            return new Node(node);
        }
        if (node < root->data)
        {
            root->left = insertNode(root->left, node);
        }
        else if (node >= root->data)
        {
            root->right = insertNode(root->right, node);
        }
        nodes++;
        return root;
    }

    Node *deleteNode(Node *&root, int node)
    {
        if (node < root->data)
        {
            root->left = deleteNode(root->left, node);
        }
        else if (node > root->data)
        {
            root->right = deleteNode(root->right, node);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                nodes--;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                nodes--;
                return temp;
            }
            else
            {
                Node *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    }

    Node *searchNode(Node *&root, int node)
    {
        int flag = 0;
        while (root != NULL)
        {
            if (node == root->data)
            {
                cout << "Node " << node << " Found" << endl;
                flag++;
                break;
            }
            else if (node < root->data)
            {
                return searchNode(root->left, node);
            }
            else if (node > root->data)
            {
                return searchNode(root->right, node);
            }
        }
        if (flag == 0)
        {
            cout << "Node " << node << " Not Found" << endl;
        }
    }

    void leftDeepestNode(Node *&root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "Left Deepest Node " << temp->data << endl;
    }

    void rightDeepestNode(Node *&root)
    {
        Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        cout << "Right Deepest Node " << temp->data << endl;
    }

    void preOrderTraversal(Node *&root)
    {
        if (root != NULL)
        {
            cout << root->data << endl;
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void inOrderTraversal(Node *&root)
    {
        if (root != NULL)
        {
            inOrderTraversal(root->left);
            cout << root->data << endl;
            inOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(Node *&root)
    {
        if (root != NULL)
        {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << endl;
        }
    }

    void treeNodesCount()
    {
        cout<<"Tree Nodes Count :"<<nodes<<endl;
    }

    int getNode()
    {
        int node;
        cout << "Enter the Node " << endl;
        cin >> node;
        return node;
    }
    ~Tree()
    {
        cout << "Tree Destroyed by Destructor" << endl;
    }
};

int main()
{
    Tree t;
    cout << "DSA - Tree Core Implementation" << endl;
    Tree::Node *root = t.createRoot();
    int op;
    do
    {
        int node;
        cout << endl;
        cout << "Choose from the Following Options" << endl;
        cout << "1.Insert Node" << endl;
        cout << "2.Delete Node" << endl;
        cout << "3.Search Node" << endl;
        cout << "4.Left Deepest Node" << endl;
        cout << "5.Right Deepest Node" << endl;
        cout << "6.preOrderTraversal" << endl;
        cout << "7.inOrderTraversal" << endl;
        cout << "8.postOrderTraversal" << endl;
        cout << "9.Tree Nodes Count" << endl;
        cout << "10.Exit" << endl;
        cout << endl;
        cin >> op;
        cout << endl;
        switch (op)
        {

        case 1:
            node = t.getNode();
            t.insertNode(root, node);
            break;

        case 2:
            node = t.getNode();
            t.deleteNode(root, node);
            break;

        case 3:
            node = t.getNode();
            t.searchNode(root, node);
            break;

        case 4:
            t.leftDeepestNode(root);
            break;

        case 5:
            t.rightDeepestNode(root);
            break;

        case 6:
            t.preOrderTraversal(root);
            break;

        case 7:
            t.inOrderTraversal(root);
            break;

        case 8:
            t.postOrderTraversal(root);
            break;

        case 9:
            t.treeNodesCount();
            break;

        case 10:
            break;

        default:cout<<"Invalid Option"<<endl;
            break;
        }
    } while (op != 10);
}