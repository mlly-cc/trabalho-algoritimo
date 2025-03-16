#include "Consulta.h"
void InserirNovaConsulta(){
Consulta consulta;
    FILE *ptarqConsulta;   
    ptarqConsulta = fopen ("Consultas.bin", "ab"); //Se não abriu, cria.
    if (ptarqConsulta == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    printf("Digite o crm do medico: ");
    scanf("%[^\n]", consulta.crm_medico);
    printf("Digite o cpf do paciente: ");
    scanf("%[^\n]", consulta.cpf_paciente);
    printf("Digite a data: ");
    scanf("%[^\n]", consulta.data);
    printf("Digite os sintomas: ");
    scanf("%[^\n]", consulta.sintomas);
    printf("Digite o encaminhamento: ");
    scanf("%[^\n]", consulta.encaminhamentos);
    //Gravando os dados no arquivo usando a função fwrite
    fwrite (&consulta, sizeof (Consulta), 1, ptarqConsulta);
    fclose (ptarqConsulta);
}
