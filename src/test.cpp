#include "test.h"

using namespace std;
int main()
{
  bool allPassed = true;
  allPassed &= utilTest();
  allPassed &= parserTest();

  if (!allPassed)
    return EXIT_FAILURE;
  cout << "All tests passed.." << endl;
  return EXIT_SUCCESS;
}