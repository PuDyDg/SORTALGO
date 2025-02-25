#include <bits/stdc++.h>
#include <ctime>

using namespace std;
int n;
vector <double> arr;

int partition(int low, int high) {

    // Choose the pivot
    double pivot = arr[low + rand() % (high-low+1)];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// The QuickSort function implementation
void quickSort(int low, int high) {

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
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


        filein >> n;
        arr.resize(n);

        for (int i = 0 ; i < n ; i++)
            filein >> arr[i];

        clock_t start = clock(); // Bắt đầu đo
        quickSort(0, n - 1);
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
