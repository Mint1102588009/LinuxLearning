#include <iostream>
using namespace std;

int partion(int * array, int low, int high){
	array[0] = array[low];
	while(high > low){
		while(array[high] >= array[0] && low != high ){
			high--;
		}
		if(low == high){
			break;
		}
		array[low] = array[high];
		low++;
		if(low == high){
			break;
		}
		while(array[low] <= array[0] && low != high){
			low++;
		}
		if(low == high){
			break;
		}
		array[high] = array[low];
		high--;
	}
	array[low] = array[0];
	return low;
}

void quickSort(int * array, int low, int high){
	if(low >= high){
		return;
	}
	int privot = partion(array, low, high);
	quickSort(array, low, (privot-1));
	quickSort(array, (privot+1), high);
}

int main(){
	int a[] = {0,3,4,2,4,0,1,1,9,9,7,0,8,0,6,4,8,3,5};
	quickSort(a, 1, 18);
	for(int i = 1; i <= 18; i++){
		cout << a[i] << " ";
	}

	return 0;
}
