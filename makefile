group.o = checkingsAccount.o account.o savingsAccount.o assign6.o

assign6: $(group.o)
	c++ $(group.o) -o assign6

assign6.o: assign6.cpp checkingsAccount.h savingsAccount.h account.h
	c++ -c assign6.cpp

checkingsAccount.o: checkingsAccount.h checkingsAccount.cpp account.h
	c++ -c checkingsAccount.cpp

savingsAccount.o: savingsAccount.h savingsAccount.cpp account.h
	c++ -c savingsAccount.cpp

account.o: account.h account.cpp
	c++ -c account.cpp