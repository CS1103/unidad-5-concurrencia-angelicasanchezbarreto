#include <iostream>
#include <pthread.h>
#include <thread>
#include <vector>
#include <ctime>

#include "merge.cpp"

using namespace std;

int part = 0;

void* merge_sort(void* arg)
{
    int thread_part = part++;

    int menor = thread_part * (MAX / 4);
    int mayor = (thread_part + 1) * (MAX / 4) - 1;

    int mitad = menor + (mayor - menor) / 2;
    if (menor < mayor) {
        merge_sort(menor, mitad);
        merge_sort(mitad + 1, mayor);
        merge(menor, mitad, mayor);
    }
}


int main()
{
    auto nt = thread::hardware_concurrency();
    vector<pthread_t> threads(nt);

    //llenado del vector
    for (int i = 0; i < MAX; i++)
        a[i] = rand() % 100;

    cout << "Array original: ";
    for (int i : a)
        cout << i << " ";

    cout << endl;

    for (int i = 0; i < nt; i++)
        pthread_create(&threads[i], NULL, merge_sort,(void*)NULL);

    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);


    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1);
    merge(0, (MAX - 1)/2, MAX - 1);


    cout << "Array ordenado: ";
    for (int i : a)
        cout << i << " ";

    return 0;
}