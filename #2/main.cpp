#include <iostream>
#include <thread>
#include <random>
#include <vector>
#include <future>

using namespace std;

random_device rd;

void exer1(int dato){
    const size_t n = 20;
    auto nt = thread::hardware_concurrency();
    auto range = n/nt;
    cout << "Cantidad: " << n << endl;
    cout << "Threads: " << nt << endl;
    cout << "Rango: " << range << endl;

    //LLENADO DEL VECTOR
    vector<int> vec(n);
    vector<thread> vec_thread(nt);

    auto filler = [&vec](size_t start, size_t stop){
        for (int i = start; i < stop; i++)
            vec[i] = rd() % 50;
    };
    for(int j=0; j<nt; j++)
        vec_thread[j] = thread(filler, range*j, range*(j+1));
    for(auto &t:vec_thread)
        t.join();
    for(auto &item:vec)
        cout<<item<<" ";
    cout<<endl;


    //INCREMENTO DE LOS VALORES
    vector<promise<int>> vec_promise(nt);
    vector<future<int>> vec_future(nt);
    vector<thread> vec_thread2(nt);

    auto summarizer = [&vec](promise<int> &prom, size_t start, size_t stop, int dato){
        for (int i = start; i < stop; i++)
            vec[i]=vec[i]+dato;
    };
    for (int i = 0; i < nt; i++)
        vec_future[i] = vec_promise[i].get_future();
    for (int i = 0; i < nt; i++)
        vec_thread2[i] = thread(summarizer,ref(vec_promise[i]),range*i,range*(i+1));
    for(int i = 0; i<nt; i++)
        vec_thread2[i].join();
    auto incremento = accumulate(begin(vec_future),end(vec_future),0,
                            [](int a, future<int> &ftr){
                                return a + ftr.get();
                            });
}

int main() {
    int n = 5;
    exer1(n);
    return 0;
}