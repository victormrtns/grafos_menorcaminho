#include <stdio.h>


int menor_caminho(int n, int matriz[][20],int a, int b);
void ligar(int ponto1,int ponto2, int matriz[][20]);
void produto_bool(int matrizadj[][20], int matriz[][20], int novamatrizadj[][20], int n);

int main(){
    const int n = 20;
    int a,b,i,j;
    int ponto1,ponto2;
    int matrizadj[n][n];
    //Digitar de onde até onde deseja chegar
    printf("Digite o destino [a-b]:  ");
    scanf("%d %d",&a,&b);
    //Inicializar a matriz como 0
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizadj[i][j] = 0;
        }
    }
    printf("Insira os pontos que você deseja ligar: ");
    ponto1 = 1;
    while(ponto1!=0){
        scanf("%d",&ponto1);
        if(ponto1 ==0)
            break;
        scanf("%d",&ponto2);
    
        ligar(ponto1,ponto2, matrizadj);
    }
    //Passa matrizadj, numero de nos, a e b como parametro
    menor_caminho(n,matrizadj,a,b);
}

int menor_caminho(int n, int matriz[][20],int a, int b){
    //cria a matrizadj que vai ser a matriz que é usada para comparação com a matriz passada por parâmetro.
    //E a matriz novamatrizadj que é uma matriz auxiliar.
    int matrizadj[n][n];
    int novamatrizadj[n][n];
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //Atribuir matriz recebida com a matrizadj criada e inicializar a novamatrizadj com 0.
            matrizadj[i][j] = matriz[i][j];
            novamatrizadj[i][j] = 0;
        }
    }
    int l;
    //Esse for serve para calcular o produto booleano de adj(l-1) (matrizadj) com adj1.
    for(l = 1;l<=n;l++){
        if(matrizadj[a][b] == 1){
            printf("Do ponto a ate o ponto b, existe um caminho de comprimento %d",l);
            return 1;
        }

        produto_bool(matrizadj, matriz, novamatrizadj, n);
        
        
    }
    printf("Não existe caminho do ponto a até o ponto b");
    return 0;
}

void ligar(int ponto1,int ponto2, int matriz[][20]){
    matriz[ponto1][ponto2] = 1;
}

void produto_bool(int matrizadj[][20], int matriz[][20], int novamatrizadj[][20], int n){
    //Recebe a matrizadj que é a matriz adj(l-1), a matriz original e a novamatrizadj que é a auxiliar que vai achar a nova matriz caminho.
    int valor;
    int i,j,k;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //Usa essa variável auxiliar
            valor = 0;
            for(k=0;k<n;k++){
            //Se a matriz original na pos [i][k] ==1 e a matrizadj (l-1) na pos[k][j] == 1, significa que tem caminho
            // na novamatrizadj(l)[i][j] == 1
                if((matriz[i][k] && matrizadj[k][j]) == 1){
                    valor = 1;
                    break;
                }
            }
            novamatrizadj[i][j] = valor;
        }
    }
//Esse for serve pra transformar a antiga matrizadj(l-1) na matrizadj(l) recebendo a matriz auxiliar novamatrizadj e sendo utilizada na func.
//principal
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrizadj[i][j] = novamatrizadj[i][j];
        }
    }

    
}