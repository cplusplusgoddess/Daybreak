// ############################################
// Author: 	Amber Rogowicz
// File	:	min_max_repeats.cpp   
// Date:	Aug 2019
// Description:
//          Return the number of duplicates of the 
//          lowest and the highest in a given list
//          of integers
//          e.g.  Inputs:  LIST = 0 -3 -5 6 22 135 17 -5 2 -3 -5 17
//                Outputs: 3 2  // returning the # of occurances 
//								// (of the lowest#)-5 and (highest)17
//          



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int getLowestNonuniqueOccurances( vector<int> intList )
{
	// Initialize our counts, etc
	int lowDups = 0;
	vector<int>::iterator lowIter = intList.begin();
	vector<int>::iterator nextIter= lowIter + 1;
	// start at the beginning of an ordered list and find the first
    // duplicated number in the list
	while( ( nextIter != intList.end() ) && ( lowDups == 0 ) )
	{
		if( *lowIter == *nextIter )
			lowDups++;
		lowIter++;
		nextIter++;
	}
	// if I found a duplicated number keep counting all the occurances
	while((nextIter != intList.end() ) && ( *lowIter == *nextIter ) )
	{
		lowDups++;
		lowIter++;
		nextIter++;
	}
	// if there was a repeated number, add 1 to it to indicated all
	// occurances of the number
	if( lowDups )
		lowDups++;
	return lowDups;
}

int getHighestNonuniqueOccurances( vector<int> intList )
{
	// Initialize our counts, etc
	int hiDups = 0;
	vector<int>::reverse_iterator rHiIter = intList.rbegin();
	vector<int>::reverse_iterator rPrevIter = rHiIter + 1;
	// start at the beginning of an ordered list and find the first
    // duplicated number in the list
	while( ( rPrevIter != intList.rend() ) && ( hiDups == 0 ) )
	{
		if( *rHiIter == *rPrevIter )
			hiDups++;
		rHiIter++;
		rPrevIter++;
	}
	// if I found a duplicated number keep counting all the occurances
	while((rPrevIter != intList.rend() ) && ( *rHiIter == *rPrevIter ) )
	{
		hiDups++;
		rHiIter++;
		rPrevIter++;
	}
	// if there was a repeated number, add 1 to it to indicated all
	// occurances of the number
	if( hiDups )
		hiDups++;
	return hiDups;
}

void print_elem( int elem )
{
	 std::cout << elem << " " ;
}
	
int main(int argc, char *argv[]) 
{
	const int NUMCASES = 4;
	vector<int> lists[] = { { 0, -3, -5, 6, 22, 135, 17, -5, 2, -3,  -5,  17 },
	                      { -3, -5, 22, 135, 17, -3, -5 },
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
		int lowDups = 0;
		int hiDups  = 0;
		std::cout << "Running with hardcoded list cases\n\n";
		for( auto i = 0; i < NUMCASES ; i++ )
		{
	    	vector<int> currList = lists[i];
	    	std::cout << "Evaluating List: \t" ;
			for_each( currList.begin() , currList.end(), print_elem ) ;
	    	std::cout << endl;
            sort(currList.begin(), currList.end());
			lowDups = getLowestNonuniqueOccurances( currList );
			hiDups = getHighestNonuniqueOccurances( currList );
			std::cout << "Lowest Duplicated Occurances: " << lowDups << "\t" ;
			std::cout << "Highest Duplicated Occurances: " << hiDups << "\t" ;
			std::cout << endl;

		}
	}
	exit(0);
}
