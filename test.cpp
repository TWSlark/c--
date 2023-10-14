#include <iostream>

using namespace std;

class lista
{
private:
    struct node {
        int value;
        node *next;
        node *prev;
    } *head;
public:
    lista(){
        head = new node();
        head->value = 0;
        head->next = NULL;
        head->prev = NULL;
    };
    ~lista(){
        node* temp = head;
        while(temp != NULL){
            node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = NULL;
        cout << "Usuwanie listy" << endl;
    };
    lista(int value){
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
    void wypisz_od_tylu(){
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->prev;
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
    void wyswietlanie(){
        cout << "Aktualny element: " << head->value << endl;
        int wybor;
        cin >> wybor;

        switch(wybor){
            case 0:
                break;
            case 1:
                if(head->prev != NULL){
                    head = head->prev;
                }
                wyswietlanie();
                break;
            case 2:
                if(head->next != NULL){
                    head = head->next;
                }
                wyswietlanie();
                break;
            default:
                cout << "Nie ma takiej opcji" << endl;
                wyswietlanie();
                break;
        }
    }
};

int main() {
    
    cout << "Utworzenie listy z liczba 5" << endl;
    lista test(5);
    test.wypisz();

    cout << "Dodanie elementow 2 i 3 na poczatek" << endl;
    test.z_przodu(3);
    test.z_przodu(2);
    test.wypisz();

    cout << "Dodanie elementu 6 i 7 na koniec" << endl;
    test.z_tylu(6);
    test.z_tylu(7);
    test.wypisz();

    cout << "Dodanie elementu 4 pod drugim elemencie" << endl;
    test.na_miejscu(4, 2);
    test.wypisz();

    cout << "Wypisanie listy od tylu" << endl;
    test.wypisz_od_tylu();
    cout << endl;

    cout << "Usuniecie pierwszego elementu" << endl;
    test.usun_pierwsze();
    test.wypisz();

    cout << "Usuniecie ostatniego elementu" << endl;
    test.usun_ostatnie();
    test.wypisz();

    cout << "Usuniecie elementu na trzecim miejscu" << endl;
    test.usun_na_miejscu(3);
    test.wypisz();
    cout << endl;

    test.z_przodu(2);
    test.z_przodu(1);
    test.z_tylu(7);
    test.z_tylu(8);
    test.z_tylu(9);
    cout << "Lista po dodaniu kilku elementow: ";
    test.wypisz();

    cout << "0 - wyjscie" << endl;
    cout << "1 - poprzedni element" << endl;
    cout << "2 - nastepny element" << endl;
    test.wyswietlanie();

    return 0;
}
