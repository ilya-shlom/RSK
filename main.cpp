#include <iostream>
#include "tableaux.h"

using namespace std;

int main() {
    int *mas;
    mas = new int[5];
    mas[0] = 5;
    mas[1] = 2;
    mas[2] = 3;
    mas[3] = 1;
    mas[4] = 4;
    Permutation A(5, mas);
    cout << "Done\n";
    Tableaux T(A.reverse().reverse());

    A.Show();
    A.complement().Show();
    T.Show();


    return 0;
}
