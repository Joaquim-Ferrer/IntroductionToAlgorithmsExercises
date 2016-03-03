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

  cout << "Write the array size" << endl;
  cin >> size;

  for(int i=0; i<size; i++) {
    cout << "Write element: ";
    cin >> array[i];
  }

  for(int cur_sorted=0; cur_sorted<size-1; cur_sorted++) {
  	int key = array[cur_sorted];

  	//Find index with lowest value
  	int min_i = cur_sorted;
  	for(int aux=cur_sorted+1; aux<size; aux++) {
  		if(array[aux] < array[min_i]) {
  			min_i = aux;
  		}
  	}

  	//Replace index with lowest value with the current index
  	array[cur_sorted] = array[min_i];
  	array[min_i] = key;
  }

  
  for(int i=0; i < size; i++){
    cout << array[i] << " ";
  }

  cout << " " << endl;
}
  /*
  This algorithm mantains a loop invariant in wich the smallest cur_sorted-th values of the array
  are always kept in ascending order in the cur_sorted first values of the array. This is kept through
  the loop and in the end only the biggest of all(the one that was never found to be smaller than any
  of the others) is kept outside the cur_sorted first values. Exactly where it belongs;

  There isn't worst case since in all the cases the loop is going to try to find the smallest value in
  the rest of the array for all n-1 cases. So the O the runtime will be O(n²); 
  */