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

