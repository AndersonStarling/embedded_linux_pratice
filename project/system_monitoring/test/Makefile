# Test cpu usage
TEST_CPU = test_cpu
SRC_CPU = model/cpu/test_cpu.cpp ../src/model/cpu/cpu.cpp
INC_CPU = ../src/model/cpu

TEST_DISK = test_disk
SRC_DISK = model/disk/test_disk.cpp ../src/model/disk/disk.cpp
INC_DISK = ../src/model/disk

all:
	mkdir -p output
# 	$(CXX) -I${INC_CPU} -o output/$(TEST_CPU) $(SRC_CPU)
	$(CXX) -I${INC_DISK} -o output/$(TEST_DISK) $(SRC_DISK)

run:
# 	output/$(TEST_CPU)
	output/$(TEST_DISK)

clean:
	rm -f output/*


