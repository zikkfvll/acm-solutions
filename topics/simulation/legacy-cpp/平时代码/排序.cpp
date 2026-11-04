#include <iostream>
using namespace std;
template<typename T> 
void bubble_sort(T arr[], int len) {
        int i, j;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] < arr[j + 1])
                                swap(arr[j], arr[j + 1]);
}
int main() {
	int t = 0;
	cin >> t;
	for(int i = 0;i < t;i++){
		int n;		
		cin >> n;
		int arr[n];
		for(int w = 0;w < n;w++){
			cin >> arr[w];	
		}
		int len = (int) sizeof(arr) / sizeof(*arr);
   		bubble_sort(arr, len);
    	for (int i = 0; i < len; i++)
       		cout << arr[i] << ' ';
   		cout << endl;
	}   
    return 0;
}
