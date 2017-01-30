%{
	#include "global.h"

	using namespace std;

	int tmpArrayElementType;	//zmienna pomocnicza dla array do przekazania typu po deklaracji
	int startOffsertParamtersFunProcHelper = 8;	// 8 dla proc 12 dla fun
	ArrayInfo tmpArrayInfo;
	vector<int> tmpArgParamVector; //lista zmiennych którym później będzie przydzielony typ podczas deklaracji | lista argumentów funkcji write, ride
	list<pair<int, ArrayInfo> > paramHelper;	//lista na parametry funkcji
	list<int> funParamsHelper; //LISTA DO OBLICZANIA INCSP

	void yyerror(char const* s);
%}

%token 	PROGRAM
%token 	BEGINN
%token 	END
%token 	VAR
%token 	INTEGER
%token  REAL
%token	ARRAY
%token 	OF
%token	FUN
%token 	PROC
%token	IF
%token	THEN
%token	ELSE
%token	DO
%token	WHILE
%token 	RELOP
%token 	MULOP
%token 	SIGN
%token 	ASSIGN
%token	OR
%token 	NOT
%token 	ID
%token 	NUM
%token 	NONE
%token 	DONE

%%

program:
		PROGRAM ID '(' start_identifiers ')' ';' declarations subprogram_declarations
			{
				writeToOutput("lab0:");
			}
		compound_statement
		'.'
			{
				writeToOutputExt("","exit","",";exit ","");
				writeToFile();
			}
		eof
	;

start_identifiers:
		ID
	| start_identifiers ',' ID
	;

identifier_list:
		ID
			{
				checkSymbolExist($1);
				tmpArgParamVector.push_back($1);
			}
	| identifier_list ',' ID
			{
				checkSymbolExist($3);
				tmpArgParamVector.push_back($3);
			}
	;

declarations:
	declarations VAR identifier_list ':' type ';'
		{
			for(auto &index : tmpArgParamVector)
			{
				if($5 == INTEGER || $5 == REAL)
				{
					SymbolTable[index].token = VAR;
					SymbolTable[index].type = $5;
					SymbolTable[index].address = getSymbolAddress(SymbolTable[index].name);
				}
				else if($5 == ARRAY)
				{
					SymbolTable[index].token = $5;
					SymbolTable[index].type = tmpArrayElementType;
					SymbolTable[index].arrayInfo = tmpArrayInfo;
					SymbolTable[index].address = getSymbolAddress(SymbolTable[index].name);
				}
				else
				{
					yyerror("Nieobslugiwany typ");
					YYERROR;
				}
			}
			tmpArgParamVector.clear();
		}
	| //empty
	;

type:
		standard_type
	| ARRAY '[' NUM '.' '.' NUM ']' OF standard_type
			{
				$$ = ARRAY;
				tmpArrayElementType = $9;
				tmpArrayInfo.startId = $3;
				tmpArrayInfo.stopId = $6;
				tmpArrayInfo.startVal = atoi(SymbolTable[$3].name.c_str());
				tmpArrayInfo.stopVal = atoi(SymbolTable[$6].name.c_str());
				tmpArrayInfo.argType = $9;
			}
	;

standard_type:
		INTEGER
	| REAL
	;

subprogram_declarations:
		subprogram_declarations subprogram_declaration ';'
	| //empty
	;

subprogram_declaration:
		subprogram_head declarations compound_statement
			{ 
				//end of fun/proc
				writeToOutputExt("","leave","",";leave ","");
				writeToOutputByToken(RETURN,-1,true,-1,true,-1,true);
				printSymbolTable();
				//reset
				clearLocalSymbols();
				isGlobal = true;
				startOffsertParamtersFunProcHelper = 8;
			}
	;

subprogram_head:
		FUN ID
			{	
				const int functionOffset = 12;
				
				checkSymbolExist($2);
				SymbolTable[$2].token = FUN;
				isGlobal = false;
				startOffsertParamtersFunProcHelper = functionOffset;
				writeToOutputByToken(FUN, $2 ,true ,-1 ,true ,-1 ,true);
			}
		arguments
			{	
				SymbolTable[$2].parameters = paramHelper;
				paramHelper.clear();
			}
		':' standard_type
			{	
				const int functionReturnOffset = 12;
				
				SymbolTable[$2].type = $7;	//return type ????????????????
				int index = insert(SymbolTable[$2].name ,VAR ,$7); 	
				SymbolTable[index].isReference = true;
				SymbolTable[index].address = functionReturnOffset;
			}
		';'
	|	PROC ID
			{ 	
				const int procedureOffset = 8;
				
				checkSymbolExist($2);
				SymbolTable[$2].token = PROC;
				isGlobal = false;
				startOffsertParamtersFunProcHelper = procedureOffset;
				writeToOutputByToken(PROC ,$2 ,true ,-1 ,true ,-1 ,true);
			}
		arguments
			{	
				SymbolTable[$2].parameters = paramHelper;
				paramHelper.clear();
			}
		';'
	;

arguments:
		'(' parameter_list ')'
			{
				const int argumentSize = 4;
				
				for(auto &argument : funParamsHelper)
				{
					SymbolTable[argument].address = startOffsertParamtersFunProcHelper;
					startOffsertParamtersFunProcHelper += argumentSize;
				}
				funParamsHelper.clear();
			}
	| //empty
	;

parameter_list:
		identifier_list ':' type
			{
				for(auto &element : tmpArgParamVector){
					SymbolTable[element].isReference = true;
					if($3 == ARRAY)
					{
						SymbolTable[element].token = ARRAY;
						SymbolTable[element].type = tmpArrayElementType;
						SymbolTable[element].arrayInfo = tmpArrayInfo;
					}
					else
					{
						SymbolTable[element].type = $3;
					}
					paramHelper.push_back(make_pair($3, tmpArrayInfo));
					funParamsHelper.push_front(element);
				}
				tmpArgParamVector.clear();
			}
	| parameter_list ';' identifier_list ':' type
			{
				for(auto &element : tmpArgParamVector)
				{
					SymbolTable[element].isReference = true;
					if($5 == ARRAY)
					{
						SymbolTable[element].token = ARRAY;
						SymbolTable[element].type = tmpArrayElementType;
						SymbolTable[element].arrayInfo = tmpArrayInfo;
					}
					else
					{
						 SymbolTable[element].type = $5;
					}
					paramHelper.push_back(make_pair($5, tmpArrayInfo));
					funParamsHelper.push_front(element);
				}
				tmpArgParamVector.clear();
			}
	;

compound_statement:
		BEGINN optional_statement END
	;

optional_statement:
		statement_list
	| //empty
	;

statement_list:
 		statement
	| statement_list ';' statement
	;

statement:
		variable ASSIGN simple_expression
			{
				writeToOutputByToken(ASSIGN,$1,true,-1, true,$3,true);
			}
	| procedure_statement
	| compound_statement
	| IF expression
	 		{	
				////jump if expression = 0
				int label1 = insertLabel();
				int num = insertNum("0",INTEGER);
				$2 = label1;
				writeToOutputByToken(EQ, label1, true, $2, true, num, true);
			}
		THEN statement
		 	{	
				int label2 = insertLabel();
				$5 = label2;
				writeToOutputByToken(JUMP, label2, true, -1, true, -1, true);
				writeToOutputByToken(LABEL, $2, true, -1, true, -1, true);
			}
		ELSE statement
			{
				writeToOutputByToken(LABEL, $5, true, -1, true, -1, true);
			}
	| WHILE
			{	
				int labelStop = insertLabel();
				int labelStart = insertLabel();
				$$ = labelStop;
				$1 = labelStart;
				writeToOutputByToken(LABEL, labelStart, true, -1, true, -1, true);
			}
		expression DO
			{
				int id = insertNum("0",INTEGER);
				writeToOutputByToken(EQ, $2, true, $3, true, id, true);
			}
		statement
			{
				writeToOutputByToken(JUMP, $1, true, -1, true, -1, true);
				writeToOutputByToken(LABEL, $2, true, -1, true, -1, true);
			}
	;

variable:
		ID
			{
				checkSymbolExist($1);
				$$ = $1;
			}
	| ID '[' simple_expression ']'
			{	//JAK SIMPLE_EXP REAL TO ZMIEŃ NA INT, ODEJMIJ OD INDEKSU INDEX STARTOWY(WYPISZ MINUS)
				//MNOŻENIE INDEKSU RAZY TYP OCZLICZENIE ADRESU ELEMENTU W NOWEJ ZMIENNEJ, ZMIANA NA REF
				//jak real zmien na int
				if(SymbolTable[$3].type == REAL)
				{
					int convertedVal = insertTempSymbol(INTEGER);
					writeToOutputByToken(REALTOINT, convertedVal, true, $3, true, -1, true);
					$3 = convertedVal;
				}
				// wyciagnij indeks array w tablicy symboli i jej poczatkowy indeks
				int startIndex = SymbolTable[$1].arrayInfo.startId;
				int realIndex = insertTempSymbol(INTEGER); //zmienna na $3 startowy rzeczywisty
				writeToOutputByToken(MINUS, realIndex, true, $3, true, startIndex, true);	// odejmij od indeksu indeks poczatkowy
				//dodaj numy jak nie ma
				int arrayElementSize = 0;
				if(SymbolTable[$1].type == INTEGER)
				{
					arrayElementSize = insertNum("4",INTEGER);
				}
				else if(SymbolTable[$1].type == REAL)
				{
					arrayElementSize = insertNum("8",INTEGER);
				}
				//element * pozycja
				writeToOutputByToken(MUL, realIndex, true, realIndex, true, arrayElementSize, true);
				int varWithAddresOfArrayElement = insertTempSymbol(INTEGER);
				//adres początku tablicy + adres elementu w tablicy i mamy w efekcie adres z wartością w tablicy
				writeToOutputByToken(PLUS, varWithAddresOfArrayElement, true, $1, false, realIndex, true);
				//ustaw, że jest to adres referentychny bo nie wskazuje na wartość lecz na wskaźnik pod którym jest wartość adresu, ustawienei typu na int/real
				SymbolTable[varWithAddresOfArrayElement].isReference = true;
				SymbolTable[varWithAddresOfArrayElement].type = SymbolTable[$1].type;
				$$ = varWithAddresOfArrayElement;
			}
	;

procedure_statement:
		ID
			{	
				// wywołanie func/proc np aaa;WYWOŁANIE BEZ PARAMETRÓW GENERUJ CALL #SSS
				checkSymbolExist($1);
				if(SymbolTable[$1].token == FUN || SymbolTable[$1].token == PROC)
				{
					if(SymbolTable[$1].parameters.size() > 0)
					{
						yyerror("Zła liczba parametrów.");
						YYERROR;
					}
					else
					{
						writeToOutput("\tcall.i #" + SymbolTable[$1].name);
					}
				}
				else
				{
					yyerror("Program oczekiwał nazwy funkcji/procedury a otrzymał coś innego.");
					YYERROR;
				}
			}
	| ID '(' expression_list ')'
			{	//JAK READ WRITE WYPISZ ..
				//OBLICZ incspCount, FOR {KONWERTUJ TYPY I WRZUĆ NUMY DO PRZEKAZANIA JAKO PARMETRY FUNKCJI GENERUJ PUSHA}
				//USUŃ Z tmpArgParamVector, ZRÓB ZMIENNĄ NA RETURN I JĄ ZWRÓĆ JAK FUNKCJA GENERUJ CALL I INCSP
				int index = $1;
				int w = lookup("write");
				int r = lookup("read");
				if(index == w || index == r)
				{
					//dla każdego elementu z tmpArgParamVector
					for(auto &element : tmpArgParamVector)
					{
						if($1 == r)
						{
							 writeToOutputByToken(READ, element,true, -1, true, -1, true );
						}
						if($1 == w)
						{
							 writeToOutputByToken(WRITE,element,true, -1, true, -1, true );
						}
					}
				}
				else
				{
					string idName = SymbolTable[$1].name;
					int index = lookupForFunction(idName);
					if(index == -1)
					{
						yyerror("Niezadeklarowana nazwa.");
						YYERROR;
					}
					if(SymbolTable[index].token == FUN || SymbolTable[index].token == PROC)
					{
					//podano za mało parametrów
						if(tmpArgParamVector.size() < SymbolTable[index].parameters.size())
						{
							yyerror("Nieprawidłowa liczba parametrów.");
							YYERROR;
						}
						// zmienna na rozmiar wrzuconych na stos referencji
						int incspCount = 0;
						//iterator po argumentach
						list<pair<int,ArrayInfo> >::iterator it=SymbolTable[index].parameters.begin();
						int startPoint = tmpArgParamVector.size() - SymbolTable[index].parameters.size();
						// przejdź po argumentach
						for(int i = startPoint; i < tmpArgParamVector.size(); i++)
						{
							int id = tmpArgParamVector[i];
							// typ argumentu procedury/funkcji
							int argumentType = (*it).first;
							if(argumentType == ARRAY)
							{
								argumentType = (*it).second.argType;
							}
							// jeśli przekazujemy NUM to stwórz nowy obiekt w tablicy
							if(SymbolTable[tmpArgParamVector[i]].token == NUM)
							{
								// zmienna tymczasowa tworz od razu o takim typie, jakiego wymaga funkcja
								int numVar = insertTempSymbol(argumentType);
								writeToOutputByToken(ASSIGN,numVar,true, -1, true, tmpArgParamVector[i], true);
								id = numVar;
							}
							// typ przekazywany
							int passedType = SymbolTable[id].type;
							// typ argumentu funkcji i typ wartosci przekazywanej są różne (INT i REAL) - konwersja
							if(argumentType != passedType){
								int tempVar = insertTempSymbol(argumentType);
								writeToOutputByToken(ASSIGN, tempVar, true, -1, true, id, true);
								id = tempVar;
							}
							writeToOutputByToken(PUSH,id,false,-1, true, -1, true);
							incspCount+=4; // zwieksz adres parametrów
							it++;
						}
						// usun z wektora argumenty
						int size = tmpArgParamVector.size();
						for(int i = startPoint;i<size;i++)
						{
							tmpArgParamVector.pop_back();
						}
						if(SymbolTable[index].token==FUN)
						{
							// zmienna na wartość zwracaną
							int id = insertTempSymbol(SymbolTable[index].type);
							writeToOutputByToken(PUSH,id,false,-1, true, -1, true);
							incspCount+=4;	// zwiększ rozmiar
							$$ = id;
						}
						// generuj call
						writeToOutputByToken(CALL, index,true,-1,true,-1,true);
						stringstream helper;
						helper << incspCount;
						//generuj incsp
						int incspNum = insertNum(helper.str(),INTEGER);
						writeToOutputByToken(INCSP,incspNum,true,-1,true,-1,true);
					}
					else
					{
						yyerror("Brak takiej funkcji/procedury.");
						YYERROR;
					}
				}
				tmpArgParamVector.clear();
			}
	;

expression_list:
		expression
			{
				tmpArgParamVector.push_back($1);
			}
	| expression_list ',' expression
			{
				tmpArgParamVector.push_back($3);
			}
	;

expression:
		simple_expression
			{
				$$ = $1;
			}
	| simple_expression RELOP simple_expression
			{
			//GENERUJE LABELE I SKACZE W ZALEŻNOŚCI CZY SPEŁNIONY WARUNEK ZWRACA RESULTVAR
			int newLabelPass = insertLabel();
			//skok jeżeli warunek spełniony
			writeToOutputByToken($2, newLabelPass, true, $1, true, $3, true);
			//wynik operacji RELOP czyli 0 lub 1
			int resultVar = insertTempSymbol(INTEGER);
			int badVal = insertNum("0",INTEGER);
			//ustawia resultVar na 0 (warunek nie spełniony, nie przeskoczyliśmy)
			writeToOutputByToken(ASSIGN, resultVar, true, -1, true, badVal, true);
			//label ostatni za którym idzie dalsza część programu ten po obu (0 i 1)
			int newLabelFinish = insertLabel();
			writeToOutputByToken(JUMP, newLabelFinish, true, -1, true, -1, true);
			//jeżeli warunek spełniony
			writeToOutputByToken(LABEL, newLabelPass, true, -1, true, -1, true);
			int goodVal = insertNum("1",INTEGER);
			writeToOutputByToken(ASSIGN, resultVar, true, -1, true, goodVal, true);//ustawia resultVar na 1 (warunek spełniony)
			//Label za całym wyrażeniem
			writeToOutputByToken(LABEL, newLabelFinish, true, -1, true, -1, true);
			$$ = resultVar;
		}
	;

simple_expression:
		term
	| SIGN term
			{
				if($1 == PLUS)
				{
					 $$ = $2;
				}
				else if($1 == MINUS)
				{
					//SUB //odejmie od 0 naszą wartość z term
					$$ = insertTempSymbol(SymbolTable[$2].type);
					int tempVar = insertNum("0",SymbolTable[$2].type);
					writeToOutputByToken($1, $$, true, tempVar, true, $2, true);
				}
			}
	| simple_expression SIGN term
			{	//GENERUJE OPERACJE + LUB - ZWRACA WYNIK
				$$ = insertTempSymbol(getResultType($1, $3));
				writeToOutputByToken($2, $$, true, $1, true, $3, true);
			}
	| simple_expression OR term
			{	//GENERUJE OR ZWRACA WYNIK
				int tmp = insertTempSymbol(INTEGER);
				$$ = tmp;
				writeToOutputByToken(OR, tmp, true, $1, true, $3, true);
			}
	;

term:
		factor
	| term MULOP factor //mulop div/mod/*..
			{
				$$ = insertTempSymbol(getResultType($1, $3));
				writeToOutputByToken($2, $$, true, $1, true, $3, true);
			}
	;

factor:
		variable
			{	//PROC NIE MOŻE BO NIE ZWRACA WYNIKU, WIĘC WYWOŁANIE FUNKCJI BEZ PARM  LUB ZMIENNA
				//JAK FUN GENERUJ PUSH CALL I INCSP JAK ZMIENNA ZWRÓĆ VARIABLE JAK FUN ADRES ZWROTNY
					int funCalled = $1;
					if(SymbolTable[funCalled].token == FUN)
					{
						if(SymbolTable[funCalled].parameters.size() > 0)
						{
							yyerror("Wywołanie funkcji przyjmującej parametry bez parametrów");
							YYERROR;
						}
						funCalled = insertTempSymbol(SymbolTable[funCalled].type);//nowa zmienna na wartość którą zwróci funkcja
						writeToOutput(string("\tpush.i #" + SymbolTable[funCalled].address));
						writeToOutput(string("\tcall.i #" + SymbolTable[$1].name));
						//funkcja bez parametrów więc incsp = 4
						writeToOutput(string("\tincsp.i #4"));
					}
					else if(SymbolTable[funCalled].token == PROC)
					{
						yyerror("Nie można pobrać wyniku bo procedura go nie zwraca");
						YYERROR;
					}
					$$ = funCalled;
				}
	| ID '(' expression_list ')'
			{ 	//OBLICZ incspCount, FOR {KONWERTUJ TYPY I WRZUĆ NUMY DO PRZEKAZANIA JAKO PARMETRY FUNKCJI GENERUJ PUSHA}
					//USUŃ Z tmpArgParamVector, ZRÓB ZMIENNĄ NA RETURN I JĄ ZWRÓĆ JAK FUNKCJA
					//GENERUJ CALL I INCSP
				string name = SymbolTable[$1].name;
				int index = lookupForFunction(name);
				if(index == -1)
				{
					yyerror("Niezadeklarowana nazwa.");
					YYERROR;
				}
				if(SymbolTable[index].token == FUN)
				{
					if(tmpArgParamVector.size()<SymbolTable[index].parameters.size())
					{
						yyerror("Nieprawidłowa liczba parametrów.");
						YYERROR;
					}
					// zmienna na rozmiar wrzuconych na stos referencji
					int incspCount = 0;
					//iterator po argumentach
					list<pair<int,ArrayInfo> >::iterator it=SymbolTable[index].parameters.begin();
					int startPoint = tmpArgParamVector.size() - SymbolTable[index].parameters.size();
					// przejdź po argumentach
					for(int i=startPoint;i<tmpArgParamVector.size();i++)
					{
						int id = tmpArgParamVector[i];
						// typ argumentu procedury/funkcji
						int argumentType = (*it).first;
						if(argumentType==ARRAY) argumentType = (*it).second.argType;
						// jeśli przekazujemy NUM to stwórz nowy obiekt w tablicy
							if(SymbolTable[tmpArgParamVector[i]].token==NUM)
							{
								// zmienna tymczasowa tworz od razu o takim typie, jakiego wymaga funkcja
								int numVar = insertTempSymbol(argumentType);
								writeToOutputByToken(ASSIGN,numVar,true, -1, true, tmpArgParamVector[i], true);
								id = numVar;
							}
							// typ przekazywany
							int passedType = SymbolTable[id].type;
							// typ argumentu funkcji i typ wartosci przekazywanej są różne (INT i REAL) - konwersja
							if(argumentType!=passedType)
							{
								int tempVar = insertTempSymbol(argumentType);
								writeToOutputByToken(ASSIGN, tempVar, true, -1, true, id, true);
								id = tempVar;
							}
							writeToOutputByToken(PUSH,id,false,-1, true, -1, true);
							incspCount+=4; // zwieksz adres parametrów
							it++;
						}
						// usun z wektora argumenty
						int size = tmpArgParamVector.size();
						for(int i = startPoint;i<size;i++)
						{
							tmpArgParamVector.pop_back();
						}
						// zmienna na wartość zwracaną
						int id = insertTempSymbol(SymbolTable[index].type);
						writeToOutputByToken(PUSH,id,false,-1, true, -1, true);
						incspCount += 4;	// zwiększ rozmiar
						$$ = id;
						// generuj call
						writeToOutputByToken(CALL, index,true,-1,true,-1,true);
						stringstream helper;
						helper << incspCount;
						// generuj incsp
						int incspNum = insertNum(helper.str(),INTEGER);
						writeToOutputByToken(INCSP,incspNum,true,-1,true,-1,true);
					}
					else if(SymbolTable[index].token==PROC)
					{
						yyerror("Procedury nie zwracają wartości, nie można wykonać operacji!");
						YYERROR;
					}
					else
					{
						yyerror("Nie znaleziono takiej funkcji/procedury.");
						YYERROR;
					}
				}
	| NUM
	| '(' expression ')'
			{
				$$ = $2;
			}
	| NOT factor
			{	
			//RÓB LABELE JAK 0 TO SKACZ JAK NIE TO TEŻ SKACZ ...
				int labelFactorEqualZero = insertLabel();
				int zeroId = insertNum("0",INTEGER);
				//jeq jeżeli factor == 0 skacz do miejsca w którym ustawimy wartość na 1
				writeToOutputByToken(EQ,labelFactorEqualZero, true, $2, true,  zeroId, true);
				//jeżeli factor był inny niż 0 to zapisz 0 to zmiennej jak boło to samo to nie wykona bo przeskoczył
				int varWithNotResult = insertTempSymbol(INTEGER);
				writeToOutputByToken(ASSIGN,varWithNotResult, true, -1, true, zeroId, true);
				//jump na koniec
				int labelFinishNOT = insertLabel();
				writeToOutputByToken(JUMP, labelFinishNOT, true, -1, true, -1, true);
				//miejsce w którym wpisujemy 1 (bo factor był 0)
				writeToOutputByToken(LABEL, labelFactorEqualZero, true, -1, true, -1, true);
				int num1 = insertNum("1",INTEGER);
				//jeżeli factor był 0 to zapisz 1
				writeToOutputByToken(ASSIGN,varWithNotResult, true, -1, true, num1, true);
				//label kończący NOT'a
				writeToOutputByToken(LABEL, labelFinishNOT, true, -1, true, -1, true);
				$$ = varWithNotResult;
			}
	;

eof:
		DONE
			{
				return 0;
			}
  ;

%%

void yyerror(char const *s)
{
	printf("Blad w linii %d: %s \n",lineno, s);
}
