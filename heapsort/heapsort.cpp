#include <bits/stdc++.h>
#include <ctime>

using namespace std;

vector<double> arr;

void siftDown(int start, int end) {
    int root = start;

    while (2 * root + 1 <= end) {
        int child = 2 * root + 1;
        int swapIdx = root;

        if (arr[swapIdx] < arr[child])
            swapIdx = child;

        if (child + 1 <= end && arr[swapIdx] < arr[child + 1])
            swapIdx = child + 1;

        if (swapIdx == root)
            return;
        else {
            swap(arr[root], arr[swapIdx]);
            root = swapIdx;
        }
    }
}

void heapSort() {
    int n = arr.size();

    for (int start = n / 2 - 1; start >= 0; start--)
        siftDown(start, n - 1);

    for (int end = n - 1; end > 0; end--) {
        swap(arr[0], arr[end]);
        siftDown(0, end - 1);
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
        heapSort();
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