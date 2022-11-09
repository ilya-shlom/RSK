#include <iostream>
#include "permutations.h"

using namespace std;

class Tableaux {
private:
    static int L; // Мощность таблицы Юнга (|λ|)
    static int N; // Столбцы таблицы Юнга
    int *Ln; // λ1, λ2, ..., λn; λ = λ1 + λ2 + ... + λn
    int **T; // Таблица Юнга
    char S; // Идентификатор таблицы
    friend class permutation;
public:
    Tableaux Transpose(const Tableaux &);

    void Show();

    void power();

    void lambda(); // Вывод множества λ

    Tableaux(Permutation w); // Таблица Юнга со случайным множеством λ
    Tableaux(Permutation w, int *ln); // Пользовательская таблица Юнга
    ~Tableaux();
};