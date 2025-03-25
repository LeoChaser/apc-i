#include <stdio.h>

int main() {
	printf("==================================\n");
	printf("      N O T A    L E G A L\n");
	printf("==================================\n");
	printf("%-15s\t%s\t%s\n", "Produto", "Quant.", "Valor Unit");
	printf("%-15s\t%03i\t     %4.2f\n", "Camiseta", 2, 39.99);
	printf("%-15s\t%03i\t     %4.2f\n", "Calca", 1, 89.90);
	printf("%-15s\t%03i\t     %4.2f\n","Meia Social", 3, 19.99);
	printf("==================================\n");
	printf("%-15s\t\t    %4.2f\n", "Total:", 229.85);

	return 0;
}
