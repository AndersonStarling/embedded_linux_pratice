# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/server.c -o ${OUTPUT_DIR}/server.o
	@gcc -o ${OUTPUT_DIR}/server ${OUTPUT_DIR}/server.o
	@gcc -c src/client.c -o ${OUTPUT_DIR}/client.o
	@gcc -o ${OUTPUT_DIR}/client ${OUTPUT_DIR}/client.o

clean:
	rm -rf ${OUTPUT_DIR}

run_server:
	@echo "Running program"
	@${OUTPUT_DIR}/server

run_client:
	@echo "Running program"
	@${OUTPUT_DIR}/client
