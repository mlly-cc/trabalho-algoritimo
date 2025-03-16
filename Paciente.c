#include "Paciente.h"

void InserirNovoPaciente(){
 Paciente pacientes;
    FILE *ptarqPaciente;   
    ptarqPaciente = fopen ("Pacientes.bin", "ab"); //Se não abriu, cria.
    printf("Digite o cpf do paciente: ");
    scanf("%[^\n]", pacientes.CPF);
    printf("Digite o nome do paciente: ");
    scanf("%[^\n]", pacientes.nome);
    printf("Digite a data de nascimento do paciente: ");
    scanf("%[^\n]", pacientes.data_de_nascimento);
    printf("Digite o telefone do paciente: ");
    scanf("%[^\n]", pacientes.telefone);
    //Gravando os dados no arquivo usando a função fwrite
    fwrite (&pacientes, sizeof (Paciente), 1, ptarqPaciente);
    fclose (ptarqPaciente);
}

void BuscarPacientePorNome(){
    FILE *ptarqPaciente;
    Paciente pacientes;
    char nome[30];
    printf("Digite o nome do paciente: ");
    scanf("%[^\n]", nome);
    ptarqPaciente = fopen ("Pacientes.bin", "rb");
        if (ptarqPaciente == NULL){
            printf("Erro ao abrir o arquivo.\n");
            exit(1);    
        }

        while (fread(&pacientes, sizeof(Paciente), 1, ptarqPaciente)){
            if (strcmp(nome, pacientes.nome) == 0) 
                printf("nome: %s\nCPF: %s\nData nascimento: %s\ntelefone: %s\n", pacientes.nome, pacientes.CPF, pacientes.data_de_nascimento, pacientes.telefone);
            printf("paciente nao encontrado");
        }
        fclose(ptarqPaciente);   
        }

void AlterarDadosPaciente(){
        char nomeAlterar[20];
        Paciente newPaciente;
        printf("Digite no Nome do paciente que se quer alterar:");
        scanf("%[^\n]%*c", nomeAlterar);
        //busca no nome no arquivo binário
         FILE *ptarqPaciente;   
        ptarqPaciente = fopen ("Pacientes.bin", "rb+");
        //controle vai armazenar a posição do registro a ser alterado no arquivo
        int controle = 0, achou = 0;
        while(fread(&newPaciente, sizeof (Paciente), 1, ptarqPaciente)){
            if (strcmp(nomeAlterar, newPaciente.nome)==0){
              printf("Dados Encontrados: \n Nome: %s, CPF: %s, data de nascimento: %s, telefone: %s", newPaciente.nome , newPaciente.CPF, newPaciente.data_de_nascimento, newPaciente.telefone);
              achou = 1;
              break;	  
              }
            controle++;  
          }
         //depois de buscar, lê os dados novos
         if (achou == 1){
           printf("\nInsira os dados novos: Nome, Data de nascimento e telefone");
           printf("\nDigite o nome do paciente: ");
            scanf("%[^\n]", newPaciente.nome);
            printf("\nDigite a data de nascimento: ");
            scanf("%[^\n]", &newPaciente.data_de_nascimento);
            printf("\nDigite o telefone: ");
            scanf("%[^\n]", &newPaciente.telefone);
            //posiciona no registro int fseek(FILE *fp, long numbytes, int origem)
                // SEEK_SET (a partir do inicio do arquivo), SEEK_CUR (a partir da posição atual), SEEK_END (fim do arquivo)
            fseek(ptarqPaciente, (controle)*sizeof(Paciente), SEEK_SET);

            //grava novos dados
            fwrite (&newPaciente, sizeof(Paciente), 1, ptarqPaciente);
         } else {
            printf("Registro não localizado!!!");
         }
        fclose (ptarqPaciente);

    }
           
