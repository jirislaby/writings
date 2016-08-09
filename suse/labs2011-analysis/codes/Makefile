REPOS=/home/latest/repos
LLVM_BIN=$(REPOS)/llvm-build/bin

CLANG=$(LLVM_BIN)/clang
CLANG_EMIT_LLVM=$(CLANG) -c -emit-llvm -Wall

KLEE_INC=$(REPOS)/klee/include
KLEE=$(REPOS)/klee/Release+Asserts/bin/klee

all:
	@echo 'Run make with one of "flow", "ai" or "se"'

clean:
	rm -f *.o *.preproc

flow: flow.c
	@echo -e '\n\n================ RUNNING CLANG CHECKER ================'
	$(CLANG) -cc1 -analyze -analyzer-checker experimental.unix.Malloc $^
	@echo -e '\n\n==================== RUNNING SMATCH ==================='
	$(REPOS)/smatch/smatch $^
	@echo -e '\n\n========================= DONE ========================'

ai: ai.xml ai.c
	stanse -g -c AutomatonChecker:$^

se: se_lock.o
	$(KLEE) $^

se_lock.o: se.o lock.o
	$(LLVM_BIN)/llvm-link -o $@ $^

se.o: se.c
	$(CLANG_EMIT_LLVM) -o $@ $^

lock.o: lock.c
	$(CLANG_EMIT_LLVM) -I$(KLEE_INC) -o $@ $^

.PHONY: all clean flow ai se
