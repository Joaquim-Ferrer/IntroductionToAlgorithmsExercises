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
  int value;
  cin >> value;
  cout << linear_search(array, size, value)<< endl;

  //Calculation of increasing order
  increasing_order(array, size);
  output(array, size);
  //Calculation of decreasing order
  decreasing_order(array, size);
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