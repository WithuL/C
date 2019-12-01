#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, b, c, d, e;
	for (a = 1; a < 6; a++) {
		for (b = 1; b < 6; b++) {
			for (c = 1; c < 6; c++) {
				for (d = 1; d < 6; d++) {
					for (e = 1; e < 6; e++) {
						if (b == 2 || a == 3) {
							if (b == 2 || e == 4) {
								if (c == 1 || d == 2) {
									if (c == 5 || d == 3) {
										if (e == 4 || a == 1) {
											if (a != b && a != c && a != d && a != e &&
												b != c && b != d && b != e &&
												c != d && c != e &&
												d != e) {
												printf("A:%d  B:%d  C:%d  D:%d  E:%d\n", a, b, c, d, e);
												system("pause");
												return 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}