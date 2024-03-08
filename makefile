BUILDDIR = bin/
DATADIR = data/
INCLUDE_CORE = include/
SRC_CORE = src/core/
SRC_LOGGING = src/logger/
TESTDIR = tests/
FLAGS = -I/usr/local/include -L/usr/local/lib/ -lgcrypt -lz -I$(INCLUDE_CORE) -fdiagnostics-color=always -g
IMPL_FILES = $(SRC_CORE)Compression.cpp $(SRC_CORE)Encryption.cpp $(SRC_CORE)FileReader.cpp $(SRC_CORE)RomContainer.cpp $(SRC_CORE)Utilities.cpp $(SRC_LOGGING)Logger.cpp

$(BUILDDIR)Test.out:
	g++ $(FLAGS) $(TESTDIR)Test.cpp $(IMPL_FILES) -o $(BUILDDIR)Test.out

clean:
	rm ./$(BUILDDIR)*