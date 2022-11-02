#include<iostream>
using namespace std;

void update(int n)
{
    n++;
}

//pass by refrance
void update2(int &n)
{
    n++;
}


int main()
{   
    // Printing Hello World
    cout<<endl<<"Hello World"<<endl;

    int n = 0;

    // refrance variable 
    int &refVar = n;

    update(n);
    cout<<n<<endl;

    update2(n);
    cout<<n<<endl;

    return 0;
}