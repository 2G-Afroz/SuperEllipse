debug: test
	@builds/SuperEllipse
test: src/*.cpp
	@g++ src/*.cpp -o builds/SuperEllipse -L./lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -std=c++11
clean:
	rm builds/* -r
	rm temp -r
