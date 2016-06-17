all:hash_main bubble_sort hash rb_tree

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

clean:
	rm -rf ./*.o hash_main bubble_sort hash rb_tree
