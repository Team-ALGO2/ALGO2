all: create_dir install_deps compile

dir = Final/src
out = bin
testdir = Final/tests

cc = cc # set compiler, change to cc = gcc if using gcc
linkers = -lssl -lcrypto -lsqlite3 -lncurses # You can get rid of specific linkers if you dont have th elibray

errors = -w  	# How to deal with errors: -fsyntax-only (check only syntax); -Werror (make warnings into errors); -w (ignore all warning)

create_dir:
	@echo "Creating bin directory"
	@rm -rf bin
	@mkdir bin

install_deps:				# Linux only
	@sudo apt-get install sqlite3 libsqlite3-dev
	@sudo apt-get install openssl libssl-dev
	@sudo apt-get install libncurses5-dev libncursesw5-dev

compile:
	@${cc} ${dir}/slots.c -o ${out}/slots ${linkers} ${errors}
	@${cc} ${dir}/calclauncher.c -o ${out}/calclauncher ${linkers} ${errors}

	@${cc} ${testdir}/unittest.c -o ${out}/test ${errors}
