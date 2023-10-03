// DSA - Graph Core Implementation

#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph
{
    public:
    int direction;
    unordered_map<int,list<int> > g;

    void createGraph()
    {
        int nodes,edges;
        cout<<"Enter the Number of Nodes in Graph: "<<endl;
        cin>>nodes;
        cout<<"Enter the Number of Edges in Graph: "<<endl;
        cin>>edges;
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cout<<"Enter the values of Linked Node (u & v) : "<<endl;
            cin>>u>>v;
            g[u].push_back(v);
            if(direction==0)
            {
                g[v].push_back(u);
            }
        }
        if(direction==0)
        {
            cout<<"Undirected Graph Created"<<endl;
        }
    }

    void addNode(int node)
    {
        if(g.find(node)==g.end())
        {
            g[node]=list<int>();
        }
    }

    void removeNode(int node)
    {
        if(g.find(node)!=g.end())
        {
            g.erase(node);
            for(auto i:g)
            {
                i.second.remove(node);
            }
        }
    }

    void addEdge(int node1,int node2)
    {
        if(g.find(node1)!=g.end() && g.find(node2)!=g.end())
        {
            g[node1].push_back(node2);
            g[node2].push_back(node1);
        }
        cout<<"Edge Between "<<node1<<" & "<<node2<<" Added"<<endl;
    }

    void removeEdge(int node1,int node2)
    {
        if(g.find(node1)!=g.end() && g.find(node2)!=g.end())
        {
            g[node1].remove(node2);
            g[node2].remove(node1);
        }
        cout<<"Edge Between "<<node1<<" & "<<node2<<" Removed"<<endl;
    }

    void searchNode(int node)
    {
        if(g.find(node)!=g.end())
        {
            cout<<"Node "<<node<<" Found in Graph"<<endl;
        }
        else 
        {
            cout<<"Node "<<node<<" Not Found in Graph"<<endl;
        }
    }

    void graphAdjList()
    {
        for(auto& i:g)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

    int getNode()
    {
        int node;
        cout<<"Enter the Node "<<endl;
        cin>>node;
        return node;
    }

    ~Graph()
    {
        cout<<"Graph Destroyed by Destructor"<<endl;
    }
};

int main()
{
    Graph graph;
    cout<<"DSA - Graph Core Implementation"<<endl;
    cout<<"Define the Type of the Graph : 0 -> Undirected | 1 -> Directed "<<endl;
    cin>>graph.direction;
    graph.createGraph();
    int op;
    do
    {
        int node;
        int node1;
        int node2;
        cout<<endl;
        cout<<"Choose from the Following Options"<<endl;
        cout<<"1.Add Node"<<endl;
        cout<<"2.Remove Node"<<endl;
        cout<<"3.Add Edge"<<endl;
        cout<<"4.Remove Edge"<<endl;
        cout<<"5.Search Node in Graph"<<endl;
        cout<<"6.Graph Adjacency List"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<endl;
        cin>>op;
        cout<<endl;
        switch (op)
        {
        case 1:
            node=graph.getNode();
            graph.addNode(node);
            break;

        case 2:
            node=graph.getNode();
            graph.removeNode(node);
            break;

        case 3:
            node1=graph.getNode();
            node2=graph.getNode();
            graph.addEdge(node1,node2);
            break;

        case 4:
            node1=graph.getNode();
            node2=graph.getNode();
            graph.removeEdge(node1,node2);
            break;

        case 5:
            node=graph.getNode();
            graph.searchNode(node);
            break;

        case 6:graph.graphAdjList();
            break;

        case 7:
            break;
        
        default:cout<<"Invalid Option"<<endl;
            break;
        }
    } while (op!=7);
}