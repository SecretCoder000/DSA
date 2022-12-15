//2
/*#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
void swap(int* xp, int* yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n - 1; i++)


for (j = 0; j < n - i - 1; j++)
if (arr[j] > arr[j + 1])
swap(&arr[j], &arr[j + 1]);
}
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main()
{

cout<<"Himanshu Seth"<<endl;
cout<<"21MCA009"<<endl;
int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
int n = sizeof(arr) / sizeof(arr[0]);
bubbleSort(arr, n);
printf("Sorted array: \n");
printArray(arr, n);
return 0;
}*/


//3
/*#include <bits/stdc++.h>
	using namespace std;
void insertionSort(int arr[], int n)
	{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
	key = arr[i];
	j = i - 1;

	// Move elements of arr[0..i-1],
	// that are greater than key, to one
	// position ahead of their
	// current position
	while (j >= 0 && arr[j] > key)
	{
	arr[j + 1] = arr[j];
	j = j - 1;
	}
	arr[j + 1] = key;
	}
	}

	void printArray(int arr[], int n)
	{
	int i;
	for (i = 0; i < n; i++)
	cout << arr[i] << " ";
	cout << endl;
	}

	// Driver code
	int main()
	{
	cout<<"Himanhu Seth"<<endl;
	cout<<"21MCA009"<<endl;
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);


	return 0;
	}

*/

//4
/*#include <iostream>
using namespace std;
void merge(int array[], int const left, int const mid,
int const right)
{
auto const subArrayOne = mid - left + 1;
auto const subArrayTwo = right - mid;
auto *leftArray = new int[subArrayOne],
*rightArray = new int[subArrayTwo];
for (auto i = 0; i < subArrayOne; i++)
leftArray[i] = array[left + i];
for (auto j = 0; j < subArrayTwo; j++)
rightArray[j] = array[mid + 1 + j];
auto indexOfSubArrayOne
= 0,
indexOfSubArrayTwo
= 0;
int indexOfMergedArray
= left;
while (indexOfSubArrayOne < subArrayOne
&& indexOfSubArrayTwo < subArrayTwo) {
if (leftArray[indexOfSubArrayOne]
<= rightArray[indexOfSubArrayTwo]) {
array[indexOfMergedArray]
= leftArray[indexOfSubArrayOne];
indexOfSubArrayOne++;
}
else {
array[indexOfMergedArray]
= rightArray[indexOfSubArrayTwo];
indexOfSubArrayTwo++;
}
indexOfMergedArray++;
}
// Copy the remaining elements of
// left[], if there are any
while (indexOfSubArrayOne < subArrayOne) {
array[indexOfMergedArray]
= leftArray[indexOfSubArrayOne];
indexOfSubArrayOne++;
indexOfMergedArray++;
}
// Copy the remaining elements of
// right[], if there are any
while (indexOfSubArrayTwo < subArrayTwo) {
array[indexOfMergedArray]
= rightArray[indexOfSubArrayTwo];
indexOfSubArrayTwo++;
indexOfMergedArray++;
}
delete[] leftArray;
delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
if (begin >= end)
return; // Returns recursively

auto mid = begin + (end - begin) / 2;
mergeSort(array, begin, mid);
mergeSort(array, mid + 1, end);
merge(array, begin, mid, end);
}
// Function to print an array
void printArray(int A[], int size)
{
for (auto i = 0; i < size; i++)
cout << A[i] << " ";
}
// Driver code
int main()
{	cout<<"Himanshu Seth"<<endl;
cout<<"21MCA009"<<endl;
int arr[] = { 12, 11, 13, 5, 6, 7 };
auto arr_size = sizeof(arr) / sizeof(arr[0]);

cout << "Given array is \n";
printArray(arr, arr_size);

mergeSort(arr, 0, arr_size - 1);

cout << "\nSorted array is \n";
printArray(arr, arr_size);
return 0;
}
*/

//5
/*#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
int i, w;
vector<vector<int>> K(n + 1, vector<int>(W + 1));

// Build table K[][] in bottom up manner
for(i = 0; i <= n; i++)
{
for(w = 0; w <= W; w++)
{
if (i == 0 || w == 0)
K[i][w] = 0;
else if (wt[i - 1] <= w)
K[i][w] = max(val[i - 1] +
K[i - 1][w - wt[i - 1]],
K[i - 1][w]);
else
K[i][w] = K[i - 1][w];
}
}
return K[n][W];
}

// Driver Code
int main()
{
cout<<"Himanshu Seth"<<endl;
cout<<"21KMCA024"<<endl;
int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int W = 50;
int n = sizeof(val) / sizeof(val[0]);
cout<<"output is \n";
cout << knapSack(W, wt, val, n);
return 0;
}
*/
//6
/*#include<bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V 9
int minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;

return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < V; i++)
printf("%d \t\t\t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src)
{
int dist[V];

bool sptSet[V];
for (int i = 0; i < V; i++)
dist[i] = INT_MAX, sptSet[i] = false;

// Distance of source vertex from itself is always 0
dist[src] = 0;
for (int count = 0; count < V - 1; count++) {

int u = minDistance(dist, sptSet);

// Mark the picked vertex as processed
sptSet[u] = true;
for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v]
&& dist[u] != INT_MAX
&& dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}// print the constructed distance array
printSolution(dist);
}
// driver's code
int main()
{
/* Let us create the example graph discussed above
cout<<"21MCA009"<<endl;
cout<<"Himanshu Seth\n";
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

// Function call
dijkstra(graph, 0);

return 0;
}*/

//7
/*#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left, *right;
    };
Node* newNode(int data)
{
Node* temp = new Node;
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
void printpostorder(struct Node* node)
{
if (node == NULL)
return;
cout << node->data << " "; printpostorder(node->left);
printpostorder(node->right);
}


int main()
{
cout<<"Himanshu Seth\n";
cout<<"21MCA009\n";
struct Node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
// Function call
cout << "\nPostorder traversal of binary tree is \n";
    printpostorder(root);
return 0;}*/

//8
/*#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
while (l <= r) {
int m = l + (r - l) / 2;
if (arr[m] == x)
return m;
if (arr[m] < x)
l = m + 1;
else
r = m - 1;
}
return -1;
}

int main(void)
{
cout<<"Himanshu Seth\n";
cout<<"21MCA009\n";
int arr[] = { 2, 3, 4, 10, 40 };
cout<<"element is 10 to be found in a array of 2,3,4,10,40\n";

int x = 10;
int n = sizeof(arr) / sizeof(arr[0]);
int result = binarySearch(arr, 0, n - 1, x);
(result == -1)
? cout << "Element is not present in array"
: cout << "Element is present at index " << result;
return 0;}*/
//9
/*#include <iostream>
using namespace std;
int search(int arr[], int N, int x)
{
int i;
for (i = 0; i < N; i++)
if (arr[i] == x)
return i;
return -1;
}
int main(void)
{
cout<<"Himanshu Seth\n 21MCA009\n";
int arr[] = { 2, 3, 4, 10, 40 };
int x = 10;
cout<<"array is 2,3,4,10,40 and 10 is to found using linear search\n";
int N = sizeof(arr) / sizeof(arr[0]);
int result = search(arr, N, x);
(result == -1)
? cout << "Element is not present in array"
: cout << "Element is present at index " << result;
return 0;
}
*/
// C++ program to find all the reachable nodes
// for every node present in arr[0..n-1].
/*#include <bits/stdc++.h>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
public:
int V; // No. of vertices

// Pointer to an array containing adjacency lists
list<int> *adj;

Graph(int ); // Constructor

void addEdge(int, int);

vector<int> BFS(int, int, int []);
};

Graph::Graph(int V)
{
this->V = V;
adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v)
{
adj[u].push_back(v); // Add w to v’s list.
adj[v].push_back(u); // Add v to w’s list.
}

vector<int> Graph::BFS(int componentNum, int src,

int visited[])
{
// Mark all the vertices as not visited
// Create a queue for BFS
queue<int> queue;

queue.push(src);

// Assign Component Number
visited[src] = componentNum;

// Vector to store all the reachable nodes from 'src'
vector<int> reachableNodes;



while(!queue.empty())
{
// Dequeue a vertex from queue
int u = queue.front();
queue.pop();

reachableNodes.push_back(u);

// Get all adjacent vertices of the dequeued
// vertex u. If a adjacent has not been visited,
// then mark it visited and enqueue it
for (auto itr = adj[u].begin();
itr != adj[u].end(); itr++)
{
if (!visited[*itr])
{
// Assign Component Number to all the
// reachable nodes
visited[*itr] = componentNum;
queue.push(*itr);
}
}
}
return reachableNodes;
}

// Display all the Reachable Nodes from a node 'n'
void displayReachableNodes(int n,
unordered_map <int, vector<int> > m)
{
vector<int> temp = m[n];
for (int i=0; i<temp.size(); i++)
cout << temp[i] << " ";

cout << endl;
}

// Find all the reachable nodes for every element
// in the arr
void findReachableNodes(Graph g, int arr[], int n)
{
// Get the number of nodes in the graph
int V = g.V;

// Take a integer visited array and initialize
// all the elements with 0
int visited[V+1];
memset(visited, 0, sizeof(visited));

// Map to store list of reachable Nodes for a
// given node.
unordered_map <int, vector<int> > m;

// Initialize component Number with 0
int componentNum = 0;

// For each node in arr[] find reachable
// Nodes
for (int i = 0 ; i < n ; i++)
{
int u = arr[i];

// Visit all the nodes of the component
if (!visited[u])
{
componentNum++;

// Store the reachable Nodes corresponding to
// the node 'i'
m[visited[u]] = g.BFS(componentNum, u, visited);
}

// At this point, we have all reachable nodes
// from u, print them by doing a look up in map m.
cout << "Reachable Nodes from " << u <<" are\n";
displayReachableNodes(visited[u], m);
}
}

// Driver program to test above functions
int main()
{
// Create a graph given in the above diagram
int V = 7;
Graph g(V);
g.addEdge(1, 2);
g.addEdge(2, 3);
g.addEdge(3, 4);
g.addEdge(3, 1);
g.addEdge(5, 6);
g.addEdge(5, 7);

// For every ith element in the arr
// find all reachable nodes from query[i]
int arr[] = {2, 4, 5};

// Find number of elements in Set
int n = sizeof(arr)/sizeof(int);

findReachableNodes(g, arr, n);

return 0;
}
*/
//8
/*#include <bits/stdc++.h>
using namespace std;
#define V 5
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];

// Key values used to pick minimum weight edge in cut
    int key[V];

// To represent set of vertices included in MST
    bool mstSet[V];

// Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

// The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }printMST(parent, graph);
}int main()
{
    cout<<"Himanshu Seth\n21MCA009\n";





    cout<<"Himanshu Seth\n21MCA009\n"; int graph[V][V] = { { 0, 2, 0, 6, 0 },
                                                           { 2, 0, 3, 8, 5 },
                                                           { 0, 3, 0, 0, 7 },
                                                           { 6, 8, 0, 0, 9 },
                                                           { 0, 5, 7, 9, 0 } };

// Print the solution primMST(graph);

    return 0;
}*/
