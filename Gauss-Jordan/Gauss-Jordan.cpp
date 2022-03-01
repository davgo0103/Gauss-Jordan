#include <iostream>


using namespace std;

void swap(double **p,int *tx, int *ty,int *m,int *n) {
    
    double tmp;
    int tmpx = *tx, tmpy = *ty;
    sw:
    for (int i = tmpy; i < *m; i++) {
        if (p[i][tmpx] != 0) {
            for (int s = tmpx; s < *n; s++) {
                tmp = p[i][s];
                p[i][s] = p[*ty][s];
                p[*ty][s] = tmp;
            }
            return;
        }
    }
    tmpx++;
    *tx = *tx + 1;
    if (tmpx != *n && tmpy != *m) {
        goto sw;
    }
    
}

int main()
{
    int m, n,x=0,y=0;
    double **matrix;


    cout << " 請輸入矩陣大小(m*n):\nm=";
    cin >> m;
    cout << "n=";
    cin >> n;
    matrix = (double**)malloc(m * sizeof(double*));
    cout << "請輸入矩陣:" << endl;
    for (int i = 0; i < m; i++) 
    {
        matrix[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }


    while (true)
    {
        if (matrix[y][x] == 0 && x < n && y < m) { //找出非零整數
            swap(*&matrix, &x, &y, &m, &n);
        }
        break;
    }




    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << x << " " << y;
}
