
#include <iostream>
using namespace std;

int countEven(int A[], int i, int j)
{
    // Base Case
    if (i == j)
    {
        if (A[i] % 2 == 0)
            return 1;
        else
            return 0;
    }

    // Divide
    int mid = (i + j) / 2;

    // Conquer
    int left = countEven(A, i, mid);
    int right = countEven(A, mid + 1, j);

    // Combine
    return left + right;
}

int main()
{
    int A[] = {10, 5, 30, 2, 15, 8};
    int n = 6;

    int total = countEven(A, 0, n - 1);

    cout << "Total Even Numbers = " << total << endl;

    return 0;
}
