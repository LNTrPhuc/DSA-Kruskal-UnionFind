#include "UnionFind.h"
using namespace std;

UnionFind::UnionFind(int vertexCount, bool compressionEnabled) {
    parent.resize(vertexCount);
    setSize.resize(vertexCount);
    componentCount = vertexCount;
    useCompression = compressionEnabled;

    for (int vertex = 0; vertex < vertexCount; ++vertex) {
        parent[vertex] = vertex;
        setSize[vertex] = 1;
    }
}

int UnionFind::findRoot(int vertex) {
    int root = vertex;
    while (parent[root] != root) {
        root = parent[root];
    }
    if (useCompression) {
        while (parent[vertex] != vertex) {
            int nextVertex = parent[vertex];
            parent[vertex] = root;
            vertex = nextVertex;
        }
    }
    return root;
}

bool UnionFind::unite(int firstVertex, int secondVertex) {
    int firstRoot = findRoot(firstVertex);
    int secondRoot = findRoot(secondVertex);
    if (firstRoot == secondRoot) {
        return false;
    }
    if (setSize[firstRoot] < setSize[secondRoot]) {
        int temporary = firstRoot;
        firstRoot = secondRoot;
        secondRoot = temporary;
    }
    parent[secondRoot] = firstRoot;
    setSize[firstRoot] += setSize[secondRoot];
    --componentCount;
    return true;
}

int UnionFind::getComponentCount() const {
    return componentCount;
}

int UnionFind::getParent(int vertex) const {
    return parent[vertex];
}
