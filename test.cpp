#include <iostream>
#include <list>

using namespace std;

class test
{
private:
    list<int> mylist;
public:
    test(){
        mylist = {1, 2, 4, 5};
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
    void wstaw(int number){
        auto it = mylist.begin();
        advance(it, 3);
        mylist.insert(it, number);
    };
    void usunp(){
        mylist.pop_front();
    };
    void usunt(){
        mylist.pop_back();
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

    cout << "Dodajemy 3 na 3 miejsce" << endl;
    lista.wstaw(3);
    lista.wypisz();

    cout << "Usuwamy liczbe z poczatku listy" << endl;
    lista.usunp();
    lista.wypisz();

    cout << "Usuwamy liczbe z konca listy" << endl;
    lista.usunt();
    lista.wypisz();

    return 0;
}
