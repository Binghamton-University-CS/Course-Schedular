COURSE = cs240
SEMESTER = spring2023
CP_NUMBER = 2
LASTNAME = Yoo
GITUSERID = hyoo0412
EXE = scheduler_cp2

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/main.o $(OBJ)/Student.o $(OBJ)/StudentList.o $(OBJ)/Course.o $(OBJ)/CourseList.o 
	$(CC) $(FLAGS) $(OBJ)/main.o $(OBJ)/Student.o $(OBJ)/StudentList.o $(OBJ)/Course.o $(OBJ)/CourseList.o -o $@

$(OBJ)/main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o $@

$(OBJ)/Student.o: Student.cpp
	$(CC) $(FLAGS) -c Student.cpp -o $@

$(OBJ)/StudentList.o: StudentList.cpp
	$(CC) $(FLAGS) -c StudentList.cpp -o $@

$(OBJ)/Course.o: Course.cpp
	$(CC) $(FLAGS) -c Course.cpp -o $@

$(OBJ)/CourseList.o: CourseList.cpp
	$(CC) $(FLAGS) -c CourseList.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz