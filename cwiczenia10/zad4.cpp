#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, r;
    vector <int> L;
    cout << "Podaj n :";
    cin >> n;
    cout << "Podaj r: ";
    cin >> r;

    int temp;
    while(r > 0){
        temp = r % n;
        L.push_back(temp);
        r = r / n;
    }

    while(L.size() != n-2){
        L.push_back(0);
    }

    //for(int i : L){
    //    //i++;
    //    cout << i << " ";
    //}

    cout << endl << "[ ";
    for (int i = L.size()-1; i >= 0; i--){
        L[i] ++;
        cout << L[i] << " ";
    }
    cout << "]";

    return 0;
}