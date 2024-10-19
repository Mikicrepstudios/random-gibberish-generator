main:
	g++ -fstack-protector main.cpp -o random-gibberish-generator -Wl,-z,relro -Wl,-z,now

install:
	sudo cp random-gibberish-generator /bin/random-gibberish-generator

uninstall:
	sudo rm /bin/random-gibberish-generator

clean:
	rm random-gibberish-generator


