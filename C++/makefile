src=$(wildcard,%.cpp)
target=$(patsubst ./%.cpp,./%.exe,$(src))

ALL:$(target)

%.exe:%.cpp
	g++ $< -o $@

clean:
	-rm -rf $(target) 

.PHONY: clean ALL
