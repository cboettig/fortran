#include <R.h>
#include <R_ext/Rdynload.h>
#include <Rversion.h>

void F77_SUB(rndstart)(void) { GetRNGstate(); }
void F77_SUB(rndend)(void) { PutRNGstate(); }
double F77_SUB(normrnd)(void) { return norm_rand(); }
double F77_SUB(unifrnd)(void) { return unif_rand(); }

static R_FortranMethodDef R_FortranDef[] = {
  {"rndstart",  (DL_FUNC) &F77_SUB(rndstart),  0, NULL},
  {"rndend",  (DL_FUNC) &F77_SUB(rndend),  0, NULL},
  {"normrnd",  (DL_FUNC) &F77_SUB(normrnd),  0, NULL},
  {"unifrnd",  (DL_FUNC) &F77_SUB(unifrnd),  0, NULL},

  {NULL, NULL, 0, NULL}
};


void R_init_NetGen(DllInfo *dll) {
  R_registerRoutines(dll, NULL, NULL, R_FortranDef, NULL);
#if defined(R_VERSION) && R_VERSION >= R_Version(3, 3, 0)
  R_useDynamicSymbols(dll, FALSE);
#endif
}
