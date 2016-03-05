using namespace std;
#include <iostream>

void input(int *array, int &size);
void insertion_sort(int *array, int index);

int main() {
	int size;
  int *array;
  array = new int[size];
  input(array, size);

  insertion_sort(array, size-1);

  for(int i=0; i<size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
	
  return 0;
}

void insertion_sort(int *array, int index) {
  if(index > 0) {
    insertion_sort(array, index-1);
    int sorted = index-1;

    int key = array[index];
    while(sorted >= 0 and key < array[sorted]) {
      array[sorted+1] = array[sorted];
      sorted--;
    }
    array[sorted + 1]=key;
  }

}

void input(int *array, int &size) {
  cout << "Write the array size" << endl;
  cin >> size;

  for(int i=0; i<size; i++) {
    cout << "Write element: ";
    cin >> array[i];
  }
}

