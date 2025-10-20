# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/poll.c -o ${OUTPUT_DIR}/poll.o
	@gcc -o ${OUTPUT_DIR}/poll ${OUTPUT_DIR}/poll.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/poll
