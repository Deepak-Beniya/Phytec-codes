App: App.o add.o print.o header.h
	gcc App.o add.o print.o -o APP
	@echo "Application binary generated"
App.o:App.c
	gcc -c App.c -o App.o
	@echo "App.o binary executed"
print.o:print.c
	gcc -c print.c -o print.o
	@echo "print.o binary executed"
add.o:add.c
	gcc -c add.c -o add.o
	@echo "add binary executed"
clean:
	rm -rf *.o APP



