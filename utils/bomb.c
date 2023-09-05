typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef int    sdword;
typedef long long    sqword;
typedef short    sword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    word;
typedef ushort sa_family_t;

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[40];
};

struct _IO_marker {
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
};

typedef struct _IO_FILE FILE;

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};

typedef uint __socklen_t;

typedef __socklen_t socklen_t;

typedef uint wint_t;

typedef qword __uint64_t;

typedef int __pid_t;

typedef ushort __ipc_pid_t;

typedef int __blkcnt_t;


// WARNING! conflicting data type names: /DWARF/size_t - /stddef.h/size_t

typedef char __int8_t;

typedef int __time_t;


// WARNING! conflicting data type names: /DWARF/__off64_t - /types.h/__off64_t

typedef uchar __u_char;

typedef sqword __int64_t;

typedef int __ssize_t;

typedef ulonglong __u_quad_t;

typedef int __rlim_t;

typedef int __swblk_t;


// WARNING! conflicting data type names: /DWARF/__off_t - /types.h/__off_t

typedef ushort __u_short;

typedef int __t_scalar_t;

typedef uint __t_uscalar_t;

typedef dword __uint32_t;

typedef word _G_uint16_t;

typedef sdword _G_int32_t;

typedef int __key_t;

typedef uint __u_int;

typedef dword _G_uint32_t;

typedef uchar __uint8_t;

typedef uint __fd_mask;

typedef int __daddr_t;

typedef int __clock_t;

typedef sdword __int32_t;

typedef uint __u_long;

typedef int __intptr_t;

typedef word __uint16_t;

typedef sword __int16_t;

typedef sword _G_int16_t;


// WARNING! conflicting data type names: /DWARF/libio.h/_IO_marker - /libio.h/_IO_marker

typedef __off_t off_t;


// WARNING! conflicting data type names: /DWARF/stdio.h/_IO_FILE - /stdio.h/_IO_FILE

typedef __off_t fpos_t;


// WARNING! conflicting data type names: /DWARF/stdio.h/FILE - /stdio.h/FILE

typedef __quad_t __rlim64_t;

typedef __quad_t __blkcnt64_t;

typedef __u_long __fsfilcnt_t;

typedef __u_int __uid_t;

typedef __u_quad_t __fsblkcnt64_t;

typedef struct __fsid_t __fsid_t, *P__fsid_t;

struct __fsid_t {
    int __val[2];
};

typedef __quad_t __loff_t;


// WARNING! conflicting data type names: /DWARF/types.h/__off64_t - /types.h/__off64_t

typedef __u_long __ino64_t;

typedef __u_int __mode_t;

typedef __u_int __nlink_t;

typedef __u_quad_t __dev_t;

typedef __u_long __fsblkcnt_t;

typedef __u_int __id_t;

typedef __u_long __ino_t;

typedef __quad_t * __qaddr_t;

typedef char * __caddr_t;

typedef struct __fd_set __fd_set, *P__fd_set;

struct __fd_set {
    __fd_mask __fds_bits[32];
};

typedef __u_quad_t __fsfilcnt64_t;

typedef __u_int __gid_t;

typedef struct nodeStruct nodeStruct, *PnodeStruct;

typedef struct nodeStruct listNode;

struct nodeStruct {
    int value;
    int index;
    struct nodeStruct * next;
};

typedef void * __gnuc_va_list;

typedef struct _IO_FILE_plus _IO_FILE_plus, *P_IO_FILE_plus;

struct _IO_FILE_plus {
};

typedef struct _IO_jump_t _IO_jump_t, *P_IO_jump_t;

struct _IO_jump_t {
};

typedef struct hostent hostent, *Phostent;

struct hostent {
    char * h_name;
    char * * h_aliases;
    int h_addrtype;
    int h_length;
    char * * h_addr_list;
};

typedef void (* __sighandler_t)(int);

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

typedef enum Elf_SectionHeaderType_x86 {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType_x86;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_x86 sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef enum Elf32_DynTag_x86 {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf32_DynTag_x86;

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_x86 {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType_x86;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_x86 p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

typedef struct Elf32_Dyn_x86 Elf32_Dyn_x86, *PElf32_Dyn_x86;

struct Elf32_Dyn_x86 {
    enum Elf32_DynTag_x86 d_tag;
    dword d_val;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};




int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  func_0x00000000();
  frame_dummy();
  iVar1 = gcc2_compiled_();
  return iVar1;
}



void FUN_08048710(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



void __register_frame_info(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fprintf(FILE *__stream,char *__format,...)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE * tmpfile(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * getenv(char *__name)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fflush(FILE *__stream)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void bcopy(void *__src,void *__dest,size_t __n)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void rewind(FILE *__stream)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int system(char *__command)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void __deregister_frame_info(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * fgets(char *__s,int __n,FILE *__stream)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

uint sleep(uint __seconds)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void __strtol_internal(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void __libc_start_main(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char *__format,...)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int fclose(FILE *__stream)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

hostent * gethostbyname(char *__name)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void bzero(void *__s,size_t __n)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int sscanf(char *__s,char *__format,...)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE * fopen(char *__filename,char *__modes)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int dup(int __fd)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int sprintf(char *__s,char *__format,...)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

int socket(int __domain,int __type,int __protocol)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * cuserid(char *__s)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

char * strcpy(char *__dest,char *__src)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void processEntry entry(undefined4 param_1,undefined4 param_2)

{
  undefined auStack_4 [4];
  
  __libc_start_main(main,param_2,&stack0x00000004,_init,_fini,param_1,auStack_4);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void gcc2_compiled_(void)

{
  code *pcVar1;
  
  if (_completed_4 == 0) {
    while (*(int *)p_3 != 0) {
      pcVar1 = *(code **)p_3;
      p_3 = p_3 + 4;
      (*pcVar1)();
    }
    __deregister_frame_info(&cie_0804b484);
    _completed_4 = 1;
  }
  return;
}



void fini_dummy(void)

{
  return;
}



void frame_dummy(void)

{
  __register_frame_info(&cie_0804b484,object_11);
  return;
}



void init_dummy(void)

{
  return;
}



// WARNING: Unknown calling convention
// Local variable input:char *[EAX:4] conflicts with parameter, skipped.

int main(int argc,char **argv)

{
  undefined4 uVar1;
  int in_stack_00000004;
  undefined4 *in_stack_00000008;
  
  if (in_stack_00000004 == 1) {
    infile = stdin;
  }
  else {
    if (in_stack_00000004 != 2) {
      printf("Usage: %s [<input_file>]\n",*in_stack_00000008);
                    // WARNING: Subroutine does not return
      exit(8);
    }
    infile = (_IO_FILE *)fopen((char *)in_stack_00000008[1],"r");
    if ((FILE *)infile == (FILE *)0x0) {
      printf("%s: Error: Couldn\'t open %s\n",*in_stack_00000008,in_stack_00000008[1]);
                    // WARNING: Subroutine does not return
      exit(8);
    }
  }
  initialize_bomb(argv);
  printf("Welcome this is my little bomb !!!! You have 6 stages with\n");
  printf("only one life good luck !! Have a nice day!\n");
  uVar1 = read_line();
  phase_1(uVar1);
  phase_defused();
  printf("Phase 1 defused. How about the next one?\n");
  uVar1 = read_line();
  phase_2(uVar1);
  phase_defused();
  printf("That\'s number 2.  Keep going!\n");
  uVar1 = read_line();
  phase_3(uVar1);
  phase_defused();
  printf("Halfway there!\n");
  uVar1 = read_line();
  phase_4(uVar1);
  phase_defused();
  printf("So you got that one.  Try this one.\n");
  uVar1 = read_line();
  phase_5(uVar1);
  phase_defused();
  printf("Good work!  On to the next...\n");
  uVar1 = read_line();
  phase_6(uVar1);
  phase_defused();
  return 0;
}



void phase_1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = strings_not_equal(param_1,"Public speaking is very easy.");
  if (iVar1 != 0) {
    explode_bomb();
  }
  return;
}



void phase_2(undefined4 param_1)

{
  int iVar1;
  int aiStack_20 [7];
  
  read_six_numbers(param_1,aiStack_20 + 1);
  if (aiStack_20[1] != 1) {
    explode_bomb();
  }
  iVar1 = 1;
  do {
    if (aiStack_20[iVar1 + 1] != (iVar1 + 1) * aiStack_20[iVar1]) {
      explode_bomb();
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return;
}



void phase_3(char *param_1)

{
  int iVar1;
  char cVar2;
  uint local_10;
  char local_9;
  int local_8;
  
  iVar1 = sscanf(param_1,"%d %c %d",&local_10,&local_9,&local_8);
  if (iVar1 < 3) {
    explode_bomb();
  }
  switch(local_10) {
  case 0:
    cVar2 = 'q';
    if (local_8 != 0x309) {
      explode_bomb();
    }
    break;
  case 1:
    cVar2 = 'b';
    if (local_8 != 0xd6) {
      explode_bomb();
    }
    break;
  case 2:
    cVar2 = 'b';
    if (local_8 != 0x2f3) {
      explode_bomb();
    }
    break;
  case 3:
    cVar2 = 'k';
    if (local_8 != 0xfb) {
      explode_bomb();
    }
    break;
  case 4:
    cVar2 = 'o';
    if (local_8 != 0xa0) {
      explode_bomb();
    }
    break;
  case 5:
    cVar2 = 't';
    if (local_8 != 0x1ca) {
      explode_bomb();
    }
    break;
  case 6:
    cVar2 = 'v';
    if (local_8 != 0x30c) {
      explode_bomb();
    }
    break;
  case 7:
    cVar2 = 'b';
    if (local_8 != 0x20c) {
      explode_bomb();
    }
    break;
  default:
    cVar2 = 'x';
    explode_bomb();
  }
  if (cVar2 != local_9) {
    explode_bomb();
  }
  return;
}



int func4(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 2) {
    iVar2 = 1;
  }
  else {
    iVar1 = func4(param_1 + -1);
    iVar2 = func4(param_1 + -2);
    iVar2 = iVar2 + iVar1;
  }
  return iVar2;
}



void phase_4(char *param_1)

{
  int iVar1;
  int local_8;
  
  iVar1 = sscanf(param_1,"%d",&local_8);
  if ((iVar1 != 1) || (local_8 < 1)) {
    explode_bomb();
  }
  iVar1 = func4(local_8);
  if (iVar1 != 0x37) { // 55
    explode_bomb();
  }
  return;
}



void phase_5(int param_1)

{
  int iVar1;
  undefined local_c [6];
  undefined local_6;
  
  iVar1 = string_length(param_1);
  if (iVar1 != 6) {
    explode_bomb();
  }
  iVar1 = 0;
  do {
    local_c[iVar1] = (&array_123)[(char)(*(byte *)(iVar1 + param_1) & 0xf)];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  local_6 = 0;
  iVar1 = strings_not_equal(local_c,"giants");
  if (iVar1 != 0) {
    explode_bomb();
  }
  return;
}



// WARNING: Type propagation algorithm not settling

void phase_6(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *local_38;
  int *local_34 [6];
  int local_1c [6];
  
  local_38 = node1;
  read_six_numbers(param_1,local_1c);
  iVar4 = 0;
  do {
    iVar2 = iVar4;
    if (5 < local_1c[iVar4] - 1U) {
      explode_bomb();
    }
    while (iVar2 = iVar2 + 1, iVar2 < 6) {
      if (local_1c[iVar4] == local_1c[iVar2]) {
        explode_bomb();
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = 0;
  do {
    iVar2 = 1;
    piVar3 = (int *)local_38;
    if (1 < local_1c[iVar4]) {
      do {
        piVar3 = (int *)piVar3[2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < local_1c[iVar4]);
    }
    local_34[iVar4] = piVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = 1;
  piVar3 = local_34[0];
  do {
    piVar1 = local_34[iVar4];
    piVar3[2] = (int)piVar1;
    iVar4 = iVar4 + 1;
    piVar3 = piVar1;
  } while (iVar4 < 6);
  piVar1[2] = 0;
  iVar4 = 0;
  do {
    if (*local_34[0] < *(int *)local_34[0][2]) {
      explode_bomb();
    }
    local_34[0] = (int *)local_34[0][2];
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}



int fun7(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = -1;
  }
  else if (param_2 < *param_1) {
    iVar1 = fun7(param_1[1],param_2);
    iVar1 = iVar1 * 2;
  }
  else if (param_2 == *param_1) {
    iVar1 = 0;
  }
  else {
    iVar1 = fun7(param_1[2],param_2);
    iVar1 = iVar1 * 2 + 1;
  }
  return iVar1;
}



void secret_phase(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = read_line();
  iVar2 = __strtol_internal(uVar1,0,10,0);
  if (1000 < iVar2 - 1U) {
    explode_bomb();
  }
  iVar2 = fun7(n1,iVar2);
  if (iVar2 != 7) {
    explode_bomb();
  }
  printf("Wow! You\'ve defused the secret stage!\n");
  phase_defused();
  return;
}



void sig_handler(void)

{
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(3);
  printf("Well...");
  fflush(stdout);
  sleep(1);
  printf("OK. :-)\n");
                    // WARNING: Subroutine does not return
  exit(0x10);
}



void invalid_phase(undefined4 param_1)

{
  printf("Invalid phase%s\n",param_1);
                    // WARNING: Subroutine does not return
  exit(8);
}



void read_six_numbers(char *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = sscanf(param_1,"%d %d %d %d %d %d",param_2,param_2 + 4,param_2 + 8,param_2 + 0xc,
                 param_2 + 0x10,param_2 + 0x14);
  if (iVar1 < 6) {
    explode_bomb();
  }
  return;
}



int string_length(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
  }
  return iVar2;
}



undefined4 strings_not_equal(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = string_length(param_1);
  iVar3 = string_length(param_2);
  if (iVar2 == iVar3) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      if (*param_1 != *param_2) goto LAB_08049057;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      cVar1 = *param_1;
    }
    uVar4 = 0;
  }
  else {
LAB_08049057:
    uVar4 = 1;
  }
  return uVar4;
}



int open_clientfd(char *param_1,ushort param_2)

{
  int __fd;
  hostent *phVar1;
  int iVar2;
  sockaddr local_14;
  
  __fd = socket(2,1,0);
  if (__fd < 0) {
    printf("Bad host (1).\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  phVar1 = gethostbyname(param_1);
  if (phVar1 == (hostent *)0x0) {
    printf("Bad host (2).\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  bzero(&local_14,0x10);
  local_14.sa_family = 2;
  bcopy(*phVar1->h_addr_list,local_14.sa_data + 2,phVar1->h_length);
  local_14.sa_data._0_2_ = param_2 >> 8 | param_2 << 8;
  iVar2 = connect(__fd,&local_14,0x10);
  if (iVar2 < 0) {
    printf("Bad host (3).\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  return __fd;
}



void initialize_bomb(void)

{
  signal(2,sig_handler);
  return;
}



undefined4 blank_line(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if ((*(byte *)(__ctype_b + 1 + cVar1 * 2) & 0x20) == 0) break;
    cVar1 = *param_1;
  }
  return 0;
}



char * skip(void)

{
  char *pcVar1;
  int iVar2;
  
  do {
    pcVar1 = fgets(input_strings + num_input_strings * 0x50,0x50,(FILE *)infile);
    if (pcVar1 == (char *)0x0) {
      return (char *)0x0;
    }
    iVar2 = blank_line(pcVar1);
  } while (iVar2 != 0);
  return pcVar1;
}



undefined1 * read_line(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  iVar2 = skip();
  if (iVar2 == 0) {
    if (infile != stdin) {
      pcVar3 = getenv("GRADE_BOMB");
      if (pcVar3 != (char *)0x0) {
                    // WARNING: Subroutine does not return
        exit(0);
      }
      infile = stdin;
      iVar2 = skip();
      if (iVar2 != 0) goto LAB_0804925f;
    }
    printf("Error: Premature EOF on stdin\n");
    explode_bomb();
  }
LAB_0804925f:
  uVar4 = 0xffffffff;
  pcVar3 = input_strings + num_input_strings * 0x50;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar4 == 0x50) {
    printf("Error: Input line too long\n");
    explode_bomb();
  }
  iVar2 = num_input_strings * 0x50;
  *(undefined *)(~uVar4 + 0x804b67e + iVar2) = 0;
  num_input_strings = num_input_strings + 1;
  return input_strings + iVar2;
}



void send_msg(int param_1)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  char *pcVar3;
  int iVar4;
  undefined4 local_54;
  undefined2 local_50;
  undefined local_4e;
  
  iVar1 = dup(0);
  if (iVar1 == -1) {
    printf("ERROR: dup(0) error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  iVar2 = close(0);
  if (iVar2 == -1) {
    printf("ERROR: close error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  __stream = tmpfile();
  if (__stream == (FILE *)0x0) {
    printf("ERROR: tmpfile error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  fprintf(__stream,"Subject: Bomb notification\n");
  fprintf(__stream,"\n");
  pcVar3 = cuserid((char *)0x0);
  if (pcVar3 == (char *)0x0) {
    local_54 = 0x6f626f6e;
    local_50 = 0x7964;
    local_4e = 0;
  }
  else {
    strcpy((char *)&local_54,pcVar3);
  }
  pcVar3 = "exploded";
  if (param_1 != 0) {
    pcVar3 = "defused";
  }
  fprintf(__stream,"bomb-header:%s:%d:%s:%s:%d\n",lab_id,bomb_id,&local_54,pcVar3,num_input_strings)
  ;
  iVar2 = 0;
  if (0 < num_input_strings) {
    do {
      iVar4 = iVar2 * 0x50;
      iVar2 = iVar2 + 1;
      fprintf(__stream,"bomb-string:%s:%d:%s:%d:%s\n",lab_id,bomb_id,&local_54,iVar2,
              input_strings + iVar4);
    } while (iVar2 < num_input_strings);
  }
  rewind(__stream);
  sprintf(scratch,"%s %s@%s","/usr/sbin/sendmail -bm",&DAT_08049c53,"bluegill.cmcl.cs.cmu.edu");
  iVar2 = system(scratch);
  if (iVar2 != 0) {
    printf("ERROR: notification error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  iVar2 = fclose(__stream);
  if (iVar2 != 0) {
    printf("ERROR: fclose(tmp) error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  iVar2 = dup(iVar1);
  if (iVar2 != 0) {
    printf("ERROR: dup(tmpstdin) error\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  iVar1 = close(iVar1);
  if (iVar1 != 0) {
    printf("ERROR: close(tmpstdin)\n");
                    // WARNING: Subroutine does not return
    exit(8);
  }
  return;
}



void explode_bomb(void)

{
  printf("\nBOOM!!!\n");
  printf("The bomb has blown up.\n");
                    // WARNING: Subroutine does not return
  exit(8);
}



void phase_defused(void)

{
  int iVar1;
  undefined local_58 [4];
  undefined local_54 [80];
  
  if (num_input_strings == 6) {
    iVar1 = sscanf(input_strings + 0xf0,"%d %s",local_58,local_54);
    if (iVar1 == 2) {
      iVar1 = strings_not_equal(local_54,"austinpowers");
      if (iVar1 == 0) {
        printf("Curses, you\'ve found the secret phase!\n");
        printf("But finding it and solving it are quite different...\n");
        secret_phase();
      }
    }
    printf("Congratulations! You\'ve defused the bomb!\n");
  }
  return;
}



void gcc2_compiled_(void)

{
  code **ppcVar1;
  
  ppcVar1 = (code **)&__CTOR_LIST__;
  if (__CTOR_LIST__ != -1) {
    do {
      (**ppcVar1)();
      ppcVar1 = ppcVar1 + -1;
    } while (*ppcVar1 != (code *)0xffffffff);
  }
  return;
}



void init_dummy(void)

{
  return;
}



void _fini(void)

{
  gcc2_compiled_();
  return;
}


