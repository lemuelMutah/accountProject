group.o = checkingsAccount.o account.o savingsAccount.o main.o

app: $(group.o)
	c++ $(group.o) -o app

main.o: main.cpp checkingsAccount.h savingsAccount.h account.h
	c++ -c assign6.cpp

checkingsAccount.o: checkingsAccount.h checkingsAccount.cpp account.h
	c++ -c checkingsAccount.cpp

savingsAccount.o: savingsAccount.h savingsAccount.cpp account.h
	c++ -c savingsAccount.cpp

account.o: account.h account.cpp
	c++ -c account.cpp
	
clean:
	rm *.o
