
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void imprimir(vector<int> vec)
{
	for(auto i : vec)
	{
		cout << i << " "; 
	}
}

void incremento(vector<int> &vec, int n)
{
	for(auto& i : vec)
	{
		i += n;
	}

	imprimir(vec);
}

int main(){
	vector<int> vec = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
	int n;
	cin >> n;
	thread t1(incremento, ref(vec), n);
	t1.join();
}
