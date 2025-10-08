# Project param
PRO_DIR = .
OUTPUT_DIR = ${PRO_DIR}/output

# Rule
create_output:
	@echo "creating output folder"
	@mkdir -p ${OUTPUT_DIR}

all: create_output
	@echo "Compiling and linking app"
	@gcc -c filestat.c -o ${OUTPUT_DIR}/filestat.o
	@gcc -o ${OUTPUT_DIR}/filestat ${OUTPUT_DIR}/filestat.o

run:
	${OUTPUT_DIR}/filestat /home/ntai/Linux_Embedded/linux_course/embedded_linux_pratice/02/filestat.c

clean:
	rm -rf ${OUTPUT_DIR}

