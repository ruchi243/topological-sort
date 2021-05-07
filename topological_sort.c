#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int n;    
int adj[MAX][MAX]; 
void create_graph();
int queue[MAX], front = -1,rear = -1;
void insert(int a);
int delete();
int isEmpty();
int indegree(int a);
int main()
{
        int i,j,count,topological_order[MAX],indeg[MAX];

        create_graph();

   
        for(i=0;i<n;i++)
        {
                indeg[i] = indegree(i);
                if( indeg[i] == 0 )
                        insert(i);
        }

        count = 0;

        while(  !isEmpty( ) && count < n )
        {
                j = delete();
        topological_order[++count] = j; 
                for(i=0; i<n; i++)
                {
                        if(adj[j][i] == 1)
                        {
                                adj[j][i] = 0;
                                indeg[i] = indeg[i]-1;
                                if(indeg[i] == 0)
                                        insert(i);
                        }
                }
        }

        if( count < n )
        {
                printf("\nTopological ordering is not possible, graph contains cycle\n");
                exit(1);
        }
        for(i=1; i<=count; i++)
                printf( "%d-->",topological_order[i]+1);
        printf("\n");

        return 0;
}

void insert(int vertex)
{
        if (rear == MAX-1)
                printf("\nQueue Overflow\n");
        else
        {
                if (front == -1)  
                        front = 0;
                rear = rear+1;
                queue[rear] = vertex ;
        }
}

int isEmpty()
{
        if(front == -1 || front > rear )
                return 1;
        else
                return 0;
}
int delete()
{
        int delete_item;
        if (front == -1 || front > rear)
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        else
        {
                delete_item = queue[front];
                front = front+1;
                return delete_item;
        }
}

int indegree(int v)
{
        int i,in_deg = 0;
        for(i=0; i<n; i++)
                if(adj[i][v] == 1)
                        in_deg++;
        return in_deg;
}

void create_graph()
{
        int i,max_edges,u,v;

        printf("\nEnter number of vertices : ");
        scanf("%d",&n);
        max_edges = n*(n-1);
        printf("\nEnter the number of edges: ");
        int edges;
        scanf("%d",&edges);
        printf("\nEnter the edges (u,v): ");
        

        for(i=1; i<=edges; i++)
        {
 
                scanf("%d %d",&u,&v);

                if((u == -1) && (v == -1))
                        break;

                if( u >= n || v >= n || u<0 || v<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                        adj[u][v] = 1;
        }
}

