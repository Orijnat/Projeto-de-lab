
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QNT_CLIENTES
    int escolha,clientes_listados, clientes_cadastrados, produtos_cadastrados;
    char clientes[10][50];
    char produtos [10][40];


// funçao responsavel por adicionar um cliente no sistema
    void add_cliente(){
        printf("digite o nome do cliente: ");
        scanf("%s", clientes[clientes_cadastrados]);
        clientes_cadastrados++;
        printf("cliente adicionado");
    } 

// funçao responsavel por adicionar produtos ao sistema
    void add_produto(){
        printf("digite o produto que sera adicionado: ");
        scanf("%s", produtos[produtos_cadastrados]);
        produtos_cadastrados++;
        printf("produto cadastrado");
    }

// funçao responsavel por realizar uma venda e gerar uma nota fiscal com os dados utilizados na venda
    void fazer_venda(){
        
    }

// funçao responsavel por listar os clientes ja cadastrados no sistema
   void listar_clientes() {
    for (int i = 0; i < clientes_cadastrados; i++) {
        printf("Listando cliente: %s\n", clientes[i]);
    }
}

// funçao responsavel por listar os produtos ja cadastrados no sistema
    void listar_produtos(){
    for (int i=0; i < produtos_cadastrados; i++)
        printf("listando produtos: %s\n", produtos[i]);
        
    }

// funçao responsavel por excluir um cliente ja cadastrado
    void excluir_cliente(){
     int i = 0;
        printf("escolha qual cliente deseja excluir: ");
        scanf("%d", &i);

        strcpy(clientes[i],  "" );

    

    }
    
    
// inicio da execuçao do codigo
int main()
{
    do{
    printf(" ");
    printf("selecione uma opçao:\n");
    
    printf("0. Para sair.\n");
    printf("1. Para adicionar um cliente.\n");
    printf("2. Para adicionar um produto.\n");
    printf("3. Para realizar uma venda.\n");
    printf("4. Para listar clientes\n");
    printf("5. para listar os produtos. \n");
    printf("6. para excluir um cliente.\n");
    scanf("%d", &escolha);
    
    if (escolha == 1){
        add_cliente();   
    }
    else if(escolha == 2){
        add_produto();
    }
    else if (escolha == 3){
        printf(" venda\n");
    }
    
    
    else if (escolha == 4){
        listar_clientes();
    }
    
    else if (escolha == 5){
        listar_produtos();
    }
    
    else if (escolha == 6){
        excluir_cliente();
    }
    
    else if (escolha ==0){
        printf(" saindo do programa\n");
    }
    
    
    
    } while(escolha > 0);
    
    
    return 0;
}