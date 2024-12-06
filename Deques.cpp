#include <iostream>

using namespace std;

class Deque {
private:
	struct Node {
    int data;
    Node* next;
    Node* prev;
};

public:
	Deque(){
	int c=0;
	}

	void PushF(int v) {
	}
	Node Novo;
        if(c==0){
            Novo->next = 0;
            Novo->prev = 0;
            Novo->data = v;
            Point = &Novo;
        }
        else{
            Novo->data=v
            Novo->prev=0;
            Novo->next=Point;
            Point = &Novo;
        }
        c++;
	}
	void PushB(int v){
	Node Novo;
        if(c==0){
            Novo->next = 0;
            Novo->prev = 0;
            Novo->data = v;
            Point = &Novo;
        }
        else{
            Point->next=&Novo;
            Novo->data=v
            Novo->next=0
            Novo->prev=Point;
        }
        c++;
	}
	int PopF(){
	    int data = Point->data;
	    int Point = Point->prev;
	    Point->next->0;
	    c--;
        return data;
	}

	int PopB(){
	    int data;
	    Node* ite;
        Ite = Point->next;
        data=ite->data;
        Point= Ite;
        c--;
        return data
	}
	void print(){
	    Ite = Point;
        while(Ite->prev!=0){
            cout<<Ite->data<<endl;
            Ite = Ite->prev;
	}
	}
private:
	int size;
	Node* Point;
	int c;
};

