#include <stdio.h>  // printf
#include <stdbool.h>
#include "onevar_secant.h"


double myparabel(double x, const double* params){
    return params[0] * x * x;
}


int main()
{
    // optimization settings
    double maxjump = 15;  // max num iter after a new best solution was found
    double maxiter = 300; // maximum total number of iterations
    double tolfun = 1e-8; // better use 1e-12
    bool disp = true;
    double delta = 0.1; // fixed learning rate
    double x0 = -0.33; // initial/start values 
    double x1 =  1.33; // important! x0 != x1

    // target function
    ONEVAR_FUNC_PTR fun = &myparabel;
    double params[] = {2.0};

    OnevarResult res;
    res = onevar_secant(fun, params, disp, maxiter, tolfun, maxjump, delta, x0, x1);

    print_onevar_result(res);
	return 0;
}
