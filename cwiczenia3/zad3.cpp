#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, r;
    vector <int> v;
    vector <int> w;

    cout << "Podaj zakres n: ";
    cin >> n;
    cout << "Podaj rank r: ";
    cin >> r;

    int pom = r;
    while(pom > 0){
        v.push_back(pom % 2);
        pom = pom/2;
    }
    r = r / 2;
    pom = r;
    while(pom > 0){
        w.push_back(pom % 2);
        pom = pom/2;
    }

    /*for(int i : v){
        cout << i << " ";
    }
    cout << endl;
    for(int i : w){
        cout << i << " ";
    }*/

    int s, ss;
    if(v.size() > w.size()){
        s = v.size();
        ss = w.size();
    }
    else{
        s = w.size();
        ss = v.size();
    }

    int R[s], R2[s], T[s];
    for (int i = 0; i < s; i++){
        R[i] = 0;
        R2[i] = 0;
        T[i] = 0;
    }
    int j = 0;
    int c;
    while(!v.empty()){
        c = v.back();
        R[j] = c;
        j++;
        v.pop_back();
    }
    j = s - ss;
    while(!w.empty()){
        c = w.back();
        R2[j] = c;
        j++;
        w.pop_back();
    }
    cout << endl;
    for (int i = 0; i < s; i++){
        cout << R[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < s; i++){
        cout << R2[i] << " ";
    }
    cout << endl;
    for( int i = 0; i < s; i++){
        if(R[i] == R2[i]){
            T[i] = 0;
        }
        else{
            T[i] = 1;
        }
        cout << T[i] << " ";
    }
    cout << endl;
    cout << "{ ";
    for (int i = 0; i < s; i++){
        if(T[i] == 1) cout << i+1 << " ";
    }
    cout << "}";



    return 0;
}

