// C++ Design Patterns and Derivatives Pricing---Listing 1.1, page 20

/*
requires
    PayOff2.cpp
    Random1.cpp,
    SimpleMC2.cpp,
*/
#include "SimpleMC2.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // double time = clock();

    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);

    cout <<"the prices are " 
        << resultCall <<" for the call, and " 
        << resultPut << " for the put.\n";

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}