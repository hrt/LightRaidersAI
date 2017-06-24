#ifndef BOT_H
#define BOT_H
#include <string>
#include <vector>
#include <iostream>
class Bot
{
public:
  Bot();
  void setTimeBank(int t);
  void setTimePerMove(int t);
  void setPlayerNames(std::string player0, std::string player1);
  void setYourBot(std::string player);
  void setYourBotId(int id);
  void setFieldWidth(int width);
  void setFieldHeight(int height);
  void updateGameRound(int round);
  void updateGameField(std::string field);
  void makeMove(int time);
  void printSettings();
private:
  int timeBank;
  int timePerMove;
  std::vector<std::string> names;
  std::string player;
  int id;
  int width;
  int height;
  int round;
  std::string field;
};

#endif