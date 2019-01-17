#ifndef Z_H
#define Z_H

#if defined(__IBM_METAL__)

// on z
#define ATTRIBUTE(mode) __attribute__((mode))
#define PTR32 __ptr32
#define PTR64 __ptr64
#define ASMREG(register) __asm(register)

#else

// off z
#define ATTRIBUTE(mode)
#define PTR32
#define PTR64
#define ASMREG(register)

#endif

#if defined(__IBM_METAL__)
#define S0C3(n)                                                 \
    __asm(                                                      \
        "*                                                  \n" \
        " LLGF  0,%0      = Value passed by caller          \n" \
        " EXRL  0,*       Execute myself                    \n" \
        " DC    C'@S0C3'  Find by '@S0C3'                     " \
        "*                                                    " \
        :                                                       \
        : "m"(n)                                                \
        : "r0");
#else
#define S0C3(n)
#endif

static void s0c3Abend(int n) { S0C3(n); }

#endif