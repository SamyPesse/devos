SDKDIR=./sdk
VERSION=12.4

help:
	@echo "Makefile for Koala Operating System."
	@echo "Please see COPYING for licensing information."
	@echo "Usage: make [ all | clean | help | build] " 
	@echo ""
	@echo "Version" $(VERSION)
	@echo

all: 
	@echo "Building Koala Kernel"
	make -C ./kernel
	@echo "Building Koala SDK"
	make -C ./sdk
	@echo "Building Koala Userland"
	make -C ./userland
	

build:
	zip -r koala-$(VERSION).zip ./


emulate:
	@echo "Running Koala Operating System."

clean:
	make -C ./kernel clean
	make -C ./userland clean
