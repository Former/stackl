#pragma once
//******************************************************
// Constants for accessing the disk device
//

#define DISK_STATUS    0xD000000
#define DISK_CMD       0xD000004
#define DISK_ADDR      0xD000008
#define DISK_BLOCK     0xD00000C

#define DISK_VECTOR     2

#define DISK_STATUS_READ_BUSY   0x00000001
#define DISK_STATUS_READ_DONE   0x00000002
#define DISK_STATUS_READ_ERROR  0x00000004
#define DISK_STATUS_WRITE_BUSY  0x00000010
#define DISK_STATUS_WRITE_DONE  0x00000020
#define DISK_STATUS_WRITE_ERROR 0x00000040
#define DISK_STATUS_BAD_BLOCK   0x00000100
#define DISK_STATUS_ATTN        0x80000000

#define DISK_CMD_INT_ENA       0x00000001
#define DISK_CMD_START_READ    0x00000002
#define DISK_CMD_START_WRITE   0x00000004

#define DISK_BLOCK_SIZE        1024

int Disk_Init();                        // For internal use by the interpreter
int Disk_Load_Boot_Block();             // For internal use by the interpreter
