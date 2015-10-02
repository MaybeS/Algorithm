#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <utility>




//Dijkstra.cc 18/34
//map[i][j]={x,y}--i:index,j:start,x:end,y:cost
//dist[i]=j--i:end,j:cost
//start
template<typename t_index, typename t_cost>
void dijkstra(const vector<vector<pair<t_index, t_cost>>>& map, vector<t_cost>& dist, const size_t& start)
{
	priority_queue<pair<t_index, t_cost>> pq;
	pq.push({ start, 0 });
	while (pq.size())
	{
		pair<t_index, t_cost> now = pq.top();
		pq.pop();
		for (int i = 0; i < map[now.first].size(); i++)
		{
			t_index next_index = map[now.first][i].first;
			if (dist[next_index] > -now.second + map[now.first][i].second)
			{
				dist[next_index] = -now.second + map[now.first][i].second;
				pq.push({ next_index, -dist[next_index] });
			}
		}
	}
}

//ConvexHull
template<typename type>
type cross(const pair<type,type> &O, const pair<type, type> &A, const pair<type, type> &B)
{
	return (type)(A.first - O.first) * (B.second - O.second) - (type)(A.second - O.second) * (B.first - O.first);
}
template<typename type>
vector<pair<type,type>> convex_hull(vector<pair<type, type>> map)
{
	int k = 0;
	vector<pair<type, type>> result(2 * map.size());
	sort(map.begin(), map.end(), [](pair<type,type> p, pair<type,type> q) { return p.second > q.second || ((!(p.second < q.second) && p.first < q.first)); });
	for (int i = 0; i < map.size(); ++i) 
	{
		while (k >= 2 && cross<type>(result[k - 2], result[k - 1], map[i]) <= 0) 
			k--;
		result[k++] = map[i];
	}
	for (int i = map.size() - 2, t = k + 1; i >= 0; i--) 
	{
		while (k >= t && cross<type>(result[k - 2], result[k - 1], map[i]) <= 0)
			k--;
		result[k++] = map[i];
	}
	result.resize(k);
	return result;
}

//Floyd-Warshall
//comment: 그래프에서 모든 꼭짓점 사이의 최단 경로의 거리를 구하는 알고리즘, 순환이 없어야함 
template<typename type>
void floydWarshall(const vector<type>& map)
{
	for(int k = 0; k< map.size(); k++)
		for(int i = 0; i < map.size(); i++)
			for(int j = 0; j< map.size(); j++)
				if(map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
}

//Toplogical Sort
//위상정렬. DAG가 아니면 빈 벡터 반환
template<typename type>
void topologicalSort_sub(size_t index, vector<type>& map, vector<type>& result, vector<type>& order)
{
	result[index] = 1;
	for(int i = 0; i < map.size(); i++)
		if(map[index][i] && !result[i])
			topologicalSort_sub(i,map,result,order);
	order.push_back(index);
}
template<typename type>
vector<type> topologicalSort(vector<type> map)
{
	vector<type> order, result(map.size(),0);
	for(int i = 0; i < map.size(); i++)
		if(!result[i])
			topologicalSort_sub(i,map,result,order);
	reverse(order.begin(), order.end());
	for(int i = 0; i < map.size(); i++)
		for(int j = i + 1; j < n; j++)
			if(map[order[j]][order[i]])
				return vector<type>();
	return order;
}

//union-find set: the vector/array contains the parent of each node
int find(vector <int>& C, int x)
	{return (C[x]==x) ? x : C[x]=find(C, C[x]);} //C++


//HamiltonCircuit
//input vector<vector<boo>> map;
bool hamiltonCycle_sub(vecotr<vector<bool>> map, vector<int> path, int pos)
{
	if(pos == map.size())
		if(map[path[pos-1]][path[0]]==1)
			return true;
		else
			return false;

	for(int i = 1; i < map.size(); i++)
	{
		if(map[path[pos-1]][i])
		{
			bool chk = true;
			for(int j = 0; j < pos; j++)
				if(path[j]==i)
				{
					chk = false;
					break;
				}
			if(chk)
			{
				path[pos] = i;
				if(hamiltonCycle_sub(map,path,pos+1))
					return true;
				path[pos] = -1;
			}
		}
	}
	return false;
}
bool hamiltonCycle(vector<vector<bool>> map)
{
	vector<int> path(map.size(),-1);
	path[0] = 0;
	if(!hamiltonCycle_sub(map,path,1))
	{
		//No solution
		return false;
	}
	//path == solution
	return true;
}