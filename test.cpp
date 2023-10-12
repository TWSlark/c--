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
    void na_miejscu(int value, int index){
        node* temp = head;
        for(int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        node* nowy = new node();
        nowy->value = value;
        nowy->next = temp->next;
        nowy->prev = temp;
        temp->next = nowy;
    };
    void usun_pierwsze(){
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    };
    void usun_ostatnie(){
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    };
    void usun_na_miejscu(int index){
        node* temp = head;
        for(int i = 0; i < index-2; i++){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete temp2;
    };
};

int main() {
    
    cout << "Utworzenie listy z liczba 5" << endl;
    test lista(5);
    lista.wypisz();

    cout << "Dodanie elementow 2 i 3 na poczatek" << endl;
    lista.z_przodu(3);
    lista.z_przodu(2);
    lista.wypisz();

    cout << "Dodanie elementu 6 i 7 na koniec" << endl;
    lista.z_tylu(6);
    lista.z_tylu(7);
    lista.wypisz();

    cout << "Dodanie elementu 4 pod drugim elemencie" << endl;
    lista.na_miejscu(4, 2);
    lista.wypisz();

    cout << "Usuniecie pierwszego elementu" << endl;
    lista.usun_pierwsze();
    lista.wypisz();

    cout << "Usuniecie ostatniego elementu" << endl;
    lista.usun_ostatnie();
    lista.wypisz();

    cout << "Usuniecie elementu na trzecim miejscu" << endl;
    lista.usun_na_miejscu(3);
    lista.wypisz();

    return 0;
}
