#ifndef __RT64_LAYER_H__
#define __RT64_LAYER_H__

typedef struct {
    unsigned char* HEADER;  /* This is the rom header (first 40h bytes of the rom) */
    unsigned char* RDRAM;
    unsigned char* DMEM;
    unsigned char* IMEM;

    unsigned int* MI_INTR_REG;

    unsigned int* DPC_START_REG;
    unsigned int* DPC_END_REG;
    unsigned int* DPC_CURRENT_REG;
    unsigned int* DPC_STATUS_REG;
    unsigned int* DPC_CLOCK_REG;
    unsigned int* DPC_BUFBUSY_REG;
    unsigned int* DPC_PIPEBUSY_REG;
    unsigned int* DPC_TMEM_REG;

    unsigned int* VI_STATUS_REG;
    unsigned int* VI_ORIGIN_REG;
    unsigned int* VI_WIDTH_REG;
    unsigned int* VI_INTR_REG;
    unsigned int* VI_V_CURRENT_LINE_REG;
    unsigned int* VI_TIMING_REG;
    unsigned int* VI_V_SYNC_REG;
    unsigned int* VI_H_SYNC_REG;
    unsigned int* VI_LEAP_REG;
    unsigned int* VI_H_START_REG;
    unsigned int* VI_V_START_REG;
    unsigned int* VI_V_BURST_REG;
    unsigned int* VI_X_SCALE_REG;
    unsigned int* VI_Y_SCALE_REG;

    void (*CheckInterrupts)(void);

    unsigned int version;
    unsigned int* SP_STATUS_REG;
    const unsigned int* RDRAM_SIZE;
} GFX_INFO;

#define DLLEXPORT extern "C" __declspec(dllexport)  
#define DLLIMPORT extern "C" __declspec(dllimport)
#define CALL   __cdecl

// Dynamic loading
//DLLEXPORT int (CALL *InitiateGFX)(GFX_INFO Gfx_Info) = nullptr;
//DLLEXPORT void (CALL *ProcessRDPList)(void) = nullptr;
//DLLEXPORT void (CALL *ProcessDList)(void) = nullptr;
//DLLEXPORT void (CALL *UpdateScreen)(void) = nullptr;
//DLLEXPORT void (CALL *PumpEvents)(void) = nullptr;

DLLIMPORT int InitiateGFX(GFX_INFO Gfx_Info);
DLLIMPORT void ProcessRDPList(void);
DLLIMPORT void ProcessDList(void);
DLLIMPORT void UpdateScreen(void);
DLLIMPORT void PumpEvents(void);

#endif
