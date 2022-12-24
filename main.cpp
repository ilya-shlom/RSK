#include <iostream>
#include <cmath>
#include <fstream>
#include "tableaux.h"

using namespace std;

int *ithPermutation(int n, int i); // генерация n-ой перестановки

int main() {
    int n = 10; // Мощность перестановок
    int pAmount = static_cast<int>(tgamma(n+1)); // кол-во перестановок множества n
    ofstream results("results_10.csv");

    results << "W;W^(rc);P;Q;\n";

    Permutation A(n);
    Tableaux T(A);


//    cout << "Random permutation: \n";
//    A.Show();
//    A.reverse().complement();
//    A.Show();
//    T.Show();
//    cout << A.ToString();
    cout << "Processing all permutations of power " << n << endl;
    for (int i = 0; i < pAmount; i++) {
//        cout << "Permutation " << i << endl;
        A.Rebuild(ithPermutation(n, i));
        results << A.ToString() << ';';
//        A.Show();
//        T.Show();
        A.reverse().complement();
        results << A.ToString() << ';';
        T.Rebuild(A);
//        A.Show();
//        T.Show();
//        cout << T.PToString() << endl;
//        cout << T.QToString() << endl;
        results << T.PToString() << ';';
        results << T.QToString() << ';' << '\n';
    }

    results.close();

    return 0;
}

int *ithPermutation(int n, int i)
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
