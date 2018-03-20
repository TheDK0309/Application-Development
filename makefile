OBJ = testmain.o screen.o appdevwave.o  
APPNAME = testmain.a

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl 

%.o : %.c
	gcc -c -o $@ $< -std=c99

clean:
	rm $(APPNAME) $(OBJ)
