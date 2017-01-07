modulos = tablasimbolos.c tablacuadruplas.c exp_a_b.c

all: proalg

parser: 
	bison -d parser.y
	
flex: 
	flex lex.l
	
proalg: parser flex $(modulos)
	gcc lex.yy.c parser.tab.c tablacuadruplas.c tablasimbolos.c exp_a_b.c -o proalg -lfl

debug: parser flex $(modulos)	
	gcc lex.yy.c parser.tab.c tablacuadruplas.c tablasimbolos.c exp_a_b.c -o proalg -lfl -D _DEBUG
clean: 
	rm -f proalg parser.tab.c parser.tab.h lex.yy.c