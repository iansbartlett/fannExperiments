//FANN Test 1 continued- applying the network generated in fannTest1. Adapted slightly from the 
//FANN getting started tutorial.
//Ian Bartlett 4/3/2014

#include <stdio.h>
#include "doublefann.c"
#include <math.h>

int main()
{
    fann_type *calc_out;
    fann_type input[2];

    struct fann *ann = fann_create_from_file("xor_float.net");

    input[0] = -1;
    input[1] = 1;
    calc_out = fann_run(ann, input);

    printf("xor test (%f,%f) -> %f\n", input[0], input[1], calc_out[0]);

    fann_destroy(ann);
    return 0;
}
