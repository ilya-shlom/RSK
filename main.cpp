#include <iostream>
#include "permutations.h"

using namespace std;

int main() {
    int *mas;
    mas = new int[6];
    mas[0] = 6;
    mas[1] = 2;
    mas[2] = 4;
    mas[3] = 1;
    mas[4] = 3;
    mas[5] = 5;
    Permutation A(10);

    A.Show();
    A.reverse();
    A.Show();


    return 0;
}
