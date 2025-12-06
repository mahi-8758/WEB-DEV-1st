#include<iostream>
using namespace std;

template<typename T>
class Sort {
    public:
    static void bubbleSort(T arr[], int n) {
        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < n-i-1; j++)
                if(arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
    }
    
    static void insertionSort(T arr[], int n) {
        for(int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    
    static void quickSort(T arr[], int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }
    
    private:
    static int partition(T arr[], int low, int high) {
        T pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i + 1;
    }
    
    static void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
};

template<typename T>
void display(T arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22};
    int arr2[] = {64, 34, 25, 12, 22};
    int arr3[] = {64, 34, 25, 12, 22};
    int n = 5;
    
    cout << "Original: ";
    display(arr1, n);
    
    Sort<int>::bubbleSort(arr1, n);
    cout << "Bubble Sort: ";
    display(arr1, n);
    
    Sort<int>::insertionSort(arr2, n);
    cout << "Insertion Sort: ";
    display(arr2, n);
    
    Sort<int>::quickSort(arr3, 0, n-1);
    cout << "Quick Sort: ";
    display(arr3, n);
    
    return 0;
}