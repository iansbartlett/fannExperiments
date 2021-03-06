//FANN code copied from the FANN quickstart guide- just getting familar with the FANN neural network interface
//Ian Bartlett 4/3/2014 

//Notes: 
//Sets up a general-purpose artifical neural network. Inputs, outputs,
//and hidden layers can all be configured in the constants. 
//More than 3 hidden layers will lead to fitting issues and accuracy 
//degradation unless care is taken.

#include <stdlib.h>
//#include "fann.h"
//#include "doublefann.h"
#include "doublefann.c"
#include <math.h>
int main()
{
    const unsigned int num_input = 2;
    const unsigned int num_output = 1;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 3;
    const float desired_error = (const float) 0.001;
    const unsigned int max_epochs = 500000;
    const unsigned int epochs_between_reports = 1000;

    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "xor.data", max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, "xor_float.net");

    fann_destroy(ann);

    return EXIT_SUCCESS;
}
