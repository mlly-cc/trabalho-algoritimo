#include "Login.h"

void CadastrarNovoUsuario(){
 Login login;
    FILE *ptarqLogin;   
    ptarqLogin = fopen ("Login.bin", "ab"); //Se não abriu, cria.
    printf("Digite o usuario: ");
    scanf("%[^\n]", login.usuario);
    printf("Digite a senha: ");
    scanf("%[^\n]", login.senha);
    //Gravando os dados no arquivo usando a função fwrite
    fwrite (&login, sizeof (Login), 1, ptarqLogin);
    fclose (ptarqLogin);
}

int VerificarLogin() {
    Login login;
    FILE *ptarqLogin;
    char usuario[20];
    char senha[10];
    ptarqLogin = fopen ("Login.bin", "rb");
    if (ptarqLogin == NULL) {
        printf("Erro ao abrir o arquivo de login.\n");
        exit (0);
    }
   // Login usuarioCadastro;
    int tentativas = 3;
    while (tentativas > 0){
        printf("Digite o nome de usuario: ");
        scanf("%s", usuario);
        printf("Digite a senha: ");
        scanf("%s", senha);
        int encontrado = 0;
        while (fread(&login, sizeof(Login), 1, ptarqLogin)) {
            if (strcmp(usuario, login.usuario) == 0 && strcmp(senha, login.senha) == 0) 
            printf("Login efetuado com sucesso!\n");
            }
    tentativas--;
    }
    if (tentativas > 0) {
        printf("Login ou senha invalidos. Voce tem mais %d tentativa(s).\n", tentativas);
    } else {
        printf("Login ou senha invalidos. Numero maximo de tentativas excedido.\n");
    }
    fclose(ptarqLogin);
        exit(0);
    }

                  //  rewind(file); // Reinicia a leitura do arquivo para nova tentativa
void menu2(){
    int opcao2;
    int opcao3;        
    int opcao4;
    int opcao5;
    printf("Digite (1) paciente \n (2) medico \n (3) consulta \n (0) para encerrar)...");
    scanf("%d%*c", &opcao2);
    if (opcao2 == 1) {
        printf("Digite (1) para cadastrar novo paciente \n (2) buscar paciente(nome) e exibir \n (3) alterar dados do paciente(exceto o CPF)\n (0) para encerrar)...");
        scanf("%d%*c", &opcao3);
        if (opcao3 == 1) {
            InserirNovoPaciente();
        }else if (opcao3 == 2) {
            BuscarPacientePorNome(); 
            } else if (opcao3 == 3) {
                AlterarDadosPaciente(); 
                } else if (opcao3 ==0)
                    exit(0);   
   }

   else if (opcao2 == 2) {
        printf("Digite (1) para cadastrar novo medico \n (2) buscar medico(nome) e exibir \n (3) listar medicos de x especialidade \n (4) alterar dados do medico(exceto o CRM)\n (0) para encerrar)...");
        scanf("%d%*c", &opcao4);
        if (opcao4== 1) {
            InserirNovoMedico();
        }else if (opcao4 == 2) {
            BuscarMedicoPorNome(); 
            } else if (opcao4 == 3) {
                ListarMedicosPorEspecialidade(); 
                } else if (opcao4 == 4) {
                    AlterarDadosMedico(); 
                    } else if (opcao4 ==0)
                        exit(0);   
        }

        else if (opcao2 == 3) {
        printf("Digite (1) para cadastrar uma nova consulta \n (2) listar todas consultas de um medico \n (3) listar consultas de um paciente \n (4) listar consultas de um dia\n (0) para encerrar)...");
        scanf("%d%*c", &opcao5);
        if (opcao5== 1) {
            InserirNovaConsulta();
        }else if (opcao5 == 2) {
            ListarConsultasPorMedico(); 
            } else if (opcao5 == 3) {
                ListarConsultasPorPaciente(); 
                } else if (opcao5 == 4) {
                    ListarConsultasPorData(); 
                    } else if (opcao5 ==3)
                        exit(0);   
        }  
// system ("pause");//pausa na tela, somente para Windows
}



