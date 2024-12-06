// Q1.: Implemente os métodos Set, HasKey e Get de HashTable
#include <iostream>

using namespace std;

class HashTable {
private:
	struct Node {
		Node *next;
		int chave;
		string text;
	};

public:
	HashTable(int tam) : tam(tam) {
		data = new Node*[tam];
		for (int i = 0; i < tam; i++){

			data[i] = 0;
		}
	}

	void Set(int key, string texto) {
		// TODO: Set e usado para inserir um valor em data (HashTable).
		int index = key % tam;
		Node* Novo = new Node;
		if(data[index] == 0){
			//Primeiro elemento a ser colocado
			Novo->text = texto;
			Novo->next = 0;
			Novo->chave = key;
			data[index] = Novo;
		}
		else{
			//Caso ja possuam elementos
		Novo->text = texto;
		Novo->chave = key;
        Novo->next = data[index];
        data[index] = Novo;
		}
}


	bool HasKey(int key) {
		// TODO: HasKey verifica se existe um valor em data (HashTable).
		int index = key % tam;
		return (data[index]!=0);
	}

	string Get(int key) {
		// TODO: Get retorna um valor com base em Key
        int index = key % tam;
        Node* aux;
        aux = data[index];
        while(aux!=0){
        	if(aux->chave == key)
        		return aux->text;
        	aux = aux->next;
		}
		return 0;
	}

	~HashTable() {
		for (int i = 0; i < tam; i++) {
			if (data[i]){

				delete data[i];
				}
		}
		delete data;
	}
private:
	int tam;
	int* ite;
	Node** data;

};


int main() {
	HashTable table(97);


	cout << table.HasKey(123456) << endl;
    table.Set(123456, "Joao Pedro");

	cout << table.HasKey(123456) << endl;
	cout << table.Get(123456) << endl;
	table.Set(123456, "Maria");
	cout << table.Get(123456) << endl;

	for (int i = 0; i < 300; i++)
		table.Set(i, "Key = " + to_string(i));

	for (int i = 0; i < 300; i++)
		cout << table.Get(i) << endl;
	return 0;
}



