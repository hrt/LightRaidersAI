CC			= g++
CFLAGS  = -std=c++11 -Wall -Werror -pedantic
SRC			= src/
OBJDIR	= obj
SRCDIR	= src
OUTDIR	= bin

OOBJ		= bot.o parser.o util.o

_DEPS		= bot.h parser.h util.h process.h test.h
DEPS    = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ		= $(OOBJ) main.o
OBJ			= $(patsubst %,$(OBJDIR)/%,$(_OBJ))

_TOBJ		= $(OOBJ) test.o bot_test.o util_test.o parser_test.o
TOBJ		=  $(patsubst %,$(OBJDIR)/%,$(_TOBJ))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(OUTDIR)/LightRaider: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(OUTDIR)/Test:	$(TOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean check all

clean:
	rm -f $(OBJDIR)/*.o $(OUTDIR)/LightRaider $(OUTDIR)/Test

check: $(OUTDIR)/LightRaider $(OUTDIR)/Test
	./$(OUTDIR)/Test < input.txt