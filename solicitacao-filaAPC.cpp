/*
1. uma função cria um encadeamento
2. o sistema também cria uma fila de mensagem para esse encadeamento, conhecida como a fila Asynchronous Procedure Call (APC, ou Chamada de Procedimento Assíncrono)
3. O sistema operacional usa funções de baixo nível do núcleo para manter a fila APC
4. Essa fila é um método muito rápido e efciente para gerenciar a E/S assíncrona

1. é possível para programas fazerem solicitações de E/S e ter funções que enviam os resultados das solicitações de E/S diretamente para a fila APC do encadeamento chamador.
2. Para enviar solicitações de E/S completas para a fila APC, serão usadas funções ReadFileEx e WriteFileEx

*/


BOOL ReadFileEx(HANDLE hArq, LPVOID lpBuffer,
    DWORD nNumBytesALer, LPOVERLAPPED lpSobreposta,
    LPOVERLAPPED_COMPLETION_ROUTINE lpRotinaFinaliz);

BOOL WriteFileEx(HANDLE hArq, LPCVOID lpBuffer,
    DWORD nMumBytesAGravar, LPOVERLAPPED epSobreposta, LOVERLAPPED_
    COMPETION_ROUTINE_lpRotinaFinaliz);

/*
1. Tanto a ReadFileEx, quando o WriteFileEx possuem em seu último parãmetro o endereço de uma rotina de filanização para executar quando eles completarem o processamento
*/

VOID WINAPI FileIOCompletionRoutine(
    DWORD dwCdgErro,   // código de finalização
    DWORD dwNumBytesTransferidos,  //números de bytes transferidos
    LPOVERLAPPED lpSobreposta //ponteiro para estrutura com informações de Entrada e Saída
);

/*
o parâmetro dwCdgErro especifica o status de finalização da E/S.

As respostas podem ser:

0          A E/S foi bem sucedida
ERROR_HANDLE_EOF     A função tentou ler além do fim do arquivo.


o parâmetro dwNumBytesTransferidos especifica o número de bytes transferidos
se houver um erro, esse parâmetro será 0

o parâmetro lpSobreposta aponta para a estrutura OVERLAPPED que é a função de E/S assíncrona especifica


a função FileIOCompletionRoutine é um marcador de lugar para um nome de função definido pelo aplicativo ou definido pela biblioteca. 
retornar da função FileIOCompletionRoutine permite que o Windows chame outra rotina de finalização de E/S.



*/