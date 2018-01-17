#ifndef _KEL_SEARCH_H_
#define _KEL_SEARCH_H_

#include <cstddef> //size_t


int sequential_search(int target, const int target_array[], std::size_t size);
int binary_search(int target, const int sorted_array[], std::size_t size);

#endif //_KEL_SEARCH_H_