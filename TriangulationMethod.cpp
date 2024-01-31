#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Введіть розмір квадратної матриці: ";
    cin >> n;
    
    double arr[n][n];
    
    cout << "Введіть елементи квадратної матриці:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    
    double det = 1;
    
    for (int i = 0; i < n; i++) {
        
        if(arr[i][i] == 0){
            bool FoundElement = false;
            for(int g = i + 1; g < n; g++){
                if(arr[g][i] != 0){
                    FoundElement = true;
                    det = det * -1;
                    for(int f = 0; f < n; f++){
                        swap(arr[g][f], arr[i][f]);
                    }
                    break;
                }
            }
            
            if(FoundElement == false){
                det = 0;
                break;
            }
        }
        
       
        for (int j = i + 1; j < n; j++) {
            double temp = arr[j][i] / arr[i][i];
            for (int k = i; k < n; k++) { 
                arr[j][k] = arr[j][k] - temp * arr[i][k];
            }
        }

        det = det*arr[i][i];
    }
    
   
    cout << "Визначник Вашої матриці: " << det << endl;
    


    
    return 0;
}
