
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lm
SOURCES = utility.c pa09.c
TARGET = pa09
TESTN := $(shell seq 1 9)
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

# -------------------------------------------------------------

TESTS := $(addprefix test,${TESTN})

.PHONY : all build clean environment help testall $(TESTS)
.DEFAULT_GOAL := build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build testall

testall: | $(TESTS)

build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(OBJF) outputs

environment:
	@cd $(CURDIR)
	@mkdir -p outputs
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "make             build $(TARGET)"
	@echo "make testall     run all testcases"
	@echo "make clean       start from scratch"
	@echo
	@echo "make test1	test on partition all"

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<
# gcc answer07.c pa07

test1: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput1 ./$(TARGET) inputs/ch_header_inputs/testcase1 outputs/output1 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput1
	 ./$(TARGET) inputs/ch_header_inputs/testcase1 outputs/output1
	 diff -q -w outputs/output1 expected/ch_expected/solution1
	 
test2: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput2 ./$(TARGET) inputs/ch_header_inputs/testcase2 outputs/output2 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput2
	 ./$(TARGET) inputs/ch_header_inputs/testcase2 outputs/output2
	 diff -q -w outputs/output2 expected/ch_expected/solution2
	 
test3: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput3 ./$(TARGET) inputs/ch_header_inputs/testcase3 outputs/output3 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput3
	 ./$(TARGET) inputs/ch_header_inputs/testcase3 outputs/output3
	 diff -q -w outputs/output3 expected/ch_expected/solution3
	 
test4: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput4 ./$(TARGET) inputs/ch_header_inputs/testcase4 outputs/output4 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput4
	 ./$(TARGET) inputs/ch_header_inputs/testcase4 outputs/output4
	 diff -q -w outputs/output4 expected/ch_expected/solution4

test5: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput5 ./$(TARGET) inputs/ch_header_inputs/testcase5 outputs/output5 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput5
	 ./$(TARGET) inputs/ch_header_inputs/testcase5 outputs/output5
	 diff -q -w outputs/output5 expected/ch_expected/solution5
	 
test6: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput6 ./$(TARGET) inputs/ch_header_inputs/testcase6 outputs/output6 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput6
	 ./$(TARGET) inputs/ch_header_inputs/testcase6 outputs/output6
	 diff -q -w outputs/output6 expected/ch_expected/solution6	 

test7: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput7 ./$(TARGET) inputs/bit_header_inputs/description_bit outputs/output7 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput7 outputchar7
	 ./$(TARGET) inputs/bit_header_inputs/description_bit outputs/output7
	 diff -q -w outputs/output7 expected/bit_expected/description_sol
	 
test8: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput8 ./$(TARGET) inputs/bit_header_inputs/gophers_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput8 outputchar8
	 ./$(TARGET) inputs/bit_header_inputs/gophers_bit outputs/output8
	 diff -q -w outputs/output8 expected/bit_expected/gophers_sol

test9: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput9 ./$(TARGET) inputs/bit_header_inputs/description_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput9 outputchar9
	 ./$(TARGET) inputs/bit_header_inputs/description_bit outputs/output8
	 diff -q -w outputs/output8 expected/bit_expected/description_sol

test10: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput10 ./$(TARGET) inputs/bit_header_inputs/poetry1_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput10 outputchar10
	 ./$(TARGET) inputs/bit_header_inputs/poetry1_bit outputs/output10
	 diff -q -w outputs/output8 expected/bit_expected/poetry1_sol

test11: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput11 ./$(TARGET) inputs/bit_header_inputs/poetry2_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput11 outputchar11
	 ./$(TARGET) inputs/bit_header_inputs/poetry2_bit outputs/output11
	 diff -q -w outputs/output8 expected/bit_expected/poetry2_sol

test12: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput12 ./$(TARGET) inputs/bit_header_inputs/prefixcodes_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput12 outputchar12
	 ./$(TARGET) inputs/bit_header_inputs/prefixcodes_bit outputs/output12
	 diff -q -w outputs/output8 expected/bit_expected/prefixcodes_sol
	 
test13: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput13 ./$(TARGET) inputs/bit_header_inputs/stone_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput13 outputchar13
	 ./$(TARGET) inputs/bit_header_inputs/stone_bit outputs/output13
	 diff -q -w outputs/output8 expected/bit_expected/stone_sol
	 
test14: $(TARGET) | environment
	 $(VALGRIND) --log-file=outputs/memoutput14 ./$(TARGET) inputs/bit_header_inputs/woods_bit outputs/output8 > dev\null
	@bin/valgrind-checker.sh outputs/memoutput14 outputchar14
	 ./$(TARGET) inputs/bit_header_inputs/woods_bit outputs/output14
	 diff -q -w outputs/output8 expected/bit_expected/woods_sol
	 
testall:  test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 test14