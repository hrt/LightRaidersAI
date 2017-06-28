#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <sstream>
#include "bot.h"
#include "process.h"

class Parser
{
public:
  Parser(Bot &bot);
  void parseLine();
private:
  std::string parseWord(std::stringstream &myStream);
  int parseInt(std::stringstream &myStream);
  void parseSettings(std::stringstream &myStream);
  void parseUpdate(std::stringstream &myStream);
  void parseAction(std::stringstream &myStream);
  Bot* bot;
  int width;
  int height;
};

#endif