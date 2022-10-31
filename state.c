#include <stdio.h>

enum event { STOP, START };
enum state { INIT, WORK, WAIT } g = INIT;

enum state init[] = { INIT, WORK };
enum state work[] = { WAIT, WORK };
enum state wait[] = { INIT, WORK };
enum state *map[] = { init, work, wait };

const char *e2s(enum event e)
{
	switch (e) {
	case START:
		return "START";
	case STOP:
		return "STOP";
	}
}

const char *s2s(enum state s)
{
	switch (s) {
	case INIT:
		return "INIT";
	case WORK:
		return "WORK";
	case WAIT:
		return "WAIT";
	}
}

void handle(enum event e)
{
	enum state s = map[g][e];
	printf("%s: %s -> %s\n", e2s(e), s2s(g), s2s(s));
	g = s;
}

int main(void)
{
	handle(START);
	handle(START);
	handle(STOP);
	handle(START);
	handle(STOP);
	handle(STOP);
}
