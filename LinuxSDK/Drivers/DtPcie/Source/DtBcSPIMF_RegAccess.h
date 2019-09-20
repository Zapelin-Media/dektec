//*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#* DtBcSPIMF_RegAccess.h *#*#*#*#*#*#*#*# (C) 2019 DekTec
//
// Device driver - SpiMasterFlash v1 (SPIMF) - Register access functions
//
// The register access functions defined here are elementary inline functions to read
// from and write to registers of BB2.0 building block SpiMasterFlash.
// These functions should solely be used by the block controller for SpiMasterFlash.
//
// 2019.06.14 13:20 - AUTOGENERATED BY DtBlock - DO NOT EDIT THIS FILE BY HAND

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
// 1. Getting fields 'MemoryId' and 'BitOrder' from register 'Config1':
//      UInt32  Reg_Config1, MemoryId, BitOrder;
//      Reg_Config1 = SPIMF_Config1_READ(pBc);
//      MemoryId    = SPIMF_Config1_GET_MemoryId(Reg_Config1);
//      BitOrder    = SPIMF_Config1_GET_BitOrder(Reg_Config1);
//
// 2. Single-function shorthand for reading field 'RxFifoLoad' from register 'FifoLoad':
//      UInt32  RxFifoLoad = SPIMF_FifoLoad_READ_RxFifoLoad(pBc);
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

// SPIMF_Config1_GET_BitOrder
// SPIMF_Config1_GET_MemoryId
// SPIMF_Config1_READ
// SPIMF_Config1_READ_BitOrder
// SPIMF_Config1_READ_MemoryId
// SPIMF_Config2_READ_SpiClockRate
// SPIMF_Config3_GET_MemorySize
// SPIMF_Config3_GET_PageSize
// SPIMF_Config3_GET_SectorSize
// SPIMF_Config3_READ
// SPIMF_Config3_READ_MemorySize
// SPIMF_Config3_READ_PageSize
// SPIMF_Config3_READ_SectorSize
// SPIMF_Config4_GET_RxFifoSize
// SPIMF_Config4_GET_TxFifoSize
// SPIMF_Config4_READ
// SPIMF_Config4_READ_RxFifoSize
// SPIMF_Config4_READ_TxFifoSize
// SPIMF_Control_READ
// SPIMF_Control_SET_Command
// SPIMF_Control_SET_Timeout
// SPIMF_Control_SET_Unlock
// SPIMF_Control_WRITE
// SPIMF_FifoLoad_GET_RxFifoLoad
// SPIMF_FifoLoad_GET_TxFifoLoad
// SPIMF_FifoLoad_READ
// SPIMF_FifoLoad_READ_RxFifoLoad
// SPIMF_FifoLoad_READ_TxFifoLoad
// SPIMF_FlashProperties_READ
// SPIMF_FlashProperties_SET_Property
// SPIMF_FlashProperties_SET_Value
// SPIMF_FlashProperties_WRITE
// SPIMF_ReadData_READ
// SPIMF_StartAddress_WRITE
// SPIMF_Status_CLEAR_Timeout
// SPIMF_Status_GET_IsBusy
// SPIMF_Status_GET_IsEnabled
// SPIMF_Status_GET_IsLocked
// SPIMF_Status_GET_Timeout
// SPIMF_Status_READ
// SPIMF_Status_READ_IsBusy
// SPIMF_Status_READ_IsEnabled
// SPIMF_Status_READ_IsLocked
// SPIMF_Status_READ_Timeout
// SPIMF_TransferSize_WRITE
// SPIMF_WriteData_WRITE

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Include Files +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

#include "DtBc.h"                     // Block controller structs and functions

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Constant Definitions +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

// Value map 'BitOrder'
#define SPIMF_BITORDER_MSB_FIRST          0x0  // Most-significant-bit first
#define SPIMF_BITORDER_LSB_FIRST          0x1  // Least-significant-bit first

// Value map 'FlashProperty'
#define SPIMF_PROP_NOP                    0x0  // No operation - do not update any
                                               // properties
#define SPIMF_PROP_INSTR_READ_SFDP        0x1  // Opcode for SFDP read instruction
#define SPIMF_PROP_INSTR_BULK_ERASE       0x2  // Opcode for bulk-erase instruction
#define SPIMF_PROP_INSTR_PAGE_PROGRAM     0x3  // Opcode for page-program instruction
#define SPIMF_PROP_INSTR_READ             0x4  // Opcode for read instruction
#define SPIMF_PROP_INSTR_READ_STATUS      0x5  // Opcode for read-status instruction
#define SPIMF_PROP_INSTR_RESET            0x6  // Opcode for reset instruction
#define SPIMF_PROP_INSTR_RESET_ENABLE     0x7  // Opcode for reset-enable instruction
#define SPIMF_PROP_INSTR_SECTOR_ERASE     0x8  // Opcode for sector-erase instruction
#define SPIMF_PROP_INSTR_WRITE_ENABLE     0x9  // Opcode for write-enable instruction
#define SPIMF_PROP_SIZE_PAGE_LOG2BYTES    0xA  // Page size expressed as log2(bytes)
#define SPIMF_PROP_SIZE_SECTOR_LOG2BYTES  0xB  // Sector size expressed as log2(bytes)
#define SPIMF_PROP_SIZE_MEM_LOG2BYTES     0xC  // Size of flash memory expressed as
                                               // log2(bytes)
#define SPIMF_PROP_SIZE_ADDR_BYTES        0xD  // Size of address expressed in bytes

// Value map 'FlashCommand'
#define SPIMF_CMD_NOP                     0x0  // No operation
#define SPIMF_CMD_PAGE_WRITE              0x1  // Write page(s) of data to the flash
                                               // device
#define SPIMF_CMD_READ                    0x2  // Read from flash device
#define SPIMF_CMD_SECTOR_ERASE            0x3  // Erase memory by sector
#define SPIMF_CMD_BULK_ERASE              0x4  // Erase the entire memory
#define SPIMF_CMD_RESET                   0x7  // Reset the flash controller
#define SPIMF_CMD_READ_SFDP               0x8  // Read serial flash discovery parameter
                                               // database

//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
//=+=+=+=+=+=+=+=+=+=+=+ REGISTER-ACCESS FUNCTIONS - IMPLEMENTATION +=+=+=+=+=+=+=+=+=+=+=
//+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config1' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_Config1_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10);
}

// Field GET functions
static __inline UInt32  SPIMF_Config1_GET_MemoryId(UInt32 Config1)
{
    return Config1 & 0xFFF;
}
static __inline UInt32  SPIMF_Config1_GET_BitOrder(UInt32 Config1)
{
    return (Config1 & 0x10000) >> 16;
}

// Field READ functions
static __inline UInt32  SPIMF_Config1_READ_MemoryId(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x10) & 0xFFF;
}
static __inline UInt32  SPIMF_Config1_READ_BitOrder(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x10) & 0x10000) >> 16;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config2' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Field READ function
static __inline UInt32  SPIMF_Config2_READ_SpiClockRate(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x14);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config3' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_Config3_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18);
}

// Field GET functions
static __inline UInt32  SPIMF_Config3_GET_PageSize(UInt32 Config3)
{
    return Config3 & 0xFF;
}
static __inline UInt32  SPIMF_Config3_GET_SectorSize(UInt32 Config3)
{
    return (Config3 & 0xFF00) >> 8;
}
static __inline UInt32  SPIMF_Config3_GET_MemorySize(UInt32 Config3)
{
    return (Config3 & 0xFF0000) >> 16;
}

// Field READ functions
static __inline UInt32  SPIMF_Config3_READ_PageSize(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x18) & 0xFF;
}
static __inline UInt32  SPIMF_Config3_READ_SectorSize(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0xFF00) >> 8;
}
static __inline UInt32  SPIMF_Config3_READ_MemorySize(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x18) & 0xFF0000) >> 16;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Config4' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_Config4_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C);
}

// Field GET functions
static __inline UInt32  SPIMF_Config4_GET_TxFifoSize(UInt32 Config4)
{
    return Config4 & 0xFFFF;
}
static __inline UInt32  SPIMF_Config4_GET_RxFifoSize(UInt32 Config4)
{
    return (Config4 & 0xFFFF0000) >> 16;
}

// Field READ functions
static __inline UInt32  SPIMF_Config4_READ_TxFifoSize(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x1C) & 0xFFFF;
}
static __inline UInt32  SPIMF_Config4_READ_RxFifoSize(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x1C) & 0xFFFF0000) >> 16;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Control' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_Control_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x20);
}

// Field SET functions
static __inline UInt32  SPIMF_Control_SET_Command(UInt32 Control, UInt32 Command)
{
    DT_ASSERT((Command & ~0xF) == 0);
    return (Control & ~0xF) | Command;
}
static __inline UInt32  SPIMF_Control_SET_Timeout(UInt32 Control, UInt32 Timeout)
{
    DT_ASSERT((Timeout & ~0x1F) == 0);
    return (Control & ~0xF800000) | (Timeout << 23);
}
static __inline UInt32  SPIMF_Control_SET_Unlock(UInt32 Control, UInt32 Unlock)
{
    DT_ASSERT((Unlock & ~0xF) == 0);
    return (Control & ~0xF0000000) | (Unlock << 28);
}

// Register WRITE function
static __inline void  SPIMF_Control_WRITE(DtBcSPIMF* pBc, UInt32 Control)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x20, Control);
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'Status' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_Status_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24);
}

// Field GET functions
static __inline UInt32  SPIMF_Status_GET_Timeout(UInt32 Status)
{
    return Status & 0x1;
}
static __inline UInt32  SPIMF_Status_GET_IsEnabled(UInt32 Status)
{
    return (Status & 0x2) >> 1;
}
static __inline UInt32  SPIMF_Status_GET_IsBusy(UInt32 Status)
{
    return (Status & 0x4) >> 2;
}
static __inline UInt32  SPIMF_Status_GET_IsLocked(UInt32 Status)
{
    return (Status & 0x8) >> 3;
}

// Field READ functions
static __inline UInt32  SPIMF_Status_READ_Timeout(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x24) & 0x1;
}
static __inline UInt32  SPIMF_Status_READ_IsEnabled(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0x2) >> 1;
}
static __inline UInt32  SPIMF_Status_READ_IsBusy(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0x4) >> 2;
}
static __inline UInt32  SPIMF_Status_READ_IsLocked(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x24) & 0x8) >> 3;
}

// Field CLEAR function
static __inline void  SPIMF_Status_CLEAR_Timeout(DtBcSPIMF* pBc)
{
    UInt32  Status = DtBc_RegRead32((DtBc*)pBc, 0x24);
    DtBc_RegWrite32((DtBc*)pBc, 0x24, Status | 0x1);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'StartAddress' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void  SPIMF_StartAddress_WRITE(DtBcSPIMF* pBc, UInt32 StartAddress)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x28, StartAddress);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'TransferSize' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void  SPIMF_TransferSize_WRITE(DtBcSPIMF* pBc, UInt32 TransferSize)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x2C, TransferSize);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FifoLoad' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Register READ function
static __inline UInt32  SPIMF_FifoLoad_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x30);
}

// Field GET functions
static __inline UInt32  SPIMF_FifoLoad_GET_TxFifoLoad(UInt32 FifoLoad)
{
    return FifoLoad & 0xFFFF;
}
static __inline UInt32  SPIMF_FifoLoad_GET_RxFifoLoad(UInt32 FifoLoad)
{
    return (FifoLoad & 0xFFFF0000) >> 16;
}

// Field READ functions
static __inline UInt32  SPIMF_FifoLoad_READ_TxFifoLoad(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x30) & 0xFFFF;
}
static __inline UInt32  SPIMF_FifoLoad_READ_RxFifoLoad(DtBcSPIMF* pBc)
{
    return (DtBc_RegRead32((DtBc*)pBc, 0x30) & 0xFFFF0000) >> 16;
}

//-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'WriteData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field WRITE function
static __inline void  SPIMF_WriteData_WRITE(DtBcSPIMF* pBc, UInt32 WriteData)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x34, WriteData);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'ReadData' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

// Field READ function
static __inline UInt32  SPIMF_ReadData_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x38);
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- Register 'FlashProperties' -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

// Register READ function
static __inline UInt32  SPIMF_FlashProperties_READ(DtBcSPIMF* pBc)
{
    return DtBc_RegRead32((DtBc*)pBc, 0x3C);
}

// Field SET functions
static __inline UInt32  SPIMF_FlashProperties_SET_Property(UInt32 FlashProperties, UInt32 Property)
{
    DT_ASSERT((Property & ~0x1F) == 0);
    return (FlashProperties & ~0x1F) | Property;
}
static __inline UInt32  SPIMF_FlashProperties_SET_Value(UInt32 FlashProperties, UInt32 Value)
{
    DT_ASSERT((Value & ~0xFF) == 0);
    return (FlashProperties & ~0xFF00) | (Value << 8);
}

// Register WRITE function
static __inline void  SPIMF_FlashProperties_WRITE(DtBcSPIMF* pBc, UInt32 FlashProperties)
{
    DtBc_RegWrite32((DtBc*)pBc, 0x3C, FlashProperties);
}

