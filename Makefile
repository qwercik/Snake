CXX = g++
CXX_PARAMS = -std=c++17 -Iinclude
LD = g++
LD_PARAMS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = obj/main.o obj/Game.o obj/TexturesManager.o

all: snake

snake: $(OBJS)
	$(LD) -o $@ $^ $(LD_PARAMS)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CXX_PARAMS)

clean:
	rm snake
	rm obj/*

run:
	./snake
