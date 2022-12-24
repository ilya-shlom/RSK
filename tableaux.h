#include <iostream>
#include "permutations.h"

using namespace std;


class Tableaux {
private:
    int L; // Мощность таблицы Юнга (|λ|)
    int N; // Столбцы таблицы Юнга
    int *Ln; // λ1, λ2, ..., λn; λ = λ1 + λ2 + ... + λn
    int **P, **Q; // Таблица Юнга (P - вставки, Q - записи)
    int c; // Число для таблицы записи
//    friend class Permutation;
public:
//    Tableaux Transpose(const Tableaux &);

    void Show();

    int power() { return L; };

    int insert_one_P(int str_num, int num);

    string PToString();

    string QToString();

    void Rebuild(const Permutation& w);
//    void lambda(); // Вывод множества λ

    explicit Tableaux(const Permutation& w); // Конструктор таблицы алгоритмом Шенстеда
    ~Tableaux(){
        for(int i = 0; i < N; ++i) {
            delete [] P[i];
            delete [] Q[i];
        }
        delete [] P;
        delete [] Q;
    };
};

Tableaux::Tableaux(const Permutation& w) : L(0), N(w.N), Ln(new int[w.N]), P(new int*[w.N]), Q(new int*[w.N]), c(0) {
    for(int i = 0; i < w.N; ++i) {
        P[i] = new int[w.N];
        Q[i] = new int[w.N];
    }
    for (int i = 0; i < N; i++) {
        Ln[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            P[i][j] = 0;
            Q[i][j] = 0;
        }
    }
    for (int i = 0; i < w.N; i++) {
        insert_one_P(0, w.W[i]);
    }
}


int Tableaux::insert_one_P(int str_num, int num) {
    int swap;

//    cout << "inserting " << num <<"...\n";
    if (!Ln[str_num]){
        L++;
        Q[str_num][Ln[str_num]] = ++c;
        P[str_num][Ln[str_num]++] = num;
    }
    else {
        for (int i = 0;i<Ln[str_num];i++){
            if (num < P[str_num][i]){
                swap = P[str_num][i];
                P[str_num][i] = num;
                return insert_one_P(str_num + 1, swap);
            }
        }
        Q[str_num][Ln[str_num]] = ++c;
        P[str_num][Ln[str_num]++] = num;
    }
    return 1;
}

void Tableaux::Rebuild(const Permutation &w) {
    L = 0;
    c = 0;
    for (int i = 0; i < N; i++) {
        Ln[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            P[i][j] = 0;
            Q[i][j] = 0;
        }
    }
    for (int i = 0; i < w.N; i++) {
        insert_one_P(0, w.W[i]);
    }
}


void Tableaux::Show() {
    cout << "Insertion table (P):\n";
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < N; j++) {
            if (P[i][j] != 0) {
                cout << P[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "\nRecord table (Q):\n";
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < N; j++) {
            if (Q[i][j] != 0) {
                cout << Q[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

string Tableaux::PToString() {
    string result;

    for (int i = 0; P[i][0] != 0; i++) {
        for (int j = 0; P[i][j] != 0; j++) {
            string s = to_string(Q[i][j]);
            result += s;
        }
        result += 'n';
    }

    return result;
}

string Tableaux::QToString() {
    string result;

    for (int i = 0; Q[i][0] != 0; i++) {
        for (int j = 0; Q[i][j] != 0; j++) {
            string s = to_string(Q[i][j]);
            result += s;
        }
        result += 'n';
    }

    return result;
}
