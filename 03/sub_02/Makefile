# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/process.c -o ${OUTPUT_DIR}/process.o -Isrc/child_process -Isrc/parent_process
	@gcc -c src/child_process/child_process.c -o ${OUTPUT_DIR}/child_process.o -Isrc/env
	@gcc -c src/parent_process/parent_process.c -o ${OUTPUT_DIR}/parent_process.o -Isrc/env
	@gcc -o ${OUTPUT_DIR}/process ${OUTPUT_DIR}/process.o ${OUTPUT_DIR}/child_process.o ${OUTPUT_DIR}/parent_process.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/process

