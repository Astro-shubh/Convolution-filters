# Define compiler and flags
CXX = g++
CXXFLAGS = -O3 -Wall
LIBS = -lfftw3

# Target name
TARGET = filter_generation

# Source files
SOURCES = filter_generation.cpp \
          source/Fresnel_for_vector.cpp \
          source/Fresnel_integrals_PRESTO.cpp \
          source/padding_and_fft.cpp \
          source/template_generator.cpp

# The build rule
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LIBS)

# Shortcut to run it
go: $(TARGET)
	./$(TARGET)
