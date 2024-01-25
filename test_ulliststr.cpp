#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//added
using namespace std;
#include <iostream>

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  //TEST 1 - push front 11 numbers
  /*dat.push_front("0");
  dat.push_front("1");
  dat.push_front("2");
  dat.push_front("3");
  dat.push_front("4");
  dat.push_front("5");
  dat.push_front("6");
  dat.push_front("7");
  dat.push_front("8");
  dat.push_front("9");
  dat.push_front("a");
  dat.push_front("b");*/

  //TEST 2 - push back 12 numbers
  /*dat.push_back("0");
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("a");
  dat.push_back("b");*/

  //TEST front and back
  /*cout << dat.front() << endl;
  cout << dat.back() << endl;*/

  //TEST pop_front
  /*dat.pop_front();
  cout << dat.front() << endl;*/

  //TEST pop_back
  /*cout << dat.back() << endl;
  dat.pop_back();
  cout << dat.back() << endl;*/

  //Another pop_front test
  /*ULListStr list;
  for (int i = 0; i < 50; i++){
	  list.push_back("a");
    list.pop_back();
  }*/
  /*for (int i = 0; i < 50; i++){
	  
  }*/
  ULListStr list;
	list.push_back("oldfront");
	list.push_back("oldback");
  cout << list.get(0) << " " << list.get(1) << endl;

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");
  cout << list.get(0) << " " << list.get(1) << endl;
	//EXPECT_TRUE(checkListContent(&list, {"newfront", "oldback"}));

	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");
  cout << list.get(0) << " " << list.get(1) << endl;
	// EXPECT_TRUE(checkListContent(&list, {"cloudfront", "newfront"}));
	// now, the original head should get deleted
	list.pop_back();
  //cout << list.get(0) << endl;
	//EXPECT_TRUE(checkListContent(&list, {"cloudfront"}));
  
	list.pop_front();
	//EXPECT_TRUE(checkListContent(&list, {}));

	list.push_front("newback");
  cout << list.get(0) << endl;
	//EXPECT_TRUE(checkListContent(&list, {"newback"}));


  /*cout << dat.get(0) << dat.get(1) << dat.get(2) << dat.get(3) << endl;
  cout << dat.get(4) << dat.get(5) << dat.get(6) << dat.get(7) << endl;  
  cout << dat.get(8) << dat.get(9) << dat.get(10) << dat.get(11) << endl; */
}
