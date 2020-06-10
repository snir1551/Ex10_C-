#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <string>
using namespace itertools;
using namespace std;

TEST_CASE("Test Range")
{
    	for (int i: range(5,9))
		    cout << i << " "; 
        cout << endl; 
        for (int i: accumulate(range(5,9))) //5,6,7,8
		cout << i << " ";      // 5 11 18 26
}

