# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/main_thread.c -o ${OUTPUT_DIR}/main_thread.o -Isrc/thread_reader -Isrc/thread_writer
	@gcc -c src/thread_reader/thread_reader.c -o ${OUTPUT_DIR}/thread_reader.o -Isrc/shared_data
	@gcc -c src/thread_writer/thread_writer.c -o ${OUTPUT_DIR}/thread_writer.o -Isrc/shared_data
	@gcc -c src/shared_data/shared_data.c -o ${OUTPUT_DIR}/shared_data.o
	@gcc -o ${OUTPUT_DIR}/thread ${OUTPUT_DIR}/main_thread.o ${OUTPUT_DIR}/thread_reader.o ${OUTPUT_DIR}/thread_writer.o ${OUTPUT_DIR}/shared_data.o -lpthread

clean:
	rm -rf ${OUTPUT_DIR}

run:
	@echo "Running program"
	@${OUTPUT_DIR}/thread
