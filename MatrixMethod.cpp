#include <iostream>
using namespace std;


int main()
{
    cout << "Введіть кількість рівнянь у Вашій системі: ";
    int n;
    cin >> n;
    double arr[n][n * 2];
    double free[n];
    
    cout << "Введіть коефіцієнти перед змінними у Вашій системі рівнянь:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << "Введіть вільні члени: " << endl;
    for(int i = 0; i < n; i++){
        cin >> free[i];
    }



    for(int i = 0; i < n; i++){
        for(int j = n; j < n * 2; j++){
            arr[i][j] = 0;
            if(i == j - n){
                arr[i][j] = 1;
            }
        }
    }

    for(int y = 0; y < n; y++){
        double k = arr[y][y];
        if(k == 0){
            for(int i = y + 1; i < n; i++){
                if(arr[i][y] != 0){
                    for(int j = 0; j < n + y; j++){
                        swap(arr[i][j], arr[y][j]);
                    }
                    swap(free[y], free[i]);
                    k = arr[y][y];
                    break;
                }
            }
        }


        for(int j = 0; j < n * 2; j++){
            arr[y][j] /= k;
        }

        for(int i = y + 1; i < n; i++){
            double k = arr[i][y] * -1;
            for(int j = 0; j < n * 2; j++){
                arr[i][j] += arr[y][j] * k;
            }
        }

        for(int i = 0; i < y; i++){
            double k = arr[i][y] * -1;
            for(int j = 0; j < n * 2; j++){
                arr[i][j] += arr[y][j] * k;
            }
        }
    }
    
    double results[n];


    for(int i = 0; i < n; i++){
        results[i] = 0;
        for(int j = n; j < n * 2; j++){
            results[i] += free[j - n] * arr[i][j];
        }
    }

    
    
    cout << "Розв'язки Вашої системи рівнянь: " << endl;
    for(int i = 0; i < n; i++){
        cout << results[i] << " ";
    }
    
    return 0;
}