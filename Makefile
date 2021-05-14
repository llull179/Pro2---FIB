OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: GrupProb.o CjtSessions.o Sessio.o CjtCursos.o program.o Curs.o CjtUsuaris.o Usuari.o CjtProblemes.o Problema.o
	g++ $(OPCIONS) -o program.exe GrupProb.o CjtSessions.o Sessio.o CjtCursos.o program.o Curs.o CjtUsuaris.o Usuari.o CjtProblemes.o Problema.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_individus.o: Cjt_individus.cc Cjt_individus.hh
	g++ $(OPCIONS) -c Cjt_individus.cc

Usuari.o: Usuari.cc Usuari.hh
	g++ $(OPCIONS) -c Usuari.cc

CjtUsuaris.o: CjtUsuaris.hh CjtUsuaris.cc
	g++ $(OPCIONS) -c CjtUsuaris.cc

CjtProblemes.o: CjtProblemes.hh CjtProblemes.cc
	g++ $(OPCIONS) -c CjtProblemes.cc

Problema.o: Problema.hh Problema.cc
	g++ $(OPCIONS) -c Problema.cc

CjtCursos.o: CjtCursos.hh CjtCursos.cc
	g++ $(OPCIONS) -c CjtCursos.cc

Curs.o: Curs.hh Curs.cc
	g++ $(OPCIONS) -c Curs.cc

CjtSessions.o: CjtSessions.hh CjtSessions.cc
	g++ $(OPCIONS) -c CjtSessions.cc

Sessio.o: Sessio.hh Sessio.cc
	g++ $(OPCIONS) -c Sessio.cc

GrupProb.o: GrupProb.hh GrupProb.cc
	g++ $(OPCIONS) -c GrupProb.cc




practica.tar: Makefile CjtUsuaris.cc CjtUsuaris.hh Usuari.hh Usuari.cc CjtSessions.cc CjtSessions.hh Sessio.hh Sessio.cc CjtCursos.cc  CjtCursos.hh Curs.hh Curs.hh BinTree.hh program.cc GrupProb.cc GrupProb.hh
	tar -cvf practica.tar *.cc *.hh Makefile
	
clean: 
	rm -f *.o *.gch *.exe *.tar
