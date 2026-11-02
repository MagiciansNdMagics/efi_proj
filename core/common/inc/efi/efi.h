#ifndef _EFI_H_
#define _EFI_H_

#pragma once

#include <types.h>
#include <efi/efi_types.h>

// Add all pre defenitions here
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI* EFI_INPUT_RESET)
(
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This,
    BOOLEAN ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI* EFI_INPUT_READ_KEY)
(
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This,
    EFI_INPUT_KEY* Key
);

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL
{
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_RESET)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    BOOLEAN ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_STRING)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    CHAR16* String
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_TEST_STRING)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    CHAR16* String
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_QUERY_MODE)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    UINTN ModeNumber,
    UINTN* Columns,
    UINTN* Rows
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_SET_MODE)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    UINTN ModeNumber
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_SET_ATTRIBUTE)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    UINTN Attribute
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_CLEAR_SCREEN)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_SET_CURSOR_POSITION)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
    UINTN Column,
    UINTN Row
);

typedef
EFI_STATUS
(EFIAPI* EFI_TEXT_ENABLE_CURSOR)
(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    BOOLEAN Visible
);

typedef struct
{
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct
{
    EFI_TABLE_HEADER Hdr;
} EFI_RUNTIME_SERVICES;

typedef
EFI_TPL
(EFIAPI* EFI_RAISE_TPL)
(
    EFI_TPL NewTpl
);

typedef
void
(EFIAPI* EFI_RESTORE_TPL)
(
    EFI_TPL OldTpl
);

typedef
EFI_STATUS
(EFIAPI* EFI_ALLOCATE_PAGES) (
    EFI_ALLOCATE_TYPE Type,
    EFI_MEMORY_TYPE MemoryType,
    UINTN Pages,
    EFI_PHYSICAL_ADDRESS* Memory
);

typedef
EFI_STATUS
(EFIAPI* EFI_FREE_PAGES)
(
    EFI_PHYSICAL_ADDRESS Memory,
    UINTN Pages
);

typedef
EFI_STATUS
(EFIAPI* EFI_GET_MEMORY_MAP)
(
    UINTN* MemoryMapSize,
    EFI_MEMORY_DESCRIPTOR* MemoryMap,
    UINTN* MapKey,
    UINTN* DescriptorSize,
    UINT32* DescriptorVersion
);

typedef
EFI_STATUS
(EFIAPI* EFI_ALLOCATE_POOL)
(
    EFI_MEMORY_TYPE PoolType,
    UINTN Size,
    void** Buffer
);

typedef
EFI_STATUS
(EFIAPI* EFI_FREE_POOL)
(
    void* Buffer
);

typedef struct
{
    EFI_TABLE_HEADER Hdr;
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTpl;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
} EFI_BOOT_SERVICES;

typedef struct
{
    EFI_TABLE_HEADER Hdr;
    CHAR16* FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;
    EFI_RUNTIME_SERVICES* RuntimeServices;
    EFI_BOOT_SERVICES* BootServices;
} EFI_SYSTEM_TABLE;

#endif