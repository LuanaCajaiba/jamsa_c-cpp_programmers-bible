   void WINAPI WriteCompletionRoutine(DWORD dwCdgErro, DWORD dwNumBytesTransf, LPOVERLAPPED pSobreposta) //error here

   

    void WINAPI ReadCompletionRoutine(DWORD dwCdgErro, DWORD dwNumByTesTransf, LPOVERLAPPED pSobreposta){

        PIOREQ pIOReq = (PIOREQ) pSobreposta;//teste
        chASSERT(dwCdgErro == NO_ERROR);
        g_cs.nReadInProgress--;

        //rounds up the number of butes to be recorded in a sector boundary

      dwNumBytesTransfer=(dwNumBytesTrandfer + g_cs.dwPageSize-1) &
            ~(g_cs.dwPageSize-1);
        chVERIFY(WriteFileEx(g_cs.hFileDst, pIOReq->pbData,
        dwNumBytesTransf,
        pSobreposta,
            WriteCompletionRoutine));
            g_cs.nWriteInProgess++
    }


    void WINAPI WriteCompletionRoutine(DWORD dwCdgErro, DWORD dwNumBytesTRansf, LPOVERLAPPED pSobreposta){

       PIOREQ pIOReq = (PIOREQ) pSobreposta;
        chASSERT(dwCdgErro == NO_ERROR);
        g_cs.nWritesInProgress--;

        if (g_cs.ulNextReadOffset.Quadpart < g_cs.ulFileSize.Quadpart)
        {
            pSobreposta->Offset = g_cs.ulNextReadOffser.LowPart;
            pSobreposta->OffsetHigh = g_cs.ulNextReadOffset.HighPart;
            chVERIFY(ReadFileEx(g_cs.hFileSrc, pIOReq->pbData,
                BUFFSIZE, pSobrecarregada, ReadCompletionRoutine));
            g_cs.nReadsInProgress++;
            g_cs.ulNextReadOffset.Quadpart += BUFFSIZE;
        }
        
    }

    