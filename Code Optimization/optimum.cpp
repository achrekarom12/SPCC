#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
 
int main()
{
    // Loop Optimization

    time_t start, end;
    time(&start);
    int m =0, l=12;
    for(long int i=0; i<1000000000; i++){
        l = l + 1;
    }
    for(long int i=0; i<1000000000; i++){
        m = m + 1;
    }
    time(&end);
    
    double time_taken = double(end - start);
    cout << "Time taken by unoptimised loop is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;

    time(&start);
    m =0;
    l=12;
    for(long int i=0; i<1000000000; i++){
        m = m + 1;
        l = l + 1;
    }
    time(&end);
 
    time_taken = double(end - start);
    cout << "Time taken by optimised loop is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl <<endl;

    // Redundant code removal
    int a = 10;
    int b = 20;
    int c = a+b;
    if(c%2 == 0){cout << "You can see me!\n" << endl;}
    else{cout << "You will never see me" << endl;}

    // Loop unrolling
    cout<<"Using Loop\n";
    for(int i=0; i<3; i++){
        cout << "Meow" << endl;
    }
    cout<<"Loop unrolling\n";
    cout<<"Meow\nMeow\nMeow\n";

    return 0;
}

/*
Output:
Time taken by unoptimised loop is : 2.000000 sec 
Time taken by optimised loop is : 1.00000 sec 

You can see me!

Using Loop
Meow
Meow
Meow
Loop unrolling
Meow
Meow
Meow

*/
