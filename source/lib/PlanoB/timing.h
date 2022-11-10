#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <locale.h>
#include <random>

#include "../sorting.h"

enum ORDEM_TYPES{
    non_decreasing,
    non_increasing,
    all_random,
    sorted_75,
    sorted_50,
    sorted_25
};

enum ALGORITHMS{
    Insertion = 1,
    Selection = 2,
    Bubble = 4,
    Shell = 8,
    Quick = 16, 
    Merge = 32,
    Radix = 64,
    All = 127
};

/// Data type we are working with.
using value_type = long int;
/// Size type.
using size_type = long int;

class Timing{
    public:
        // has_ended();
        bool has_ended();
        //begin_data();
        int* begin_data(); //ADRESS TO FIRST POSITION
        //end_data();    
        int* end_data(); //ADRESS TO LAST POSITION++
        //next();
        int next(); //GO TO NEXT SCENARIO
        //readInput();
        //void readInput(int qtdArgs,char** argv); //READ ALL THE ARGUMENTS THAT REPRESENT THE CLIENT'S CHOICES

        timing(short which_algs=0){
            if(which_algs & ALGORITHMS::Insertion){
                std::cout << "Insertion Ligado\n";
                m_sorting_algs.push_back("Insertion",sa::insertion);
            }
            if(which_algs & ALGORITHMS::Selection){
                std::cout << "Selection Ligado\n";
                m_sorting_algs.push_back("Selection",sa::selection);
            }
            if(which_algs & ALGORITHMS::Bubble){
                std::cout << "Bubble Ligado\n";
                m_sorting_algs.push_back("Bubble",sa::bubble);
            }
            if(which_algs & ALGORITHMS::Shell){
                std::cout << "Shell Ligado\n";
                m_sorting_algs.push_back("Shell",sa::shell);
            }
            if(which_algs & ALGORITHMS::Quick){
                std::cout << "Quick Ligado\n";
                m_sorting_algs.push_back("Quick",sa::quick);
            }
            if(which_algs & ALGORITHMS::Merge){
                std::cout << "Merge Ligado\n";
                m_sorting_algs.push_back("Merge",sa::merge);
            }
            if(which_algs & ALGORITHMS::Radix){
                std::cout << "Radix Ligado\n";
                m_sorting_algs.push_back("Radix",sa::radix);
            }
        }
    private:
        std::vector<value_type> backup;
        std::vector<value_type> sorting;

        typedef std::vector<value_type>::interator RandomIt;
        using SortFuncType = void (*)(RandomIt, RandomIt, Compare);

        using MapItem = std::pair<std::string, SortFuncType>;
        std::vector<MapItem> m_sorting_algs;

        int currentScenario;
        int currentSample;
        int currentAlgorithm;
};