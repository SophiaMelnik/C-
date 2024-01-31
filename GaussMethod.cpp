
#include <iostream>

using namespace std;


int main() {
	int n;
	cout << "Введіть кількість рівнянь у Вашій системі: ";
	cin >> n;
	int m = n + 1;
	
	double arr[n][n+1];
	
	cout << "Введіть коефіцієнти перед змінними:" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << "Введіть вільні члени: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][n];
	}
	
	for (int y = 0; y < n; y++) {
		double k = arr[y][y];
		while (k == 0) {
			for (int i = y + 1; i < n; i++) {
				if (arr[i][y] != 0) {
					for (int j = 0; j < m; j++) {
						double temp = arr[i][j];
						arr[i][j] = arr[y][j];
						arr[y][j] = temp;
					}
				}
			}
			k = arr[y][y];
		}
		for (int i = 0; i < m; i++) {
			arr[y][i] /= k;
		}
		for (int i = y + 1; i < n; i++) {
			double k = arr[i][y] * -1;
			for (int j = 0; j < m; j++) {
				double item = arr[y][j] * k;
				arr[i][j] += item;
			}
		}
		for (int i = 0; i < y; i++) {
			double k = arr[i][y] * -1;
			for (int j = 0; j < m; j++) {
				double item = arr[y][j] * k;
				arr[i][j] += item;
			}
		}

	}

    cout << "Розв'язки даної системи лінійних рівнянь: " << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i][n] == 0) {
			cout << 0 << " " << endl;
		}
		else {
			cout << arr[i][n] << " " << endl;
		}
	}

}