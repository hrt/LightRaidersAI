#include "parser_test.h"

using namespace std;

bool parseLineTest()
{
  bool allPassed = true;

  Bot bot = Bot();
  Parser parser = Parser(bot);


  int timeBank = 10000;
  int timePerMove = 200;
  std::string p0_name = "player0";
  std::string p1_name = "player1";
  int botid = 0;
  int width = 16;
  int height = 16;
  int round = 0;

  for (int i = 0; i < 9; i++)
    parser.parseLine();

  allPassed &= timeBank == bot.getTimeBank();
  allPassed &= timePerMove == bot.getTimePerMove();
  allPassed &= !bot.getPlayerNames()[0].compare(p0_name);
  allPassed &= !bot.getPlayerNames()[1].compare(p1_name);
  allPassed &= !bot.getYourBot().compare(p0_name);
  allPassed &= botid == bot.getYourBotId();
  allPassed &= width == bot.getFieldWidth();
  allPassed &= height == bot.getFieldHeight();
  allPassed &= round == bot.getRound();

  return allPassed;
}

bool parserTest()
{
  bool allPassed = true;
  allPassed &= parseLineTest();
  return allPassed;
}