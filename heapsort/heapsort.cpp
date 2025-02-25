#include <bits/stdc++.h>
#include <ctime>

using namespace std;
int n;
vector <double> arr;

void heap(int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap(n, largest);
    }
}

void heapSort(){
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heap(i, 0);
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

        clock_t start = clock(); 
        heapSort();
        clock_t end = clock(); 
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
