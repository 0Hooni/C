#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2

class vertex
{
public:
	int data;
	int degree;
	bool visited;
	vector<vertex *> adj_list;
	vertex(int data)
	{
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class edge
{
public:
	vertex *src;
	vertex *dst;
	int data;
	bool edge_stat;
	edge(vertex *src, vertex *dst)
	{
		this->src = src;
		this->dst = dst;
		this->edge_stat = NOT_EXPLORED;
	}
};

#define vertexRange 1000

class graph
{
public:
	edge ***edgeMatrix;
	vector<vertex *> vertex_list;
	vector<edge *> edge_list;
	graph()
	{
		edgeMatrix = new edge **[vertexRange];
		for (int i = 0; i < vertexRange; i++)
		{
			edgeMatrix[i] = new edge *[vertexRange];
			for (int j = 0; j < vertexRange; j++)
			{
				edgeMatrix[i][j] = NULL;
			}
		}
	}

	vertex *findvertex(int data)
	{
		vertex *v = NULL;
		for (int i = 0; i < vertex_list.size(); i++)
		{
			if (vertex_list[i]->data == data)
			{
				v = vertex_list[i];
				break;
			}
		}
		return v;
	}
	edge *findedge(int src, int dst)
	{
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++)
		{
			if (vertex_list[i]->data == src)
			{
				_src = i;
			}
			if (vertex_list[i]->data == dst)
			{
				_dst = i;
			}
		}
		if (edgeMatrix[_src][_dst] == NULL)
		{
			return NULL;
		}
		else
		{
			return edgeMatrix[_src][_dst];
		}
	}

	void insert_vertex(int n)
	{
		if (findvertex(n) != NULL)
		{
			return;
		}

		else
		{
			int size = vertex_list.size();

			vertex *newVertex = new vertex(n);
			vertex_list.push_back(newVertex);
		}
	}

	void insert_edge(int source, int destination)
	{
		vertex *src = findvertex(source);
		vertex *dst = findvertex(destination);
		int _src = NULL, _dst = NULL;
		for (int i = 0; i < vertex_list.size(); i++)
		{
			if (vertex_list[i]->data == source)
			{
				_src = i;
			}
			if (vertex_list[i]->data == destination)
			{
				_dst = i;
			}
		}

		if (findedge(source, destination) == NULL)
		{
			edge *new_e = new edge(src, dst);
			edge_list.push_back(new_e);
			edgeMatrix[_src][_dst] = new_e;
			edgeMatrix[_dst][_src] = new_e;
			src->adj_list.push_back(dst);
			dst->adj_list.push_back(src);
		}
		else
		{
			cout << -1 << endl;
			return;
		}
		src->degree++;
		dst->degree++;
	}

	void DFS(vertex *curV)
	{
		curV->visited = true;
		cout << curV->data << " ";
		for (int i = 0; i < curV->adj_list.size(); i++)
		{
			vertex *v = curV->adj_list[i];

			if (v->visited == false)
			{
				DFS(v);
			}
		}
	}

};

int main()
{
	graph *g = new graph();

	int N = 0; //정점의 개수
	int M = 0; //간선의 개수
	int A = 0; //DFS 수행시 시작하는 정점의 번호
	cin >> N >> M >> A;

	for (int i = 0; i < N; i++)
	{
		int vertexNum = 0;
		cin >> vertexNum;

		g->insert_vertex(vertexNum);
	}

	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		v1 = v2 = 0;
		cin >> v1 >> v2;

		g->insert_edge(v1, v2);
	}

	g->DFS(g->findvertex(A));
}
