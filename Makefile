ifeq ($(OS),Windows_NT)
	include Makefile.mingw
else
	include Makefile.linux
endif
