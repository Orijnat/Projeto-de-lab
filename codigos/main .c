
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QNT_CLIENTES
    int esc,clientes_listados, clientes_cadastrados, produtos_cadastrados;
    char clientes[10][50];
    char produtos [10][40];
    
    
    void add_cliente(){
        printf("digite o nome do cliente: ");
        scanf("%s", clientes[clientes_cadastrados]);
        clientes_cadastrados++;
        printf("cliente adicionado");
    } 
    
    void add_produto(){
        printf("digite o produto que sera adicionado: ");
        scanf("%s", produtos[produtos_cadastrados]);
        produtos_cadastrados++;
        printf("produto cadastrado");
    }
    void fazer_venda(){
        
    }
    
   void listar_clientes() {
    for (int i = 0; i < clientes_cadastrados; i++) {
        printf("Listando cliente: %s\n", clientes[i]);
    }
}

    
    void listar_produtos(){
    for (int i=0; i < produtos_cadastrados; i++)
        printf("listando produtos: %s\n", produtos[i]);
        
    }
    
    void excluir_cliente(){
     int i = 0;
        printf("escolha qual cliente deseja excluir: ");
        scanf("%d", &i);

    }
    
    
    
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
    scanf("%d", &esc);
    
    if (esc == 1){
        add_cliente();   
    }
    else if(esc == 2){
        add_produto();
    }
    else if (esc == 3){
        printf(" venda\n");
    }
    
    
    else if (esc == 4){
        listar_clientes();
    }
    
    else if (esc == 5){
        listar_produtos();
    }
    
    else if (esc== 6){
        excluir_cliente();
    }
    
    else if (esc ==0){
        printf(" saindo do programa\n");
    }
    
    
    
    } while(esc > 0);
    
    
    return 0;
}