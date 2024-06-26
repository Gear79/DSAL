#include <iostream>
#include <queue>

using namespace std;

void dfs(int s, int n, string arr[], int adj_mat[][50], bool visited[])
{
    visited[s] = true;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr, adj_mat, visited);
    }
}

void bfs(int s, int n, string arr[], int adj_mat[][50])
{
    bool visited[n] = {false};
    queue<int> bfsq;

    cout << arr[s] << " ";
    bfsq.push(s);
    visited[s] = true;

    while (!bfsq.empty())
    {
        int v = bfsq.front();
        bfsq.pop();
        for (int i = 0; i < n; i++)
        {
            if (adj_mat[v][i] && !visited[i])
            {
                cout << arr[i] << " ";
                visited[i] = true;
                bfsq.push(i);
            }
        }
    }
}

int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of cities.";
        return 1;
    }

    string cities[n];
    int adj_mat[50][50] = {0};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }

    // Input distances between cities
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj_mat[i][j];
            if (adj_mat[i][j] < 0)
            {
                cout << "Distance cannot be negative. Please enter a non-negative distance.";
                return 1;
            }
            adj_mat[j][i] = adj_mat[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";

    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }

    cout << "Enter Starting Vertex: ";
    cin >> u;

    if (u < 0 || u >= n)
    {
        cout << "Invalid starting vertex.";
        return 1;
    }

    cout << "DFS: ";
    bool visited_dfs[n] = {false};
    dfs(u, n, cities, adj_mat, visited_dfs);
    cout << endl;

    cout << "BFS: ";
    bfs(u, n, cities, adj_mat);

    return 0;
}
