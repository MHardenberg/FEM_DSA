flags= -std=c++23 -fsanitize=address -o0 -Wall -Wpedantic
linker=

bubble:
	gcc ./test/test_bubble.c ./src/bubble.c $(flags) $(linker) -o ./bin/test_bubble.out -g
	./bin/test_bubble.out 9 8 7 6 54 31 1414 253 63 141 11 2 0 0 0 12 523 1 1 45 6 \
		2123 123 32 325 67 90 9 1 243 5 1332 500 11123 5325 2 4 6 8 9 2 1 1 4


list:
	gcc ./test/test_llist.c ./src/dataStructures/llist.c  $(flags) $(linker) -o ./bin/test_llist.out -g
	./bin/test_llist.out


queue:
	gcc ./test/test_queue.c ./src/dataStructures/queue.c ./src/dataStructures/llist.c $(flags) $(linker) -o ./bin/test_queue.out -g
	./bin/test_queue.out


stack:
	g++ ./test/test_stack.cpp $(flags) $(linker) -o ./bin/test_stack.out -g
	./bin/test_stack.out


alist:
	g++ ./test/test_alist.cpp $(flags) $(linker) -o ./bin/test_alist.out -g
	./bin/test_alist.out


rBuffer:
	gcc ./test/test_ringBuffer.c ./src/dataStructures/ringBuffer.c $(flags) $(linker) -o ./bin/test_rBuffer.out -g
	./bin/test_rBuffer.out


labyrinth:
	g++ ./test/test_labyrinth.cpp ./src/labyrinth.cpp $(flags) $(linker) -o ./bin/test_labyrinth.out -g
	./bin/test_labyrinth.out


quick:
	g++ ./test/test_quick.cpp $(flags) $(linker) -o ./bin/test_quick.out -g
	./bin/test_quick.out
