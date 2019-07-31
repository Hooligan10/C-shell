TARGETS = pinfo.c readline.c parseline.c main.c execute.c PWD.c ECHO.c LS.c LSa.c LSla.c LSl.c ChangeDirec.c tildadirec.c FGc.c Redirect.c Piping.c Setenv.c Unsetenv.c Getenv.c 
TARGETSO = pinfo.o readline.o parseline.o main.o execute.o PWD.o ECHO.o LS.o LSa.o LSla.o LSl.o ChangeDirec.o tildadirec.o FGc.o Redirect.o Piping.o Setenv.o Unsetenv.o Getenv.o


makeo: 	$(TARGETSO)
	gcc -o main $(TARGETSO)

compile: $(TARGETS)
	gcc -c $(TARGETS)

debug: $(TARGETS)
	gcc -c -g -Wall $(TARGETS)


clean: $(TARGETSO)
	rm *.o
