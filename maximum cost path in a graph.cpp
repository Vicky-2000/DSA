// Link to the problem : https://www.techiedelight.com/maximum-cost-path-graph-source-destination/

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest, weight;
};
 
// A class to represent a graph object
class Graph
{
    public:
    // a vector of vectors of `Edge` to represent an adjacency list
    vector<vector<Edge>> adjList;
 
    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type vector<Edge>
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
 
            adjList[src].push_back({src, dest, weight});
            adjList[dest].push_back({dest, src, weight});
        }
    }
};
 
// A BFS Node
struct Node
{
    // current vertex number and cost of the current path
    int vertex, weight;
 
    // set of nodes visited so far in the current path
    set<int> s;
};
 
// Perform BFS on graph `g` starting from vertex `v`
int modifiedBFS(Graph const &g, int src, int k)
{
    // create a queue for doing BFS
    queue<Node> q;
 
    // add source vertex to set and enqueue it
    set<int> vertices;
    vertices.insert(0);
    q.push({src, 0, vertices});
 
    // stores maximum cost of a path from the source
    int maxCost = INT_MIN;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node node = q.front();
        q.pop();
 
        int v = node.vertex;
        int cost = node.weight;
        vertices = node.s;
 
        // if the destination is reached and BFS depth is equal to `m`,
        // update the minimum cost calculated so far
        if (cost > k) {
            maxCost = max(maxCost, cost);
        }
 
        // do for every adjacent edge of `v`
        for (Edge edge: g.adjList[v])
        {
            // check for a cycle
            if (vertices.find(edge.dest) == vertices.end())
            {
                // add current node to the path
                set<int> s = vertices;
                s.insert(edge.dest);
 
                // push every vertex (discovered or undiscovered) into
                // the queue with a cost equal to the
                // parent's cost plus the current edge's weight
                q.push( {edge.dest, cost + edge.weight, s} );
            }
        }
    }
 
    // return max-cost
    return maxCost;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 6, 11}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7},
        {2, 3, -8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1},
        {6, 5, 2}, {7, 6, 9}, {7, 1, 6}
    };
 
    // total number of nodes in the graph
    int N = 9;
 
    // build a graph from the given edges
    Graph g(edges, N);
 
    int src = 0;
    int cost = 50;
 
    // Start modified BFS traversal from source vertex `src`
    int maxCost = modifiedBFS(g, src, cost);
 
    if (maxCost != INT_MIN) {
        cout << maxCost;
    }
    else {
        cout << "All paths from source have their costs < " << cost;
    }
 
    return 0;
}


