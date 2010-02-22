%: %.cpp debug.h
	g++ $< -o $@ -Wall -Wextra -lm -g -ansi -fno-inline -DDEBUG -O2 

%.run: %
	./$<

%.rin: % %.in
	./$< <$<.in

