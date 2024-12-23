CFLAGS = -std=c99 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

main: main.c
	gcc $(CFLAGS) -o vkCheck main.c $(LDFLAGS)
	./vkCheck
	

clean:
	rm -f vkCheck