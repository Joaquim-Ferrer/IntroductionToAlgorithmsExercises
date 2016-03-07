#define LINEAR_SEARCH
#define INCREASING_ORDER

using namespace std;
#include <iostream>

void input(int *array, int &size);
int linear_search(int *array, int size, int value);
void increasing_order(int *array, int size);
void decreasing_order(int *array, int size);
void output(int *array, int size);

int main() {

  //Input
  int size;
  int *array;
  array = new int[size];
  input(array, size);

  //linear search
#ifdef LINEAR_SEARCH
  int value;
  cout << "Write an element to search: ";
  cin >> value;
  cout << linear_search(array, size, value)<< endl;
#endif

#ifdef INCREASING_ORDER
  //Calculation of increasing order
  increasing_order(array, size);
#else
  //Calculation of decreasing order
  decreasing_order(array, size);
  #endif

  output(array, size);
  return 0;

}

void input(int *array, int &size) {
  cout << "Write the array size" << endl;
  cin >> size;

  for(int i=0; i<size; i++) {
    cout << "Write element: ";
    cin >> array[i];
  }
}

int linear_search(int *array, int size, int value) {
  int ans = -1;

  for(int i = 0; i < size; i++) {
    if(array[i] == value) {
      ans = i;
      break;
    }
  }

  return ans;
}


void increasing_order(int *array, int size) {
  for(int j=1; j<size; j++) {
    int key = array[j];

    int sorted = j-1;
    while(sorted >= 0 and array[sorted] > key) {
      array[sorted + 1] = array[sorted];
      sorted--;
    }

    array[sorted + 1] = key;
  }
}

void decreasing_order(int *array, int size) {
  for(int j=1; j<size; j++) {
    int key = array[j];

    int sorted = j-1;
    while(sorted >= 0 and array[sorted] < key) {
      array[sorted + 1] = array[sorted];
      sorted--;
    }
    array[sorted + 1] = key;
  }
}

void output(int *array, int size) {
  for(int i=0; i < size; i++){
    cout << array[i] << " ";
  }

  cout << " " << endl;
}

int binary_search(int *array, int low, int high, int to_find) {

  if(low == high) {
    if(array[low] == to_find) {
      return low;
    }
    else {
      return -1;
    }
  }
  int index_found = -2;
  int middle = (high + low) / 2;

  if(array[middle] == to_find) {
    return middle;
  }
  else if(array[middle] > to_find) {
    index_found = binary_search(array, low, middle-1, to_find);
  }
  else {
    index_found = binary_search(array, middle + 1, high, to_find);
  }
  return index_found;

}