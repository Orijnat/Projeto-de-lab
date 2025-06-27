
#include <stdio.h>
#include <string.h>
#include "structs.h"

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Venda vendas[MAX_VENDAS];

int total_vendas = 0, total_produtos = 0, total_clientes = 0, escolha;

// funçao responsavel por adicionar um cliente no sistema
    void add_cliente(){
        if (total_clientes < MAX_CLIENTES) {
            Cliente c;
            c.id = total_clientes + 1;
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", c.nome);

            printf("Informe o CPF do cliente: ");
            scanf(" %14s", c.cpf);

            clientes[total_clientes++] = c;
            printf("Cliente cadastrado com ID %d\n", c.id);

        } else {
            printf("Limite de clientes atingido.\n");
        }
    } 

// funçao responsavel por adicionar produtos ao sistema
    void add_produto(){
        if (total_produtos < MAX_PRODUTOS) {
            Produto p;
            p.id = total_produtos + 1;

            printf("Informe o nome do produto: ");
            scanf(" %[^\n]", p.nome);

            printf("Preço por unidade do produto: ");
            scanf("%f", &p.preco);

            printf("Estoque do produto: ");
            scanf("%d", &p.estoque);

            produtos[total_produtos++] = p;
            printf("Produto cadastrado com ID %d\n", p.id);
        } else {
            printf("Limite de produtos atingido.\n");
        }
    }

// funçao responsavel por realizar uma venda e gerar uma nota fiscal com os dados utilizados na venda
    void fazer_venda(){
       if (total_vendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido.\n");
        return;
    }

    Venda v;
    v.id = total_vendas + 1;

    printf("ID do cliente: ");
    if (scanf("%d", &v.cliente_id) != 1) {
        printf("Entrada inválida! Retornando ao menu...\n");
        while (getchar() != '\n');
        return;
    }

    int cliente_existe = 0;
    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].id == v.cliente_id) {
            cliente_existe = 1;
            break;
        }
    }
    if (!cliente_existe) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Data da venda (DD/MM/AAAA): ");
    scanf(" %10s", v.data);

    printf("Quantos itens na venda? ");
    if (scanf("%d", &v.total_itens) != 1 || v.total_itens <= 0 || v.total_itens > MAX_ITENS_VENDA) {
        printf("Quantidade inválida. Retornando ao menu...\n");
        while (getchar() != '\n');
        return;
    }

    v.total = 0;
    for (int i = 0; i < v.total_itens; i++) {
        int pid, qtd;
        printf("ID do produto %d: ", i + 1);
        if (scanf("%d", &pid) != 1) {
            printf("ID inválido. Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        Produto *p = NULL;
        for (int j = 0; j < total_produtos; j++) {
            if (produtos[j].id == pid) {
                p = &produtos[j];
                break;
            }
        }

        if (!p) {
            printf("Produto não encontrado.\n");
            i--; // volta para repetir este item
            continue;
        }

        printf("Quantidade: ");
        if (scanf("%d", &qtd) != 1 || qtd <= 0) {
            printf("Quantidade inválida. Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        if (qtd > p->estoque) {
            printf("Estoque insuficiente!\n");
            i--;
            continue;
        }

        v.itens[i].produto_id = pid;
        v.itens[i].quantidade = qtd;
        v.itens[i].valor_unitario = p->preco;
        v.total += qtd * p->preco;

        p->estoque -= qtd;
    }

    vendas[total_vendas++] = v;

    printf("Venda registrada! Total da venda: R$ %.2f\n", v.total);
}


// funçao responsavel por listar os clientes ja cadastrados no sistema
   void listar_clientes() {
        if (total_clientes == 0) {

            printf("Nenhum cliente cadastrado.\n");
            return;
        }
        for (int i = 0; i < total_clientes; i++) {
            printf("ID: %d | Nome: %s | CPF: %s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
        }
    }

// funçao responsavel por listar os produtos ja cadastrados no sistema
    void listar_produtos() {
        if (total_produtos == 0) {
            printf("Nenhum produto cadastrado.\n");
            return;
        }

        for (int i = 0; i < total_produtos; i++) {
            printf("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n",
                   produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].estoque);
        }
    }

// Funcao que lista todoas as vendas ja efetuadas
    void listar_vendas() {
        if (total_vendas == 0) {
            printf("Nenhum venda realizada.\n");
            return;
        }
        for (int i = 0; i < total_vendas; i++) {
            Venda *v = &vendas[i];
            printf("\nVenda ID: %d | Cliente ID: %d | Data: %s | Total: R$ %.2f\n", v->id, v->cliente_id, v->data, v->total);
            for (int j = 0; j < v->total_itens; j++) {
                printf("  Produto ID: %d | Quantidade: %d | Valor por item: R$ %.2f\n",
                       v->itens[j].produto_id, v->itens[j].quantidade, v->itens[j].valor_unitario);
            }
        }
    }

// atualiza os dados do cliente selecionado
    void atualizar_cliente() {
        int id;
        printf("Informe o ID do cliente a ser atualizado: ");

        if (scanf("%d", &id) != 1) {
            printf("Entrada inválida! Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        int encontrado = 0;
        for (int i = 0; i < total_clientes; i++) {
            if (clientes[i].id == id) {
                printf("Cliente encontrado: %s (CPF: %s)\n", clientes[i].nome, clientes[i].cpf);
                printf("Novo nome: ");
                scanf(" %[^\n]", clientes[i].nome);
                printf("Novo CPF: ");
                scanf(" %14s", clientes[i].cpf);
                printf("Cliente atualizado com sucesso!\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Cliente com ID %d não encontrado.\n", id);
        }
    }

//atualiza os dados dos produtos inseridos no programa
void atualizar_produto() {
        int id;
        printf("Informe o ID do produto a ser atualizado: ");
        if (scanf("%d", &id) != 1) {
            printf("Entrada inválida! Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        int encontrado = 0;
        for (int i = 0; i < total_produtos; i++) {
            if (produtos[i].id == id) {
                printf("Produto: %s | Preço: R$ %.2f | Estoque: %d\n",
                       produtos[i].nome, produtos[i].preco, produtos[i].estoque);
                printf("Novo nome: ");
                scanf(" %[^\n]", produtos[i].nome);
                printf("Novo preço: ");
                scanf("%f", &produtos[i].preco);
                printf("Nova quantidade em estoque: ");
                scanf("%d", &produtos[i].estoque);
                printf("Produto atualizado com sucesso!\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Produto com ID %d não encontrado.\n", id);
        }
    }

//exclui o produto selecionado do sistema
void excluir_produto() {
        int id;
        printf("Informe o ID do produto a ser excluído: ");
        if (scanf("%d", &id) != 1) {
            printf("Entrada inválida! Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        int encontrado = 0;
        for (int i = 0; i < total_produtos; i++) {
            if (produtos[i].id == id) {
                encontrado = 1;
                for (int j = i; j < total_produtos - 1; j++) {
                    produtos[j] = produtos[j + 1];
                }
                total_produtos--;
                printf("Produto excluído com sucesso!\n");
                break;
            }
        }

        if (!encontrado) {
            printf("Produto com ID %d não encontrado.\n", id);
        }
    }

// funçao responsavel por excluir um cliente ja cadastrado
    void excluir_cliente(){
        int id;
        printf("Informe o ID do cliente a ser excluído: ");

        if (scanf("%d", &id) != 1) {
            printf("Entrada inválida! Retornando ao menu...\n");
            while (getchar() != '\n');
            return;
        }

        int encontrado = 0;
        for (int i = 0; i < total_clientes; i++) {
            if (clientes[i].id == id) {
                encontrado = 1;
                for (int j = i; j < total_clientes - 1; j++) {
                    clientes[j] = clientes[j + 1];  // move os próximos para preencher o "buraco"
                }
                total_clientes--;
                printf("Cliente excluído com sucesso!\n");
                break;
            }
        }

        if (!encontrado) {
            printf("Cliente com ID %d não encontrado.\n", id);
        }
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
    printf("6. Para listar as vendas.\n");
    printf("7. para atualizar um cliente.");
    printf("8. Para atualizar os produtos.\n");
    printf("9. Para excluir um produto.\n");
    printf("10. para excluir um cliente.\n");
    scanf("%d", &escolha);
    
    if (escolha == 1){
        add_cliente();   
    }
    else if(escolha == 2){
        add_produto();
    }

    else if (escolha == 3){
        fazer_venda();
    }

    else if (escolha == 4){
        listar_clientes();
    }
    
    else if (escolha == 5){
        listar_produtos();
    }
    
    else if (escolha == 6){
        listar_vendas();
    }

    else if (escolha == 7) {
        atualizar_cliente();
    }

    else if (escolha == 8) {
        atualizar_produto();
    }

    else if (escolha == 9) {
        excluir_produto();
    }

    else if (escolha ==10) {
        excluir_cliente();
    }
    
    else if (escolha ==0){
        printf(" saindo do programa\n");
    }
    

    } while(escolha > 0);
    
    
    return 0;
}