/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include<stdio.h>
#include<stdlib.h>

int trataString(char *);//A função que receberá a string inserida e retornará a quantidade de palavras na mesma.

int main(){
  int QtdPalavras = 0, resultado = 0;
  char *str = NULL;//O ponteiro para array de caracteres que guardará nossa string.

  scanf("%[^\n]", str);//Recebemos a string de entrada até ser inserido o caractere de quebra de linha.
  
  if(str != NULL) resultado = trataString(str);//Somente chama a função se a string str não estiver VAZIA (quando o usuário não insere nenhuma palavra e clica enter).
  
  printf("%d\n", resultado);
  
  return 0;
}

/**
 * Esta função conta e retorna o número de palavras em uma frase.
 * Retorna -1 se a entrada for nula.
 */
int trataString(char *str){
  int i = 0;
  int QtdPalavras = 0;
  char ultimo = -1, penultimo = -1;//Guardam os valores dos ultimos caracteres analisados para serem utilizados em condiçes de contorno. Iniciam com valor -1 para não serem confundidos com nenhum caractere antes de serem realmente preenchidos pela entrada de texto.
  
  if(str == NULL) return -1;
  
  for(i = 0; str[i] != '\0'; i++){
    
    if(conjunto(str[i]) == 0 && conjunto[ultimo] != 0){//Se estamos sobre um separador e o caractere anterior não era separador, conte mais uma palavra.
      
      QtdPalavras++;
      
    }
      
    if(conjunto(str[i]) == 1 && (ultimo == '.' || ultimo == ',') && conjunto[penultimo] == 1){//Esta condição indica que passamos por um número de ponto flutuante.
      
      QtdPalavras--;//Os algarismos de um ponto flutuante serão contados como duas palavras quando deveriam ser apenas uma. Nesta linha, descontamos este erro.
      
    }
    
    //Atualizando os caracteres.
    penultimo = ultimo;
    ultimo = str[i];
    
  }
  
  //Se a frase não terminou com um ponto, possivelmente, nao teremos contado a última palavra. Aqui verificamos e corrigimos isso.
  if(conjunto(ultimo) == 2 || conjunto(ultimo) == 1) QtdPalavras++;
  
  return QtdPalavras;
  
}

/**
 * Esta função verifica a qual conjunto de caracteres o dado argumento pertence.
 * Retorna 2, se for uma letra, 1, se for um número, e 0 (zero) se for qual-
 * quer outro caractere (separador).
 */
int conjunto(char c){
  
  if('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z') return 2;
  
  if('0' <= c && c <= '9') return 1;
  
  return 0;
}
