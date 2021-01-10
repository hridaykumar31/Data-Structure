#include<bits/stdc++.h>
using namespace std;
int adj[100][100];
class node
{
    private:
    int data;
    node *next;
    node *front=NULL;
    node *rear=NULL;
    bool *visited;
    public:
    void input(int n1,int n2);
    void bfs(int s,int n);
    void enqueue(int x);
    int dequeue();
    int isempty();
   /* node()
    {
      front=NULL;
      rear=NULL;
    }
    */
};
void node::enqueue(int x)
{
    node *temp;
    temp=new node();
    if(temp==NULL)
    {
        cout<<"Queue is full!"<<endl;
    }
    else
    {
        temp->data=x;
        temp->next=NULL;
        if(front==NULL)
        {
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }

}
int node::dequeue()
{
 int x=-1;
 if(front==NULL)
 {
     cout<<"Queue is empty!!!!:"<<endl;
 }
 else
 {
     node *temp;
     temp=new node();
     temp=front;
     x=front->data;
     front=front->next;
     free(temp);
 }
 return x;
}
void node::input(int n1,int n2)
{
 adj[n1][n2]=1;
}
int node::isempty()
{
    return front==NULL;
}
void node::bfs(int s,int n)
{
  visited=new bool[n];
  for(int i=0;i<n;i++)
  {
      visited[i]=false;
  }
  cout<<s<<" ";
  enqueue(s);
  visited[s]=true;
  while(!isempty())
  {
      int i=dequeue();
      for(int j=0;j<n;j++)
      {
          if(adj[i][j]==1&&visited[j]==false)
          {
              cout<<j<<" ";
             enqueue(j);
             visited[j]=true;
          }
      }
  }


}

int main()
{
    node ob;
    int n,e;
    cout<<"enter the number of node:"<<endl;
    cin>>n;
    cout<<"enter the number of edge:"<<endl;
    cin>>e;
    for(int i=1;i<=e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        ob.input(n1,n2);
    }
    ob.bfs(1,n);



 return 0;
}
