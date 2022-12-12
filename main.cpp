#include <iostream>
#include <cmath>
#include "tableaux.h"

using namespace std;

int *ithPermutation(const int n, int i); // генерация n-ой перестановки

int main() {
    int n = 5; // Мощность перестановок
    int pAmount = static_cast<int>(tgamma(n+1)); // кол-во перестановок множества n

    Permutation A(n);
    Tableaux T(A);

//    cout << "Random permutation: \n";
//    A.Show();
//    A.reverse().complement();
//    A.Show();
//    T.Show();

    cout << "Processing all permutations of power " << n << endl;
    for (int i = 0; i < pAmount; i++) {
        A.Rebuild(ithPermutation(n, i));
        A.Show();
        A.reverse().complement();
        T.Rebuild(A);
        A.Show();
        T.Show();
    }



    return 0;
}

int *ithPermutation(const int n, int i)
{
    int j, k = 0;
    int *fact = (int *)calloc(n, sizeof(int));
    int *perm = (int *)calloc(n, sizeof(int));

    // compute factorial numbers
    fact[k] = 1;
    while (++k < n)
        fact[k] = fact[k - 1] * k;

    // compute factorial code
    for (k = 0; k < n; ++k)
    {
        perm[k] = i / fact[n - 1 - k] + 1;
        i = i % fact[n - 1 - k];
    }

    // readjust values to obtain the permutation
    // start from the end and check if preceding values are lower
    for (k = n - 1; k > 0; --k)
        for (j = k - 1; j >= 0; --j)
            if (perm[j] <= perm[k])
                perm[k]++;
    free(fact);

    return perm;
}
