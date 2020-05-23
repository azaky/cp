#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Graph {
	public:
		Graph () {
			nSimpul = 0;
		}
		Graph (int nSimpul) {
			this->nSimpul = nSimpul;
			AdjList = new vector<pair<int,int> >[nSimpul+1];
		}
		~Graph () {
			// printf("HALO KUDA!");
		}
		
		void AddEdge (int A, int B, int Weight) {
			if (1 <= A && A <= nSimpul && 1 <= B && B <= nSimpul) {
				AdjList[A].push_back(make_pair(B,Weight));
			}
			else {
				// pokoknya error di sini
			}
		}
		
		bool IsEdgeExist (int A, int B) {
			for (vector<pair<int,int> >::iterator it = AdjList[A].begin(); it != AdjList[A].end(); it++) {
				if (it->first == B) return true;
			}
			return false;
		}
		
		void DeleteEdge (int A, int B) {
			if (IsEdgeExist (A, B)) {
				vector<pair<int,int> >::iterator it = AdjList[A].begin();
				while (it->first != B) it++;
				while (it != AdjList[A].end()) {
					*it = *(it+1);
					it++;
				}
				AdjList[A].pop_back();
			}
		}
		
		int ShortestPath (int A, int B) {
			//Dijkstra Algorithm from A
			int *distance = new int[nSimpul+1];
			set< pair<int,int> > s;
			
			for (int i = 1; i <= nSimpul; ++i) {
				if (i == A) {
					distance[i] = 0;
				}
				else {
					distance[i] = -99;
				}
			}
			
			s.insert(make_pair(0, A));
			while (!s.empty()) {
				int V = s.begin()->second;
				int D = s.begin()->first;
				s.erase(s.begin());
				
				if (V == B) break;
				
				for (vector<pair<int,int> >::iterator it = AdjList[V].begin(); it != AdjList[V].end(); it++) {
					int U = it->first;
					int newD = D + it->second;
					if (distance[U] > 0 && distance[U] > newD || distance[U] < 0) {
						if (distance[U] > 0) {
							s.erase(make_pair(distance[U], U));
						}
						distance[U] = newD;
						s.insert(make_pair(distance[U], U));
					}
				}
			}
			
			return distance[B];
		}
		vector<int> ShortestPathVec (int A, int B) {
			//Dijkstra Algorithm from A
			int *distance = new int[nSimpul+1];
			set< pair<int,int> > s;
			vector<int> r;
		
			for (int i = 1; i <= nSimpul; ++i) {
				if (i == A) {
					distance[i] = 0;
				}
				else {
					distance[i] = -99;
				}
			}
			s.insert(make_pair(0, A));
			while (!s.empty()) {
				int V = s.begin()->second;
				//r.push_back(V);
				int D = s.begin()->first;
				s.erase(s.begin());
				
				if (V == B) break;
				
				for (vector<pair<int,int> >::iterator it = AdjList[V].begin(); it != AdjList[V].end(); it++) {
					int U = it->first;
					int newD = D + it->second;
					if (distance[U] > 0 && distance[U] > newD || distance[U] < 0) {
						if (distance[U] > 0) {
							s.erase(make_pair(distance[U], U));
						}
						distance[U] = newD;
						s.insert(make_pair(distance[U], U));
						
					}
				}
			}
			if (distance[B] != -99) {
				int V = B;
				while (V != A) {
					r.push_back(V);
					for (vector<pair<int,int> >::iterator it = AdjList[V].begin(); it != AdjList[V].end(); it++) {
						if (distance[it->first] + it->second == distance[V]) {
							V = it->first;
							break;
						}
					}
				}
				r.push_back(A);
				reverse(r.begin(), r.end());
			}
			
			return r;
		}
			
	private:
		int nSimpul;
		vector<pair<int,int> > *AdjList; //AdjList[A].push_back(make_pair(B,Weight));
};

int main() {
	int N, M;
	vector<int> r;
	scanf("%d%d",&N,&M);
	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int U, V, Weight;
		scanf("%d%d%d",&U,&V,&Weight);
		G.AddEdge(U,V,Weight);
		G.AddEdge(V,U,Weight);
	}
	
	while (true) {
		int U, V;
		scanf("%d%d",&U,&V);
		if (1 <= U && U <= N && 1 <= V && V <= N) {
			printf("Jarak terpendek antara %d dan %d adalah %d\n",U,V,G.ShortestPath(U,V));
			r=G.ShortestPathVec(U,V);
			printf("Cara kesana : \n");
			for(vector<int>::iterator it = r.begin();it!=r.end();it++){
				printf("%d ",*it);
			}
		}
		else {
			printf("Ngaco woy!\n");
		}
	}
	return 0;
}
