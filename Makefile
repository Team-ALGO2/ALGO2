all: clean compile 

dir = Final/src
serverdir = Server
out = bin
testdir = Final/tests

cc = cc # set compiler, change to cc = gcc if using gcc
linkers = -lssl -lcrypto -lsqlite3 -lncurses # You can get rid of specific linkers if you dont have th elibray

errors = -w  	# How to deal with errors: -fsyntax-only (check only syntax); -Werror (make warnings into errors); -w (ignore all warning)

clean:
	@echo "Creating bin directory"
	@rm -rf bin
	@mkdir bin

	@rm -rf *.o

install_deps:				# Linux only
	sudo apt-get install sqlite3 libsqlite3-dev
	sudo apt-get install openssl libssl-dev
	sudo apt-get install libncurses5-dev libncursesw5-dev

compile:
	${cc} ${dir}/slots.c -o ${out}/slots ${linkers} ${errors}

	${cc} ${testdir}/unittest.c -o ${out}/test ${errors}

test:
	make
	@${out}/test

slots:
	make
	@${out}/slots

slots_inf:
	make
	@${out}/slots -1

help:
	clear
	@echo "Use one of the follow commands:"
	@echo "make 			-- To build the executables"
	@echo "make test		-- To test the code"
	@echo "make slots		-- To run slots"
	@echo "make slots_inf		-- To run slots forever"
