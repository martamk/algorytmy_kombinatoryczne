#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, temp, x;
    vector<int> ciag;

    cout << "Podaj n" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ciag.push_back(0);
    }
    cout << endl;

    temp = n-1;
    int dl = 0;

    for(int u = 0; u <= n; u++){
        dl = 0;
        temp = n-1;
        ciag.clear();
        for (int i = 0; i < n; i++) {
            ciag.push_back(0);
        }

        do {
            for(int q = 0; q < n; q++){
                dl = dl + ciag[q];
            }
            //cout << dl << " " << u << endl;
            if(dl == u){
                cout << "[";
                for (int i = 0; i < n; i++) {
                    if (ciag[i] == 1) {
                        cout << i + 1;
                    }
                }
                cout << "]" << endl;
            }
            for (temp; temp >= 0; temp--) {
                if (ciag[temp] == 0) {
                    ciag[temp] = 1;
                    x = temp + 1;
                    temp = n-1;
                    break;
                }
            }

            for (x; x < n; x++) {
                ciag[x] = 0;
            }
            dl = 0;

        } while (temp > 0);

    }
    return 0;
}
