#include <stdlib.h>
#include <iostream>
#include<vector>
using namespace std;

class sort_me
{
    public:
        void quick_sort(vector <int>&, int,int);
        int partition(vector <int>&, int, int);
        
};

void sort_me :: quick_sort(vector <int> &v,int l, int r)
{
    if(l<r)
    {
        int s;
        s = partition(v,l,r);
        quick_sort(v, l,s-1);
        quick_sort(v, s+1,r);
    }
}

int sort_me :: partition(vector <int> &v, int l, int r)
{
    int p = v[l];
    int i = l;
    int j = r+1;

    do
    {
        do
        {
            i++;
        }while(i<=r && v[i]<p);

        do
        {
            j--;
        }while(j>=l &&  v[j]>p);

        swap(v[i],v[j]);
        
    }while(i<j);

    swap(v[i],v[j]);
    swap(v[l],v[j]);

    return j;
}

int main()
{
    sort_me sorter;
    int n; 
    cout<<"Enter no.of elements\n";
    cin>>n;

    vector <int> v(n);
    cout<<"Enter the elements\n";
    for(int i=0; i<n; i++) 
        cin>>v[i];


    sorter.quick_sort(v,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<"\t";
    }

    return 0;
}