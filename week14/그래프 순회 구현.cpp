// 그래프 순회 구현

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Vertex {
public:
	Vertex(int vertex_id) : vertex_id(vertex_id) {}

private:
	friend class Graph;
	int vertex_id;
	vector<Vertex*> adjacent_vertiecs;
	bool visit;
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

	void Clear() {
		for (Vertex* vertex : adjacency_list) {
			vertex->visit = false;
		}
	}

	void DFS(Vertex* now) {
		now->visit = true;

		for (Vertex* adjacent_vertex : now->adjacent_vertiecs) {
			if (adjacent_vertex->visit != true) {
				DFS(adjacent_vertex);
			}
		}
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

	void DFS(int vertex_id) {
		Vertex* start = FindVertex(vertex_id);
		if (start == nullptr) {
			return;
		}
		Clear();
		DFS(start);
	}

	void BFS(int vertex_id) {
		Vertex* start = FindVertex(vertex_id);
		if (start == nullptr) {
			return;
		}
		queue<Vertex*> bfs_queue;
		bfs_queue.push(start);
		start->visit = true;
		while (!bfs_queue.empty()) {
			Vertex* now = bfs_queue.front();
			bfs_queue.pop();
			for (Vertex* adjacent_vertex : now->adjacent_vertiecs) {
				if (adjacent_vertex->visit == false) {
					adjacent_vertex->visit = true;
					bfs_queue.push(adjacent_vertex);
				}
			}
		}
	}

	/*
	간단한 그래프 구현
	const int N = 1005;
	vector<int> edge[N];
	bool visit[N];

	void insertEdge(int srcVertexId, int dstVertexId) {
		edge[srcVertexId].push_back(dstVertexId);
		edge[dstVertexId].push_back(srcVertexId);
	}

	void DFS(int curVertexId) {
		visit[curVertexId] = true;
		for (int i{ 0 }; i < edge[curVertexId].size(); i++) {
			if (visit[edge[curVertexId]] != true) {
				DFS(edge[curVertexId][i]);
			}
		}
	}

	void BFS(int vertexId) {
		queue<int> q;
		q.push(vertexId);
		visit[vertexId] = true;
		while (!q.empty()) {
			int curVertexId = q.front();
			q.pop();
			for (int i{ 0 }; i < edge[curVertexId].size(); i++) {
				if (visit[edge[curVertexId][i]] != true) {
					q.push(edge[curVertexId][i]);
					visit[edge[curVertexId][i]] = true;
				}
			}
		}
	}
	*/
};