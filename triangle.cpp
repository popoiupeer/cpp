#include <iostream>
using namespace std;

void print(int* newarr, int c)
{
    for(int i = 0; i<c; ++i)
    {
        cout<<newarr[i]<<' ';
        
    }
    cout<<endl;
}

void pask(int n)
{
    cout<< "1 "<<endl<<"1 1"<<endl;
    int c = 1;
    int* start = new int[c]{1};
    ++c;
    int* array = new int[c]{1,1};
    ++c;
    int* farray = array;
    for(int i = 0; i<n; ++i)
    {
        int* newarr = new int[c];
        
        newarr[0] = 1;
        newarr[c-1] = 1;
        
        for(int j = 1; j<c; ++j)
        {
            newarr[j] = farray[j-1] + farray[j];
        }
        print( newarr,  c);
        farray = newarr;
        ++c;
    }
}

int main() {
int n;
cin>>n;
n=n-2;
pask(n);
}
