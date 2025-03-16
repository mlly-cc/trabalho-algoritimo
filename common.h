#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char usuario[20];
    char senha[10];
}Login;

typedef struct {
    char CPF[12];
    char nome[30];
    char data_de_nascimento[11];
    char telefone[14];
}Paciente;

typedef struct {
    char CRM[6];
    char nome[50];
    char especialidade[20];
    char data_de_nascimento[11];
    float valor_hora_trabalho;
    char telefone[14];
} Medico;

typedef struct {
    char crm_medico[6];
    char cpf_paciente[12];
    char data[11];
    char sintomas[100];
    char encaminhamentos[100];
} Consulta;
