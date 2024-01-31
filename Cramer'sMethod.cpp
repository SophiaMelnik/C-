#include <iostream>

using namespace std;

const int n = 3;


void copy_mass(float arr[n][n], float copyArr[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copyArr[i][j] = arr[i][j];
        }
    }
}

float det(float arr[n][n]){
    float det = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i][i] == 0) {
            bool FoundElement = false;
            for (int g = i + 1; g < n; g++) {
                if (arr[g][i] != 0) {
                    FoundElement = true;
                    det = det * -1;
                    for (int f = 0; f < n; f++) {
                        swap(arr[g][f], arr[i][f]);
                    }
                    break;
                }
            }
            if (FoundElement == false) {
                det = 0;
                break;
            }
        }



        for (int j = i + 1; j < n; j++) {
            float temp = arr[j][i] / arr[i][i];
            for (int k = i; k < n; k++) {
                arr[j][k] = arr[j][k] - temp * arr[i][k];
            }
        }

        det = det * arr[i][i];
    }
    return det;
}

void obmin(float arr[n][n], float freemembers[n], int column){
    for (int i = 0; i < n; i++) {
        arr[i][column] = freemembers[i];
    }
}


int main(){
    float arr[n][n];
    float freemembers[n];
    float copyArr[n][n];
    float detArr[n+1];
    
    
    
    
    cout << "Введіть коефіцієнти перед змінними Вашої системи рівнянь:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            copyArr[i][j] = arr[i][j];
        }
    }
    
    
    cout << "Введіть вільні члени Вашої системи рівнянь:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> freemembers[i];
    }
    
    
    detArr[0] = det(copyArr);
    
    if (detArr[0] == 0) {
        cout << "Відповіді немає" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        copy_mass(arr, copyArr);
        obmin(copyArr, freemembers, i);
        detArr[i + 1] = det(copyArr);
    }
    
    
    
    cout << "Розв'язки Вашої системи рівнянь: " << endl;
    for (int i = 1; i < n+1; i++) {
        detArr[i] /= detArr[0];
        cout << "x" << i << " = " << detArr[i] << endl;
    }

    
    return 0;
}

