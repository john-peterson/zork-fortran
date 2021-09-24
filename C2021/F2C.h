// Based on f2c.h: The Standard Fortran to C header file.
// Assumes C99, which is now (well into the 21st century) POSIX.
// That means: boolean types, function prototypes, "rb" and "wb" for fopen, "const", "void", etc.
#include <stdbool.h>
#include <stdlib.h>

// These types will be nativized, after it's made OK to do so.
typedef long Bool; // Logical.

#define abs(X)		((X) >= 0? (X): -(X))
#define min(A, B)	((A) <= (B)? (A): (B))
#define max(A, B)	((A) >= (B)? (A): (B))

// A wrapper for the built-in functions defined in the f2c library.
int DoFio(size_t N, void *X, size_t dN);
int DoUio(size_t N, void *X, size_t dN);
int CompS(char *A, char *B, size_t N);
void StopS(char *A, size_t N);
int OpenF(int Unit, char *File, char *Sta, char *Acc, char *Fm, int Rl);
int CloseF(int Unit);
int BegInDU(int Unit, int Rec);
int EndInDU(void);
int BegInSF(int Unit, char *Format);
int EndInSF(void);
int BegInSU(int Unit);
int EndInSU(void);
int BegExSF(int Unit, char *Format);
int EndExSF(void);
int BegExSU(int Unit);
int EndExSU(void);
