//q1) Implemente uma Min-Heap de forma iterativa. Use o esqueleto abaixo:

#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    Heap()
    {
        count = 0;
    }

    void Insert(int value)
    {
        //Push no vecotr e depois tem que vecificar
        data.push_back(value);
        count++;
        upHeapfy(count-1);
    }
    void Remove()
    {
        data[0] = data[count-1];
        data.pop_back();
        count--;
        downHeapfy(0);
    }
    void downHeapfy(int index) {
        int e = Left(index);
        int d = Right(index);
        int menor = index;

        if (e < count && data[e] < data[index])
            menor = e;
        if (d < count && data[d] < data[menor])
            menor = d;

        if (menor != index) {
            int c = data[index];
            data[index] = data[menor];
            data[menor] = c;
            downHeapfy(menor);
        } 
    }
    void Print()
    {
        cout << "digraph G {" << endl;
        for (int i = 0; i < count; i++)
        {
            int l = Left(i);

            if (l < count)
            {
                cout << "\t" << data[i] <<" -> " << data[l] << endl;

                int r = Right(i);
                if (r < count)
                    cout << "\t" << data[i] <<" -> " << data[r] << endl;
            }
            else
            {
                cout << "\t" << data[i] << ";" << endl;
            }
        }
        cout << "}";
    }
    void upHeapfy(int i)
    {
        if (i == 0)
            return;
        int a = Father(i);
        if (data[i] < data[a]){
            int c = data[i];
            data[i] = data[a];
            data[a] = c;
        }
        upHeapfy(a);
    }

    inline int Left(const int i) const
    {
        return i * 2 + 1;
    }

    inline int Right(const int i) const
    {
        return i * 2 + 2;
    }

    inline int Father(const int i) const
    {
        return (i - 1)/ 2;
    }
    ~Heap()
    {
       // delete[] data;
    }

private:
    vector<int>data;
    int count;

};

int main() {
    Heap vetor;
    vetor.Insert(5);
    vetor.Insert(4);
    vetor.Insert(3);
    vetor.Insert(2);
    vetor.Insert(1);
    vetor.Insert(6);
    vetor.Insert(7);
    vetor.Insert(8);
    vetor.Remove();
    vetor.Remove();
    vetor.Remove();
    vetor.Print();
    return 0;
}