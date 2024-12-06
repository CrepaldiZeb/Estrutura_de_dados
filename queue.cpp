//Q2

#include <iostream>

using namespace std;

class Stack {
public:
	Stack(int size) {
		vet = new int[size];
		// Seu construtor. Use para iniciar os atributos.
		cout << "Eu sou um construtor" << endl;
		this->size = size;
		b=0,f=0;
	}

	void push(int value) {
		// TODO: Push deve empilhar um valor.
		if(b<size){
			vet[b%size]=value;
			b++;
		}
		else {
			cout << "fully stacked" << endl;
		}

	}

	void pop() {
		// TODO: Pop deve desempilhar um valor.
		if((f%size)<=(b%size)){
            vet[f] = 0;
            f++;
		}
	}

	int count() {
		// TODO: Deve retornar o total de elementos dentro da pilha.

		return (b%size)-(f%size);
	}

	int front() {
		// TODO: Deve retornar o elemento do topo da pilha
		return vet[f];
	}

	int back() {
		// TODO: Deve retornar o elemento do topo da pilha
		return vet[b];
	}

	bool isFull() {
		// TODO

		return ((b%size) - (f%size) == size);
	}

	bool isEmpty() {
		// TODO

		return ((b%size) - (f%size) == 0);
	}

	void print() {
		// TODO: Esse método deve printar os valores do array!
		for(int i =0;i<b;i++){
            cout<< vet[i] << endl;
		}
	}

	~Stack() {
		cout << "Eu sou um destrutor" << endl;
		// Destrutor! Use para desalocar os dados criados com o new
		delete[] vet;
	}

private:
	int size; // Atributo privado. Pode ser acessado com this->atributo ou só com atributo
	int f,b;
	int *vet;
};


int main() {
	Stack v(20);
	v.push(4);
	return 0;
}
