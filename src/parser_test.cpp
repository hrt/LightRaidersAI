#include "parser_test.h"

using namespace std;

bool parseLineTest()
{
  bool allPassed = true;

  Bot bot = Bot();
  Parser parser = Parser(bot);


  int timeBank = 10000;
  parser.parseLine();
  allPassed &= timeBank == bot.getTimeBank();

  return allPassed;
}

bool parserTest()
{
  bool allPassed = true;
  allPassed &= parseLineTest();
  return allPassed;
}