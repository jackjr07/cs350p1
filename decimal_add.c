
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef
unsigned char
digit ;

int input_decimal_integer(digit *x)
// return -1 if illegal, else put digits
// in the array x[] with x[0] containing
// the least significant digit and
// return the number of digits
{
  char v[100] ;
  int n ;
  scanf("%s",v) ;
  n = 0 ;
  while (v[n] != '\0') {
    if (v[n] < '0') return -1 ;
    if (v[n] > '9') return -1 ;
    n++ ;
  }

  int m = 0 ;
  n-- ;
  while (n >= 0) {
    x[m++] = v[n--] - '0' ;
  }

  return m ;
}


int print_decimal_integer(digit *x, int n)
{
  int i ;
  for (i = n-1 ; i >= 0 ; i--) {
    printf("%c",x[i]+'0') ;
  }
}



int add (digit *res,
	 digit *a, int m,
	 digit *b, int n)
{
  int i,max ;
  digit ad,bd,sum,carry ;
  
  if (m > n) { max = m ; } else { max = n ; }
  carry = 0 ;

  for (i = 0 ; i < max ; i++) {
    if (i >= m) { ad = 0 ; } else { ad = a[i] ; }
    if (i >= n) { bd = 0 ; } else { bd = b[i] ; }

    sum = ad + bd + carry ;

    if (sum >= 10) {
      sum = sum - 10 ;
      carry = 1 ;
    } else {
      carry = 0 ;
    }
    
    res[i] = sum ;
  }

  if (carry == 1) {
    res[i] = carry ;
    i++ ;
  }

  return i ;
}

  
int main()
{
  digit x[100], y[100], z[100] ;
  int xlen, ylen, zlen ;

  xlen = input_decimal_integer(x) ;
  printf("x = ") ; print_decimal_integer(x,xlen) ;  printf("\n") ;


  ylen = input_decimal_integer(y) ;
  printf("y = ") ; print_decimal_integer(y,ylen) ;  printf("\n") ;
  
  zlen = add(z,   x,xlen,    y,ylen) ;

  printf("z = ") ; print_decimal_integer(z,zlen) ;  printf("\n") ;  


}
