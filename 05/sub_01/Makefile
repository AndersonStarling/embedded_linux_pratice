# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/sigint.c -o ${OUTPUT_DIR}/sigint.o
	@gcc -o ${OUTPUT_DIR}/sigint ${OUTPUT_DIR}/sigint.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/sigint
