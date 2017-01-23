cc = g++
flags = -pedantic
objects = emitter.o lexer.o main.o parser.o symbol.o

comp: $(objects)
	$(cc) $(flags) $^ -o $@ -lfl
lexer.c: lexer.l global.h
	flex -o lexer.c lexer.l
parser.c parser.h: parser.y
	bison -o parser.c -d parser.y
emitter.o: emitter.c parser.h global.h
	$(cc) $(flags) -c emitter.c -o emitter.o
lexer.o: lexer.c global.h
	$(cc) $(flags) -c lexer.c -o lexer.o
main.o: main.c global.h
	$(cc) $(flags) -c main.c -o main.o
parser.o: parser.c parser.h global.h
	$(cc) $(flags) -c parser.c -o parser.o
symbol.o: symbol.c global.h
	$(cc) $(flags) -c symbol.c -o symbol.o

clean:
	rm -f *.o
	rm -f comp
	rm -f lexer.c
	rm -f parser.c
	rm -f parser.h

.PHONY : clean
