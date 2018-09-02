#include <iostream>

using namespace std;

int main()
{
    int x[4][3] = {{0, 0, 1}, {1, 1, 0}, {0, 0, 1}, {1, 1, 0}};//entradas para treinar a rede
    int d[4] = {-1, 1, -1, 1}; //valores desejados para cada padrão de entradas
    float w[3] = {0.4,-0.6,0.6};
    float limiar = 0.5;
    float n = 0.4; //taxa de aprendizado
    float u;
    float y;
    for(int i = 0;i < 4;i++){
        cout << "---pesos---" << endl;
        cout << "w0 = " << w[0] << ", w1 = " << w[1] << ", w2 = " << w[2] << endl;
        cout << "---entradas---" << endl;
        cout << x[i][0] << " , " << x[i][1] << " , " << x[i][2]<< endl;
        u = w[0]*x[i][0] + w[1]*x[i][1] + w[2]*x[i][2] + -limiar;
        cout << "d = " << d[i] << endl;
        cout << "u = " << u << endl;
        cout << "limiar = " << limiar << endl;
        if(u >= 0){
            y = 1;
            cout << "Saída: y = " << y << endl;
        }
        else if (u < 0) {
            y = -1;
            cout << "Saída: y = " << y << endl;
        }
        //atualizando os pesos
        for(int j = 0;j < 3; j++){
            w[j] = w[j] + n*x[i][j]*(d[i] - y);
        }
        limiar = limiar + (-1)*n*(d[i] - y);
    }
    return 0;
}
