#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Graph {
public:
    Graph(int size) : size(size) {
        vertices = new vector<int>[size];
    }

    void Connect(int src, int dst) {
        vertices[src].push_back(dst);
    }

   void Disconect(int scr, int dist){
    	int holder;
    	int aux;
    	for(int i=0;i<vertices[scr].size();i++){
    		if(vertices[scr].at(i) == dist)
    			 aux = i;
    		else{
    			cout << "conexão inexistente"<< endl;
    			return ;
			}
		}
			holder = vertices[scr].at(vertices[scr].size()-1);
			vertices[scr].at(vertices[scr].size()-1) = vertices[scr].at(aux);
			vertices[scr].at(aux) = holder;
			vertices[scr].pop_back();
	}

    bool BuscaP(int scr, int dist){
        stack <int> s;
        bool visitado[size]={false};
        visitado[scr]=true;
        int x = 0;
        int jafoi;
        do {
        if (visitado[jafoi] == false || x == 0) {
        for(int i=0;i<vertices[scr].size();i++){
            s.push(vertices[scr].at(i));
            if(vertices[scr].at(i)==dist)
                return true;
        }
        visitado[s.top()]=true;
        }
        s.pop();
        if (s.empty() == false)
            jafoi = s.top();
        x++;
        } while (s.empty() == false);
        return false;
    }

    bool BuscaL(int scr, int dist) {
        queue <int> s;
        bool visitado[size]={false};
        visitado[scr]=true;
        int x = 0;
        int jafoi;
        do {
        if (visitado[jafoi] == false || x == 0) {
        for(int i=0;i<vertices[scr].size();i++){
            s.push(vertices[scr].at(i));
            if(vertices[scr].at(i)==dist)
                return true;
        }
        visitado[s.front()]=true;
        }
        s.pop();
        if (s.empty() == false)
            jafoi = s.front();
        x++;
        } while (s.empty() == false);
        return false;
    }

    void Print() {
        cout << "digraph G {" << endl;
        for (int s = 0; s < size; s++) {
            vector<int> v = vertices[s];
            int totalEdges = v.size();
            if (totalEdges == 0)
                cout << StrVertice(s)  << ";" << endl;

            for (int d = 0; d < totalEdges; d++) {
                cout << StrVertice(s)
                << " -> " <<  StrVertice(v[d])
                << ";" << endl;
            }
        }

        cout << "}" << endl;
    }

    ~Graph() {
        delete[] vertices;
    }
private:
    inline char StrVertice(const int i) {
        return (char) ('a' + i);
    }

private:
    vector<int>* vertices;
    int size;
};


int main()
{
    Graph g(5);
    g.Connect(0,1);
    g.Connect(2,0);
    g.Connect(2,1);
    g.Connect(2,2);
    g.Connect(2,3);
    g.Connect(2,4);
    g.Connect(2,5);
    g.Connect(1,2);
    g.Connect(3,1);
    g.Connect(4,4);
    g.Print();
    g.Disconect(0,1);
    g.Print();
    bool resultado = g.BuscaP(2,5);
    bool resultado2 = g.BuscaL(2,5);


    return 0;
}
