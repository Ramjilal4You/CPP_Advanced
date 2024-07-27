//this program is for demonstrating the memory Leaks
#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 10000000; i++) {
		int* ptr = new int[10];
		cout << i;
		//delete[]ptr;
	}
	cout << "-main()\n";
	return 0;
}