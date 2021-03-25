#include <iostream>
#include <random>
using namespace std;
int main()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 16); // fat
    std::uniform_int_distribution<> distr1(0, 16); // fiber
    std::uniform_int_distribution<> distr2(10, 60); // wiek
    std::uniform_int_distribution<> distr3(0, 1); // czy ostre
    int T[6];
    // niech w sumie będzie 60

    for(int n=0; n<10; n++) {
        T[0] = distr2(eng); //wiek
        T[1] = distr(eng);  //fat
        T[2] = distr1(eng);  //fiber
        T[3] = distr3(eng); //sex
        T[4] = 1;   //spicy
        T[5] = 1;   //HTD
        for (int i : T){
            cout << i << ",";
        }
        //cout << distr(eng) << "," << distr(eng);
        cout << endl;
    }
}