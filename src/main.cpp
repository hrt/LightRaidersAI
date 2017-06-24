#include <iostream>
#include "parser.h"
#include "bot.h"

int main()
{
  Bot bot = Bot();
  Parser parser = Parser(bot);
  parser.parseLine();  
}