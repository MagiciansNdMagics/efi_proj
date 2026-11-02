#ifndef _EFI_TYPES_H_
#define _EFI_TYPES_H_

#pragma once

#include <types.h>

#if defined(__x86_64__) || defined(_M_X64)
    #define INTN long long signed int
    #define UINTN long long unsigned int
    #define EFIAPI __attribute__((ms_abi))
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    #define INTN signed int
    #define UINTN unsigned int
    #define EFIAPI __attribute__((regparm(0)))
#endif

// Signed
#define INT8 signed char
#define INT16 signed short
#define INT32 signed int
#define INT64 long long signed int

// Unsigned
#define UINT8 unsigned char
#define UINT16 unsigned short
#define UINT32 unsigned int
#define UINT64 long long unsigned int

// Other types
#define CHAR8 UINT8
#define CHAR16 UINT16
#define BOOLEAN UINT8

#define EFI_STATUS UINTN
#define EFI_HANDLE void*
#define EFI_EVENT void*
#define EFI_LBA UINT64
#define EFI_TPL UINTN

#define EFI_PHYSICAL_ADDRESS UINT64
#define EFI_VIRTUAL_ADDRESS UINT64

// Add structs after this
typedef struct
{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

typedef struct
{
    UINT16 ScanCode;
    CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

typedef struct
{
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

// Add enums after this
typedef enum
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum
{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

#endif