using namespace std;

int maximum69Number (int num) {
    int sum = 0;
    int count = 1;
    while (num > 0) {
        sum = sum * 10 + num % 10;
        num /= 10;
    }
    num = sum;
    sum = 0;
    while (num > 0) {
        int r = num % 10;
        if (r == 6 && count == 1)
            r = 9, count--;
        sum = sum * 10 + r;
        num /= 10;
    }
    return sum;
}
