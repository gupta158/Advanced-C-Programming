
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS = -lm
SOURCES = answer06.c pa06.c
TARGET = pa06
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


test1: $(TARGET) | environment
	./$(TARGET) images/01-unnormalized-smile.ee264 > outputs/output1
	$(VALGRIND) --log-file=outputs/memoutput1 ./$(TARGET) images/01-unnormalized-smile.ee264 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput1
	
test2: $(TARGET) | environment
	./$(TARGET) images/corrupt-testcases/bad-width-height.ee264 > outputs/output2
	$(VALGRIND) --log-file=outputs/memoutput1 ./$(TARGET) images/corrupt-testcases/bad-width-height.ee264 >/dev/null
	@bin/valgrind-checker.sh outputs/memoutput1\2
	

