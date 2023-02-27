int fibonacci(int max_fib){
    int a = 0;
    int b = 1;
    int c = 0;
    int i = 0;
    while(i < max_fib){
        c = a + b;
        a = b;
        b = c;
        i = i + 1;
    }
    return c;
}

int main(void){
    int max_fib = 10;
    int result = fibonacci(max_fib);
    return result;
}
