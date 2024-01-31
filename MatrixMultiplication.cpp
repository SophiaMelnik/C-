#include <iostream>
using namespace std;

int main()
{
    int m;
    int n;
    cout << "Введіть кількість рядків матриці А: ";
    cin >> m;
    cout << "Введіть кількість стовпців матриці А: ";
    cin >> n;
    int A[m][n];
    int number;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> number;
            A[i][j] = number;
        }
    }
    int k;
    int q;
    cout << "Введіть кількість рядків матриці В: ";
    cin >> k;
    cout << "Введіть кількість стовпців матриці В: ";
    cin >> q;
    int B[k][q];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < q; j++){
            cin >> number;
            B[i][j] = number;
        }
    }
    
    int C[m][q];
    if(n!=k){
        cout << "Дію виконати неможливо";
        return 0;
    }else{
        for(int i = 0; i < m; i++){
            for(int j = 0; j < q; j++){
                C[i][j] = 0;
                for(int k = 0; k < n; k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }
    
    cout << "Отримуємо матрицю: " << endl;
    cout << m << " " << q << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

