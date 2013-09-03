SDKDIR=./sdk
VERSION=1

help:
	@echo "Makefile for Building Dev Operating System."
	@echo "Please see LICENSE for licensing information."
	@echo "Usage: make [ all | clean | help | build] " 
	@echo ""
	@echo "Version" $(VERSION)
	@echo

all: 
	@echo "Building Kernel"
	make -C ./kernel
	@echo "Building SDK"
	make -C ./sdk
	@echo "Building Userland"
	make -C ./userland
	

build:
	zip -r devos-$(VERSION).zip ./


emulate:
	@echo "Running Dev Operating System."

clean:
	make -C ./kernel clean
	make -C ./userland clean
