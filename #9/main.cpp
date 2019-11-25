#include <iostream>
#include <vector>
#include <thread>

using namespace std;

vector<int> a = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };

int num;
bool encontrado = false;
int part = 0;

void* busqueda_binaria(void* arg)
{
    int thread_part = part++;
    int mitad;

    int menor = thread_part * (size(a) / 4);
    int mayor = (thread_part + 1) * (size(a) / 4);

    while (menor < mayor && !encontrado)  {
        mitad = (mayor - menor) / 2 + menor;

        for(auto it=begin(a); it!=end(a);it++) {
            if (*(it+mitad) == num) {
                encontrado = true;
                break;
            } else if (*(it+mitad) > num)
                mayor = mitad - 1;
            else
                menor = mitad + 1;
        }
    }
}


int main(){

    cin >> num;
    auto nt = thread::hardware_concurrency();
    vector<pthread_t> threads(nt);

    for (int i = 0; i < nt; i++)
        pthread_create(&threads[i], NULL, busqueda_binaria, (void*)NULL);

    for (int i = 0; i < nt; i++)
        pthread_join(threads[i], NULL);

    if (encontrado)
        cout << num << " se encontró en el vector" << endl;
    else
        cout << num << " no se encontró en el vector" << endl;

    return 0;
}