#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
    int nodes;//nodes of the graph
    list<int>* adjLists;//take the edge of a node
    bool* visited;//it is used to check the node visited or not
    int* dist;//is is used for taking the least number of  edge required to travel from root to a node
    int* parent;//it is used for taking the parent root for a node. i use it for printing the shortest path
public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int starting_node);
    bool isvisited(int node);
    int distance(int node);
    int parent_node(int node);
    ~Graph()
    {
        delete []adjLists;
        delete []visited;
        delete []dist;
        delete []parent;
    }
};

Graph::Graph(int vertices)//create a graph with given nodes
{
    nodes= vertices;
    adjLists = new list<int>[nodes];
    visited = new bool[nodes];
    dist=new int[nodes];
    parent=new int[nodes];
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);//add edge in a node
}

// BFS algorithm
void Graph::BFS(int starting_node)
{
    for (int i = 0; i <= nodes; i++)
    {
        visited[i] = false;
        dist[i]=0;
    }
    list<int> q;
    parent[starting_node]=-1;//there is no parent for the root node
    visited[starting_node] = true;//visit the root node
    q.push_back(starting_node);

    list<int>::iterator i;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop_front();

        for (i = adjLists[curr_node].begin(); i != adjLists[curr_node].end(); i++)
        {
            int adj_node = *i;
            if (!visited[adj_node])
            {
                parent[adj_node]=curr_node;
                visited[adj_node] = true;
                dist[adj_node]=1+dist[curr_node];
                q.push_back(adj_node);
            }
        }
    }
}

bool Graph::isvisited(int node)
{
    return visited[node];
}

int Graph::distance(int node)
{
    return dist[node];
}

int Graph::parent_node(int node)
{
    return parent[node];
}

int main()
{
    FILE *wfile; //it is used for writing the output in a file
    FILE *rfile;    //it is used for reading the input from a file
    rfile=fopen("ginput.txt","r"); //open the ginput file for reading the input
    wfile=fopen("goutput.txt","w"); //open the goutput.txt file for writing the output
    int t; //test case
    fscanf(rfile,"%d", &t);
    while(t--)
    {
        int n; //number of faces in the die
        fscanf(rfile,"%d", &n);
        int x; //size of the board
        fscanf(rfile,"%d", &x);
        int l, s;
        vector<pair<int,int> >ladder; //take the starting and ending point of a ladder
        vector<pair<int,int> >snake; //take the starting and ending point of a snake

        fscanf(rfile,"%d", &l);//ladder
        for (int i = 0; i < l; i++)
        {
            int initial, final;
            fscanf(rfile,"%d", &initial);//starting of the ladder
            fscanf(rfile,"%d", &final);//ending of the ladder
            ladder.push_back(make_pair(initial, final));
        }
        fscanf(rfile,"%d", &s);//snake
        for (int i = 0; i < s; i++)
        {
            int initial, final;
            fscanf(rfile,"%d", &initial);//starting of the snake
            fscanf(rfile,"%d", &final); //ending of the snake
            snake.push_back(make_pair(initial, final));
        }
        Graph g(x + 1); //create a graph of x+1 node
        for (int i = 1; i <= x; i++)//here i create the adjacency list for each of the square
        {
            int end = 0;//for checking the square is a starting point of snake or ladder
            for (int j = 0; j < ladder.size(); j++)
            {
                if (i == ladder[j].first)
                {
                    end = 1;
                    break;
                }
            }
            for (int j = 0; j < snake.size(); j++)
            {
                if (i == snake[j].first)
                {
                    end = 1;
                    break;
                }
            }
            if (end == 1)//if the square is a starting point of a ladder or snake then we already take the square
            {
                continue;
            }
            for (int j = 1; j <= n; j++)//the die has n faces
            {
                int tmp = i + j;//move from i to i+j square
                if (tmp <= x && tmp >= 1)//we do not interested in the squares that is larger than x and it is not necessay to check the condition tmp>=1
                {
                    g.addEdge(i, tmp);//we can go from i to tmp
                }
                for (int k = 0; k < ladder.size(); k++)//if the tmp square has a ladder then i will climb
                {
                    if (tmp == ladder[k].first && ladder[k].second <= x && ladder[k].second >= 1)
                    {
                        g.addEdge(i, ladder[k].second);
                        tmp = ladder[k].second;
                        k = 0;//if the ending point of a ladder has a starting point of another ladder.
                    }
                }
                tmp = i + j;
                for (int k = 0; k < snake.size(); k++)
                {
                    if (tmp == snake[k].first && snake[k].second >= 1 && snake[k].second <= x)
                    {
                        g.addEdge(i, snake[k].second);
                        tmp = snake[k].second;
                        k = 0;
                    }
                }
            }
        }
        g.BFS(1);// the bfs take the first square
        int move=g.distance(x);
        if(move!=0)//if move equal to zero then we do not visit the x square
        {
            fprintf(wfile,"%d\n",move);//least number of move to reach the square x
            vector<int>ans;//take the shortest path
            int p=x;
            while(g.parent_node(p)!=-1)
            {
                ans.push_back(p);
                for(int i=0; i<ladder.size(); i++)
                {
                    if(ladder[i].second==p)
                    {
                        ans.push_back(ladder[i].first);
                        break;
                    }
                }
                p=g.parent_node(p);
            }
            ans.push_back(p);
            for(int i=ans.size()-1; i>0; i--)
            {
                fprintf(wfile,"%d -> ",ans[i]);
            }
            fprintf(wfile,"%d\n",ans[0]);
            int reach=0;
            for(int i=1; i<=x; i++)
            {
                if(g.isvisited(i)!=true)
                {
                    fprintf(wfile,"%d ",i);
                    reach=1;
                }
            }
            if(reach==0)
            {
                string str="All reachable";
                fprintf(wfile,"%s\n",str.c_str());
            }
            else
            {
                int i;
                fprintf(wfile,"\n",i);
            }
        }
        else
        {
            int i=-1;
            fprintf(wfile,"%d\n",i);
            string str="No solution";
            fprintf(wfile,"%s\n",str.c_str());
            int reach=0;
            for(int i=1; i<=x; i++)
            {
                if(g.isvisited(i)!=true)
                {
                    fprintf(wfile,"%d ",i);
                    reach=1;
                }
            }
            if(reach==0)
            {
                string str="All reachable";
                fprintf(wfile,"%s\n",str.c_str());
            }
        }
    }
    fclose(rfile);//close the file that i open for reading the input
    fclose(wfile);//close the file that i open for writing the input
    return 0;
}
