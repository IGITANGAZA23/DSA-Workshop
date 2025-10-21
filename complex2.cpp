#include <iostream>
int fun5(int n) {
int i, j, m = 0;
for (i = 1; i <= n; i *= 2) {
 for (j = 0; j <= i; j++) {
m += 1;
}
}
return m;


}
// Testing Code
int main() {
	int n = 1000;
    std::cout << "N = "<<n<< ", Number of instructions: "<< fun5 (n); 
    return 0;
}
