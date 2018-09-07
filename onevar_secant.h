#ifndef ONEVAR_SECANT_H
#define ONEVAR_SECANT_H

#include "onevar_func_ptr/onevar_func_ptr.h" 
#include "onevar_result/onevar_result.h" 
#include "stopping_gd/stopping_gd.h"
#include <stddef.h>
#include <math.h>

OnevarResult onevar_secant(
    ONEVAR_FUNC_PTR func, const double* params, 
    bool disp, double maxiter, double tolfun, double maxjump,  
    double delta, double start0, double start1);
    
#endif /* ONEVAR_SECANT_H */
