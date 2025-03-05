#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>

using namespace std;

typedef pair<int, string> Pair;

void addEdge(unordered_map<string, vector<Pair>>& graph, const string& from, const string& to, int cost)
{
    graph[from].push_back({cost, to});
    graph[to].push_back({cost, from}); // Assuming bidirectional travel
}

int dijkstra(unordered_map<string, vector<Pair>>& graph, const string& start, const string& end)
{
    // Min-heap priority queue: (current_cost, current_node)
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    unordered_map<string, int> minCost;

    // Initialize all nodes with infinite cost
    for (const auto& node : graph)
    {
        minCost[node.first] = INT_MAX;
    }

    pq.push({0, start});
    minCost[start] = 0;

    while (!pq.empty())
    {
        auto [currentCost, currentNode] = pq.top();
        pq.pop();

        // If we reach the target node, return the cost
        if (currentNode == end)
        {
            return currentCost;
        }

        // Process neighbors
        for (const auto& neighbor : graph[currentNode])
        {
            int edgeCost = neighbor.first;
            string neighborNode = neighbor.second;

            int newCost = currentCost + edgeCost;
            if (newCost < minCost[neighborNode])
            {
                minCost[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }

    // If we cannot reach the target node
    return -1;
}

int main()
{
    unordered_map<string, vector<Pair>> graph;

    // Adding edges
    addEdge(graph, "Danmark", "India", 2);
    addEdge(graph, "Danmark", "America", 30);
    addEdge(graph, "India", "Japan", 2);
    addEdge(graph, "India", "Korea", 6);
    addEdge(graph, "Japan", "Korea", 3);
    addEdge(graph, "Japan", "Taiwan", 15);
    addEdge(graph, "Korea", "Singapore", 10);
    addEdge(graph, "Singapore", "Taiwan", 1);
    addEdge(graph, "Taiwan", "Russia", 6);
    addEdge(graph, "Taiwan", "America", 12);
    addEdge(graph, "Russia", "America", 5);

    string start = "Danmark";
    string end = "America";

    int result = dijkstra(graph, start, end);

    if (result != -1)
    {
        cout << "The minimum cost time from " << start << " to " << end << " is: " << result << " hours." << endl;
    }
    else
    {
        cout << "There is no path from " << start << " to " << end << "." << endl;
    }

    return 0;
}
