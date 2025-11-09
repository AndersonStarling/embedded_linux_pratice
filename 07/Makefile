# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/task/worker/worker.c -o ${OUTPUT_DIR}/worker.o -Isrc/
	@gcc -o ${OUTPUT_DIR}/worker ${OUTPUT_DIR}/worker.o -lrt
	@gcc -c src/task/dispatcher/dispatcher.c -o ${OUTPUT_DIR}/dispatcher.o -Isrc/
	@gcc -o ${OUTPUT_DIR}/dispatcher ${OUTPUT_DIR}/dispatcher.o -lrt

clean:
	rm -rf ${OUTPUT_DIR}

run_dis:
	@echo "Running program"
	@${OUTPUT_DIR}/dispatcher

run_wor:
	@echo "Running program"
	@${OUTPUT_DIR}/worker



