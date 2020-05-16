SDIR=src
ODIR=obj

OBJ = $(patsubst %, $(ODIR)/%,$(patsubst %.cpp, %.o,$(shell cd $(SDIR); find -name "*.cpp" -printf " %f")))

obj/%.o: src/%.cpp
	g++ -c -o $@ $<

bin/olcPack: $(OBJ)
	g++ -o $@ $^ -lstdc++fs -std=c++17

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
