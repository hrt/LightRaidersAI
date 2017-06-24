#include "parser.h"
using namespace std;

Parser::Parser(Bot &Bot) : bot(bot)
{
}

void Parser::parseLine()
{
  string input = "";

  string process = "";

  getline(cin, input);
  while (true)
  {
    stringstream myStream(input);
    if (myStream >> process)
      break;
  }

  if (!process.compare(PROCESS_SETTINGS))
  {
    cout << "Processing settings.." << endl;
  } else if (!process.compare(PROCESS_UPDATE))
  {
    cout << "Processing update.." << endl;
  } else if (!process.compare(PRCOESS_ACTION))
  {
    cout << "Processing action.." << endl;
  } else {
    cout << "Undefined action.." << endl;
  }
}