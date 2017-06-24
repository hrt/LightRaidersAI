#include "bot.h"

using namespace std;

Bot::Bot()
{

}

void Bot::setTimeBank(int t)
{
  timeBank = t;
}

void Bot::setTimePerMove(int t)
{
  timePerMove = t;
}

void Bot::setPlayerNames(string player0, string player1)
{
  names.clear();
  names.push_back(player0);
  names.push_back(player1);
}

void Bot::setYourBot(string player)
{
  this->player = player;
}

void Bot::setYourBotId(int id)
{
  this->id = id;
}

void Bot::setFieldWidth(int width)
{
  this->width = width;
}

void Bot::setFieldHeight(int height)
{
  this->height = height;
}

void Bot::updateGameRound(int round)
{
  this->round = round;
}

void Bot::updateGameField(std::string field)
{
  this->field = field;
}

void Bot::makeMove(int time)
{
  cout << "not yet implemented" << endl;
  printSettings();
}

void Bot::printSettings()
{
  cout << "TimeBank : " << timeBank << endl;
  cout << "TimePerMove : " << timePerMove << endl;
  if (names.size() >= 2)
    cout << "PlayerNames : " << names[0] << ", " << names[1] << endl;
  cout << "Player : " << player << endl;
  cout << "id : " << id << endl;
  cout << "width : " << width << endl;
  cout << "height : " << height << endl;
  cout << "round : " << round << endl;
  cout << "field : " << field << endl << endl << endl;
}