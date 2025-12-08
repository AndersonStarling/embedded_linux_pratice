# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/process.c -o ${OUTPUT_DIR}/process.o
	@gcc -o ${OUTPUT_DIR}/process ${OUTPUT_DIR}/process.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/process
