#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *infile;

float sales[12];
char *months[] = {"January", "February", "March", 
                  "April", "May", "June", 
                  "July", "August", "September", 
                  "October", "November", "December"};

// Get average of array range
float arr_avg(float *arr, int start, int end) {
  float sum;
  for (int i = start; i <= end; i++) {
    sum += arr[i];
  }
  int len = end - start + 1;
  return sum/len;
}

// Get min value of array
int arr_min(float *arr, int len) {
  int min;
  for (int i = 0; i < len; i++) {
    min = (arr[i] < min)? i : min;
  }
  return min;
}

// Get max vaalue of array
int arr_max(float *arr, int len) {
  int max;
  for (int i = 0; i < len; i++) {
    max = (arr[i] > max)? i : max;
  }
  return max;
}

int comp(const void *x, const void *y) {
  return (sales[*(int*)x] < sales[*(int*)y]);
}

int main() {
  // Read in the data from the input file
  infile = fopen("input.txt", "r");
  for (int i = 0; i < 12; i++) {
    fscanf(infile, "%f", &sales[i]);
  }
  fclose(infile);

  // Print the header
  printf("Monthly Sales Report for 2024\n\n");

  // Print the sales for each month
  printf("Month%-10sSales\n-----%-10s-----\n", "", "");
  for (int i = 0; i < 12; i++) {
    printf("%-15s$%.2f\n", months[i], sales[i]);
  }

  // Sales summary
  int min_sales = arr_min(sales, 12);
  int max_sales = arr_max(sales, 12);
  float sales_avg = arr_avg(sales, 0, 11);

  printf("\nSales Summary:\n\n");
  printf("Minimum Sales:\t$%.2f  (%s)\n", sales[min_sales], months[min_sales]);
  printf("Maximum Sales:\t$%.2f  (%s)\n", sales[max_sales], months[max_sales]);
  printf("Average Sales:\t$%.2f\n\n", sales_avg);

  // Six month moving average
  printf("Six-Month Moving Average Report:\n\n");
  for (int end = 5; end < 12; end++) {
    int start = end - 5;
    float avg = arr_avg(sales, start, end);
    printf("%-10s- %-15s$%.2f\n", months[start], months[end], avg);
  }

  // Sorted Sales
  int indices[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  qsort(indices, 12, sizeof(int), comp);

  printf("\nSales Report (Highest to Lowest)\n\n");
  printf("Month%-10sSales\n-----%-10s-----\n", "", "");

  for (int i = 0; i < 12; i++) {
    printf("%-15s$%.2f\n", months[indices[i]], sales[indices[i]]);
  }

  return 0;
}




