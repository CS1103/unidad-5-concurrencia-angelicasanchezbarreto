#include <iostream>
#include <string>
#include <future>
#include <vector>

using namespace std;

long long int fibonacci(int n){
    vector<int> fibo;
    if(n==0)
        return 0;
    int valor = 0;
    int output = 1;

    for (int i = 1; i < n; i++)
    {
        int temporal;
        temporal = valor + output;
        valor = output;
        output = temporal;
        fibo.push_back(output);
    }

    for(auto &v:fibo)
        cout << v << " ";

    return output;

};

void fibonacci_thread(unsigned int n, promise<unsigned int>* prom){
    vector<int> fibo;
    if(n==0)
        prom->set_value(0);
    int valor = 0;
    int output = 1;

    for (int i = 1; i < n; i++)
    {
        int temporal;
        temporal = valor + output;
        valor = output;
        output = temporal;
        fibo.push_back(output);
    }

    for(auto &v:fibo)
        cout << v << " ";

    prom->set_value(output);

};


using namespace std;
int main() {
    //Primera forma
    int n;
    cout << "Inserte la cantidad de números: ";
    cin >> n;
    auto* prom1= new promise<unsigned int>();
    auto fut1= prom1->get_future();
    thread* t1= new thread(fibonacci_thread,n,prom1);
    t1->join();
    delete  t1;
    delete prom1;
    return 0;


    //Segunda forma
    /*int n;
    cout << "Inserte la cantidad de números: ";
    cin >> n;
    //future<long long int> result = async(fibonacci, n);
    async(fibonacci, n);
     */
    return 0;
}