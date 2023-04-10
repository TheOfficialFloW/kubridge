#ifndef __KUBRDIGE_H__
#define __KUBRDIGE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <psp2/types.h>
#include <psp2/kernel/sysmem.h>

typedef struct SceKernelAddrPair {
  uint32_t addr;                  //!< Address
  uint32_t length;                //!< Length
} SceKernelAddrPair;

typedef struct SceKernelPaddrList {
  uint32_t size;                  //!< sizeof(SceKernelPaddrList)
  uint32_t list_size;             //!< Size in elements of the list array
  uint32_t ret_length;            //!< Total physical size of the memory pairs
  uint32_t ret_count;             //!< Number of elements of list filled by ksceKernelGetPaddrList
  SceKernelAddrPair *list;        //!< Array of physical addresses and their lengths pairs
} SceKernelPaddrList;

typedef struct SceKernelAllocMemBlockKernelOpt {
  SceSize size;                   //!< sizeof(SceKernelAllocMemBlockKernelOpt)
  SceUInt32 field_4;
  SceUInt32 attr;                 //!< OR of SceKernelAllocMemBlockAttr
  SceUInt32 field_C;
  SceUInt32 paddr;
  SceSize alignment;
  SceUInt32 extraLow;
  SceUInt32 extraHigh;
  SceUInt32 mirror_blockid;
  SceUID pid;
  SceKernelPaddrList *paddr_list;
  SceUInt32 field_2C;
  SceUInt32 field_30;
  SceUInt32 field_34;
  SceUInt32 field_38;
  SceUInt32 field_3C;
  SceUInt32 field_40;
  SceUInt32 field_44;
  SceUInt32 field_48;
  SceUInt32 field_4C;
  SceUInt32 field_50;
  SceUInt32 field_54;
} SceKernelAllocMemBlockKernelOpt;

SceUID kuKernelAllocMemBlock(const char *name, SceKernelMemBlockType type, SceSize size, SceKernelAllocMemBlockKernelOpt *opt);

void kuKernelFlushCaches(const void *ptr, SceSize len);

int kuKernelCpuUnrestrictedMemcpy(void *dst, const void *src, SceSize len);

int kuPowerGetSysClockFrequency(void);
int kuPowerSetSysClockFrequency(int freq);

#ifdef __cplusplus
}
#endif

#endif
