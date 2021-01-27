#include <iostream>
using namespace std;


int main() {
	int num, first, second;
	do {
		cout << "enter num: ";
		cin >> num;
	} while (num < 4);

	for (int i = 2; i < num; i++){

		bool isPrime = true;
		first = i;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				first = -1;
				break;
			}
		}

		if (isPrime) {
			second = num - first;
			for (int j = 2; j < num - first; j++) {
				if ((num - first) % j == 0) {
					isPrime = false;
					second = -1;
					break;
				}
			}
		}

		if (isPrime) {
			cout << num << " = " << first << " + " << second << endl;
			break;
		}
		
	}
	return 0;
}
