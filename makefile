cc = g++
flags = -pedantic

objects = inc.o inc.h SymbolTableHelper.o SymbolTableHelper.h emitter.o lexer.o main.o parser.o symbol.o

comp: $(objects)
	$(cc) $(flags) $(objects) -o comp -lfl
SymbolTableHelper.o: SymbolTableHelper.c global.h
	$(cc) $(flags) -c SymbolTableHelper.c -o SymbolTableHelper.o
lexer.c: lexer.l global.h
	flex -o lexer.c lexer.l
parser.c parser.h: parser.y
	bison -o parser.c -d parser.y
emitter.o: emitter.c parser.h global.h inc.h
	$(cc) $(flags) -c emitter.c -o emitter.o
lexer.o: lexer.c global.h
	$(cc) $(flags) -c lexer.c -o lexer.o
inc.o: inc.c global.h
	$(cc) $(flags) -c inc.c -o inc.o
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
