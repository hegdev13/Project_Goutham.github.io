#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class FenwickTree 
{
public:
    FenwickTree(int size);
    void update(int i, int d);
    int query(int i);
    double average();

private:
    vector<int> bit;
    int n;
};


void FenwickTree::update(int i, int d) 
{
    while (i <= n) 
    {
        bit[i] += d;
        i += i & -i;
    }
}

int FenwickTree::query(int i) 
{
    int sum = 0;
    while (i > 0) 
    {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

double FenwickTree::average() 
{
    int totalSum = query(n);
    return static_cast<double>(totalSum) / n;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) 
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    FenwickTree fenwickTree(size);
    vector<int> array(size + 1);

    cout << "Enter the array elements:" << endl;
    for (int i = 1; i <= size; i++) 
    {
        cin >> array[i];
        fenwickTree.update(i, array[i]);
    }

    cout << "The average of the array elements is: " << fenwickTree.average() << endl;

    int l, r;
    cout << "Enter a range (left right) to query the sum: ";
    cin >> l >> r;

    if (l > 0 && r <= size && l <= r) 
        cout << "The sum of elements from index " <<l<< " to " <<r<< " is: "<< fenwickTree.query(r) - fenwickTree.query(l - 1) << endl;
    else 
        cout << "Invalid range!" << endl;

    return 0;
}
