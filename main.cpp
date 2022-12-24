#include <iostream>
#include <cmath>
#include <fstream>
#include "tableaux.h"

using namespace std;

int *ithPermutation(const int n, int i); // генерация n-ой перестановки

int main() {
    int n = 4; // Мощность перестановок
    int pAmount = static_cast<int>(tgamma(n+1)); // кол-во перестановок множества n
    ofstream results("results_3.csv");

    results << "W;W^(rc);P;Q;\n";

    Permutation A(n);
    Tableaux T(A);


//    cout << "Random permutation: \n";
//    A.Show();
//    A.reverse().complement();
//    A.Show();
//    T.Show();

    cout << "Processing all permutations of power " << n << endl;
    for (int i = 0; i < pAmount; i++) {
//        cout << "Permutation " << i << endl;
        cout << A.ToString() << endl;
        results << A.ToString() << ';';
        A.Rebuild(ithPermutation(n, i));
        results << A.ToString() << ';';
//        A.Show();
//        T.Show();
        A.reverse().complement();
        T.Rebuild(A);
//        A.Show();
//        T.Show();
        cout << T.PToString();
        results << T.PToString() << ';';
        results << T.QToString() << ';' << '\n';
    }

    results.close();

    return 0;
}

int *ithPermutation(const int n, int i)
{
    int j, k = 0;
    int *fact = new int[n];
    int *perm = new int[n];

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

    delete [] fact;

    return perm;
}
