#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define PI 3.141592653589793

int main(int argc, char** argv) {

	bool running = true;

	bool quiet = false;
	if (argc > 1) {
		if (!strcmp(argv[1], "-q")) {
			quiet = true;
		}
	}

	double left, right;
	char operator[2];

	scanf("%lf", &left);

	while (running) {

		scanf("%1s", operator);

		bool isUnary = true;
		switch (operator[0]) {
			case 'q':
				running = false;
				continue;
			case '(':
				left = floor(left);
				break;
			case ')':
				left = ceil(left);
				break;
			case '_':
				left = round(left);
				break;
			case '!':
				left = -left;
				break;
			case 'p':
				left = PI;
				break;
			case 's':
				left = sin(left);
				break;
			case 'c':
				left = cos(left);
				break;
			case 't':
				left = tan(left);
				break;
			case 'S':
				left = asin(left);
				break;
			case 'C':
				left = acos(left);
				break;
			case 'T':
				left = atan(left);
				break;
			case 'l':
				left = log(left);
				break;
			case 'L':
				left = log10(left);
				break;
			default:
				isUnary = false;
		}

		if (!isUnary) {
			scanf("%lf", &right);

			switch (operator[0]) {
				case '+':
					left = left + right;
					break;
				case '-':
					left = left - right;
					break;
				case '*':
					left = left * right;
					break;
				case '/':
					left = left / right;
					break;
				case '%':
					left = (long long)left % (long long)right;
					break;
				case '^':
					left = pow(left, right);
					break;
				case 'r':
					left = pow(left, 1/right);
					break;
				case '=':
					left = right;
					break;
				default:
					printf("Invalid operator\n");
					return 1;
			}
		}

		if (!quiet) { printf("> %.4lf ", left); }
	}


	if (quiet) { printf("%.4lf\n", left); }

	return 0;
}

