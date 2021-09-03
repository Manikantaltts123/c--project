PROJECT_NAME = CubeEatery
TEST_PROJECT_NAME = TEST_$(PROJECT_NAME)

BUILD_DIR = Build

SRC = src/check_user_option.cxx\
	  src/display_menu.cxx\
	  src/generate_file_map.cxx\
	  src/generate_price_map.cxx\
	  src/calculate_price.cxx\
	  src/calculate_final_price.cxx\
	  src/read_log_file.cxx\
	  src/check_membership.cxx\
	  src/displaybill.cxx

#COV_SRC = Testingmain.c

TEST_SRC = test/test_cubeeatery.cxx

INC_H = inc
#INC_T = unity

# for makefile to run in both windows and linux build
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	g++ main.cxx -I $(INC_H) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) -lm
# to run the project
run: all
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
# to make the build documentation
doc:
	make -C doc
$(BUILD_DIR):
	mkdir $(BUILD_DIR)
# for unit testing
test:
	g++ -I $(INC_H) $(SRC) $(TEST_SRC) -lgtest -lgtest_main -lpthread -o $(call FixPath,$(TEST_PROJECT_NAME).$(EXEC)) -lm
	./$(call FixPath,$(TEST_PROJECT_NAME).$(EXEC))
# for CI code coverage
Cppcheck:
	cppcheck --enable=all .
coverage:
	cp test/test_cubeeatery.cxx .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H)  test_cubeeatery.cxx $(SRC) -o $(call FixPath, $(TEST_PROJECT_NAME).$(EXEC)) -lm
	$(call FixPath, ./$(TEST_PROJECT_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) test.c
# for valgrind testing
valgrind:
	valgrind ./$(TEST_PROJECT_NAME).$(EXEC)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean -C doc
	rmdir $(BUILD_DIR) doc/html
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
