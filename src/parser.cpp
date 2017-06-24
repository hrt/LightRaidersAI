#include "parser.h"
using namespace std;

Parser::Parser(Bot &Bot) : bot(bot)
{
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
    cout << "Undefined process.." << endl;
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

void Parser::parseSettings(stringstream &myStream)
{

  string settings = parseWord(myStream);

  if (!settings.compare(SETTINGS_TIMEBANK))
  {
    cout << SETTINGS_TIMEBANK << endl;
  } else if (!settings.compare(SETTINGS_YOUR_BOT))
  {
    cout << SETTINGS_YOUR_BOT << endl;
  } else if (!settings.compare(SETTINGS_PLAYER_NAMES))
  {
    cout << SETTINGS_PLAYER_NAMES << endl;
  } else if (!settings.compare(SETTINGS_FIELD_WIDTH))
  {
    cout << SETTINGS_FIELD_WIDTH << endl;
  } else if (!settings.compare(SETTINGS_FIELD_HEIGHT))
  {
    cout << SETTINGS_FIELD_HEIGHT << endl;
  } else if (!settings.compare(SETTINGS_YOUR_BOT_ID))
  {
    cout << SETTINGS_YOUR_BOT_ID << endl;
  } else if (!settings.compare(SETTINGS_TIME_PER_MOVE))
  {
    cout << SETTINGS_TIME_PER_MOVE << endl;
  } else {
    cout << "Undefined settings.." << endl;
  }

}

void Parser::parseUpdate(stringstream &myStream)
{
  string update = parseWord(myStream);
  update = parseWord(myStream);

  if (!update.compare(UPDATE_GAME_ROUND))
  {
    cout << UPDATE_GAME_ROUND << endl;
  } else if (!update.compare(UPDATE_GAME_FIELD))
  {
    cout << UPDATE_GAME_FIELD << endl;
  } else {
    cout << "Undefined update.." << endl;
  }
}

void Parser::parseAction(stringstream &myStream)
{
  string action = parseWord(myStream);

  if (!action.compare(ACTION_MOVE))
  {
    cout << ACTION_MOVE << endl;
  } else {
    cout << "Undefined action.." << endl;
  }
}