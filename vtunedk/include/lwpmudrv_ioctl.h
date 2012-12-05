/*COPYRIGHT**
 * -------------------------------------------------------------------------
 *               INTEL CORPORATION PROPRIETARY INFORMATION
 *  This software is supplied under the terms of the accompanying license
 *  agreement or nondisclosure agreement with Intel Corporation and may not
 *  be copied or disclosed except in accordance with the terms of that
 *  agreement.
 *        Copyright (c) 2007-2012 Intel Corporation.  All Rights Reserved.
 * -------------------------------------------------------------------------
**COPYRIGHT*/



#ifndef _LWPMUDRV_IOCTL_H_
#define _LWPMUDRV_IOCTL_H_

#if defined(__cplusplus)
extern "C" {
#endif

// IOCTL_SETUP
//

#if defined(DRV_OS_WINDOWS)

//
// NtDeviceIoControlFile IoControlCode values for this device.
//
// Warning:  Remember that the low two bits of the code specify how the
//           buffers are passed to the driver!
//
// 16 bit device type. 12 bit function codes
#define LWPMUDRV_IOCTL_DEVICE_TYPE  0xA000   // values 0-32768 reserved for Microsoft
#define LWPMUDRV_IOCTL_FUNCTION     0xA00    // values 0-2047  reserved for Microsoft

//
// Basic CTL CODE macro to reduce typographical errors
// Use for FILE_READ_ACCESS
//
#define LWPMUDRV_CTL_READ_CODE(x)    CTL_CODE(LWPMUDRV_IOCTL_DEVICE_TYPE,  \
                                              LWPMUDRV_IOCTL_FUNCTION+(x), \
                                              METHOD_BUFFERED,             \
                                              FILE_READ_ACCESS)

#define LWPMUDRV_IOCTL_START                        LWPMUDRV_CTL_READ_CODE(1)
#define LWPMUDRV_IOCTL_STOP                         LWPMUDRV_CTL_READ_CODE(2)
#define LWPMUDRV_IOCTL_INIT_PMU                     LWPMUDRV_CTL_READ_CODE(3)
#define LWPMUDRV_IOCTL_INIT                         LWPMUDRV_CTL_READ_CODE(4)
#define LWPMUDRV_IOCTL_EM_GROUPS                    LWPMUDRV_CTL_READ_CODE(5)
#define LWPMUDRV_IOCTL_SET_CPU_MASK                 LWPMUDRV_CTL_READ_CODE(17)
#define LWPMUDRV_IOCTL_PCI_READ                     LWPMUDRV_CTL_READ_CODE(18)
#define LWPMUDRV_IOCTL_PCI_WRITE                    LWPMUDRV_CTL_READ_CODE(19)
#define LWPMUDRV_IOCTL_READ_PCI_CONFIG              LWPMUDRV_CTL_READ_CODE(20)
#define LWPMUDRV_IOCTL_FD_PHYS                      LWPMUDRV_CTL_READ_CODE(21)
#define LWPMUDRV_IOCTL_WRITE_PCI_CONFIG             LWPMUDRV_CTL_READ_CODE(22)
#define LWPMUDRV_IOCTL_INSERT_MARKER                LWPMUDRV_CTL_READ_CODE(23)
#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC           LWPMUDRV_CTL_READ_CODE(24)
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT               LWPMUDRV_CTL_READ_CODE(25)
#define LWPMUDRV_IOCTL_NUM_CORES                    LWPMUDRV_CTL_READ_CODE(26)
#define LWPMUDRV_IOCTL_TSC_SKEW_INFO                LWPMUDRV_CTL_READ_CODE(27)
#define LWPMUDRV_IOCTL_PAUSE                        LWPMUDRV_CTL_READ_CODE(28)
#define LWPMUDRV_IOCTL_RESUME                       LWPMUDRV_CTL_READ_CODE(29)
#define LWPMUDRV_IOCTL_SET_ASYNC_EVENT              LWPMUDRV_CTL_READ_CODE(30)
#define LWPMUDRV_IOCTL_ASYNC_STOP                   LWPMUDRV_CTL_READ_CODE(31)
#define LWPMUDRV_IOCTL_COLLECT_SYS_CONFIG           LWPMUDRV_CTL_READ_CODE(32)
#define LWPMUDRV_IOCTL_GET_SYS_CONFIG               LWPMUDRV_CTL_READ_CODE(33)
#define LWPMUDRV_IOCTL_TERMINATE                    LWPMUDRV_CTL_READ_CODE(35)
#define LWPMUDRV_IOCTL_READ_MSRS                    LWPMUDRV_CTL_READ_CODE(36)
#define LWPMUDRV_IOCTL_LBR_INFO                     LWPMUDRV_CTL_READ_CODE(37)
#define LWPMUDRV_IOCTL_RESERVE                      LWPMUDRV_CTL_READ_CODE(38)
#define LWPMUDRV_IOCTL_MARK                         LWPMUDRV_CTL_READ_CODE(39) 
#define LWPMUDRV_IOCTL_SEED_NAME                    LWPMUDRV_CTL_READ_CODE(41)
#define LWPMUDRV_IOCTL_VERSION                      LWPMUDRV_CTL_READ_CODE(51)
#define LWPMUDRV_IOCTL_CHIPSET_INIT                 LWPMUDRV_CTL_READ_CODE(52)
#define LWPMUDRV_IOCTL_GET_CHIPSET_DEVICE_ID        LWPMUDRV_CTL_READ_CODE(53)
#define LWPMUDRV_IOCTL_SWITCH_GROUP                 LWPMUDRV_CTL_READ_CODE(54) 
#define LWPMUDRV_IOCTL_GET_NUM_CORE_CTRS            LWPMUDRV_CTL_READ_CODE(55) 
#define LWPMUDRV_IOCTL_PWR_INFO                     LWPMUDRV_CTL_READ_CODE(56) 
#define LWPMUDRV_IOCTL_NUM_DESCRIPTOR               LWPMUDRV_CTL_READ_CODE(57) 
#define LWPMUDRV_IOCTL_DESC_NEXT                    LWPMUDRV_CTL_READ_CODE(58) 
#define LWPMUDRV_IOCTL_MARK_OFF                     LWPMUDRV_CTL_READ_CODE(59) 
#define LWPMUDRV_IOCTL_CREATE_MARKER                LWPMUDRV_CTL_READ_CODE(60)
#define LWPMUDRV_IOCTL_GET_DRIVER_STATE             LWPMUDRV_CTL_READ_CODE(61) 
#define LWPMUDRV_IOCTL_READ_SWITCH_GROUP            LWPMUDRV_CTL_READ_CODE(62) 
#define LWPMUDRV_IOCTL_EM_GROUPS_UNC                LWPMUDRV_CTL_READ_CODE(63)
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT_UNC           LWPMUDRV_CTL_READ_CODE(64)
#define LWPMUDRV_IOCTL_INIT_UNC                     LWPMUDRV_CTL_READ_CODE(65)
#define LWPMUDRV_IOCTL_READ_MSR                     LWPMUDRV_CTL_READ_CODE(67)
#define LWPMUDRV_IOCTL_WRITE_MSR                    LWPMUDRV_CTL_READ_CODE(68)
#define LWPMUDRV_IOCTL_THREAD_SET_NAME              LWPMUDRV_CTL_READ_CODE(69)
#define LWPMUDRV_IOCTL_GET_PLATFORM_INFO            LWPMUDRV_CTL_READ_CODE(70)
#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC_STANDALONE LWPMUDRV_CTL_READ_CODE(71)
#define LWPMUDRV_IOCTL_READ_AND_RESET               LWPMUDRV_CTL_READ_CODE(72)
#define LWPMUDRV_IOCTL_SET_CPU_TOPOLOGY             LWPMUDRV_CTL_READ_CODE(73)
#define LWPMUDRV_IOCTL_INIT_NUM_DEV                 LWPMUDRV_CTL_READ_CODE(74)
#define LWPMUDRV_IOCTL_SET_GFX_EVENT                LWPMUDRV_CTL_READ_CODE(75)
#define LWPMUDRV_IOCTL_GET_NUM_SAMPLES              LWPMUDRV_CTL_READ_CODE(76)

#elif defined(DRV_OS_LINUX) || defined(DRV_OS_SOLARIS) || defined (DRV_OS_ANDROID)
// IOCTL_ARGS
typedef struct IOCTL_ARGS_NODE_S  IOCTL_ARGS_NODE;
typedef        IOCTL_ARGS_NODE   *IOCTL_ARGS;
struct IOCTL_ARGS_NODE_S {
    U64    r_len;
    char  *r_buf;
    U64    w_len;
    char  *w_buf;
};

// IOCTL_SETUP
//
#define LWPMU_IOC_MAGIC   99

#define LWPMUDRV_IOCTL_START                  _IO (LWPMU_IOC_MAGIC,  1)
#define LWPMUDRV_IOCTL_STOP                   _IO (LWPMU_IOC_MAGIC,  2)
#define LWPMUDRV_IOCTL_INIT_PMU               _IOW(LWPMU_IOC_MAGIC,  3, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_INIT                   _IOW(LWPMU_IOC_MAGIC,  4, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_EM_GROUPS              _IOW(LWPMU_IOC_MAGIC,  5, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SET_CPU_MASK           _IOW(LWPMU_IOC_MAGIC, 17, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_PCI_READ               _IOW(LWPMU_IOC_MAGIC, 18, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_PCI_WRITE              _IOW(LWPMU_IOC_MAGIC, 19, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_READ_PCI_CONFIG        _IOW(LWPMU_IOC_MAGIC, 20, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_FD_PHYS                _IOW(LWPMU_IOC_MAGIC, 21, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_WRITE_PCI_CONFIG       _IOW(LWPMU_IOC_MAGIC, 22, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_INSERT_MARKER          _IOW(LWPMU_IOC_MAGIC, 23, int)
#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC     _IOW(LWPMU_IOC_MAGIC, 24, int)
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT         _IOW(LWPMU_IOC_MAGIC, 25, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SYS_CONFIG             _IOR(LWPMU_IOC_MAGIC, 26, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_TSC_SKEW_INFO          _IOW(LWPMU_IOC_MAGIC, 27, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_NUM_CORES              _IOR(LWPMU_IOC_MAGIC, 28, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_COLLECT_SYS_CONFIG     _IOR(LWPMU_IOC_MAGIC, 29, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_SYS_CONFIG         _IOR(LWPMU_IOC_MAGIC, 30, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_PAUSE                  _IO (LWPMU_IOC_MAGIC, 31)
#define LWPMUDRV_IOCTL_RESUME                 _IO (LWPMU_IOC_MAGIC, 32)
#define LWPMUDRV_IOCTL_SET_ASYNC_EVENT        _IOW(LWPMU_IOC_MAGIC, 33, void* )
#define LWPMUDRV_IOCTL_ASYNC_STOP             _IO (LWPMU_IOC_MAGIC, 34)
#define LWPMUDRV_IOCTL_TERMINATE              _IO (LWPMU_IOC_MAGIC, 35)
#define LWPMUDRV_IOCTL_READ_MSRS              _IOR(LWPMU_IOC_MAGIC, 36, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_LBR_INFO               _IOW(LWPMU_IOC_MAGIC, 37, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_RESERVE                _IOR(LWPMU_IOC_MAGIC, 38, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_MARK                   _IOW(LWPMU_IOC_MAGIC, 39, IOCTL_ARGS)  
#define LWPMUDRV_IOCTL_AWAIT_STOP             _IOR(LWPMU_IOC_MAGIC, 40, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_KERNEL_CS              _IOR(LWPMU_IOC_MAGIC, 42, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SET_UID                _IOW(LWPMU_IOC_MAGIC, 43, uid_t)
#define LWPMUDRV_IOCTL_VERSION                _IOR(LWPMU_IOC_MAGIC, 51, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_CHIPSET_INIT           _IOW(LWPMU_IOC_MAGIC, 52, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_CHIPSET_DEVICE_ID  _IOW(LWPMU_IOC_MAGIC, 53, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SWITCH_GROUP           _IO (LWPMU_IOC_MAGIC, 54) 
#define LWPMUDRV_IOCTL_GET_NUM_CORE_CTRS      _IOR(LWPMU_IOC_MAGIC, 55, IOCTL_ARGS) 
#define LWPMUDRV_IOCTL_PWR_INFO               _IOW(LWPMU_IOC_MAGIC, 56, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_NUM_DESCRIPTOR         _IOW(LWPMU_IOC_MAGIC, 57, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_DESC_NEXT              _IOW(LWPMU_IOC_MAGIC, 58, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_MARK_OFF               _IOW(LWPMU_IOC_MAGIC, 59, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_CREATE_MARKER          _IOW(LWPMU_IOC_MAGIC, 60, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_DRIVER_STATE       _IOW(LWPMU_IOC_MAGIC, 61, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_READ_SWITCH_GROUP      _IOR(LWPMU_IOC_MAGIC, 62, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_EM_GROUPS_UNC          _IOW(LWPMU_IOC_MAGIC, 63, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT_UNC     _IOW(LWPMU_IOC_MAGIC, 64, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_INIT_UNC               _IOW(LWPMU_IOC_MAGIC, 65, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_RO_INFO                _IOW(LWPMU_IOC_MAGIC, 66, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_READ_MSR               _IOR(LWPMU_IOC_MAGIC, 67, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_WRITE_MSR              _IOW(LWPMU_IOC_MAGIC, 68, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_THREAD_SET_NAME        _IOW(LWPMU_IOC_MAGIC, 69, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_PLATFORM_INFO      _IOR(LWPMU_IOC_MAGIC, 70, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC_STANDALONE _IOR(LWPMU_IOC_MAGIC, 71, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_READ_AND_RESET         _IOR(LWPMU_IOC_MAGIC, 72, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SET_CPU_TOPOLOGY       _IOW(LWPMU_IOC_MAGIC, 73, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_INIT_NUM_DEV           _IOW(LWPMU_IOC_MAGIC, 74, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_SET_GFX_EVENT          _IOW(LWPMU_IOC_MAGIC, 75, IOCTL_ARGS)
#define LWPMUDRV_IOCTL_GET_NUM_SAMPLES        _IOR(LWPMU_IOC_MAGIC, 76, IOCTL_ARGS) 

#elif defined(DRV_OS_MAC)

// IOCTL_ARGS
typedef struct IOCTL_ARGS_NODE_S  IOCTL_ARGS_NODE;
typedef        IOCTL_ARGS_NODE   *IOCTL_ARGS;
struct IOCTL_ARGS_NODE_S {
	U64    r_len;
	char  *r_buf;
	U64    w_len;
	char  *w_buf;
	U32	  command;
};
	
typedef struct CPU_ARGS_NODE_S  CPU_ARGS_NODE;
typedef        CPU_ARGS_NODE   *CPU_ARGS;
struct CPU_ARGS_NODE_S {
	U64    r_len;
	char  *r_buf;
	U32	  command;
	U32	  CPU_ID;
	U32	  BUCKET_ID;
};
	
// IOCTL_SETUP
//
#define LWPMU_IOC_MAGIC   99
#define OS_SUCCESS        0   // TODO - move into abstraction layer
#define OS_STATUS         int // TODO - ditto
#define OS_ILLEGAL_IOCTL  -ENOTTY
#define OS_NO_MEM         -ENOMEM
#define OS_FAULT          -EFAULT

// Task file Opcodes.
// keeping the definitions as IOCTL but in MAC OSX
// these are really OpCodes consumed by Execute command.
#define LWPMUDRV_IOCTL_START                  1
#define LWPMUDRV_IOCTL_STOP                   2
#define LWPMUDRV_IOCTL_INIT_PMU               3
#define LWPMUDRV_IOCTL_INIT                   4
#define LWPMUDRV_IOCTL_EM_GROUPS              5  
	
#define LWPMUDRV_IOCTL_SET_CPU_MASK           17 
#define LWPMUDRV_IOCTL_PCI_READ               18
#define LWPMUDRV_IOCTL_PCI_WRITE              19
#define LWPMUDRV_IOCTL_READ_PCI_CONFIG        20
#define LWPMUDRV_IOCTL_FD_PHYS                21
#define LWPMUDRV_IOCTL_WRITE_PCI_CONFIG       22
#define LWPMUDRV_IOCTL_INSERT_MARKER          23
#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC     24
	
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT         25
#define LWPMUDRV_IOCTL_SYS_CONFIG             26
#define LWPMUDRV_IOCTL_TSC_SKEW_INFO          27
#define LWPMUDRV_IOCTL_NUM_CORES              28
#define LWPMUDRV_IOCTL_COLLECT_SYS_CONFIG     29
#define LWPMUDRV_IOCTL_GET_SYS_CONFIG         30
	
#define LWPMUDRV_IOCTL_PAUSE                  31
#define LWPMUDRV_IOCTL_RESUME                 32
#define LWPMUDRV_IOCTL_SET_ASYNC_EVENT        33
#define LWPMUDRV_IOCTL_ASYNC_STOP             34

#define LWPMUDRV_IOCTL_TERMINATE              35
#define LWPMUDRV_IOCTL_READ_MSRS              36
#define LWPMUDRV_IOCTL_LBR_INFO               37
#define LWPMUDRV_IOCTL_RESERVE                38
#define LWPMUDRV_IOCTL_MARK                   39
	
#define LWPMUDRV_IOCTL_AWAIT_STOP             40

#define LWPMUDRV_IOCTL_KERNEL_CS              42
#define LWPMUDRV_IOCTL_SET_UID                43
	
#define LWPMUDRV_IOCTL_VERSION                51
#define LWPMUDRV_IOCTL_CHIPSET_INIT           52
#define LWPMUDRV_IOCTL_GET_CHIPSET_DEVICE_ID  53
// NEW
#define LWPMUDRV_IOCTL_SWITCH_GROUP           54 
#define LWPMUDRV_IOCTL_GET_NUM_CORE_CTRS      55 
#define LWPMUDRV_IOCTL_PWR_INFO               56 
#define LWPMUDRV_IOCTL_NUM_DESCRIPTOR         57 
#define LWPMUDRV_IOCTL_DESC_NEXT              58 
#define LWPMUDRV_IOCTL_MARK_OFF               59 
#define LWPMUDRV_IOCTL_CREATE_MARKER          60
// EMON	INTERNAL
#define LWPMUDRV_IOCTL_GET_DRIVER_STATE       61
#define LWPMUDRV_IOCTL_READ_SWITCH_GROUP      62
#define LWPMUDRV_IOCTL_EM_GROUPS_UNC          63
#define LWPMUDRV_IOCTL_EM_CONFIG_NEXT_UNC     64
#define LWPMUDRV_IOCTL_INIT_UNC               65
// #define LWPMUDRV_IOCTL_RO_INFO             66
#define LWPMUDRV_IOCTL_READ_MSR               67
#define LWPMUDRV_IOCTL_WRITE_MSR              68
#define LWPMUDRV_IOCTL_THREAD_SET_NAME        69

#define LWPMUDRV_IOCTL_GET_NORMALIZED_TSC_STANDALONE     71

#define LWPMUDRV_IOCTL_READ_AND_RESET         72
#define LWPMUDRV_IOCTL_SET_CPU_TOPOLOGY       73
#define LWPMUDRV_IOCTL_INIT_NUM_DEV           74
#define LWPMUDRV_IOCTL_SET_GFX_EVENT          75
#define LWPMUDRV_IOCTL_GET_NUM_SAMPLES        76
    
// This is only for MAC OSX
#define LWPMUDRV_IOCTL_PROVIDE_FUNCTION_PTRS  999

#else
#error "unknown OS in lwpmudrv_ioctl.h"
#endif

#if defined(__cplusplus)
}
#endif

#endif