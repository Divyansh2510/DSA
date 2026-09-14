#include <iostream>
#include <vector>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

    // Check if one rectangle is completely to the left of the other
    if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0])
        return false;

    // Check if one rectangle is completely above/below the other
    if (rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
        return false;

    return true;
}

int main() {

    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    if (isRectangleOverlap(rec1, rec2))
        cout << "Rectangles overlap" << endl;
    else
        cout << "Rectangles do not overlap" << endl;

    return 0;
}
