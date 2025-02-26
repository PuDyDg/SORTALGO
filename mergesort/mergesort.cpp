#include <bits/stdc++.h>
#include <ctime>
using namespace std;

vector<double> arr;

void mergeArrays(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> leftArr(n1);
    vector<double> rightArr(n2);

    copy(arr.begin() + left, arr.begin() + mid + 1, leftArr.begin());
    copy(arr.begin() + mid + 1, arr.begin() + right + 1, rightArr.begin());

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSortRecursive(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(left, mid);
        mergeSortRecursive(mid + 1, right);
        mergeArrays(left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> testnames;

    for (int numtest = 0; numtest <= 9; numtest++) {
        testnames.push_back(to_string(numtest));
    }

    ofstream report("report.txt");
    double totalDuration = 0;

    for (int numtest = 0; numtest <= 9; numtest++) {
        const string input = testnames[numtest] + ".inp";
        const string output = testnames[numtest] + ".out";
        ifstream filein(input);
        ofstream fileout(output);

        int n;
        filein >> n;
        arr.resize(n);

        for (int i = 0; i < n; i++)
            filein >> arr[i];

        clock_t start = clock();
        mergeSortRecursive(0, n - 1);
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        report << "test" << numtest + 1 << ":    " << duration << "\n";
        totalDuration += duration;

        for (const auto& val : arr) {
            fileout << val << " ";
        }

        filein.close();
        fileout.close();
    }

    totalDuration /= 10;
    report << "Average duration: " << totalDuration << "\n";
    report.close();

    return 0;
}