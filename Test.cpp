#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace itertools;
using namespace std;


TEST_CASE("Test Range")
{
    vector<int> result = {5,6,7,8};
    int j = 0;
    for(int i : range(5,9))
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 4);
    CHECK(j != 5);
    CHECK(j != 3);
    CHECK(j != 0);

    j = 0;
    result.clear();
    result = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    for(int i : range(0,21))
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 21);
    CHECK(j != 20);
    CHECK(j != 22);
    CHECK(j != 19);
    CHECK(j != 0);
    j = 0;
    result.clear();
    result = {5,5};

    for(int i : range(5,5))
    {
        CHECK(0==1); // dont need to get
    }
        
}

TEST_CASE("Test Accumulate")
{
    vector<int> result1 = {3,7,12,18,25,33};
    int j = 0;

    for (int i: accumulate(range(3,9))) // 3, 3+4, 3+4+5, 3+4+5+6, 3+4+5+6+7, 3+4+5+6+7+8 = 3,7,12,18,25,33
    {
        CHECK(i == result1.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 7);
    CHECK(j != 5);
    CHECK(j != 0);
    
    vector<int> vec = {3,4,5,6,7,8};
    j = 0;
    for (int i: accumulate(vec)) // 3, 3+4, 3+4+5, 3+4+5+6, 3+4+5+6+7, 3+4+5+6+7+8 = 3,7,12,18,25,33
    {
        CHECK(i == result1.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 7);
    CHECK(j != 5);
    CHECK(j != 0);
    j=0;
    vector<string> result2 = {"I","ILove","ILoveC++"};
    vector<string> vecString = {"I","Love","C++"};
    for (auto i: accumulate(vecString) ) // I,ILove,ILoveC++
    {
        CHECK(result2.at(j) == i);
        ++j;
    }
    CHECK(j == 3);
    CHECK(j != 4);
    CHECK(j != 2);
    CHECK(j != 0);
    j=0;
    vector<int> result3 = {3,12,60,360,2520,20160};

    for (int i: accumulate(range(3,9),[](int x, int y){return x*y;})) // 3,12,60,360,2520,20160
    {
        CHECK(i == result3.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 7);
    CHECK(j != 5);
    CHECK(j != 0);
    j=0;
    result3.clear();

    result3 = {3,7,12,18,25,33};
    for (int i: accumulate(range(3,9),[](int x, int y){return x+y;})) // 3,7,12,18,25,33
    {
        CHECK(i == result3.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 7);
    CHECK(j != 5);
    CHECK(j != 0);
    j=0;
    vector<int> set1 = {3,12,60,360,2520,20160};
    set<int> myset = {3,4,5,6,7,8};
    for (int i: accumulate(myset,[](int x, int y){return x*y;})) //3,3*4,3*4*5 ...
    {
        CHECK(i == set1.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 7);
    CHECK(j != 5);
    CHECK(j != 0);


		
}


TEST_CASE("Test Filterfalse")
{
    vector<int> result = {5,7};
    int j = 0;
    for (auto i: filterfalse([](int i){return i%2==0;}, range(5,9)) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);
    CHECK(j != 3);
    CHECK(j != 1);
    CHECK(j != 0);

    result.clear();
    j = 0;
    CHECK(j != 2);
    CHECK(j != 3);
    CHECK(j != 1);
    result = {6,8};
    for (auto i: filterfalse([](int i){return i%2!=0;}, range(5,9)) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);
    CHECK(j != 3);
    CHECK(j != 1);
    CHECK(j != 0);

    result.clear();
    j = 0;
    result = {3,4,5,7,8};
    set<int> myset = {3,4,5,6,7,8};
    for (auto i: filterfalse([](int i){return i==6;}, myset) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 5);
    CHECK(j != 6);
    CHECK(j != 4);
    CHECK(j != 0);

    result.clear();
    j = 0;
    result = {-20,-2,-1,0,-99};
    set<int> myset2 = {-20,-2,-1,0,1,3,4,5,6,7,8,20,30,40,50,60,70,72,80,90,-99,100};
    for (auto i: filterfalse([](int i){return i > 0;}, myset2) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 5);
    CHECK(j != 21);
    CHECK(j != 23);
    CHECK(j != 0);
}


TEST_CASE("Test Compress")
{
    vector<int> result = {7};
    int j = 0;
    vector<bool> myvectorBool1 = {false,false,true,false};
    for (auto i: compress(range(5,9), myvectorBool1) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 1);
    CHECK(j != 7);
    CHECK(j != 6);
    CHECK(j != 5);
    CHECK(j != 4);
    CHECK(j != 2);
    CHECK(j != -1);
    CHECK(j != 0);
    CHECK(j != 9);
    CHECK(j != 10);
    CHECK(j != 11);
    CHECK(j != 12);
    result.clear();
    j = 0;

    result = {1,7,11,20};
    j = 0;
    vector<int> myvec = {1,3,7,10,11,16,20};
    vector<bool> myvecBool = {true,false,true,false,true,false,true};
    for (auto i: compress(myvec, myvecBool) )
    {
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 4);
    CHECK(j != 5);
    CHECK(j != 6);
    CHECK(j != 5);
    CHECK(j != 3);
    CHECK(j != 2);
    CHECK(j != 1);
    CHECK(j != -1);
    CHECK(j != 0);
    CHECK(j != 9);
    CHECK(j != 10);
    CHECK(j != 11);
    CHECK(j != 12);

    result.clear();
    j = 0;

    vector<char> resultString = {'I','L', 'o', 'v', 'e', 'C', '+','+'};
    j = 0;
    CHECK(j != 7);
    CHECK(j != 6);
    CHECK(j != 5);
    CHECK(j != 4);
    CHECK(j != 3);
    CHECK(j != 2);
    CHECK(j != 9);
    CHECK(j != 10);
    CHECK(j != 11);
    CHECK(j != 12);
    CHECK(j != 13);
    CHECK(j != 14);
    CHECK(j != 15);
    CHECK(j != 16);
    CHECK(j != 17);
    CHECK(j != 18);
    CHECK(j != 19);
    CHECK(j != 20);
    vector<bool> myVectorBool {true,false,false,false,true,true,true,true,true,true,true};
    
    for (auto i: compress(string("InotLoveC++"), myVectorBool))
    {
        CHECK(resultString.at(j) == i);
        ++j;
    }
    CHECK(j == 8);
    CHECK(j != 7);
    CHECK(j != 6);
    CHECK(j != 5);
    CHECK(j != 4);
    CHECK(j != 3);
    CHECK(j != 2);
    CHECK(j != 1);
    CHECK(j != -1);
    CHECK(j != 0);
    CHECK(j != 9);
    CHECK(j != 10);
    CHECK(j != 11);
    CHECK(j != 12);
    CHECK(j != 13);
    CHECK(j != 14);
    CHECK(j != 15);
    CHECK(j != 16);
    CHECK(j != 17);
    CHECK(j != 18);
    CHECK(j != 19);
    CHECK(j != 20);


    result.clear();
    j = 0;


}

