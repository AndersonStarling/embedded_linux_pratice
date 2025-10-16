# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/main_thread.c -o ${OUTPUT_DIR}/main_thread.o -Isrc/thread_1 -Isrc/thread_2 -Isrc/thread_3 -Isrc/shared_data
	@gcc -c src/thread_1/thread_1.c -o ${OUTPUT_DIR}/thread_1.o -Isrc/shared_data
	@gcc -c src/thread_2/thread_2.c -o ${OUTPUT_DIR}/thread_2.o -Isrc/shared_data
	@gcc -c src/thread_3/thread_3.c -o ${OUTPUT_DIR}/thread_3.o -Isrc/shared_data
	@gcc -c src/shared_data/shared_data.c -o ${OUTPUT_DIR}/shared_data.o
	@gcc -o ${OUTPUT_DIR}/thread ${OUTPUT_DIR}/main_thread.o ${OUTPUT_DIR}/thread_1.o ${OUTPUT_DIR}/thread_2.o ${OUTPUT_DIR}/thread_3.o ${OUTPUT_DIR}/shared_data.o -lpthread

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/thread
