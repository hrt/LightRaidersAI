#include "parser.h"
#include "util.h"
using namespace std;

Parser::Parser(Bot &bot)
{
  this->bot = bot;
}

void Parser::parseLine()
{
  string input = "";

  getline(cin, input);
  stringstream myStream(input);

  string process = parseWord(myStream);

  if (!process.compare(PROCESS_SETTINGS))
  {
    parseSettings(myStream);
  } else if (!process.compare(PROCESS_UPDATE))
  {
    parseUpdate(myStream);
  } else if (!process.compare(PRCOESS_ACTION))
  {
    parseAction(myStream);
  } else {
    cerr << "Undefined process.." << endl;
  }
}

string Parser::parseWord(stringstream &myStream)
{
  string word = "";
  while (true)
  {
    if (myStream >> word)
      return word;
  }
}

int Parser::parseInt(stringstream &myStream)
{
  int i;
  while (true)
  {
    if (myStream >> i)
      return i;
  }
}

void Parser::parseSettings(stringstream &myStream)
{

  string settings = parseWord(myStream);

  if (!settings.compare(SETTINGS_TIMEBANK))
  {
    bot.setTimeBank(parseInt(myStream));
  } else if (!settings.compare(SETTINGS_YOUR_BOT))
  {
    bot.setYourBot(parseWord(myStream));
  } else if (!settings.compare(SETTINGS_PLAYER_NAMES))
  {
    std::vector<string> players = split(parseWord(myStream), ',');
    bot.setPlayerNames(players[0], players[1]);
  } else if (!settings.compare(SETTINGS_FIELD_WIDTH))
  {
    bot.setFieldWidth(parseInt(myStream));
  } else if (!settings.compare(SETTINGS_FIELD_HEIGHT))
  {
    bot.setFieldHeight(parseInt(myStream));
  } else if (!settings.compare(SETTINGS_YOUR_BOT_ID))
  {
    bot.setYourBotId(parseInt(myStream));
  } else if (!settings.compare(SETTINGS_TIME_PER_MOVE))
  {
    bot.setTimePerMove(parseInt(myStream));
  } else {
    cerr << "Undefined settings.." << endl;
  }

}

void Parser::parseUpdate(stringstream &myStream)
{
  string update = parseWord(myStream);
  update = parseWord(myStream);

  if (!update.compare(UPDATE_GAME_ROUND))
  {
    bot.updateGameRound(parseInt(myStream));
  } else if (!update.compare(UPDATE_GAME_FIELD))
  {
    bot.updateGameField(parseWord(myStream));
  } else {
    cerr << "Undefined update.." << endl;
  }
}

void Parser::parseAction(stringstream &myStream)
{
  string action = parseWord(myStream);

  if (!action.compare(ACTION_MOVE))
  {
    bot.makeMove(parseInt(myStream));
  } else {
    cerr << "Undefined action.." << endl;
  }
}