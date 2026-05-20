#include <iostream>
#include <vector>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();

    vector<int> freq(n + 1, 0), res(n);
    int count = 0;

    for (int i = 0; i < n; ++i) {

        freq[A[i]]++;
        if (freq[A[i]] == 2)
            count++;

        freq[B[i]]++;
        if (freq[B[i]] == 2)
            count++;

        res[i] = count;
    }

    return res;
}

int main() {

    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    vector<int> result = findThePrefixCommonArray(A, B);

    cout << "Prefix Common Array: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
