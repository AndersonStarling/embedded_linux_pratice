# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/sigalarm.c -o ${OUTPUT_DIR}/sigalarm.o
	@gcc -o ${OUTPUT_DIR}/sigalarm ${OUTPUT_DIR}/sigalarm.o

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/sigalarm
