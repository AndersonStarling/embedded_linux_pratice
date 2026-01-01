# Test cpu usage
TEST_CPU = test_cpu
SRC_CPU = model/cpu/test_cpu.cpp ../src/model/cpu/cpu.cpp
INC_CPU = ../src/model/cpu

TEST_DISK = test_disk
SRC_DISK = model/disk/test_disk.cpp ../src/model/disk/disk.cpp
INC_DISK = ../src/model/disk

TEST_MEM = test_mem
SRC_MEM = model/mem/test_mem.cpp ../src/model/mem/mem.cpp
INC_MEM = ../src/model/mem

TEST_SYSTEM = test_system
SRC_SYSTEM = model/system/test_system.cpp ../src/model/system/system.cpp
INC_SYSTEM = ../src/model/system

TEST_MODEL = test_model
SRC_MODEL = model/test_model.cpp ../src/model/model.cpp ../src/model/cpu/cpu.cpp ../src/model/disk/disk.cpp ../src/model/mem/mem.cpp ../src/model/system/system.cpp
INC_MODEL = -I../src/model -I../src/model/cpu -I../src/model/disk -I../src/model/mem -I../src/model/system

all:
	mkdir -p output
	$(CXX) -I${INC_CPU} -o output/$(TEST_CPU) $(SRC_CPU)
	$(CXX) -I${INC_DISK} -o output/$(TEST_DISK) $(SRC_DISK)
	$(CXX) -I${INC_MEM} -o output/$(TEST_MEM) $(SRC_MEM)
	$(CXX) -I${INC_SYSTEM} -o output/$(TEST_SYSTEM) $(SRC_SYSTEM)
	$(CXX) ${INC_MODEL} -o output/$(TEST_MODEL) $(SRC_MODEL)

run:
# 	@echo "--------------"
# 	output/$(TEST_CPU)
# 	@echo "--------------"
# 	output/$(TEST_DISK)
# 	@echo "--------------"
	output/$(TEST_MEM)
# 	@echo "--------------"
# 	output/$(TEST_SYSTEM)
# 	@echo "--------------"
# 	output/$(TEST_MODEL)
# 	@echo "--------------"

clean:
	rm -f output/*
