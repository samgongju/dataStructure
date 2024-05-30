// 인접 행렬 표현법(Adjacency Matrix Representation)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct vertex {
	int vertexId;
	int matrixId;
	vertex* prev;
	vertex* next;

	vertex() {
		vertexId = matrixId = -1;
		prev = next = NULL;
	}

	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		prev = next = NULL;
	}
};

struct edge {
	vertex* src;
	vertex* dst;
	edge* prev;
	edge* next;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}

	edge(vertex* src, vertex* dsdt) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};

class vertexList {
private:
	vertex* header;
	vertex* trailer;

public:
	vertexList() {
		header = new vertex;
		trailer = new vertex;
		header->next = trailer;
		trailer->prev = header;
	}

	void insertVertex(vertex* newv) {
		newv->prev = trailer->prev;
		newv->next = trailer;
		newv->matrixId = trailer->prev->matrixId + 1;
		trailer->prev->next = newv;
		trailer->prev = newv;
	}

	void eraseVertex(vertex* delv) {
		for (vertex* cur = delv; cur != trailer; cur = cur->next) {
			cur->matrixId--;
		}

		delv->prev->next = delv->next;
		delv->next->prev = delv->prev;
		delete delv;
	}

	vertex* findVertex(int vertexId) {
		for (vertex* cur = header->next; cur != trailer; cur = cur->next) {
			if (cur->vertexId == vertexId) {
				return cur;
			}
		}

		return NULL;
	}
};

class edgeList {
private:
	edge* header;
	edge* trailer;

public:
	edgeList() {
		header = new edge();
		trailer = new edge();
		header->next = trailer;
		trailer->prev = header;
	}

	void insertEdge(edge* newe) {
		newe->prev = trailer->prev;
		newe->next = trailer;
		trailer->prev->next = newe;
		trailer->prev = newe;
	}

	void eraseEdge(edge* dele) {
		dele->prev->next = dele->next;
		dele->next->prev = dele->prev;
		delete dele;
	}
};

class graph {
private:
	vector<vector<edge*>> edgeMatrix;
	vertexList vList;
	edgeList eList;

public:
	void insertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}

		vertex* newVertex = new vertex(vertexId);

		for (int i{ 0 }; i < edgeMatrix.size(); i++) {
			edgeMatrix[i].push_back(NULL);
		}
		edgeMatrix.push_back(vector<edge*>(edgeMatrix.size() + 1, NULL));

		vList.insertVertex(newVertex);
	}

	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);
		if (delVertex == NULL) {
			return;
		}

		int matrixId = delVertex->matrixId;
		for (int i{ 0 }; i < edgeMatrix.size(); i++) {
			if (i != matrixId) {
				if (edgeMatrix[i][matrixId] != NULL) {
					eList.eraseEdge(edgeMatrix[i][matrixId]);
				}
				edgeMatrix[i].erase(edgeMatrix[i].begin() + matrixId);
			}
		}

		edgeMatrix.erase(edgeMatrix.begin() + matrixId);
		vList.eraseVertex(delVertex);
	}

	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL) {
			return;
		}

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL || edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			return;
		}

		edge* newEdge = new edge(src, dst);
		eList.insertEdge(newEdge);
		edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = newEdge;
	}

	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* src = vList.findVertex(srcVertexId);
		vertex* dst = vList.findVertex(dstVertexId);
		if (src == NULL || dst == NULL) {
			return;
		}

		int srcMatrixId = src->matrixId;
		int dstMatrixId = dst->matrixId;

		if (edgeMatrix[srcMatrixId][dstMatrixId] != NULL || edgeMatrix[dstMatrixId][srcMatrixId] != NULL) {
			return;
		}

		eList.eraseEdge(edgeMatrix[srcMatrixId][dstMatrixId]);
		edgeMatrix[srcMatrixId][dstMatrixId] = edgeMatrix[dstMatrixId][srcMatrixId] = NULL;
	}
};

int main() {
	return 0;
}
