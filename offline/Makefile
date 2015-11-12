
EXE:= main
INC_DIR:= ./include
SRC_DIR:= ./src
SRCS:= $(wildcard $(SRC_DIR)/*.cpp)
LIBS:= -lpthread

$(EXE):$(SRCS)
	g++ -g -o $@ $^  $(LIBS) $(addprefix -I, $(INC_DIR))
clean:
	rm main
