target += hash_main bubble_sort hash rb_tree insertion_sort\
	interval_max_sum quick_sort dynamic_programming dynamic_programming_fib\
	BT_StackMiddelSearch

all:$(target)

hash_main: main.o hash_exe.o
	g++ -o $@ $?
hash_exe.o:hash_exe.cpp
	g++ -c -o $@ $<
main.o:main.cpp
	g++ -c -o $@ $<
hash_exe.cpp:hash_exe.h
main.cpp: hash_exe.h

bubble_sort:bubble_sort.c
	gcc -o $@ $<

hash:hash.c
	gcc -o $@ $<
hash.c:hash.h

rb_tree:rb_tree.o rb_tree_main.o
	gcc -o $@ $?
rb_tree.o:rb_tree.c
	gcc -c -o $@ $<
rb_tree_main.o:rb_tree_main.c
	gcc -c -o $@ $<

insertion_sort: insertion_sort.o
	gcc -o $@ $?

insertion_sort.o: insertion_sort.c
	gcc -c -o $@ $<

interval_max_sum:interval_maxSum.c
	gcc -o $@ $<

quick_sort: quick_sort.c
	gcc -o $@ $< 

dynamic_programming:dynamic_programming.c
	gcc -o $@ $<

dynamic_programming_fib:dynamic_programming_fib.c
	gcc -o $@ $<

BT_StackMiddelSearch:binary_tree.c
	gcc -o $@ $<

clean:
	rm -rf ./*.o $(target) 
