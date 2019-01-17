TARGET = runfile
OBJS = main.o datatools.o init_arrays.o jacobi.o check_convergence.o gaussseidel.o

OPT = -g -fast -xloopinfo -xopenmp
ISA = 
PARA = 

CCC = CC
CXX = CC
CXXFLAGS = 

CFLAGS = $(OPT) $(ISA) $(PARA) $(XOPT)

LIBS =

$(TARGET): $(OBJS)
	$(CCC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	@/bin/rm -f *.o core

realclean: clean
	@rm -f $(TARGET)


# dependenies
#
main.o : main.c datatools.c init_arrays.c jacobi.c gaussseidel.c
jacobi.o: check_convergence.c
gaussseidel.o: check_convergence.c
init_arrays.o: init_arrays.h datatools.c
datatools.o: datatools.h
