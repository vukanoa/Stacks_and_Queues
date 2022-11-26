CC	:= g++
CXXFLAGS:= -O0 -g -Wall
TARGET	:= program
BUILD	:= build
SRCDIR	:= src
HDRDIR	:= hdr
HDRS	:= -I$(HDRDIR)
SRCS	:= $(wildcard $(SRCDIR)/*.cpp)
OBJS	:= $(patsubst $(SRCDIR)/%.cpp,$(BUILD)/%.o,$(SRCS))
DEPS	:= $(patsubst $(SRCDIR)/%.cpp,$(BUILD)/%.d,$(SRCS))

.PHONY = all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(BUILD)/%.o: $(SRCDIR)/%.cpp | $(BUILD)
	$(CC) $(CXXFLAGS) $(HDRS) -c $< -o $@

$(BUILD)/%.d: $(SRCDIR)/%.cpp | $(BUILD)
	$(CC) $(HDRS) -MM -MT $(BUILD)/$*.o $< > $@

include $(DEPS)

$(BUILD):
	mkdir build

clean:
	rm -rf $(TARGET) $(BUILD)
