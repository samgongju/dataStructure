// 그래프 순회 구현

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct vertex {
	bool visit;
	int vertexId;
	int degree;
	vertex* prev;
	vertex* next;
	edgeList incidentEdge;

	vertex() {
		vertexId = -1;
		degree = 0;
		prev = next = NULL;
		visit = false;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		degree = 0;
		prev = next = NULL;
		visit = false;
	}
};

struct edge {
	vertex* srcVertex;
	vertex* dstVertex;
	edgeNode* srcIncidentEdgeNode;
	edgeNode* dstIncidentEdgeNode;
	edgeNode* totalEdgeNode;

	edge() {
		srcVertex = dstVertex = NULL;
	}

	edge(vertex* src, vertex* dst) {
		this->srcVertex = src;
		this->dstVertex = dst;
	}
};

struct edgeNode {
	edge* edgeInfo;
	edgeNode* prev;
	edgeNode* next;

	edgeNode() {
		edgeInfo = NULL;
		prev = next = NULL;
	}

	edgeNode(edge* edgeInfo) {
		this->edgeInfo = edgeInfo;
		prev = next = NULL;
	}
};

class vertexList {
public:
	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}

	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}

	void eraseVertex(vertex* delVertex) {
		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}

	vertex* findVertex(int vertexId) {
		for (vertex* curVertex = header->next; curVertex != trailer; curVertex = curVertex->next) {
			if (curVertex->vertexId == vertexId) {
				return curVertex;
			}
		}
		return NULL;
	}

private:
	vertex* header;
	vertex* trailer;
};

class Vertex {
public:
	Vertex(int vertex_id) : vertex_id(vertex_id) {}

private:
	friend class Graph;
	int vertex_id;
	vector<Vertex*> adjacent_vertiecs;
	bool visit;
};

class edgeList {
public:
	edgeList() {
		header = new edgeNode();
		trailer = new edgeNode();
		header->next = trailer;
		trailer->prev = header;
	}

	void insertEdge(edge* newEdge) {
		edgeNode* newEdgeNode = new edgeNode(newEdge);
		newEdgeNode->prev = trailer->prev;
		newEdgeNode->next = trailer;
		trailer->prev->next = newEdgeNode;
		trailer->prev = newEdgeNode;
	}

	void eraseEdge(edgeNode* delEdge) {
		delEdge->prev->next = delEdge->next;
		delEdge->next->prev = delEdge->prev;
		delete delEdge;
	}

	edgeNode* header;
	edgeNode* trailer;
};

void DFS(vertex* curVertex) {
	curVertex->visit = true;
	for (edgeNode* e = curVertex->incidentEdge.header->next; e != curVertex->incidentEdge.trailer; e = e->next) {
		if (curVertex == e->edgeInfo->srcVertex) {
			if (e->edgeInfo->dstVertex->visit != true) {
				DFS(e->edgeInfo->dstVertex);
			}
		}
		else {
			if (e->edgeInfo->srcVertex->visit != true) {
				DFS(e->edgeInfo->srcVertex);
			}
		}
	}
}

void BFS(int vertexId) {
	vertex* v = vList.findVertex(vertexId);
	queue<vertex*> q;
	q.push(v);
	v->visit = true;
	while (!q.empty()) {
		vertex* curVertex = q.front();
		q.pop();
		for (edgeNode* e = curVertex->incidentEdge.header->next; e != curVertex->incidentEdge.trailer; e = e->next) {
			if (curVertex == e->edgeInfo->srcVertex) {
				if (e->edgeInfo->dstVertex->visit != true) {
					q.push(e->edgeInfo->dstVertex);
					e->edgeInfo->dstVertex->visit = true;
				}
			}
			else {
				if (e->edgeInfo->srcVertex->visit != true) {
					q.push(e->edgeInfo->srcVertex);
					e->edgeInfo->srcVertex->visit = true;
				}
			}
		}
	}
}