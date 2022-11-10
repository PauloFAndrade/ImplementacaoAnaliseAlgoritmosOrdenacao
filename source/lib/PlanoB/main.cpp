/*!
 * @file main.cpp
 * Benchmarking suit to compare sorting algorithms under verios situations.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
#include <cassert>  
#include <algorithm>
#include <functional>
#include <string.h>
using std::function;

#include "../sorting.h"
#include "timing.h"

//=== ALIASES
    
/// Data type we are working with.
using value_type = long int;
/// Size type.
using size_type = long int;
/// Alias for duration measure.
using duration_t = std::chrono::duration<double>;


//=== FUNCTION IMPLEMENTATION.

/// Print time different in an humam readable form.
void print_diff( const std::chrono::time_point<std::chrono::steady_clock> &start,
                 const std::chrono::time_point<std::chrono::steady_clock> &end ){
    auto diff = end - start;
    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;
    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;
}

/// The running options
struct RunningOpt{
    size_t min_sample_sz{1000};   //!< Default 10^3.
    size_t max_sample_sz{100000}; //!< The max sample size.
    int n_samples{25};            //!< The number of samples to collect.
    short which_algs{0};          //!< Bit code for the chosen algorithms to run.
    short which_scenarios{1};     //!< Bit code for the chosen scenarios to run.

    /// Returns the sample size step, based on the [min,max] sample sizes and # of samples.
    size_type sample_step(void){
        return static_cast<float>(max_sample_sz-min_sample_sz)/(n_samples-1);
    }

    void readInput(int qtdArgs,char* argv[]){
        std::cout << "Quantidade De Argumentos: " << qtdArgs << std::endl;
        for(int i{0};i<qtdArgs;i++){
            if(strcmp(argv[i],"-min")==0){
                min_sample_sz = std::stoi(argv[i+1]);
                std::cout << "Valor Mínimo: " << min_sample_sz << std::endl;
            }else if(strcmp(argv[i],"-max")==0){
                max_sample_sz = std::stoi(argv[i+1]);
                std::cout << "Valor Máximo: " << max_sample_sz << std::endl;
            }else if(strcmp(argv[i],"-s")==0){
                n_samples = std::stoi(argv[i+1]);
                std::cout << "Quantidade de Amostras: " << n_samples << std::endl;
            }else if(strcmp(argv[i],"insertion")==0){
                which_algs += Insertion;
            }else if(strcmp(argv[i],"selection")==0){
                which_algs += Selection;
            }else if(strcmp(argv[i],"bubble")==0){
                which_algs += Bubble;
            }else if(strcmp(argv[i],"shell")==0){
                which_algs += Shell;
            }else if(strcmp(argv[i],"merge")==0){
                which_algs += Merge;
            }else if(strcmp(argv[i],"quick")==0){
                which_algs += Quick;
            }else if(strcmp(argv[i],"radix")==0){
                which_algs += Radix;
            }
        }
    }
};

/// Comparison function for the test experiment.
constexpr bool compare( const int&a, const int &b ){
    return ( a < b );
}

//=== CONSTANT DEFINITIONS.

/// Number of runs we need to calculate the average runtime for a single algorithm.
constexpr short N_RUNS = 5;

//=== The main function, entry point.
int main( int argc, char * argv[] ){
    // Process any command line arguments.
    // TODO: create proper cli for this program.
    // sort_suit [running_options] <nominal_alg_list>
    // $./sort_suite -min 10000 -max 100000 -s 25 quick insertion radix
    RunningOpt run_opt;
    //timing dataset;

    // READ ALL CHOSEN OPTIONS
    run_opt.readInput(argc,argv);

    Timing teste{run_opt.which_algs};
    
    // FOR EACH DATA SCENARIO DO...
    //while(!dataset.has_ended()){
        // Collect data in a linear (arithmetic) scale.
        // FOR EACH SAMPLE SIZE DO...
        /*
        for ( auto ns{0} ; ns < run_opt.n_samples ; ++ns ){
            // FOR EACH SORTING ALGORITHM DO...
            // Select the first sorting algorithm.
            while (!sort_algs.has_ended()){
                // Run each algorithm N_RUN times and calculate a sample avarage for each dependent variable.
                // FOR EACH RUN DO...This is necessary to reduce any measurement noise.
                for( auto ct_run(0) ; ct_run < N_RUNS ; ++ct_run ) {
                    // Reset timer
                    auto start = std::chrono::steady_clock::now();
                    //================================================================================
                    sorting(dataset.begin_data(), dataset.end_data(), compare);
                    //================================================================================
                    auto end = std::chrono::steady_clock::now();
                    // How long did it take?
                    auto diff( end - start );
                    // -------------------------------------------------------------------------------
                    // Calculating a running (repeatedly updated) sample average.
                    // Updating elapsed time sample mean.
                    auto elapsed_time_mean = elapsed_time_mean + (  diff - elapsed_time_mean ) / static_cast<double>(ct_run+1);
                } // Loop all runs for a single sample size.
            } // Loop through all algorithms activated.
            // DATA COLLECTION FOR THIS SAMPLE SIZE (ROW) ENDS HERE.
            // If this is the first time, we must first print the header.
            if (!printed_header ){
            }
            // Send out data line to the output file.
            out_file << data_line.str() << '\n';
            // Reset dataline for the next row (sample size).
            data_line.str("");
        } // Loop through each sample size required.
        // Go to the next active scenario.
        dataset.next();
        // Close the file corresponding to this dataset.
        out_file.close();
        
    }  Loop data scenarios.

    return EXIT_SUCCESS;
}*/