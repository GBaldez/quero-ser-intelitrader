#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char *argv[]) {
	
	int arr1[] = {3, 7, 12, 5, 8, 21, 9, 14, 6, 11};
	int arr2[] = {18, 4, 15, 10, 25, 2, 13, 17, 20, 1};
	
	int smallestDistance = INT_MAX;
	int a, b;
	
	for (int i = 0; i < sizeof(arr1) / sizeof(int);  i++) {
		for (int j = 0; j < sizeof(arr2) / sizeof(int);  j++) {
    		
		int temp = arr1[i] - arr2[j];
		
		if (temp < 0) {
			temp = temp * -1;
		}
		
		if (temp < smallestDistance) {
			smallestDistance = temp;
			a = arr1[i];
			b = arr2[j];
		} 
		
		}
	}
	cout << "The smallest distance is between: " << a << " and " << b << ". That results in: " <<  smallestDistance;
}
