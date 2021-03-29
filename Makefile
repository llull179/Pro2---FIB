OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: Cjt_individus.o Parcrom.o Cjt_trets.o program.o Individu.o
	g++ $(OPCIONS) -o program.exe Cjt_individus.o Parcrom.o Cjt_trets.o program.o Individu.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_individus.o: Cjt_individus.cc Cjt_individus.hh
	g++ $(OPCIONS) -c Cjt_individus.cc

Parcrom.o: Parcrom.cc Parcrom.hh
	g++ $(OPCIONS) -c Parcrom.cc

CjtUsuariois.o: CjtUsuariois.hh CjtUsuariois.cc
	g++ $(OPCIONS) -c CjtUsuariois.cc

Usuario.o: Usuario.hh Usuario.cc
	g++ $(OPCIONS) -c Usuario.cc



practica.tar: Makefile Cjt_individus.hh Cjt_individus.cc CjtUsuarios.hh CjtUsuarios.cc Usuario.cc Usuario.hh Parcrom.hh Parcrom.cc BinTree.hh program.cc html.zip
	tar -cvf practica.tar *.cc *.hh Makefile html.zip
	
clean: 
	rm -f *.o *.gch *.exe *.tar
