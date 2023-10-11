#include <iostream>
#include <list>

using namespace std;

class test
{
private:
    list<int> mylist;
public:
    test(){
        mylist = {1, 2, 3, 4, 5};
    };
    ~test(){
        mylist.clear();
    };
    void wypisz(){
        for (int numbers : mylist) {
            cout << numbers << " ";
        }
        cout << endl;
    };
    void dodajp(int number){
        mylist.push_front(number);
    };
    void dodajt(int number){
        mylist.push_back(number);
    };
};

int main() {
    test lista;

    lista.wypisz();

    cout << "Dodajemy 0 na poczatek" << endl;
    lista.dodajp(0);
    lista.wypisz();

    cout << "Dodajemy 6 na koniec" << endl;
    lista.dodajt(6);
    lista.wypisz();

    return 0;
}
