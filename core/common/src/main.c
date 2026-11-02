#include <main.h>
#include <efi/efi.h>
#include <lib/panic.h>

EFI_STATUS
main
(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
    panic();
}