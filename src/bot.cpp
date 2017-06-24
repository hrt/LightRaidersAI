#include "bot.h"

using namespace std;

Bot::Bot()
{
  srand(time(NULL));
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
  positionP0 = -10000;
  positionP1 = -10000;
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
    int difference = p - positionP0;
    positionP0 = p;
    switch (difference)
    {
      case MOVED_UP: return UP;
      case MOVED_DOWN: return DOWN;
      case MOVED_LEFT: return LEFT;
      case MOVED_RIGHT: return RIGHT;
      default: return ANY;
    }
  } else if (!position.compare(POS_P1))
  {
    int difference = p - positionP1;
    positionP1 = p;
    switch(difference)
    {
      case MOVED_UP: return UP;
      case MOVED_DOWN: return DOWN;
      case MOVED_LEFT: return LEFT;
      case MOVED_RIGHT: return RIGHT;
      default: return ANY;
    }
  } else {
    cerr << "Unexpected field position.." << endl;
  }
  return -1337;
}

void Bot::makeMove(int time)
{
  vector<int> moves = generateMoves(id, field);
  int randomIndex = rand() % (moves.size());
  cout << moveToString(moves[randomIndex]) << endl;
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
    case ANY: return 'O';
    case LEFT: return '<';
    case RIGHT: return '>';
    case DOWN: return 'v';
    case UP: return '^';
    case WALL: return 'x';
    case EMPTY: return ' ';
    default: return '!';
  }
}

vector<int> Bot::generateMoves(int id, vector<vector<int>> field)
{
  vector<int> moves;
  int position = -1;
  if (id == PID_0)
  {
    position = positionP0;
  } else if (id == PID_1)
  {
    position = positionP1;
  } else {
    cerr << "Unexpected id (generateMoves) .." << endl;
    return moves;
  }

  int x = position%FIELD_WIDTH;
  int y = position/FIELD_WIDTH;

  int direction = field[x][y];

  switch (direction)
  {
    case ANY:
      moves.push_back(UP);
      moves.push_back(DOWN);
      moves.push_back(LEFT);
      moves.push_back(RIGHT);
      break;
    case UP:
      if (x < (FIELD_WIDTH_R))
        moves.push_back(RIGHT);
      if (x > 0)
        moves.push_back(LEFT);
      if (y > 0)
        moves.push_back(UP);
      break;
    case DOWN:
      if (x < (FIELD_WIDTH_R))
        moves.push_back(RIGHT);
      if (x > 0)
        moves.push_back(LEFT);
      if (y < FIELD_HEIGHT_R)
        moves.push_back(DOWN);
      break;
    case LEFT:
      if (x > 0)
        moves.push_back(LEFT);
      if (y < FIELD_HEIGHT_R)
        moves.push_back(DOWN);
      if (y > 0)
        moves.push_back(UP);
      break;
    case RIGHT:
      if (x < (FIELD_WIDTH_R))
        moves.push_back(RIGHT);
      if (y < FIELD_HEIGHT_R)
        moves.push_back(DOWN);
      if (y > 0)
        moves.push_back(UP);
      break;
  }

  return moves;
}

string Bot::moveToString(int move)
{
  switch (move)
  {
    case (UP): return "up";
    case (DOWN): return "down";
    case (LEFT): return "left";
    case (RIGHT): return "right";
    default: return "Invalid Move (moveToString).."; 
  }
}