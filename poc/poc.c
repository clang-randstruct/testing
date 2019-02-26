#include <stdio.h>

struct mystruct {
	char *first;
	char *second;
}__attribute__((no_randomize_layout)) __attribute__((randomize_layout));
struct autoselecttest {
        int (*test1)();
	int (*test2)();
};
struct autotestfail {
	int (*test1)();
	int test2;
};
struct notautoselect {
	int (*test1)();
	int (*test2)();
}__attribute__((no_randomize_layout));
int distance(void *a, void *b)
{
	return a - b;
}

int main(void)
{
	struct mystruct m;
	struct autoselecttest a;
	struct notautoselect n;
	struct autotestfail f;
	f.test1 = NULL;
	f.test2 = 1;
	a.test1 = NULL;
	a.test2 = NULL;
	n.test1 = NULL;
	n.test2 = NULL;
	m.first = "I'm the first!";
	m.second = "and I'm the second!";
        printf("Autofail test: %i\n", &f.test1);
	printf("Autofail test: %i\n", &f.test2);
	printf("Auto test: %i\n", &a.test1);
	printf("Auto test: %i\n", &a.test2);
	printf("%d first\n", distance((void*)&m.first, (void*)&m));
	printf("%d second\n", distance((void*)&m.second, (void*)&m));
	return 0;
}
