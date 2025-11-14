# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
all:
	@echo "Building source file"
	@mkdir -p ${OUTPUT_DIR}
	@gcc -c src/consumer/consumer.c -o ${OUTPUT_DIR}/consumer.o -Isrc/
	@gcc -o ${OUTPUT_DIR}/consumer ${OUTPUT_DIR}/consumer.o -lrt
	@gcc -c src/producer/producer.c -o ${OUTPUT_DIR}/producer.o -Isrc/
	@gcc -o ${OUTPUT_DIR}/producer ${OUTPUT_DIR}/producer.o -lrt

clean:
	rm -rf ${OUTPUT_DIR}

run_con:
	@echo "Running program"
	@${OUTPUT_DIR}/consumer

run_pro:
	@echo "Running program"
	@${OUTPUT_DIR}/producer



