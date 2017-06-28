#include "test.h"

using namespace std;
int main()
{
  bool allPassed = true
;  allPassed &= botTest();
  allPassed &= parserTest();
  allPassed &= utilTest();
  if (!allPassed)
    return EXIT_FAILURE;
  cout << "All tests passed.." << endl;
  return EXIT_SUCCESS;
}