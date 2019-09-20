//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcSDITXPHY_RegAccess.h *#*#*#*#*#*#*#* (C) 2019 DekTec
//
// Device driver - SdiTxPhy v1 (SDITXPHY) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block SdiTxPhy.
// These functions should solely be used by the block controller for SdiTxPhy.
//
// 2019.04.19 12:26 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- License -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Copyright (C) 2019 DekTec Digital Video B.V.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//  1. Redistributions of source code must retain the above copyright notice, this list
//     of conditions and the following disclaimer.
//  2. Redistributions in binary format must reproduce the above copyright notice, this
//     list of conditions and the following disclaimer in the documentation.
//
// THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL DEKTEC DIGITAL VIDEO BV, ITS AGENTS OR ITS EMPLOYEES BE LIABLE FOR
// ANY DIRECT, INDIRECT, CONSEQUENTIAL, INCIDENTAL, OR OTHER DAMAGES (INCLUDING DAMAGES
// FOR THE LOSS OF USE, INFORMATION, GOODWILL, PROFIT, WORK STOPPAGE, DATA, BUSINESS OR
// REVENUE) UNDER ANY CIRCUMSTANCES, OR UNDER ANY LEGAL THEORY, WHETHER IN CONTRACT, IN
// TORT, IN NEGLIGENCE, OR OTHERWISE, ARISING FROM THE USE OF, OR INABILITY TO USE THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ EXAMPLES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//
// 1. Getting fields 'DeviceFamily' and 'MaxSdiRate' from register 'Config':
//      UInt32  Reg_Config, DeviceFamily, MaxSdiRate;
//      Reg_Config   = SDITXPHY_Config_READ(pBc);
//      DeviceFamily = SDITXPHY_Config_GET_DeviceFamily(Reg_Config);
//      MaxSdiRate   = SDITXPHY_Config_GET_MaxSdiRate(Reg_Config);
//
// 2. Single-function shorthand for reading field 'IsFifoInhibited' from register
//    'CdcFifoStatus':
//      UInt32  IsFifoInhibited = SDITXPHY_CdcFifoStatus_READ_IsFifoInhibited(pBc);
//
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ NOTES +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//
// A) No automatic caching is provided, the user has to manage a 'cache' of 32-bit
// register values himself. The number of register reads and writes shall be minimized,
// as these are extremely slow (hundreds of CPU cycles for PCIe bus and orders of
// magnitude longer for USB).
//
// B) To read a field, the register shall first be read into an UInt32 using a READ
// function, followed by getting the field from the UInt32 value with a GET function.
// Field READ functions (a combination of the register READ- and field GET function) are
// provided for convenience, but these should only be used if the register value is just
// needed once for getting a single field.
//
// C) No register-access functions are generated for the BlockId register at address 0,
// nor for interrupt-status registers. The driver has generic (BB-independent) functions
// available for accessing these registers.

//=+=+=+=+=+=+=+=+=+=+=+ List of Generated Register-Access Functions +=+=+=+=+=+=+=+=+=+=+

// SDITXPHY_C10A10_PllLookup_GET_Pll0
// SDITXPHY_C10A10_PllLookup_GET_Pll1
// SDITXPHY_C10A10_PllLookup_GET_Pll2
// SDITXPHY_C10A10_PllLookup_GET_Pll3
// SDITXPHY_C10A10_PllLookup_READ
// SDITXPHY_C10A10_PllLookup_READ_Pll0
// SDITXPHY_C10A10_PllLookup_READ_Pll1
// SDITXPHY_C10A10_PllLookup_READ_Pll2
// SDITXPHY_C10A10_PllLookup_READ_Pll3
// SDITXPHY_C10A10_PllSelectionMux_READ
// SDITXPHY_C10A10_PllSelectionMux_WRITE
// SDITXPHY_CdcFifoControl_READ
// SDITXPHY_CdcFifoControl_SET_InhibitFifo
// SDITXPHY_CdcFifoControl_WRITE
// SDITXPHY_CdcFifoStatus_CLEAR_Underflow
// SDITXPHY_CdcFifoStatus_GET_IsFifoInhibited
// SDITXPHY_CdcFifoStatus_GET_Load
// SDITXPHY_CdcFifoStatus_GET_Underflow
// SDITXPHY_CdcFifoStatus_READ
// SDITXPHY_CdcFifoStatus_READ_IsFifoInhibited
// SDITXPHY_CdcFifoStatus_READ_Load
// SDITXPHY_CdcFifoStatus_READ_Underflow
// SDITXPHY_Config_GET_DeviceFamily
// SDITXPHY_Config_GET_MaxSdiRate
// SDITXPHY_Config_GET_NumClocks
// SDITXPHY_Config_GET_PllIdClk1
// SDITXPHY_Config_GET_PllIdClk2
// SDITXPHY_Config_READ
// SDITXPHY_Config_READ_DeviceFamily
// SDITXPHY_Config_READ_MaxSdiRate
// SDITXPHY_Config_READ_NumClocks
// SDITXPHY_Config_READ_PllIdClk1
// SDITXPHY_Config_READ_PllIdClk2
// SDITXPHY_Control_READ
// SDITXPHY_Control_SET_Arm
// SDITXPHY_Control_SET_BlockEnable
// SDITXPHY_Control_SET_GenlockSofDelay
// SDITXPHY_Control_SET_OperationalMode
// SDITXPHY_Control_SET_SrcFactor
// SDITXPHY_Control_SET_TxClkReset
// SDITXPHY_Control_WRITE
// SDITXPHY_Status_GET_ArmStatus
// SDITXPHY_Status_GET_OperationalStatus
// SDITXPHY_Status_GET_ResetInProgress
// SDITXPHY_Status_READ
// SDITXPHY_Status_READ_ArmStatus
// SDITXPHY_Status_READ_OperationalStatus
// SDITXPHY_Status_READ_ResetInProgress

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'ArmStatus'
#define SDITXPHY_ARMSTATUS_IDLE      0x0  // Transmission starts when operational mode
                                          // becomes RUN
#define SDITXPHY_ARMSTATUS_PREARMED  0x1  // Armed and awaiting RUN
#define SDITXPHY_ARMSTATUS_ARMED     0x2  // Armed and awaiting GenlockSoF before
                                          // starting transmission

// Value map 'BlockEnable'
#define SDITXPHY_BLKENA_DISABLED     0x0  // Block is entirely disabled
#define SDITXPHY_BLKENA_ENABLED      0x1  // Block is enabled and processes data

// Value map 'DeviceFamily'
#define SDITXPHY_FAMILY_CV           0x0  // Intel Cyclone V
#define SDITXPHY_FAMILY_C10          0x1  // Intel Cyclone 10
#define SDITXPHY_FAMILY_A10          0x2  // Intel Arria 10

// Value map 'OperationalStatus'
#define SDITXPHY_OPSTATUS_IDLE       0x0  // Block is inactive
#define SDITXPHY_OPSTATUS_STANDBY    0x1  // Block is partially operational
#define SDITXPHY_OPSTATUS_RUN        0x2  // Block performs its normal function
#define SDITXPHY_OPSTATUS_ERROR      0x3  // An error has occurred

// Value map 'SdiSrcFactor'
#define SDITXPHY_SDIMODE_BYPASS      0x0  // No up/down-sampling (x1)
#define SDITXPHY_SDIMODE_x2          0x1  // x2 up/down-sampling
#define SDITXPHY_SDIMODE_x11         0x2  // x11 up/down sampling

// Value map 'SdiRate'
#define SDITXPHY_SDIMODE_SD          0x0  // SDI mode is SD-SDI
#define SDITXPHY_SDIMODE_HD          0x1  // SDI mode is HD-SDI
#define SDITXPHY_SDIMODE_3G          0x2  // SDI mode is 3G-SDI
#define SDITXPHY_SDIMODE_6G          0x3  // SDI mode is 6G-SDI
#define SDITXPHY_SDIMODE_12G         0x4  // SDI mode is 12G-SDI

// Value map 'OperationalMode'
#define SDITXPHY_OPMODE_IDLE         0x0  // Block is inactive
#define SDITXPHY_OPMODE_STANDBY      0x1  // Block is partially operational
#define SDITXPHY_OPMODE_RUN          0x2  // Block performs its normal function

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDITXPHY_Config_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4);
}

// Field GET functions
static __inline UInt32  SDITXPHY_Config_GET_DeviceFamily(UInt32 Config)
{
    return Config & 0xF;
}
static __inline UInt32  SDITXPHY_Config_GET_MaxSdiRate(UInt32 Config)
{
    return (Config & 0x70) >> 4;
}
static __inline UInt32  SDITXPHY_Config_GET_NumClocks(UInt32 Config)
{
    return (Config & 0x180) >> 7;
}
static __inline UInt32  SDITXPHY_Config_GET_PllIdClk1(UInt32 Config)
{
    return (Config & 0x7FE00) >> 9;
}
static __inline UInt32  SDITXPHY_Config_GET_PllIdClk2(UInt32 Config)
{
    return (Config & 0x1FF80000) >> 19;
}

// Field READ functions
static __inline UInt32  SDITXPHY_Config_READ_DeviceFamily(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x4) & 0xF;
}
static __inline UInt32  SDITXPHY_Config_READ_MaxSdiRate(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x70) >> 4;
}
static __inline UInt32  SDITXPHY_Config_READ_NumClocks(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x180) >> 7;
}
static __inline UInt32  SDITXPHY_Config_READ_PllIdClk1(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x7FE00) >> 9;
}
static __inline UInt32  SDITXPHY_Config_READ_PllIdClk2(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x4) & 0x1FF80000) >> 19;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDITXPHY_Control_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x8);
}

// Field SET functions
static __inline UInt32  SDITXPHY_Control_SET_BlockEnable(UInt32 Control, UInt32 BlockEnable)
{
    DT_ASSERT((BlockEnable & ~0x1) == 0);
    return (Control & ~0x1) | BlockEnable;
}
static __inline UInt32  SDITXPHY_Control_SET_OperationalMode(UInt32 Control, UInt32 OperationalMode)
{
    DT_ASSERT((OperationalMode & ~0x3) == 0);
    return (Control & ~0x6) | (OperationalMode << 1);
}
static __inline UInt32  SDITXPHY_Control_SET_TxClkReset(UInt32 Control, UInt32 TxClkReset)
{
    DT_ASSERT((TxClkReset & ~0x1) == 0);
    return (Control & ~0x8) | (TxClkReset << 3);
}
static __inline UInt32  SDITXPHY_Control_SET_Arm(UInt32 Control, UInt32 Arm)
{
    DT_ASSERT((Arm & ~0x1) == 0);
    return (Control & ~0x10) | (Arm << 4);
}
static __inline UInt32  SDITXPHY_Control_SET_SrcFactor(UInt32 Control, UInt32 SrcFactor)
{
    DT_ASSERT((SrcFactor & ~0xF) == 0);
    return (Control & ~0x1E0) | (SrcFactor << 5);
}
static __inline UInt32  SDITXPHY_Control_SET_GenlockSofDelay(UInt32 Control, UInt32 GenlockSofDelay)
{
    DT_ASSERT((GenlockSofDelay & ~0xFFFF) == 0);
    return (Control & ~0xFFFF000) | (GenlockSofDelay << 12);
}

// Register WRITE function
static __inline void  SDITXPHY_Control_WRITE(DtBcSDITXPHY* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x8, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDITXPHY_Status_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC);
}

// Field GET functions
static __inline UInt32  SDITXPHY_Status_GET_OperationalStatus(UInt32 Status)
{
    return Status & 0x3;
}
static __inline UInt32  SDITXPHY_Status_GET_ResetInProgress(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}
static __inline UInt32  SDITXPHY_Status_GET_ArmStatus(UInt32 Status)
{
    return (Status & 0x30) >> 4;
}

// Field READ functions
static __inline UInt32  SDITXPHY_Status_READ_OperationalStatus(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x3;
}
static __inline UInt32  SDITXPHY_Status_READ_ResetInProgress(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x4) >> 2;
}
static __inline UInt32  SDITXPHY_Status_READ_ArmStatus(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0xC) & 0x30) >> 4;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CdcFifoControl' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SDITXPHY_CdcFifoControl_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field SET function
static __inline UInt32  SDITXPHY_CdcFifoControl_SET_InhibitFifo(UInt32 CdcFifoControl, UInt32 InhibitFifo)
{
    DT_ASSERT((InhibitFifo & ~0x1) == 0);
    return (CdcFifoControl & ~0x10) | (InhibitFifo << 4);
}

// Register WRITE function
static __inline void  SDITXPHY_CdcFifoControl_WRITE(DtBcSDITXPHY* pBc, UInt32 CdcFifoControl)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x10, CdcFifoControl);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'CdcFifoStatus' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  SDITXPHY_CdcFifoStatus_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

// Field GET functions
static __inline UInt32  SDITXPHY_CdcFifoStatus_GET_Underflow(UInt32 CdcFifoStatus)
{
    return CdcFifoStatus & 0x1;
}
static __inline UInt32  SDITXPHY_CdcFifoStatus_GET_Load(UInt32 CdcFifoStatus)
{
    return (CdcFifoStatus & 0xFF00) >> 8;
}
static __inline UInt32  SDITXPHY_CdcFifoStatus_GET_IsFifoInhibited(UInt32 CdcFifoStatus)
{
    return (CdcFifoStatus & 0x10000) >> 16;
}

// Field READ functions
static __inline UInt32  SDITXPHY_CdcFifoStatus_READ_Underflow(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14) & 0x1;
}
static __inline UInt32  SDITXPHY_CdcFifoStatus_READ_Load(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x14) & 0xFF00) >> 8;
}
static __inline UInt32  SDITXPHY_CdcFifoStatus_READ_IsFifoInhibited(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x14) & 0x10000) >> 16;
}

// Field CLEAR function
static __inline void  SDITXPHY_CdcFifoStatus_CLEAR_Underflow(DtBcSDITXPHY* pBc)
{
    UInt32  CdcFifoStatus = DtBc_RegRead32((DtBc*)pBc, 0x14);
    DtBc_RegWrite32((DtBc*)pBc, 0x14, CdcFifoStatus | 0x1);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllSelectionMux' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field READ function
static __inline UInt32  SDITXPHY_C10A10_PllSelectionMux_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x20) & 0xFF;
}

// Field WRITE function
static __inline void  SDITXPHY_C10A10_PllSelectionMux_WRITE(DtBcSDITXPHY* pBc, UInt32 PllSelectionMux)
{
    DT_ASSERT((PllSelectionMux & ~0xFF) == 0);
    DtBc_RegWrite32((DtBc*)pBc, 0x20, PllSelectionMux);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'PllLookup' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  SDITXPHY_C10A10_PllLookup_READ(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24);
}

// Field GET functions
static __inline UInt32  SDITXPHY_C10A10_PllLookup_GET_Pll0(UInt32 PllLookup)
{
    return PllLookup & 0xF;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_GET_Pll1(UInt32 PllLookup)
{
    return (PllLookup & 0xF0) >> 4;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_GET_Pll2(UInt32 PllLookup)
{
    return (PllLookup & 0xF00) >> 8;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_GET_Pll3(UInt32 PllLookup)
{
    return (PllLookup & 0xF000) >> 12;
}

// Field READ functions
static __inline UInt32  SDITXPHY_C10A10_PllLookup_READ_Pll0(DtBcSDITXPHY* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24) & 0xF;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_READ_Pll1(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0xF0) >> 4;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_READ_Pll2(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0xF00) >> 8;
}
static __inline UInt32  SDITXPHY_C10A10_PllLookup_READ_Pll3(DtBcSDITXPHY* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0xF000) >> 12;
}
