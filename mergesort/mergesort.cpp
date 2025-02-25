#include <bits/stdc++.h>
#include <ctime> 
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<double>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<double> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<double>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector <string> testnames;

    for (int numtest = 0 ; numtest <= 9 ; numtest++) {
        string tmp;
        tmp += (numtest + '0');
        testnames.push_back(tmp);
    }
    ofstream report("report.txt");

    double res = 0;

    for (int numtest = 0 ; numtest <= 9 ; numtest++) {
        const string input = testnames[numtest] + ".inp";
        const string output = testnames[numtest] + ".out";
        ifstream filein(input);
        ofstream fileout(output);

        int n;
        vector <double> arr;
        filein >> n;
        arr.resize(n);

        for (int i = 0 ; i < n ; i++)
            filein >> arr[i];

        clock_t start = clock(); // Bắt đầu đo
        mergeSort(arr, 0, n-1);
        clock_t end = clock(); // Kết thúc đo
        double duration = double(end - start) / CLOCKS_PER_SEC;
        report << "test" << numtest+1 << ":    " << duration << "\n";
        res += duration;
        for (int i = 0; i < n; i++) {
            fileout << arr[i] << " ";
        }
        filein.close();
        fileout.close();


    }

    res /= 10;
    report << res;

    report.close();
    return 0;
}
