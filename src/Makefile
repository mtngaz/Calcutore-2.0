WWW = -Werror -Wextra -Wall
G = g++
OS = $(shell uname)

ifeq ($(OS), Linux)
	MV = Smart_Calc
	OPEN = cd build/ && ./Smart_Calc
else
	MV = Smart_Calc.app
	OPEN = open build/Smart_Calc.app
endif

all: install

install: clean
	mkdir build
	cd View/ && qmake && make && make clean && rm Makefile && rm .qmake.stash && mv $(MV) ../build/
	$(OPEN)

uninstall:
	rm -rf build;

test: clean
	$(G) $(WWW) tests.cc Model/*.cc -lgtest -o test
	./test

dvi: 
	open index.html

dist:
	tar -cf SmartCalc_v2.0.tar Controller Model View index.html Makefile


gcov_report: clean
	$(G) $(WWW) -fprofile-arcs -ftest-coverage tests.cc Model/*.cc -lgtest -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d .
	genhtml -o test_html unit_test.info
	open test_html/index.html

clean:
	rm -rf build test *.a *.gch *.gcno *.gcna *.gcda *.info *.dSYM test_html

style_i:
	clang-format -style=google -i Model/*.cc Model/*.h Controller/*.h 

style_n:
	clang-format -style=google -n Model/*.cc Model/*.h Controller/*.h 


valgrind:
	valgrind --leak-check=full --leak-resolution=med ./test

leaks:
	leaks -atExit -- ./test
