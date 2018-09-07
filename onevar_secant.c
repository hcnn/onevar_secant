#include "onevar_secant.h"

OnevarResult onevar_secant(
    ONEVAR_FUNC_PTR func, const double* params, 
    bool disp, double maxiter, double tolfun, double maxjump,  
    double delta, double start0, double start1)
{
    // declare variables
    OnevarResult res;
    double u, x, xprev, xbest, f, fprev, fbest;

    size_t i = 0; //maxiter
    size_t j = 0; //maxjump

    // set start values
    xprev = start0;
    x = start1;

    // first run
    fprev = func(xprev, params);
    f = func(x, params);

    if(f < fprev){
        fbest = f; xbest = x;
    }else{ //reorder
        fbest = fprev; xbest = xprev;
        fprev = f; xprev = x;
        f = fbest; x = xbest;
    }

    // Display
    if(disp){
        printf("Initial fun0 = %.8f\n", fbest);
        printf("%6s %6s %12s %12s\n", "i", "hump", "fun", "x");
    }

    // start loop
    while( i < maxiter && j < maxjump){
        // compute update
        u = (x - xprev) * fprev / (f - fprev);
        // store as previous value
        xprev = x;
        fprev = f;
        // compute new
        x -= delta * u;
        f = func(x, params);

        // Display
        if( disp ){
            printf("%6d %6d %12.8f %12.8f\n", (int)i, (int)j, f, x);
        }
        
        // Store results
        if( !stopping_gd(f, fbest, tolfun) ){
            fbest = f;
            xbest = x;
            j = 0;
        }else{
            j++;
        }
        i++;
    }

    // store results
    res.x = xbest;
    res.fval = fbest;
    res.numeval = i;
    return res;
}
