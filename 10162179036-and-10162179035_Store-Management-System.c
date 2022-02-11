#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This programme provides the functionality of maintaining the records of goods

struct goods {
	int id;
	char name[100];
	float price;
	int quantity;
};

struct goods a[1000], b[1000];

FILE *fp;

int i = 0;

float t_price = 0;

void add() {
	fp = fopen("goods.txt", "a");

	printf("\nEnter the good ID: ");
	scanf("%d", &a[i].id);
	printf("\nEnter the name of the good: ");
	scanf("%s", a[i].name);
	printf("\nEnter the price of the good: ");
	scanf("%f", &a[i].price);
	printf("\nEnter the quantity of good: ");
	scanf("%d", &a[i].quantity);

	fprintf(fp, "%d %s %.2f %d\n", a[i].id, a[i].name, a[i].price, a[i].quantity);
	i++;

	fclose(fp);
}

void display() {
	char c;
	float t_price = 0;
	fp = fopen("goods.txt", "r");

	printf("\n");

	while((c = getc(fp)) != EOF) {
		putchar(c);
	}

	fclose(fp);
}

void update(int u_id, int choice) {
	fp = fopen("goods.txt", "w");
	fclose(fp);

	fp = fopen("goods.txt", "a");

	if (choice == 1)
	{
		for (int j = 0; j < i; j++) {
			if (u_id == a[j].id) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);

				printf("\nEnter the new ID of the good: ");
				scanf("%d", &a[j].id);

				for (int k = 0; k < i; k++) {
					fprintf(fp, "%d %s %.2f %d\n", a[k].id, a[k].name, a[k].price, a[k].quantity);
				}
			}
		}
	}

	if (choice == 2)
	{
		for (int j = 0; j < i; j++) {
			if (u_id == a[j].id) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);

				printf("\nEnter the new NAME of the good: ");
				scanf("%s", a[j].name);

				for (int k = 0; k < i; k++) {
					fprintf(fp, "%d %s %.2f %d\n", a[k].id, a[k].name, a[k].price, a[k].quantity);
				}
			}
		}
	}

	if (choice == 3)
	{
		for (int j = 0; j < i; j++) {
			if (u_id == a[j].id) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);

				printf("\nEnter the new PRICE of the good: ");
				scanf("%f", &a[j].price);

				for (int k = 0; k < i; k++) {
					fprintf(fp, "%d %s %.2f %d\n", a[k].id, a[k].name, a[k].price, a[k].quantity);
				}
			}
		}
	}

	if (choice == 4)
	{
		for (int j = 0; j < i; j++) {
			if (u_id == a[j].id) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);

				printf("\nEnter the new QUANTITY of the good: ");
				scanf("%d", &a[j].quantity);

				for (int k = 0; k < i; k++) {
					fprintf(fp, "%d %s %.2f %d\n", a[k].id, a[k].name, a[k].price, a[k].quantity);
				}
			}
		}
	}

	printf("\nRecord updated!\n");

	fclose(fp);
}

void search(int n) {
	fp = fopen("goods.txt", "r");

	if (n == 1) {
		int s_id;
		float t_price = 0;
		printf("\nThe ID you want to search: ");
		scanf("%d", &s_id);
		printf("\n");

		for (int j = 0; j < i; j++) {
			if (s_id == a[j].id) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);
				t_price += a[j].price;
			}
		}

		printf("\nTotal price of the good(s) are: %.2f\n", t_price);
	}

	else if (n == 2) {
		char s_name[100];
		float t_price = 0;
		printf("\nThe NAME you want to search: ");
		scanf("%s", s_name);
		printf("\n");

		for (int j = 0; j < i; j++) {
			if (strcmp(s_name, a[j].name) == 0) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);
				t_price += (a[j].quantity * a[j].price);
			}
		}

		printf("\nTotal price of the good(s) are: %.2f\n", t_price);
	}

	else if (n == 3) {
		float s_price, t_price = 0;
		printf("\nThe PRICE you want to search: ");
		scanf("%f", &s_price);
		printf("\n");

		for (int j = 0; j < i; j++) {
			if (s_price == a[j].price) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);
				t_price += (a[j].quantity * a[j].price);
			}
		}

		printf("\nTotal price of the good(s) are: %.2f\n", t_price);
	}

	else if (n == 4) {
		int s_quantity;
		float t_price = 0;
		printf("\nThe QUANTITY you want to search: ");
		scanf("%d", &s_quantity);
		printf("\n");

		for (int j = 0; j < i; j++) {
			if (s_quantity == a[j].quantity) {
				printf("%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);
				t_price += (a[j].quantity * a[j].price);
			}
		}

		printf("\nTotal price of the good(s) are: %.2f\n", t_price);
	}

	else {
		printf("\nPlease pick from the options provided!\n");
	}

	fclose(fp);
}

void delete(int n) {
	fp = fopen("goods.txt", "w");
	fclose(fp);

	fp = fopen("goods.txt", "a");

	if (n == 1) {
		int d_id;
		printf("\nThe ID you want to delete: ");
		scanf("%d", &d_id);

		int k = 0;
		for (int j = 0; j < i; j++) {
			if (d_id != a[j].id) {
				b[k].id = a[j].id;
				strcpy(b[k].name, a[j].name);
				b[k].price = a[j].price;
				b[k].quantity = a[j].quantity;
				k++;
			}
		}

		for (int j = 0; j < k; j++) {
			a[j].id = b[j].id;
			strcpy(a[j].name, b[j].name);
			a[j].price = b[j].price;
			a[j].quantity = b[j].quantity;
		}

		for (int j = 0; j < k; j++) {
			fprintf(fp, "%d %s %.2f %d\n", a[j].id, a[j].name, a[j].price, a[j].quantity);
		}
	}

	else if (n == 2) {
		char d_name[100];
		printf("\nThe NAME you want to delete: ");
		scanf("%s", d_name);
		printf("\n");

		int k = 0;
		for (int j = 0; j < i; j++) {
			if (strcmp(d_name, a[j].name) != 0) {
				b[k].id = a[j].id;
				strcpy(b[k].name, a[j].name);
				b[k].price = a[j].price;
				b[k].quantity = a[j].quantity;
				k++;
			}
		}

		for (int j = 0; j < k; j++) {
			a[j].id = b[j].id;
			strcpy(a[j].name, b[j].name);
			a[j].price = b[j].price;
			a[j].quantity = b[j].quantity;
		}

		for (int j = 0; j < k; j++) {
			fprintf(fp, "%d %s %.2f %d\n", b[j].id, b[j].name, b[j].price, b[j].quantity);
		}
	}

	else {
		printf("\nPlease pick from the options provided!\n");
	}

	printf("\nRecord Deleted!\n");

	fclose(fp);

}

int main() {
	fp = fopen("goods.txt", "w");
	fclose(fp);

	int choice, ch, num;

	start:
	printf("\nPlease pick one of these options:-\n");
	printf("\n1 => Add New Goods.\n2 => Display Goods.\n3 => Update Goods.\n4 => Search Goods.\n5 => Delete Goods.\n6 => Exit\n\nEnter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
			add();
			goto start;

		case 2:
			display();

			for (int j = 0; j < 1000; j++) {
				t_price += (a[j].quantity * a[j].price);
			}

			printf("\nTotal price of the good(s) are: %.2f\n", t_price);
			t_price = 0;

			goto start;

		case 3:
			display();

			printf("\nEnter the ID of the good to UPDATE: ");
			scanf("%d", &num);

			printf("\nPlease input the parameter you want to UPDATE from the options below:-\n\n1 -> ID.\n2 -> Name.\n3 -> Price.\n4 -> Quantity.\n\nEnter your choice: ");
			scanf("%d", &ch);
			printf("\n");
			update(num, ch);
			goto start;

		case 4:
			printf("\nPlease input the SEARCH parameter from the options below:-\n\n1 -> By ID.\n2 -> By Name.\n3 -> By Price.\n4 -> By Quantity.\n\nEnter your choice: ");
			scanf("%d", &ch);
			search(ch);

			goto start;

		case 5:
			printf("\nPlease input the parameter for DELETION from the options below:-\n\n1 -> By ID.\n2 -> By Name.\n\nEnter your choice: ");
			scanf("%d", &ch);
			delete(ch);
			goto start;

		case 6:
			for (int j = 0; j < 1000; j++) {
				t_price += (a[j].quantity * a[j].price);
			}

			printf("\nTotal price of the good(s) are: %.2f\n", t_price);

			t_price = 0;
			return 0;

		default:
			printf("\nPlease input from the options given!\n");
			goto start;
	}

	t_price = 0;
	return 0;
}