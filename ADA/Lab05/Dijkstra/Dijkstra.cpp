#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <utility>

const int INF = std::numeric_limits<int>::max();

class Graph {
private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjacencyList.resize(vertices);
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight});
    }

    int getNumVertices() const {
        return numVertices;
    }

    const std::vector<std::pair<int, int>>& getNeighbors(int vertex) const {
        return adjacencyList[vertex];
    }

    void printGraph() const {
        std::cout << "\nGrafo creado:\n";
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vértice " << i << ": ";
            for (const auto& edge : adjacencyList[i]) {
                std::cout << "(" << edge.first << ", peso: " << edge.second << ") ";
            }
            std::cout << "\n";
        }
    }
};

class Dijkstra {
private:
    const Graph& graph;
    std::vector<int> distances;
    std::vector<int> previous;
    std::vector<bool> visited;

    int findMinDistance() {
        int minDistance = INF;
        int minIndex = -1;

        for (int i = 0; i < graph.getNumVertices(); i++) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void printPath(int startVertex, int endVertex) const {
        if (distances[endVertex] == INF) {
            std::cout << "No hay camino";
            return;
        }

        std::stack<int> path;
        int current = endVertex;

        while (current != -1) {
            path.push(current);
            current = previous[current];
        }

        while (!path.empty()) {
            std::cout << path.top();
            path.pop();
            if (!path.empty()) {
                std::cout << " -> ";
            }
        }
    }

public:
    Dijkstra(const Graph& g) : graph(g) {
        int numVertices = graph.getNumVertices();
        distances.resize(numVertices, INF);
        previous.resize(numVertices, -1);
        visited.resize(numVertices, false);
    }

    void calculateShortestPaths(int startVertex) {
        distances[startVertex] = 0;

        for (int count = 0; count < graph.getNumVertices(); count++) {
            int currentVertex = findMinDistance();

            if (currentVertex == -1) break;

            visited[currentVertex] = true;

            const auto& neighbors = graph.getNeighbors(currentVertex);
            for (const auto& edge : neighbors) {
                int neighborVertex = edge.first;
                int edgeWeight = edge.second;

                if (!visited[neighborVertex]) {
                    int newDistance = distances[currentVertex] + edgeWeight;
                    if (newDistance < distances[neighborVertex]) {
                        distances[neighborVertex] = newDistance;
                        previous[neighborVertex] = currentVertex;
                    }
                }
            }
        }
    }

    void printResults(int startVertex) const {
        std::cout << "\n=== Caminos más cortos desde el vértice " << startVertex << " ===\n\n";

        for (int i = 0; i < graph.getNumVertices(); i++) {
            std::cout << "Vértice " << i << ": ";
            
            if (distances[i] == INF) {
                std::cout << "No alcanzable\n";
            } else {
                std::cout << "Distancia = " << distances[i] << ", Camino: ";
                printPath(startVertex, i);
                std::cout << "\n";
            }
        }
    }
};

int main() {
    srand(time(0));

    const int numVertices = 8;
    const int numEdges = 15;

    Graph graph(numVertices);

    std::cout << "Generando grafo con " << numVertices << " vértices y " << numEdges << " aristas...\n";

    int edgesAdded = 0;
    while (edgesAdded < numEdges) {
        int source = rand() % numVertices;
        int destination = rand() % numVertices;
        
        if (source != destination) {
            int weight = rand() % 10 + 1;
            graph.addEdge(source, destination, weight);
            edgesAdded++;
        }
    }

    graph.printGraph();

    int startVertex;
    std::cout << "\nIngrese el vértice de inicio (0-" << numVertices - 1 << "): ";
    std::cin >> startVertex;

    if (startVertex < 0 || startVertex >= numVertices) {
        std::cout << "Vértice inválido!\n";
        return 1;
    }

    Dijkstra dijkstra(graph);
    dijkstra.calculateShortestPaths(startVertex);
    dijkstra.printResults(startVertex);

    return 0;
}
