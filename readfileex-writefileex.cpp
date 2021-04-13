Bool ReadFileEx(
    HANDLE hArq,    //indicativo do arquivo a ler
    LPVOID lpBuffer,    //endereço do buffer
    DWORD nNumBytesALer,    // números de bytes a ler
    LPOVERLAPPED lsSobreposta,  //endereço do deslocamento
    LPOVERLAPPED_COMPLETION_ROUTINE
    lpRotinaFinalizacao    //endereço da rotina de finalização

);

