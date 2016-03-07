using namespace std;
#include <iostream>

int binary_search(int *array, int low, int high, int to_find);

int main() {
  int size;
  int *array;
  array = new int[size];

  cout <<"Write size of sequence\n";
  cin >> size;

  for(int i=0; i<size; i++) {
    cout << "Write number: ";
    cin >> array[i];
  }
  int to_find;
  cin >> to_find;

  cout << binary_search(array, 0, size-1, to_find) << endl;
  return 0;
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


/* The worst-case running time of binary search is O(log n) because as we split
the tree in halves, we will(at most) reach log n levels plus the first one. And
onde we reach that log n level, we will be considering only one number wich 
will be the nunmber we are looking for or won't in which case there's not that 
number in the ordered sequence.*/ 