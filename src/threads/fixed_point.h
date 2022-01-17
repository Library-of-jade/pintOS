#define F (1 << 14)
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))
// x and y denote fixed_point numbers in 17.14 format
// n is an integer

int int_to_fp(int n);           /* convert integer to fixed point */
int fp_to_int_round(int x);     /* convert fixed point to integer (round) */
int fp_to_int(int x);           /* convert fixed point to integer */
int add_fp(int x, int y);       /* add(fixed point) */
int add_mixed(int x, int n);    /* add(fixed point, integer) */
int sub_fp(int x, int y);       /* subtract(fixed point : x - y) */
int sub_mixed(int x, int n);    /* subtract(fixed point, integer : x - n) */
int mul_fp(int x, int y);       /* multiply(fixed point) */
int mul_mixed(int x, int n);    /* multiply(fixed point, integer) */
int div_fp(int x, int y);       /* divide(fixed point : x / y) */
int div_mixed(int x, int n);    /* divide(fixed point, integer : x/n) */


int int_to_fp(int n){
    return n * F;
}

int fp_to_int_round(int x){
    if(x > 0)
        return (x + F / 2) / F;
    else
        return (x - F / 2) / F;
}

int fp_to_int(int x){
    return x / F;
}

int add_fp(int x, int y){
    return x + y;
}

int add_mixed(int x, int n){
    return x + n * F;
}

int sub_fp(int x, int y){
    return x - y;
}

int sub_mixed(int x, int n){
    return x - n * F;    
}

int mul_fp(int x, int y){
    return ((int64_t)x) * y / F;
}

int mul_mixed(int x, int n){
    return x * n;
}


int div_fp(int x, int y){
    return ((int64_t)x) * F / y;
}


int div_mixed(int x, int n){
    return x / n;
}