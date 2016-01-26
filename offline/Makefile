
EXE:= main
INC_DIR:= ./include ./include/cppjieba
SRC_DIR:= ./src
SRCS:= $(wildcard $(SRC_DIR)/*.cpp)
LIBS:= -lpthread
CXXFLAGS:= -std=c++11

$(EXE):$(SRCS)
	g++ -g -o $@ $^  $(LIBS) $(addprefix -I, $(INC_DIR)) $(CXXFLAGS)
clean:
	rm main
