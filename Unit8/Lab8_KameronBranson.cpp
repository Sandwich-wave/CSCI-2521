#include <iostream>
using namespace std;

void FindPrevNext (int x, int prev, int next) {
    prev = x - 1;
    next = x + 1;
}

int main() {
    int x = 10;
    int y;
    int z;
    FindPrevNext (x, y, z);
    cout << "Previous = " << y << ", Next = " << z;
    return 0;
}