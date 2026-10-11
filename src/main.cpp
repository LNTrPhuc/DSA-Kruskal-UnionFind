#include "Kruskal.h"
#include <iostream>
using namespace std;

const int MAX_VERTICES = 1000000;
const int MAX_EDGES = 2000000;

bool readGraph(Graph& graph) {
    int edgeCount;
    if (!(cin >> graph.vertexCount >> edgeCount)) {
        cerr << "Invalid vertex or edge count.\n";
        return false;
    }
    if (graph.vertexCount < 0 || graph.vertexCount > MAX_VERTICES ||
        edgeCount < 0 || edgeCount > MAX_EDGES) {
        cerr << "Counts exceed the supported limits.\n";
        return false;
    }
    graph.edges.clear();
    graph.edges.reserve(edgeCount);
    for (int index = 0; index < edgeCount; ++index) {
        Edge edge;
        if (!(cin >> edge.from >> edge.to >> edge.weight)) {
            cerr << "Invalid data for edge " << index + 1 << ".\n";
            return false;
        }
        if (edge.from < 0 || edge.from >= graph.vertexCount ||
            edge.to < 0 || edge.to >= graph.vertexCount) {
            cerr << "Invalid vertex index for edge " << index + 1 << ".\n";
            return false;
        }
        graph.edges.push_back(edge);
    }
    return true;
}

void printResult(const Graph& graph, const MSTResult& result) {
    if (graph.vertexCount == 0) {
        cout << "Empty graph: no spanning tree.\n";
    } else if (!result.hasSpanningTree) {
        cout << "Disconnected graph: no spanning tree.\n";
        cout << "Minimum spanning forest:\n";
    } else {
        cout << "Minimum spanning tree:\n";
    }
    int edgeCount = result.edges.size();
    for (int index = 0; index < edgeCount; ++index) {
        Edge edge = result.edges[index];
        cout << edge.from << " - " << edge.to << " | weight = " << edge.weight << '\n';
    }
    cout << "Selected edges: " << result.edges.size() << '\n';
    cout << "Total weight: " << result.totalWeight << '\n';
    cout << "Components: " << result.componentCount << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Graph graph;
    cout << "Enter V E, followed by E lines: from to weight\n" << flush;
    if (!readGraph(graph)) {
        return 1;
    }
    Kruskal solver;
    MSTResult result = solver.solve(graph, true);
    printResult(graph, result);
    return 0;
}
