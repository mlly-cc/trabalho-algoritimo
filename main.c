
int main()
{

  int opcao;
  printf("Digite (1) para efetuar o login e (2) para cadastrar novo usuario e (0) para encerrar)...");
  scanf("%d%*c", &opcao);
  if (opcao == 1) {
        VerificarLogin();
      if(VerificarLogin()==1){
        menu2();
      }  
   }else if (opcao == 2) {
        CadastrarNovoUsuario(); 
       } else if (opcao == 0)
            exit(0);  
 system ("pause");//pausa na tela, somente para Windows
  return(0);
}
