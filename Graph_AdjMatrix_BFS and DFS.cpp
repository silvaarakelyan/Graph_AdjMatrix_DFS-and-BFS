#include<iostream>
#include<list>
using namespace std;

////////////////////QUEUE////////////////////////
struct node {
    int info;
    node *next;
};
 
class Queue {
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();
 
};
 
void Queue::display(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}
 
Queue::Queue() {
    front = NULL;
    rear = NULL;
}
 
Queue::~Queue() {
    delete front;
}
 
void Queue::enqueue(int data) {
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}
 
int Queue::dequeue() {
    node *temp = new node();
    int value;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}
 
bool Queue::isEmpty() {
    return (front == NULL);
}
 
/////////////////////////Graph///////////////////////////////
class Graph{
private:
	int **AdjMatrix;
	int   vertex;
	void DFS_Helper(int i, bool *visited);
public:
   	 Graph(int size=2);
	~Graph();
	void addEdge(int x, int y);
	bool isConnected(int x,int y);
	void BFS(int s);
	void DFS(int s);
};

//constructor
Graph::Graph(int size){
	int i,j;
	
	if (size < 2){
		vertex = 2;
	}
    else vertex = size;
	AdjMatrix= new int*[vertex];
	//creating 2D array
	for (i = 0; i < vertex; ++i)
	{
		AdjMatrix[i] = new int[vertex];
	}
	//initially setting no edge
    for (i = 0; i < vertex; ++i){
        for (j = 0; j < vertex; ++j){
			AdjMatrix[i][j] = 0;
		}
	}
} 

//destructor
Graph::~Graph() {
    for (int i = 0; i < vertex; ++i){
    delete [] AdjMatrix[i];
	delete [] AdjMatrix;
	}
} 


bool Graph::isConnected(int x, int y) {
    return (AdjMatrix[x-1][y-1] == 1);
} 

//adding adge
void Graph::addEdge(int x, int y) {
	AdjMatrix[x-1][y-1] = AdjMatrix[y-1][x-1] = 1;
} 


void Graph:: DFS(int s){
	bool *visited=new bool[vertex+1];
	for(int i=0; i<vertex; i++){
		visited[i]=false;
	}
 
	cout<<"Traversal by DFS"<<endl;
	  
		DFS_Helper(s, visited);
}


void Graph:: DFS_Helper(int i, bool *visited){
	visited[i]=true;
	cout<<i<<endl;
	for(int j=0; j<vertex; j++){
		if((!visited[j])&& AdjMatrix[i][j]==1){
		    
			DFS_Helper(j, visited);
		}
	}
}


void Graph::BFS(int s){
	bool *explored=new  bool[vertex];

	for(int i=0; i<vertex; i++){
		explored[i]=false;
	}

	Queue queue;
	explored[s]=true;
	queue.enqueue(s);
	cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
	

	while(!queue.isEmpty()){
			int top;
			top= queue.dequeue();
			//show explored vertex
			cout<<top <<" ";

			for(int j=0; j<vertex; j++) {
				if((AdjMatrix[top][j]==1)&&(! explored[j])){
					explored[j]=true;
					queue.enqueue(j);
				}
			}
	}
	
	delete [] explored;
}


int main(){
	Graph g(12);
	g.addEdge(1, 2); g.addEdge(1, 3);
    g.addEdge(2, 4); g.addEdge(3, 4);
    g.addEdge(3, 6); g.addEdge(4 ,7);
    g.addEdge(5, 6); g.addEdge(5, 7);

	g.DFS(1);
	g.BFS(1);
	system("pause");
}
