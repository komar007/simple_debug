%: %.cpp debug.hpp
	g++ $< -o $@ -Wall -Wextra -lm -g -ansi -fno-inline -DDEBUG -O2 

%.run: %
	./$<

%.rin: % %.in
	./$< <$<.in

