#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class kruskal
{
    public:
        vector <pair<pair<int,int>,int> > inp;
        int vertices;
        vector <int> arr;
        int cost = 0;
        int root;

        void read_input();
        void q_sort(vector <pair<pair<int,int>,int> >, int l, int r);
        int partition(vector <pair<pair<int,int>,int> >, int l, int r);
        void union_kruskal(vector <int> arr, int u,int v);
        int find_kruskal(vector <int> arr, int i, int j);
        void kruskal_alg();

};

void kruskal :: read_input()
{   
    cout<<"enter number of vertices\n";
    cin>>vertices;
    for(int i=0;i<vertices;i++)
    {
        arr.push_back(i);
    }

    int ch;
    while(1)
    {
        cout<<"1. enter data\n";
        cout<<"0. exit\n";
        cin>>ch;

        switch(ch)
        {
            case 1: 
                int u,v,w;
                cout<<"enter vertices:\n";
                cin>>u>>v;
                cout<<"enter weight:\n";
                cin>>w;
                inp.push_back(make_pair(make_pair(u,v),w));
                break;
            case 0:
                return;
            default : 
                cout<<"invalid input...\n";
                break;
        }

    }
}

void kruskal :: q_sort(vector <pair<pair<int,int>,int> > inp,int l, int r)
{
    int s;
    if(l<r)
    {
        s = partition(inp,l,r);
        q_sort(inp,l,s-1);
        q_sort(inp,s+1,r);
    }
}
int kruskal ::  partition(vector <pair<pair<int,int>,int> > inp, int l, int r)
{
    int p = inp[0].second;
    int i = l, j =r+1;

    do
    {
        do
        {
            i++;
        }while(i<=r && inp[i].second<p);
        do
        {
            j--;
        }while(j>=l && inp[j].second>p);

        swap(inp[i].second,inp[j].second);

    }while(i<j);
    swap(inp[i].second,inp[j].second);
    swap(inp[l].second,inp[j].second);

    return j;
}

void kruskal :: union_kruskal(vector <int> arr, int u, int v)
{
    int temp = arr[u];
    for(int i=0;i<vertices;i++)
    {
        if(arr[i] == temp)
        {
            arr[i] = arr [v];
        }
    }

}
int kruskal :: find_kruskal(vector <int> arr, int i, int j)
{
    if(arr[i]==arr[j])
        return 1;
    else
        return 0;
}

void kruskal :: kruskal_alg()
{
    int edges =0;
    for(int i=0; i< inp.size(); i++)
    {
        cout<<"Assesing (u,v)";
        int res = find_kruskal(arr,inp[i].first.first, inp[i].first.second);

        if(res == 0)
        {
            //output
            cout<<"u = "<< inp[i].first.first<<"\t v = "<<inp[i].first.second<<endl;
            union_kruskal(arr,inp[i].first.first, inp[i].first.second);

            //implement root and cost;
            cost += inp[i].second;
        }
        if(res == 1)
            continue;
        
    }
    root = arr[0];
    cout<<"cost = "<<cost<<endl;
    cout<<"root = "<<root<<endl;
}

int main()
{
    kruskal k;

    k.read_input();
    k.q_sort();
    k.kruskal_alg()
    return 0;
}
