#include <iostream>
#include <vector>
#include <thread>

using namespace std;

template <typename Container>
void delete_duplicated(Container &cnt, int num){
    for(auto it = cnt.begin(); it != cnt.end(); it++){
            if(*it==num){
                cnt.erase(it);
                it--;
            }
    }

    for(auto iter = cnt.begin(); iter != cnt.end(); iter++){
        cout<<*iter<<" ";
    }

}

int main() {
    vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
    thread t1([&v1]{delete_duplicated(v1,3);});
    t1.join();

    cout<<endl;

    vector<int> v3 = {1, 1, 1, 1, 3, 2, 2, 2, 2, 5};
    thread t2([&v3]{delete_duplicated(v3,2);});
    t2.join();

    return 0;
}