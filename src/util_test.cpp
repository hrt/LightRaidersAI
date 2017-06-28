#include "util_test.h"

using namespace std;
bool utilTest()
{
  bool allPassed = true;

  string testTwoSeperated = "4,5";
  string testThreeSeperated = "4,5,7";
  string testStringSeperated = "hello;world";

  vector<string> t2 = split(testTwoSeperated, ',');
  vector<string> t3 = split(testThreeSeperated, ',');
  vector<string> ts = split(testStringSeperated, ';');

  allPassed &= !t2[0].compare("4") && !t2[1].compare("5");
  allPassed &= !t3[0].compare("4") && !t3[1].compare("5") && !t3[2].compare("7");
  allPassed &= !ts[0].compare("hello") && !ts[1].compare("world");

  return allPassed;
}