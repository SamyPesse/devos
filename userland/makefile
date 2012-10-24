ALLDIR=$(wildcard *)

all:
	-@for file in $(ALLDIR); do make -C $$file; done; true

clean:
	-@for file in $(ALLDIR); do make -C $$file clean; done; true

