#include<iostream>
#include<vector>
using namespace std;

class Vertex {
private:
	friend class Graph;
	int vertex_id;
	vector<Vertex*> adjacent_vertiecs;

public:
	Vertex(int vertex_id) : vertex_id(vertex_id) {}
};

class Graph {
private:
	Vertex* FindVertex(int vertex_id) const {
		int idx = GetIndex(adjacency_list, vertex_id);
		if (idx == -1) {
			return nullptr;
		}
		return adjacency_list[idx];
	}

	int GetIndex(const vector<Vertex*>& list, int vertex_id) const {
		int sz = static_cast<int>(list.size());
		for (int i{ 0 }; i < sz; i++) {
			if (list[i]->vertex_id == vertex_id) {
				return i;
			}
		}
		return -1;
	}
	vector<Vertex*> adjacency_list;

public:
	Graph() = default;
	void InsertVertex(int vertex_id) {
		if (FindVertex(vertex_id) != nullptr) {
			return;
		}

		Vertex* new_vertex = new Vertex(vertex_id);
		adjacency_list.push_back(new_vertex);
	}

	void InsertEdge(int src_vertex_id, int dst_vertex_id) {
		Vertex* src = FindVertex(src_vertex_id);
		Vertex* dst = FindVertex(dst_vertex_id);

		if (src == nullptr || dst == nullptr) {
			return;
		}

		if (GetIndex(src->adjacent_vertiecs, dst_vertex_id) != -1 ||
			GetIndex(dst->adjacent_vertiecs, src_vertex_id) != -1) {
			return;
		}

		src->adjacent_vertiecs.push_back(dst);
		dst->adjacent_vertiecs.push_back(src);
	}

	void EraseVertex(int vertex_id) {
		Vertex* vertex = FindVertex(vertex_id);

		if (vertex == nullptr) {
			return;
		}

		for (Vertex* adjacent_vertex : vertex->adjacent_vertiecs) {
			adjacent_vertex->adjacent_vertiecs.erase(adjacent_vertex->adjacent_vertiecs.begin() + GetIndex(adjacent_vertex->adjacent_vertiecs, vertex_id));
		}

		adjacency_list.erase(adjacency_list.begin() + GetIndex(adjacency_list, vertex_id));

		delete vertex;
	}

	void EraseEdge(int src_vertex_id, int dst_vertex_id) {
		Vertex* src = FindVertex(src_vertex_id);
		Vertex* dst = FindVertex(dst_vertex_id);

		if (src == nullptr || dst == nullptr) {
			return;
		}

		int src_dst_index = GetIndex(src->adjacent_vertiecs, dst_vertex_id);
		int dst_src_index = GetIndex(dst->adjacent_vertiecs, src_vertex_id);

		if (src_dst_index == -1 || dst_src_index == -1) {
			return;
		}

		src->adjacent_vertiecs.erase(src->adjacent_vertiecs.begin() + src_dst_index);
		dst->adjacent_vertiecs.erase(dst->adjacent_vertiecs.begin() + dst_src_index);
	}
};