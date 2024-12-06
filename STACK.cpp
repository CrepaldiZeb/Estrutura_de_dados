//Q1

#include <iostream>

using namespace std;

class Stack {
public:
	Stack(int size) {
		vet = new int[size];
		// Seu construtor. Use para iniciar os atributos.
		cout << "Eu sou um construtor" << endl;
		this->size = size;
		top = -1;
	}

	void push(int value) {
		// TODO: Push deve empilhar um valor.
		if(top+1<size){
			 vet[top+1];
			top++;
		}
		else {
			cout<< "TA CHEIO PATr„o";
		}
	}

	void pop() {
		// TODO: Pop deve desempilhar um valor.
		if(top<=-1)
			cout<< "tem mais anda n„o"<<endl;
		else
			top--;
	}

	int count() {
		// TODO: Deve retornar o total de elementos dentro da pilha.
		return top+1 ;
	}

	int topo() {
		// TODO: Deve retornar o elemento do topo da pilha
		return vet[top];
	}
	
	bool isFull() {
		// TODO
		return top==size;
	}

	bool isEmpty() {
		// TODO
		return top==-1;
	}

	void print() {
		// TODO: Esse m√©todo deve printar os valores do array!
		for(int i=0;i<size;i++){
			cout << vet[i] << " " << endl;
		}
	}

	~Stack() {
		cout << "Eu sou um destrutor" << endl;
		// Destrutor! Use para desalocar os dados criados com o new
		delete[] vet;
	}

private:
	int size; // Atributo privado. Pode ser acessado com this->atributo ou s√≥ com atributo
	int top;
	int *vet;
};


int main() {
	Stack v(20);
	v.push(4);
	return 0;
}
