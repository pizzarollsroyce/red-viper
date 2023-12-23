#ifndef V810_MEM_H
#define V810_MEM_H

// Memory Structure for the VIP Reg (Could have done it with an array
// but this is pretier...)
typedef struct {
    HWORD INTPND;
    HWORD INTENB;
    HWORD INTCLR;
    HWORD DPSTTS;
    HWORD DPCTRL;
    HWORD BRTA;
    HWORD BRTB;
    HWORD BRTC;
    HWORD REST;
    HWORD FRMCYC;
    HWORD CTA;
    HWORD XPSTTS;
    HWORD XPCTRL;
    HWORD tFrame;   //not publicly visible
    HWORD VER;
    HWORD SPT[4];
    HWORD GPLT[4];
    HWORD JPLT[4];
    HWORD BKCOL;
} V810_VIPREGDAT;

typedef struct {
    BYTE SCR;       //Serial Controll Reg,  0x02000028
    BYTE WCR;       //Wait Controll Reg,    0x02000024
    BYTE TCR;       //Timer Controll Reg,   0x02000020
    BYTE THB;       //Timer Higher Byte,    0x0200001C
    BYTE TLB;       //Timer Lower Byte,     0x02000018
    HWORD tTHW;     //Timer TempHWord, 	not publicly visible
    WORD tTRC;      //Timer TempResolutionCount, not publicly visible
    HWORD tCount;   //Timer Counter register, not publicly visible
    BYTE tReset;    //Timer Reset register, not publicly visible
    BYTE SHB;       //Serial Higher Byte,   0x02000014  //Read Only
    BYTE SLB;       //Serial Lower Byte,    0x02000010  //Read Only
    BYTE CDRR;      //Com Recv Data Reg,    0x0200000C  //Read Only
    BYTE CDTR;      //Com Trans Data Reg,   0x02000008
    BYTE CCSR;      //Com Cnt Stat Reg,     0x02000004
    BYTE CCR;       //Com Controll Reg,     0x02000000
} V810_HREGDAT;

//Export some data structs...
extern V810_MEMORYFETCH V810_ROM1; // US Games
extern V810_MEMORYFETCH V810_DISPLAY_RAM;
extern V810_MEMORYFETCH V810_SOUND_RAM;
extern V810_MEMORYFETCH V810_VB_RAM;
extern V810_MEMORYFETCH V810_GAME_RAM;
extern V810_VIPREGDAT   tVIPREG;
extern V810_HREGDAT     tHReg;

//////////////////////////////////////////////////////////
// Global CPU Objects
V810_MEMORYFETCH V810_ROM1; // US Games

V810_MEMORYFETCH V810_DISPLAY_RAM;
V810_MEMORYFETCH V810_SOUND_RAM;
V810_MEMORYFETCH V810_VB_RAM;
V810_MEMORYFETCH V810_GAME_RAM;

V810_REGFETCH V810_VIPCREG;
V810_REGFETCH V810_HCREG;

V810_VIPREGDAT tVIPREG;
V810_HREGDAT   tHReg;

extern int is_sram; //Flag if writes to sram...

// Memory read functions
BYTE   mem_rbyte(WORD addr);
SHWORD mem_rhword(WORD addr);
WORD   mem_rword(WORD addr);

// Memory write functions
void mem_wbyte(WORD addr, BYTE data);
void mem_whword(WORD addr, HWORD data);
void mem_wword(WORD addr, WORD data);

// Hardware control register read functions
BYTE  hcreg_rbyte(WORD addr);
HWORD hcreg_rhword(WORD addr);
WORD  hcreg_rword(WORD addr);

// Hardware control register write functions
void hcreg_wbyte(WORD addr, BYTE data);
void hcreg_whword(WORD addr, HWORD data);
void hcreg_wword(WORD addr, WORD data);

// Port read functions
BYTE  port_rbyte(WORD addr);
HWORD port_rhword(WORD addr);
WORD  port_rword(WORD addr);

// Port write functions
void port_wbyte(WORD addr, BYTE data);
void port_whword(WORD addr, HWORD data);
void port_wword(WORD addr, WORD data);

// Register I/O read functions
BYTE  vipcreg_rbyte(WORD addr);
HWORD vipcreg_rhword(WORD addr);
WORD  vipcreg_rword(WORD addr);

// Register I/O write functions
void vipcreg_wbyte(WORD addr, BYTE data);
void vipcreg_whword(WORD addr, HWORD data);
void vipcreg_wword(WORD addr, WORD data);

#endif
