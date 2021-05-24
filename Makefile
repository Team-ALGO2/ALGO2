all: clean install_deps compile 

dir = Final/src
serverdir = Server
out = bin
testdir = Final/tests

# set compiler, change to cc = gcc if using gcc
cc = cc 

# You can get rid of specific linkers if you dont have the libray
linkers = 

# How to deal with errors: -fsyntax-only (check only syntax); -Werror (make warnings into errors); -w (ignore all warning)
errors = -w  	

clean:
	@echo "Creating bin directory"
	@rm -rf bin
	@mkdir bin

	@rm -rf *.o
	@rm -rf start


install_deps:
	sudo apt-get install sqlite3 libsqlite3-dev
	sudo apt-get install openssl libssl-dev
	sudo apt-get install libncurses5-dev libncursesw5-dev

compile:
	${cc} ${dir}/slots.c -o ${out}/slots ${linkers} ${errors}
	${cc} ${testdir}/unittest.c -o ${out}/test ${errors}

test:
	${out}/test

slots:
	${out}/slots

slots_inf:
	${out}/slots -1

help:
	clear
	@echo "Use one of the follow commands:"
	@echo "make 			-- To build the executables"
	@echo "make test		-- To test the code"
	@echo "make slots		-- To run slots"
	@echo "make slots_inf		-- To run slots forever"

web:
	clear
	@echo "To start the server, execute:"
	@echo "cd Server"
	@echo "make"
	@echo "./server"