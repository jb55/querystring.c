
PREFIX ?= /usr/local
OBJ ?= querystring.o
STATIC ?= querystring.a

all: $(STATIC)

querystring.o: querystring.c

example: example.c querystring.o
	$(CC) -o $@ $^

$(STATIC): $(OBJ)
	ar rcs $@ $<

install: $(STATIC)
	install -D $(STATIC) $(PREFIX)/lib/$(STATIC)
	install -D querystring.h $(PREFIX)/include/querystring.h

.PHONY: libs install

clean:
	rm -f $(STATIC) $(OBJ) test
