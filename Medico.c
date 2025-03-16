#include"Medico.h"

void InserirNovoMedico(){
    Medico medico;
    FILE *ptarqMedico;   
    ptarqMedico = fopen ("Medicos.bin", "ab"); //Se não abriu, cria.
    printf("Digite o crm do medico: ");
    scanf("%[^\n]", medico.CRM);
    printf("Digite o nome do medico: ");
    scanf("%[^\n]", medico.nome);
    printf("Digite a especialidade do medico: ");
    scanf("%[^\n]", medico.especialidade);
    printf("Digite a data de nascimento do medico: ");
    scanf("%[^\n]", medico.data_de_nascimento);
    printf("Digite o valor da hora de trabalho do medico: ");
    scanf("%f", &medico.valor_hora_trabalho);
    printf("Digite o telefone do medico: ");
    scanf("%[^\n]", medico.telefone);
    //Gravando os dados no arquivo usando a função fwrite
    fwrite (&medico, sizeof (Medico), 1, ptarqMedico);
    fclose (ptarqMedico);
}

void BuscarMedicoPorNome(){
  FILE *ptarqMedico;
  Medico medico;
  char nome[30];
  printf("Digite o nome do medico: ");
  scanf("%[^\n]*%c", nome);//pegar o \n mascara
  ptarqMedico = fopen ("Medicos.bin", "rb");
  if (ptarqMedico == NULL){
      printf("Erro ao abrir o arquivo.\n");
      exit(1);    
  }
  while (fread(&medico, sizeof(Medico), 1, ptarqMedico)){
      if (strcmp(nome, medico.nome) == 0) 
          printf("nome: %s\nCRM: %s\nEspecialidade: %s\nData nascimento: %s\nvalor hora de trabalho: %f\ntelefone: %s\n", medico.nome, medico.CRM, medico.especialidade, medico.data_de_nascimento, medico.valor_hora_trabalho, medico.telefone);
  }
      printf("medico nao encontrado");
      fclose(ptarqMedico);
      exit(0);
}

void listarMedicosPorEspecialidade(){
    FILE *ptarqMedico;
    Medico medico;
    char especialidade[20];
    int contaespecialidade = 0;
    printf("Digite a especialidade do medico: ");
    scanf("%[^\n]", especialidade);
        ptarqMedico = fopen ("Medicos.bin", "rb");
        if (ptarqMedico == NULL){
            printf("Erro ao abrir o arquivo.\n");
            exit(1);    
        }
        while (fread(&medico, sizeof(Medico), 1, ptarqMedico)){
            if (strcmp(especialidade, medico.especialidade) == 0) {
                contaespecialidade++;
                printf("nome: %s\nCRM: %s\nEspecialidade: %s\nData nascimento: %s\nvalor hora de trabalho: %f\ntelefone: %s\n", medico.nome, medico.CRM, medico.especialidade, medico.data_de_nascimento, medico.valor_hora_trabalho, medico.telefone);
            }
            printf("especialidade nao encontrada");
        }
    fclose(ptarqMedico);
    return 1;
            
        }

void AlterarDadosMedico(){
        char nomeMedicoAlterar[20];
        Medico newMedico;
        printf("Digite no Nome do Medico que se quer alterar:");
        scanf("%[^\n]%*c", nomeMedicoAlterar);
        //busca no nome no arquivo binário
         FILE *ptarqMedico;   
        ptarqMedico = fopen ("Medicos.bin", "rb+");
        //controle vai armazenar a posição do registro a ser alterado no arquivo
        int controle = 0, achou = 0;
        while(fread(&newMedico, sizeof (Medico), 1, ptarqMedico)){
            if (strcmp(nomeMedicoAlterar, newMedico.nome)==0){
                 printf("dados do medico encontratdo: \nnome: %s\nCRM: %s\nEspecialidade: %s\nData nascimento: %s\nvalor hora de trabalho: %f\ntelefone: %s\n", newMedico.nome, newMedico.CRM, newMedico.especialidade, newMedico.data_de_nascimento, newMedico.valor_hora_trabalho, newMedico.telefone);
            achou = 1;
            break;	  
            }
            controle++;  
          }
         //depois de buscar, lê os dados novos
         if (achou == 1){
            printf("\nInsira os dados novos:");
            printf("\nDigite o nome do medico: ");
            scanf("%[^\n]", newMedico.nome);
            printf("\nDigite a especialidade do medico: ");
            scanf("%[^\n]", newMedico.especialidade);
            printf("\nDigite a data de nascimento: ");
            scanf("%[^\n]", newMedico.data_de_nascimento);
             printf("\nDigite o valor hora de trabalho do medico: ");
             scanf("%[^\n]", newMedico.valo_hora_trabalho);
            printf("\nDigite o telefone: ");
            scanf("%[^\n]", newMedico.telefone);
            //posiciona no registro int fseek(FILE *fp, long numbytes, int origem)
                // SEEK_SET (a partir do inicio do arquivo), SEEK_CUR (a partir da posição atual), SEEK_END (fim do arquivo)
            fseek(ptarqMedico, (controle)*sizeof(Medico), SEEK_SET);

            //grava novos dados
            fwrite (&newMedico, sizeof(Medico), 1, ptarqMedico);
         } else {
            printf("Registro do medico não localizado!!!");
         }
        fclose (ptarqMedico);
    }
