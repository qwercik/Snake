CXX = g++
CXXFLAGS = -std=c++14 -Iinclude
LD = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = obj/main.o obj/Game.o 

all: snake

snake: $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm snake
	rm obj/*

run:
	./snake
