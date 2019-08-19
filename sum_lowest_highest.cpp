// ############################################
// Author: 	Amber Rogowicz
// File	:	sum_lowest_highest.cpp   
// Date:	Aug 2019
// Description:
//          Given N number of integers in a list
//          return the sum of the lowest N-1 elements in the list
//          and the sum of the highest N-1 elements in the list
//          e.g.  Inputs:  LIST = 0 -1 2 -3 -4 -5 6 7 8 9
//                Outputs: 10 19  
//          



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// for test purposes hardcoded lists containing end cases, etc
// are provided


static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << "  | -h | # | [ANY GARBAGE]\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t WITH NO PARAMETERS \t\t means use default case lists \n"
              << "\t TODO: INT INT INT INT \t\t  = run with a list of integers separated by spaces \n"
              << std::endl;
}

void print_elem( int elem )
{
	 std::cout << elem << " " ;
}
	
int main(int argc, char *argv[]) 
{
	const int NUMCASES = 4;
	vector<int> lists[] = { { 0, -1 , 2,  -3, -4, -5, 6, 7, 8, 9 },
							{ 0, -3, -5, 6, 22, 135, 17, -5, 2, -3,  -5,  17 },
	                      	{ 0, -5, 22, 135, 17 },
	                      	{ 1 } };

    if (argc > 1) 
	{
		// get the list of integers from the command line
    	std::string arg  = argv[1];
        if ((arg == "-h") || (arg == "--help")) 
		{
            // user  is asking for help to run the program
            show_usage(argv[0]);
            return(1);
    	}
		/* 
		try {
            // string -> of space separated integers
            // TODO intList.push_back( std::stoi(arg));
		} catch(...){
            	//return(1);
    	} 
		*/
    } else 
	{
		std::cout << "Running with hardcoded list cases\n\n";
		int numSummed;
		for( auto i = 0; i < NUMCASES ; i++ )
		{
	    	vector<int> currList = lists[i];
	    	std::cout << "Evaluating List: \t" ;
			for_each( currList.begin() , currList.end(), print_elem ) ;
	    	std::cout << endl;
            sort(currList.begin(), currList.end());
			numSummed = currList.size()-1;
			// since Im providing the lists, no need to check for empty list
			if( numSummed == 0 )
			{
			     std::cout << "Not enough list elements to compute a sum of N-1 elements" << endl;
			}else {
				std::cout << "Lowest " << numSummed << " sum: " << accumulate( currList.begin(), currList.end() - 1, 0) << endl;
				std::cout << "Highest " << numSummed << " sum: " << accumulate( currList.begin()+1, currList.end(), 0 ) << endl;
			}
			
			std::cout << endl;

		}
	}
	exit(0);
}
