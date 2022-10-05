#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <thread>

using namespace std;

// sleep sort function
void sleepSort(int arr[], int n)
{
    // Create n threads
    thread th[n];

    // Create n threads to sort the array
    for (int i = 0; i < n; i++)
        th[i] = thread([i, arr] {
            this_thread::sleep_for(chrono::milliseconds(arr[i] * 100));
            cout << arr[i] << " ";
        });

    // Join the threads to the main thread
    for (int i = 0; i < n; i++)
        th[i].join();
}

// Driver code
int main()
{
    int arr[] = {17, 68, 22, 9, 94, 53, 2, 98, 71, 49, 59, 60, 31, 10, 86, 26, 21, 89, 42, 92, 85, 40, 38, 18, 37, 45, 8, 56, 54, 36, 84, 62, 51, 81, 69, 23, 30, 73, 33, 88, 58, 3, 96, 91, 14, 79, 97, 95, 67, 66, 64, 77, 13, 27, 61, 19, 11, 41, 28, 78, 57, 99, 52, 100, 5, 35, 70, 16, 47, 87, 50, 76, 48, 15, 34, 7, 74, 65, 75, 93, 72, 1, 55, 29, 46, 43, 63, 90, 83, 12, 4, 6, 24, 80, 32, 25, 82, 20, 44, 39};
    int n = sizeof(arr) / sizeof(arr[0]);
    sleepSort(arr, n);
    cout << endl;
    system("pause");
    return 0;
}