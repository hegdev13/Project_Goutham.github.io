/*
This is a modified implementation of Boyer-Moore, it also computes the frequency of the pattern.
The corresponding file is BM-text.txt


*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class BoyerMoore 
{
private:
    string pattern;
    vector<int> BSST;
    vector<int> GSST;

    void computeBSST();
    void computeGSST();

public:
    BoyerMoore(const string& pat) : pattern(pat) 
    {
        computeBSST();
        computeGSST();
    }

    void search(const string& text) 
    {
        int n = text.size();
        int l = pattern.size();
        int i = 0, count = 0;

        while (i <= n-l) 
        {
            int j=l-1;
            while (j>=0 && pattern[j] == text[i+j])
                j--;

            if (j < 0) 
            {
                int line = (i/5)+1;
                cout<<"Pattern found at line "<<line<<endl;
                count+=1;
                i+=(i+l<n) ? GSST[0] : 1;
            } 
            else 
            {
                int bsst_val = BSST[text[i + j]];
                int gsst_val = GSST[j];
                i+=max(bsst_val, gsst_val);
            }
        }
        cout<<"\n\nFrequency = "<<count<<endl;
    }
};

void BoyerMoore :: computeBSST() 
{
    int l=pattern.size();
    BSST.assign(256, l);
    for (int i=0; i < l-1; i++) 
        BSST[pattern[i]] = l-i-1;
}

void BoyerMoore :: computeGSST() 
{
    int l = pattern.size();
    GSST.resize(l, l);
    vector<int> shift_k(l+1, 0);

    int i = l, j = l+1;
    shift_k[i] = j;

    while (i > 0) 
    {
        while (j<=l && pattern[i-1] != pattern[j - 1] ) 
        {
            if (GSST[j] == l) 
                GSST[j] = j-i;
            j = shift_k[j];
        }
        i--;j--;
        shift_k[i] = j;
    }

    j=shift_k[0];

    for (i = 0; i < l; i++) 
    {
        if (GSST[i] == l)
            GSST[i] = j;
        if (i == j)
            j = shift_k[j];
    }
}

int main() 
{
    string text, pattern, fileName = "BM-text.txt";

    ifstream inputFile(fileName);
    if (!inputFile) 
    {
        cerr<<"Error: Could not open file"<<fileName<<endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) 
        text += line;
    inputFile.close();

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    BoyerMoore bm(pattern);
    bm.search(text);

    return 0;
}
