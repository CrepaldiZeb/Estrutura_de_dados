// Q1.: Implemente as operações Remove e Contains. Use como referência o exemplo abaixo:

#include <iostream>
#include <string>

using namespace std;

class Tree {
    private:
        struct Node {
            int key;
            Node* left;
            Node* right;
        };
    public:
        Tree() : root(0) {

        }

        void Insert(int key) {
            Node* novo = new Node();
            novo->key = key;
            novo->left = 0;
            novo->right = 0;

            if (root == 0) {
                root = novo;
            } else {
                Node *p = Parent(key);
                if (p == 0)
                    return;

                if (p->key > key)
                    p->left = novo;
                else
                    p->right = novo;
            }
        }

        void Print() {
            InOrder(root);
        }

        ~Tree() {
            Free(root);
            root = 0;
        }

        bool contains(int key){
            return this->busca(root,key);
        }


    private:

        bool busca(Node* test, int key){
        Node* it = test;
        if(it == 0){
            return false;
        }

            if(it->key == key){
                found = it;
                return true;
            }

           else if(key >= it->key){
                if(it->right !=0){
                it = it->right;
                return busca(it,key);
            }
                return false;
        }
            else{
                if(it->left !=0){
                it = it->left;
                return busca(it,key);
            }
                return false;
            }
    }

        void InOrder(Node* r) {
            if (r == 0)
                return;

            InOrder(r->left);
            cout << r->key << endl;
            InOrder(r->right);
        }

        void Free(Node* root) {
            if (root == 0)
                return;

            Free(root->left);
            Free(root->right);
            delete root;
        }

        Node* Parent(int key) {
            Node* it = root;
            Node *p = root;
            while (it != 0) {
                p = it;
                if (it->key > key) {
                    it = it->left;
                } else if (it->key < key) {
                    it = it->right;
                } else {
                    return 0;
                }
            }

            return p;
        }

        void c1(Node* a){
            delete a;
        }

        void c2(Node* atual, int ladop, int  ladof){
            Node* pai = Parent(atual->key);
            if(ladop == 0)
            {
                if(ladof == 0)
                    pai->left = atual->left;
                else
                    pai->left = atual->right;
            }
            else{
                if(ladof == 0)
                    pai->right = atual->left;
                else
                    pai->right = atual->right;
            }
            delete atual;
        }
        void c3(Node* a){
            int f;
            Node* ite = a;
            while(ite->right != 0){
                ite = ite->right;
            }
            f = a->key;
            a->key = ite-> key;
            ite->key = f;

            if(qualc(ite)==1)
                c1(ite);

            else if(qualc(ite)==2)
                c2(ite,ladop, ladof);

        }

        void remov(int key){
            if(!busca(root,key))
                return;
            else{
                if(qualc(found)== 1){
                    c1(found);
                }
                else if(qualc(found)== 2){
                    c2(found,ladop, ladof);
                }
                else{
                    c3(found);
                }
            }
        }

        int qualc(Node* a){
            if(a->left == 0 && a->right == 0)
                return 1;

            else if((a->right == 0 && a->left != 0) || (a->right != 0 && a->left == 0)){
                if(a->right == 0 && a->left != 0)
                    ladof = 0;
                else
                    ladof = 1;
                Node* p = Parent(a->key);

                if(p->left->key == a->key)
                   ladop = 0;
                else
                    ladop = 1;

                return 2;
            }

            else
                return 3;
        }
    private:
        Node *root;
        Node* found;
        int ladof;
        int ladop;
};


int main()
{
    Tree t;
    t.Insert(20);
    t.Insert(10);
    t.Insert(5);
    t.Insert(15);
    t.Insert(25);
    t.Insert(16);
    t.Insert(50);
    t.Insert(-1);
    t.Print();
    cout << t.contains(50) << endl;
    return 1;
}
