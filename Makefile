CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LD = g++
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = obj/main.o obj/App.o obj/ResourceManager.o obj/Menu.o obj/About.o

all: snake

snake: $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm obj/*
	rm snake

run:
	./snake
