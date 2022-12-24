#include <iostream>
#include <ctime>
#include <random>
#include <cstring>
#include <algorithm>

using namespace std;

void shuffle_array(int arr[], int n) // Перемешивание массива
{

    // To obtain a time-based seed
    unsigned seed = 0;

    // Shuffling our array using random_shuffle
    shuffle(arr, arr + n, std::mt19937(std::random_device()()));
}

class Permutation {
private:
    int N; // Длина перестановки
    int *W; // Перестановка
    friend class Tableaux;
public:
    Permutation &reverse();

    Permutation &complement();

    Permutation &inverse();

    void Rebuild(int *uw); // Перезапись значений перестановки

    void Shuffle(); // Перемешивание значений перестановки

    void Show();

    int power() const { return N; }

    string ToString();

    Permutation(int n, int *uw); // Пользовательская перестановка
    explicit Permutation(int n); // Генерация перестановки длины n
    ~Permutation() { delete[] W; }
};

Permutation &Permutation::reverse() {
    Permutation temp(N, W);

    for (int i = 0; i < N; i++) {
        W[i] = temp.W[N - i - 1];
    }
    cout << "W^(r)\n";

    return *this;
}

Permutation &Permutation::inverse() {
    Permutation temp(N, W);

    for (int i = 0; i < N; i++) {
        W[temp.W[temp.W[i] - 1] - 1] = temp.W[i];
    }
    cout << "W^(-1)\n";

    return *this;
}

Permutation &Permutation::complement() {
    for (int i = 0; i < N; i++) {
        W[i] = N + 1 - W[i];
    }
    cout << "W^(c)\n";

    return *this;
}

void Permutation::Rebuild(int *uw) {
    memcpy(W, uw, sizeof(int) * N);
}

void Permutation::Shuffle() {
    int *mas;
    mas = new int[N];

    for (int i = 0; i < N; i++) {
        mas[i] = i + 1;
    }
    shuffle_array(mas, N);
    memcpy(W, mas, sizeof(int) * N);
}

void Permutation::Show() {
    cout << "W = { ";
    for (int i = 0; i < N; i++) {
        cout << W[i] << ' ';
    }
    cout << "}\n";
}

Permutation::Permutation(int n) : W(new int[n]), N(n) {
    Shuffle();
}

Permutation::Permutation(int n, int *uw) : W(new int[n]), N(n) {
    memcpy(W, uw, sizeof(int) * N);
}

string Permutation::ToString() {
    string result("");

    for (int i = 0; i < N; i++) {
        string s = to_string(W[i]);
        result += s;
    }

    return result;
}
