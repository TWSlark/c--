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
    test(){};
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
            cout << temp->value << endl;
            temp = temp->next;
        }
    };
    
};

int main() {
    
    test lista(5);
    lista.wypisz();

    return 0;
}
