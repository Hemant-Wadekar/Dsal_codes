#include <iostream>
using namespace std;

int cost[10][10] = {0}, qu[10], front = 0, rear = 0;
int  visited[10] = {0},  visited1[10] = {0};
int n, m; 


void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

   
    for (int k = 0; k < m; k++) {
        int i, j;
        cout << "\nEnter the connecting edges (format:v1 v2):";
        cin >> i >> j;
        
        cost[i][j] = 1;
        cost[j][i] = 1; 
    }
}
void displayAdjMatrix() {
    cout << "The adjacency matrix of the graph is:\n";
    cout<<"     ";
    for(int i=1;i<n+1;i++)
    {
        cout<< i <<"    ";
    }
    cout<<"\n";
    for (int i = 1; i < n+1; i++) {
        cout<< i <<" | ";
        for (int j = 1; j < n+1; j++) {
            cout << " " << cost[i][j] << " | ";
        }
        cout << endl;
    }
}

void bfs() {
    int v;
    cout << "Enter initial vertex for BFS: ";
    cin >> v;

    if (v < 0 || v > n) { 
        cout << "Invalid vertex!\n";
        return;
    }

    cout << "The BFS of the Graph is: ";
    visited[v] = 1;
    qu[rear++] = v;

    while (front < rear) {
        int current = qu[front++];
        cout << current << " ";

        for (int j = 1; j < n+1; j++) {
            if (cost[current][j] != 0 && !visited[j]) {
                visited[j] = 1;
                qu[rear++] = j; 
            }
        }
    }
    cout << endl;
}


void dfs(int v) {
    cout << v << " ";
    visited1[v] = 1;

    for (int j = 1; j < n+1; j++) { 
        if (cost[v][j] != 0 && !visited1[j]) {
            dfs(j);
        }
    }
}

void DFS() {
    int v;
    cout << "Enter initial vertex for DFS: ";
    cin >> v;

    if (v < 0 || v >= n) {
        cout << "Invalid vertex!\n";
        return;
    }
    cout << "The DFS of the Graph is: ";
    dfs(v);
    cout << endl;
}


int main() {
    int ch;
    do{
    cout << "\n******** DSAL Practical No. 06 (C-13) ******" << endl;
    cout << "\n**************** MENU **************" << endl;
    cout << "1. Create Graph\n2. Display Adjacency Matrix\n3. BFS\n4. DFS\n5. Exit\n";
    cout << "Enter Your Choice: ";
    cin >> ch;

        switch (ch) {
            case 1:
                createGraph();
                break;
            case 2:
                displayAdjMatrix();
                break;
            case 3:
                bfs();
                break;
            case 4:
                DFS();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }while(ch!=5);
    return 0;
}
