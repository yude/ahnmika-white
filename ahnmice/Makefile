PREFIX?=/opt/cegcc

CXX=$(PREFIX)/bin/arm-mingw32ce-g++
STRIP=$(PREFIX)/bin/arm-mingw32ce-strip

OUTPUT=AppMain.exe

CXXFLAGS= -DEV_PLATFORM_WIN32 -DUNICODE -D_UNICODE -DEV_UNSAFE_SWPRINTF -mwin32 \
-O2 -mcpu=arm926ej-s -D_WIN32_WCE=0x600 -D_LARGEFILE_SOURCE=1 -D_LARGEFILE64_SOURCE=1 \
-D_FILE_OFFSET_BITS=64 -static

.PHONY:		all clean

all:				$(OUTPUT)

clean:			
				rm -f $(OUTPUT)

AppMain.exe:	main.cpp
				$(CXX) main.cpp -o AppMain.exe $(CXXFLAGS)
				$(STRIP) AppMain.exe

