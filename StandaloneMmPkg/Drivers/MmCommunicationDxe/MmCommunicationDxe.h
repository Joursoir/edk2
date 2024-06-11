/** @file

  Copyright (c) 2024, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef MM_COMMUNICATION_DXE_H_
#define MM_COMMUNICATION_DXE_H_

#include <PiDxe.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiRuntimeLib.h>

#include <Protocol/SmmControl2.h>
#include <Protocol/MmCommunication2.h>
#include <Protocol/MmCommunication.h>

#include <Guid/MmCommBuffer.h>
#include <Guid/EventGroup.h>

/**
  Communicates with a registered handler.

  This function provides a service to send and receive messages from a registered UEFI service.

  @param[in] This                     The EFI_MM_COMMUNICATION_PROTOCOL instance.
  @param[in, out] CommBufferPhysical  Physical address of the MM communication buffer.
  @param[in, out] CommBufferVirtual   Virtual address of the MM communication buffer.
  @param[in, out] CommSize            The size of the data buffer being passed in. On exit, the size of data
                                      being returned. Zero if the handler does not wish to reply with any data.
                                      This parameter is optional and may be NULL.

  @retval EFI_SUCCESS                 The message was successfully posted.
  @retval EFI_INVALID_PARAMETER       The CommBuffer was NULL.
  @retval EFI_BAD_BUFFER_SIZE         The buffer is too large for the MM implementation.
                                      If this error is returned, the MessageLength field
                                      in the CommBuffer header or the integer pointed by
                                      CommSize, are updated to reflect the maximum payload
                                      size the implementation can accommodate.
  @retval EFI_ACCESS_DENIED           The CommunicateBuffer parameter or CommSize parameter,
                                      if not omitted, are in address range that cannot be
                                      accessed by the MM environment.

**/
EFI_STATUS
EFIAPI
MmCommunicate2 (
  IN CONST EFI_MM_COMMUNICATION2_PROTOCOL  *This,
  IN OUT VOID                              *CommBufferPhysical,
  IN OUT VOID                              *CommBufferVirtual,
  IN OUT UINTN                             *CommSize OPTIONAL
  );

/**
  Communicates with a registered handler.

  This function provides a service to send and receive messages from a registered UEFI service.

  @param[in] This                     The EFI_MM_COMMUNICATION_PROTOCOL instance.
  @param[in, out] CommBufferPhysical  Physical address of the MM communication buffer
  @param[in, out] CommSize            The size of the data buffer being passed in. On exit, the size of data
                                      being returned. Zero if the handler does not wish to reply with any data.
                                      This parameter is optional and may be NULL.

  @retval EFI_SUCCESS                 The message was successfully posted.
  @retval EFI_INVALID_PARAMETER       The CommBuffer was NULL.
  @retval EFI_BAD_BUFFER_SIZE         The buffer is too large for the MM implementation.
                                      If this error is returned, the MessageLength field
                                      in the CommBuffer header or the integer pointed by
                                      CommSize, are updated to reflect the maximum payload
                                      size the implementation can accommodate.
  @retval EFI_ACCESS_DENIED           The CommunicateBuffer parameter or CommSize parameter,
                                      if not omitted, are in address range that cannot be
                                      accessed by the MM environment.

**/
EFI_STATUS
EFIAPI
MmCommunicate (
  IN CONST EFI_MM_COMMUNICATION_PROTOCOL  *This,
  IN OUT VOID                             *CommBufferPhysical,
  IN OUT UINTN                            *CommSize OPTIONAL
  );

#endif
