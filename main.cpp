#include <iostream>
#include <cmath>
#include <fstream>
#include "tableaux.h"

using namespace std;

int *ithPermutation(int n, int i); // генерация n-ой перестановки

int main() {
    for (int n = 1; n <= 11; n++) {
        int pAmount = static_cast<int>(tgamma(n+1)); // кол-во перестановок множества n
        string filename = "results_simil_Q_" + to_string(n) + ".csv";
        ofstream results(filename);

        results << "W;W^(rc);Q;\n";

        Permutation A(n), B(n);
        Tableaux T1(A), T2(A);


    //    cout << "Random permutation: \n";
    //    A.Show();
    //    A.reverse().complement();
    //    A.Show();
    //    T.Show();
    //    cout << A.ToString();
    int mas[5] = {1, 4, 3, 5, 2};
        cout << "Processing all permutations of power " << n << endl;
        for (int i = 0; i < pAmount; i++) {
    //        cout << i << endl;
    //        cout << "Permutation " << i << endl;
            A.Rebuild(mas);
            T1.Rebuild(A);
            T1.Show();
//            B.Rebuild(ithPermutation(n, i));
            A.reverse().complement();
            T1.Rebuild(A);
            T1.Show();
            T2.Rebuild(B);
            if(T1.QToString() == T2.QToString()) {
                T1.Show();
                results << A.ToString() << ';';
                results << B.ToString() << ';';
                results << T2.QToString() << ';' << '\n';
            }
        }

        results.close();
    }

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
