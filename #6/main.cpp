#include <iostream>
#include <thread>
#include <vector>
#include "Nodo.cpp"

using namespace std;

void append(Nodo* head, int new_data)
{
    Nodo* nuevo_nodo = new Nodo(new_data);
    Nodo *tail = head;
    nuevo_nodo->setData(new_data);
    nuevo_nodo->setNext(NULL);
    if (head == NULL)
    {
        head = nuevo_nodo;
        return;
    }
    while (tail->goNext(1)!= NULL)
        tail = tail->goNext(1);

    tail->setNext(nuevo_nodo);
}


void printList(Nodo *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->getData();
        node = node->goNext(1);
    }
}

int main() {

    auto creando_nodos = [](Nodo* head,int new_data){
        Nodo* nuevo_nodo = new Nodo(new_data);
        Nodo *tail = head;
        nuevo_nodo->setData(new_data);
        nuevo_nodo->setNext(NULL);

        if (head == NULL)
        {head = nuevo_nodo;
            return;}
        while (tail->goNext(1)!= NULL)
            tail = tail->goNext(1);
        tail->setNext(nuevo_nodo);
    };

    Nodo *nuevo_nodo=new Nodo(1);
    
    thread t1 = thread(creando_nodos,nuevo_nodo,2);
    t1.join();
    thread t2 = thread(creando_nodos,nuevo_nodo->goNext(1),3);
    t2.join();
    thread t3 = thread(creando_nodos,nuevo_nodo->goNext(2),4);
    t3.join();
    thread t4 = thread(creando_nodos,nuevo_nodo->goNext(3),5);
    t4.join();
    thread t5 = thread(creando_nodos,nuevo_nodo->goNext(3),6);
    t5.join();
    thread t6 = thread(creando_nodos,nuevo_nodo->goNext(2),7);
    t6.join();

    printList(nuevo_nodo);

    return 0;
}