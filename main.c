#include <stdio.h>
#define INF 9999
#define MAX 10

void sortOrdersByPriority() {
    int orders[] = {101, 102, 103, 104, 105};
    int priority[] = {3, 1, 5, 2, 4};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] < priority[j + 1]) {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = temp;
            }
        }
    }

    printf("\nOrders sorted by priority:\n");
    for (int i = 0; i < n; i++) {
        printf("Order ID: %d | Priority: %d\n", orders[i], priority[i]);
    }
}

void greedyDeliverySelection() {
    int deliveryTime[] = {20, 10, 30, 15, 25};
    int orderID[] = {101, 102, 103, 104, 105};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (deliveryTime[j] > deliveryTime[j + 1]) {
                int temp = deliveryTime[j];
                deliveryTime[j] = deliveryTime[j + 1];
                deliveryTime[j + 1] = temp;

                temp = orderID[j];
                orderID[j] = orderID[j + 1];
                orderID[j + 1] = temp;
            }
        }
    }

    printf("\nGreedy Delivery Selection:\n");
    printf("Delivering orders with shortest delivery time first:\n");

    for (int i = 0; i < n; i++) {
        printf("Order ID: %d | Delivery Time: %d minutes\n", orderID[i], deliveryTime[i]);
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

void packageOptimization() {
    int weight[] = {2, 3, 4, 5};
    int profit[] = {50, 60, 100, 120};
    int capacity = 7;
    int n = 4;

    int dp[10][10];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nDynamic Programming Package Optimization:\n");
    printf("Maximum package value that can be carried: %d\n", dp[n][capacity]);
}

void shortestRoute() {
    int graph[MAX][MAX] = {
        {0, 4, 0, 0, 8},
        {4, 0, 2, 0, 0},
        {0, 2, 0, 6, 0},
        {0, 0, 6, 0, 3},
        {8, 0, 0, 3, 0}
    };

    int distance[MAX], visited[MAX];
    int n = 5;
    int start = 0;

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest Delivery Routes from Warehouse:\n");
    for (int i = 0; i < n; i++) {
        printf("Location %d distance: %d km\n", i, distance[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Smart Delivery Optimizer =====");
        printf("\n1. Sort Orders by Priority");
        printf("\n2. Greedy Delivery Selection");
        printf("\n3. Package Optimization using DP");
        printf("\n4. Shortest Route using Dijkstra");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortOrdersByPriority();
                break;

            case 2:
                greedyDeliverySelection();
                break;

            case 3:
                packageOptimization();
                break;

            case 4:
                shortestRoute();
                break;

            case 5:
                printf("Exiting project...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}