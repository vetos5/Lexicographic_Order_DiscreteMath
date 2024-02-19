//Задано натуральне число n. Навести в лексикографічному порядку всі перестановки елементів множини {1, 2, ..., n}.

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

void reversePrint(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printPermutations(int arr[], int n) {
    do {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        int i, j;
        for (i = n - 2; i >= 0; --i) {
            if (arr[i] < arr[i + 1]) {
                break;
            }
        }

        if (i < 0) {
            break;
        }

        for (j = n - 1; j > i; --j) {
            if (arr[j] > arr[i]) {
                break;
            }
        }

        swap(arr[i], arr[j]);
        reversePrint(arr, i + 1, n - 1);
    } while (true);

    delete[] arr;
}

int main() {
    int n;
 
    cout << "Input n: ";
    cin >> n;

    int* elements = new int[n];
    for (int i = 0; i < n; ++i) {
        elements[i] = i + 1;
    }

    cout << "Lexicographically ordered permutations of {1, 2, ..., " << n << "}:" << endl;
    printPermutations(elements, n);

    return 0;
}

