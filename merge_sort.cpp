using namespace std;
#include <iostream>

void input(int *array, int &size);
void merge_sort(int *array, int p, int q);
void merge(int *array, int p, int middle, int q);

int main() {
	int size;
	int *array;
	array = new int[size];
	input(array, size);

	merge_sort(array, 0, size-1);

  for(int i=0; i<size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
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

void merge_sort(int *array, int p, int q) {
	//if there's more than an element between p and q inclusive
  if(p < q) {
    int middle = (p + q) / 2;
    merge_sort(array, p, middle);
    merge_sort(array, middle + 1, q);
    merge(array, p, middle, q);
	}
}

void merge(int *array, int p, int middle, int q) {
  int size1 = middle - p + 1;
  int size2 = q - middle;
  int *A, *B;
  A = new int[size1];
  B = new int[size2];

  //Copies the sub arrays
  for(int i=0; i<size1; i++) {
    A[i] = array[p + i];
  }
  for(int i=0; i<size2; i++) {
    B[i] = array[middle + i + 1];
  }

  //Merges both sorted arrays in one sorted array
  int l=0;
  int r=0;
  int i=p;
  while(l<size1 && r<size2) {
    if(A[l] < B[r]) {
      array[i] = A[l++];
    }
    else {
      array[i] = B[r++];
    }
    i++;
  }
  //if array was fully copied, copy rest of b
  if(l == size1) {
    while(r<size2) {
      array[i] = B[r++];
      i++;
    }
  }
  //or A
  else {
    while(l<size1) {
      array[i] = A[l++];
      i++;
    }
  }
}