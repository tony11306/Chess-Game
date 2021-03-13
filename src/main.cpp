#include "Queen.h"
#include <iostream>

using namespace std;

int main() {
    Queen q = Queen('1', '2');

    cout << "color: " << q.getColor() << ", id: " << q.getPieceID() << endl;

    system("pause");
    return 0;
}