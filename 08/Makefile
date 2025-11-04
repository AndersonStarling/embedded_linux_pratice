# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/process.c -o ${OUTPUT_DIR}/process.o -Isrc/child -Isrc/parent
	@gcc -c src/child/child_ls.c -o ${OUTPUT_DIR}/child_ls.o
	@gcc -c src/child/child_wc.c -o ${OUTPUT_DIR}/child_wc.o
	@gcc -c src/parent/parent.c -o ${OUTPUT_DIR}/parent.o
	@gcc -o ${OUTPUT_DIR}/process ${OUTPUT_DIR}/process.o ${OUTPUT_DIR}/child_ls.o ${OUTPUT_DIR}/child_wc.o ${OUTPUT_DIR}/parent.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/process

