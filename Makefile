SDIR=src
ODIR=obj

# create required directories
DUMMY:= $(shell mkdir -p $(ODIR) bin)

OBJ = $(patsubst %, $(ODIR)/%,$(patsubst %.cpp, %.o,$(shell cd $(SDIR); find -name "*.cpp" -printf " %f")))

obj/%.o: src/%.cpp
	g++ -c -o $@ $<

bin/olcPack: $(OBJ)
	g++ -o $@ $^ -lstdc++fs -std=c++17

.PHONY: install
install:
	cp bin/olcPack /usr/local/bin/

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
