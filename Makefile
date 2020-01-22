all: create_dir compile

dir = Final/src
out = bin
testdir = Final/tests

errors = -w  	# How to deal with errors: -fsyntax-only (check only syntax); -Werror (make warnings into errors); -w (ignore all warning)

create_dir:
	@echo "Creating bin directory"
	@rm -rf bin
	@mkdir bin

compile:
	@cc ${dir}/slots.c -o ${out}/slots ${errors}
	@cc ${dir}/users.c -o ${out}/users -lssl -lcrypto -lsqlite3 ${errors}
	@cc ${dir}/calclauncher.c -o ${out}/calclauncher -lncurses ${errors}

	@cc ${testdir}/test.c -o ${out}/test ${errors}
