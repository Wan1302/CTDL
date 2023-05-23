#include <iostream>
#include <list>
using namespace std;

class Graph {
    int num_vertices;
    list<int>* adj_list;

public:
    Graph(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_list = new list<int>[num_vertices];
    }

    void add_edge(int source, int destination) {
        adj_list[source].push_back(destination);
        adj_list[destination].push_back(source);
    }

    void print_graph() {
        for (int vertex = 0; vertex < num_vertices; vertex++) {
            cout << "Adjacency list of vertex " << vertex << ": ";
            for (int neighbor : adj_list[vertex]) {
                cout << neighbor << " -> ";
            }
            cout << "None" << endl;
        }
    }
};

int main() {
    // Khởi tạo đồ thị
    Graph graph(5);

    // Thêm cạnh
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    // In danh sách kề của đồ thị
    graph.print_graph();

    return 0;
}