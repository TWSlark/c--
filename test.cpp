#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
    node *prev;
};

class test
{
private:
    node* head;
public:
    test(){
        head = new node();
        head->value = 0;
        head->next = NULL;
        head->prev = NULL;
    };
    ~test(){};
    test(int value){
        head = new node();
        head->value = value;
        head->next = NULL;
        head->prev = NULL;
    };
    void wypisz(){
        node* temp = head;
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    };
    void z_przodu(int value){
        node* temp = new node();
        temp->value = value;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head = temp;
    };
    void z_tylu(int value){
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        node* nowy = new node();
        nowy->value = value;
        nowy->next = NULL;
        nowy->prev = temp;
        temp->next = nowy;
    };
};

int main() {
    
    cout << "Utworzenie listy" << endl;
    test lista(5);
    lista.wypisz();

    cout << "Dodanie elementu na poczatek" << endl;
    lista.z_przodu(4);
    lista.wypisz();

    cout << "Dodanie elementu na koniec" << endl;
    lista.z_tylu(7);
    lista.wypisz();

    return 0;
}
