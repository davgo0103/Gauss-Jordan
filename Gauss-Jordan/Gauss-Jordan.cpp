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
void operation(double** p, int* tx, int* ty, int* m, int* n) {
    int tmpy = *ty; 
    double leader = p[tmpy][*tx];
    if (leader != 0) { 
        for (int i = *tx; i < *n; i++) { //取得前導1
            if (leader != 1) {
                p[tmpy][i] = p[tmpy][i] / leader;
            }
            else {
                break;
            }
        }
        up(p, tx, ty, m, n);
        down(p, tx, ty, m, n);
    }
    
    *ty = *ty + 1;
}


void up(double** p, int* tx, int* ty, int* m, int* n) {
    int tmpx = *tx, tmpy = *ty;
    
}

void down(double** p, int* tx, int* ty, int* m, int* n) {
    int tmpx = *tx, tmpy = *ty;
}

void print(double** p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
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
        operation(*&matrix, &x, &y, &m, &n);

        

            if (x + 1 > n || y + 1 > m) {
            break;
        }
    }

    print(*&matrix, m, n);
    cout << x << " " << y;
}
