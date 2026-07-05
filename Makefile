# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRCDIR = src
OBJDIR = obj
TARGET = kv_engine

# Find all .cpp files in src/
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Convert .cpp filenames to .o filenames inside an obj/ folder
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Default target to build the executable
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile .cpp files into .o object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJDIR):
	mkdir $(OBJDIR)

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(TARGET)