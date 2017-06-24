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
  last_p0 = -10000;
  last_p1 = -10000;
  this->height = height;
  initialiseField();
}

void Bot::updateGameRound(int round)
{
  this->round = round;
}

void Bot::updateGameField(string positions)
{
  initialiseField();
  vector<string> position = split(positions, POS_DELIM);
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
      field[i][j] = convertPosition(position[i + j * width], i + j * width);
  }
  // this->field = field;
}

int Bot::convertPosition(string position, int p)
{
  if (!position.compare(POS_EMPTY))
  {
    return EMPTY;
  } else if (!position.compare(POS_WALL))
  {
    return WALL;
  } else if (!position.compare(POS_P0))
  {
    int difference = p - last_p0;
    last_p0 = p;
    switch (difference)
    {
      case MOVED_UP: return UP_P0;
      case MOVED_DOWN: return DOWN_P0;
      case MOVED_LEFT: return LEFT_P0;
      case MOVED_RIGHT: return RIGHT_P0;
      default: return ANY_P0;
    }
  } else if (!position.compare(POS_P1))
  {
    int difference = p - last_p1;
    last_p1 = p;
    switch(difference)
    {
      case MOVED_UP: return UP_P1;
      case MOVED_DOWN: return DOWN_P1;
      case MOVED_LEFT: return LEFT_P1;
      case MOVED_RIGHT: return RIGHT_P1;
      default: return ANY_P1;
    }
  } else {
    cerr << "Unexpected field position.." << endl;
  }
  return -1337;
}

void Bot::makeMove(int time)
{
  cerr << "not yet implemented" << endl;
  printSettings();
}

void Bot::initialiseField()
{
  field.clear();
  for (int i = 0; i < width; i++)
  {
    field.push_back(vector<int>());
    for (int j = 0; j < height; j++)
      field[i].push_back(EMPTY);
  }
}

void Bot::printSettings()
{
  cerr << "TimeBank : " << timeBank << endl;
  cerr << "TimePerMove : " << timePerMove << endl;
  if (names.size() >= 2)
    cerr << "PlayerNames : " << names[0] << ", " << names[1] << endl;
  cerr << "Player : " << player << endl;
  cerr << "id : " << id << endl;
  cerr << "width : " << width << endl;
  cerr << "height : " << height << endl;
  cerr << "round : " << round << endl;
  printField();
}

void Bot::printField()
{
  cerr << endl << endl;
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
      cerr << fieldToChar(field[i][j]);
    cerr << endl;
  }
  cerr << endl << endl;
}

char Bot::fieldToChar(int f)
{
  switch (f)
  {
    case ANY_P1:
    case LEFT_P0:
    case LEFT_P1: return '<';
    case ANY_P0:
    case RIGHT_P0:
    case RIGHT_P1: return '>';
    case DOWN_P0:
    case DOWN_P1: return 'v';
    case UP_P0:
    case UP_P1: return '^';
    case WALL: return 'x';
    case EMPTY: return ' ';
    default: return '!';
  }
}