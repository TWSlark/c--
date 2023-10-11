#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> mylist = {1, 2, 3, 4, 5};
    
    for (int numbers : mylist) {
        cout << numbers << " ";
    }
    cout << endl;

    return 0;
}
