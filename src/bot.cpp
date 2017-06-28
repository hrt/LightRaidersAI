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

int Bot::getTimeBank()
{
  return timeBank;
}

int Bot::getTimePerMove()
{
  return timePerMove;
}

std::vector<std::string> Bot::getPlayerNames()
{
  return names;
}

std::string Bot::getYourBot()
{
  return player;
}

int Bot::getYourBotId()
{
  return id;
}

int Bot::getFieldWidth()
{
  return width;
}

int Bot::getFieldHeight()
{
  return height;
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
  int position = -1;
  int enemyPosition = -1;
  if (id == PID_0)
  {
    position = positionP0;
    enemyPosition = positionP1;
  } else if (id == PID_1)
  {
    position = positionP1;
    enemyPosition = positionP0;
  }

  int enemyId = 1-id;

  vector<int> myMoves = generateMoves(id, position, field);
  vector<int> enemyMoves = generateMoves(enemyId, position, field);
  if (myMoves.size() == 0)
  {
    cout << "no_moves" << endl;
  }
  else
  {
    int maxScore = -999999;
    int bestMove = -1;

    for (int move : myMoves)
    {
      int tempPosition = position;
      int currentScore = 0;
      vector<vector<int>> newField(field);
      vector<int> childMoves = generateMoves(id, tempPosition, newField);


      while (find(childMoves.begin(), childMoves.end(), move) != childMoves.end())
      {
        currentScore += 1;
        newField = applyMove(id, tempPosition, move, newField);
        childMoves = generateMoves(id, tempPosition, newField);
      }

      int minScore = 999999;

      for (int move : enemyMoves)
      {
        int tempPosition = enemyPosition;
        int currentScore = 0;

        vector<int> childMoves = generateMoves(enemyId, tempPosition, newField);


        while (find(childMoves.begin(), childMoves.end(), move) != childMoves.end())
        {
          currentScore -= 1;
          newField = applyMove(enemyId, tempPosition, move, newField);
          childMoves = generateMoves(enemyId, tempPosition, newField);
        }

        if (currentScore < minScore)
        {
          minScore = currentScore;
        }

      }

      currentScore -= minScore;

      if (currentScore > maxScore)
      {
        maxScore = currentScore;
        bestMove = move;
      }
    }
    cout << moveToString(bestMove) << endl;
  }
}

  vector<vector<int>> Bot::applyMove(int id, int &position, int move, vector<vector<int>> field)
  {
    int x = position%FIELD_WIDTH;
    int y = position/FIELD_WIDTH;
    field[x][y] = WALL;

    switch (move)
    {
      case UP:
        y -= 1;
        break;
      case DOWN:
        y += 1;
        break;
      case LEFT:
        x -= 1;
        break;
      case RIGHT:
        x += 1;
        break;
      default:
        cerr << "Invalid move (applyMove).." << endl;
    }

    field[x][y] = move;
    position = x + y * FIELD_WIDTH;
    return field;
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
  printField(field);
}

void Bot::printField(vector<vector<int>> field)
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

vector<int> Bot::generateMoves(int id, int position, vector<vector<int>> field)
{
  vector<int> moves;

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
      if (x < (FIELD_WIDTH_R) && field[x+1][y] == EMPTY)
        moves.push_back(RIGHT);
      if (x > 0 && field[x-1][y] == EMPTY)
        moves.push_back(LEFT);
      if (y > 0 && field[x][y-1] == EMPTY)
        moves.push_back(UP);
      break;
    case DOWN:
      if (x < (FIELD_WIDTH_R) && field[x+1][y] == EMPTY)
        moves.push_back(RIGHT);
      if (x > 0 && field[x-1][y] == EMPTY)
        moves.push_back(LEFT);
      if (y < FIELD_HEIGHT_R && field[x][y+1] == EMPTY)
        moves.push_back(DOWN);
      break;
    case LEFT:
      if (x > 0 && field[x-1][y] == EMPTY)
        moves.push_back(LEFT);
      if (y < FIELD_HEIGHT_R && field[x][y+1] == EMPTY)
        moves.push_back(DOWN);
      if (y > 0 && field[x][y-1] == EMPTY)
        moves.push_back(UP);
      break;
    case RIGHT:
      if (x < (FIELD_WIDTH_R) && field[x+1][y] == EMPTY)
        moves.push_back(RIGHT);
      if (y < FIELD_HEIGHT_R && field[x][y+1] == EMPTY)
        moves.push_back(DOWN);
      if (y > 0 && field[x][y-1] == EMPTY)
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