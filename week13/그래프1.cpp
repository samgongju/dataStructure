// 인접 행렬 표현법(Adjacency Matrix Representation)
// 그래프(간단한 구현) 코드

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Vertex {
private:
	friend class Graph;
	int vertex_id;

public:
	Vertex(int vertex_id) {
		this->vertex_id = vertex_id;
	}

	int GetMatrixIdx() {
		return vertex_id;
	}
};

class Graph {
private:
	Vertex* FindVertex(int vertex_id) {
		return vertices_list[vertex_id];
	}

	int N;
	vector<Vertex*> vertices_list;
	vector<vector<bool>> adjacency_matrix;

public:
	Graph(int N) {
		this->N = N;
		vertices_list.resize(N + 1, nullptr);
		adjacency_matrix.resize(N + 1, vector<bool>(N + 1, false));
	}

	void InsertVertex(int vertex_id) {
		if (FindVertex(vertex_id) != nullptr) {
			return;
		}

		Vertex* new_vertex = new Vertex(vertex_id);
		vertices_list[vertex_id] = new_vertex;
	}

	void EraseVertex(int vertex_id) {
		Vertex* erase = FindVertex(vertex_id);
		if (erase == nullptr) {
			return;
		}

		for (int i{ 1 }; i < N; ++i) {
			adjacency_matrix[i][erase->GetMatrixIdx()] = false;
			adjacency_matrix[erase->GetMatrixIdx()][i] = false;
		}

		delete vertices_list[vertex_id];
		vertices_list[vertex_id] = nullptr;
	}

	void InsertEdge(int src_vertex_id, int dst_vertex_id) {
		Vertex* src = FindVertex(src_vertex_id);
		Vertex* dst = FindVertex(dst_vertex_id);

		if (src == nullptr || dst == nullptr) { return; }
		if (adjacency_matrix[src->GetMatrixIdx()][dst->GetMatrixIdx()] != false ||
			adjacency_matrix[dst->GetMatrixIdx()][src->GetMatrixIdx()] != false) {
			return;
		}

		adjacency_matrix[src->GetMatrixIdx()][dst->GetMatrixIdx()] = true;
		adjacency_matrix[dst->GetMatrixIdx()][src->GetMatrixIdx()] = true;
	}

	void EraseEdge(int src_vertex_id, int dst_vertex_id) {
		Vertex* src = FindVertex(src_vertex_id);
		Vertex* dst = FindVertex(dst_vertex_id);

		if (src == nullptr || dst == nullptr) { return; }
		if (adjacency_matrix[src->GetMatrixIdx()][dst->GetMatrixIdx()] == false ||
			adjacency_matrix[dst->GetMatrixIdx()][src->GetMatrixIdx()] == false) {
			return;
		}

		adjacency_matrix[src->GetMatrixIdx()][dst->GetMatrixIdx()] = false;
		adjacency_matrix[dst->GetMatrixIdx()][src->GetMatrixIdx()] = false;
	}
};
