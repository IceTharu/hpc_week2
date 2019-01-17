TARGET = runfile
OBJS = main.o datatools.o init_arrays.o jacobi.o jacobi_omp.o check_convergence.o update.o

OPT = -g -fast -xloopinfo -xopenmp -xinstrument=datarace
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

