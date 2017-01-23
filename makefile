all: comp
cc = g++
flags = -pedantic
flex_param = -lfl
objects = emitter.o lexer.o main.o parser.o symbol.o

global.h: parser.h
lexer.c: lexer.l global.h
	flex -o $@ $<
parser.c parser.h: parser.y
	bison -o parser.c -d parser.y
lexer.o: lexer.c global.h
	$(cc) $(flags) -c $< $(flex_param)
%.o: %.c global.h
	$(cc) $(flags) -c $< -o $@
comp: $(objects)
	$(cc) $(flags) $^ -o $@ $(flex_param)

clean:
	rm -f *.o
	rm -f comp
	rm -f lexer.c
	rm -f parser.c
	rm -f parser.h

.PHONY: all clean
