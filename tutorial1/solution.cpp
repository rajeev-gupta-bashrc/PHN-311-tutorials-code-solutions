#include <bits/stdc++.h>
#include "machar.h"
using namespace std;
void solution2a(){
    double num = -1;
    // underflow
    while (isfinite(num*2))
    {
        num*=2;
    }
    cout<<"Lower limit for double number "<<num<<endl;
    // overrflow
    num=1;
    while (isfinite(num*2))
    {
        num*=2;
    }
    cout<<"Upper limit for double number "<<num<<endl;
}
void solution2b(){
    float num = -1;
    // underflow
    while (abs(num/2)>0)
    {
        num/=2;
    }
    cout<<"Lower limit for single-bit precision number "<<num<<endl;
    // overrflow
    num=1;
    while (isfinite(num*2)>0)
    {
        num*=2;
    }
    cout<<"Upper limit for single-bit precision number "<<num<<endl;
}
void solution2c(){
    int lower = -1;
    int upper = 1;
    // integers uses 2's complement, hence for a large values than the upperlimit of int 
    // the computer will consider it as a negative number.
    while(upper>0){
        // cout<<upper<<endl;
        upper*=2;
    }
    cout<<"Upper limit for int number "<<upper-1<<endl;
    // similiarly the negative value of int will become positive
    //  as the value is decreased further
    while(1){
        int check = lower*2;
        if(check) lower=check;
        else break;
        // cout<<lower<<endl;
    }
    cout<<"Lower limit for int number "<<lower<<endl;
}
void solution3a(){
    double x = 1.0;
    double em = 1.0;

    while (1.0 + em != 1.0) {
        em = x;
        x /= 2.0;
    }
    cout << "Machine Precision of double-precision floats (εM_double): "
         << em << endl;
}
void solution3b(){
    complex<double> cmp = 1.0;
    complex<double> e_cmp = 1.0;

    while (1.0 + e_cmp != 1.0) {
        e_cmp = cmp;
        cmp /= 2.0;
    }

    cout << "Machine Precision of complex numbers (εM_complex): " << e_cmp << endl;

}
double my_cos(double x, long long n_max){
    double ans=0;
    long long fact_2i = 1;
    for (int i = 0; i <= n_max; i++)
    {
        double c = pow(-1, i%2);
        for (long long j = 0; j < 2*i; j++)
        {
            c*=x;
            c/=(j+1);
        }
        ans+=c;
        // cout<<c<<endl;
    }
    return ans;
}
void solution4(){
    int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
    float eps, epsneg, xmin, xmax;
    machar(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp, &eps, &epsneg, &xmin, &xmax);

    // Display the machine characteristics
    cout << "Machine Characteristics:" << endl;
    cout << "------------------------------" << endl;
    cout << "Base (radix) of the machine (ibeta): " << ibeta << endl;
    cout << "Number of base-ibeta digits in the mantissa (it): " << it << endl;
    cout << "Rounding mode (irnd): " << irnd << endl;
    cout << "Guard digits (ngrd): " << ngrd << endl;
    cout << "Machine precision (machep): " << machep << endl;
    cout << "Negative of machine precision (negep): " << negep << endl;
    cout << "Number of bits in the exponent (iexp): " << iexp << endl;
    cout << "Minimum exponent (minexp): " << minexp << endl;
    cout << "Maximum exponent (maxexp): " << maxexp << endl;
    cout << "Smallest positive floating-point number (xmin): " << xmin << endl;
    cout << "Largest positive floating-point number (xmax): " << xmax << endl;
    cout << "Machine precision (εM): " << eps << endl;
}
void solution5(){
    double pi = 3.141592653, pi1 = 3.141592654;
    for (int i = 1; i < 10; i++)
    {
        cout<<setprecision(15);
        cout<<my_cos(-pi1+pi1*i/10, 10000) << " " << cos(-pi1+pi*i/10) << endl;
        // break;
    }
}
int main()
{
    solution4();
    // solution5();
    // solution2a();
    // solution2b();
    // solution2c();
    // solution3a();
    // solution3b();
    
    return 0;
}