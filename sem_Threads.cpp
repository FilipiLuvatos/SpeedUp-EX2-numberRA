#include <iostream>
#include <sys/time.h>
#include <pthread.h>
#include <cstdlib>

//Filipi de Luca Valim dos Santos
//RA 22216027-7

using namespace std;

int contador=0;

 
    typedef unsigned long long timestamp_t;

    static timestamp_t
    get_timestamp ()
    {
      struct timeval now;
      gettimeofday (&now, NULL);
      return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
    }
    
int TestaPrimo3(int n) {
    
    int EhPrimo,
        d=3;
    if (n <= 1 || (n != 2 && n % 2 == 0))
        EhPrimo = 0;    /* nenhum numero inteiro <= 1 ou par > 2 e' primo */
    else
        EhPrimo = 1;        /* o numero e' primo ate que se prove o contrario */

    while (EhPrimo  && d <= n / 2) {
        if (n % d == 0)
            EhPrimo = 0;
        d = d + 2;        /* testar apenas Ã­mpares*/
    }
    return EhPrimo;
}



int main(int argc, char** argv) {
	

	
	double aaa = 222;
	double bbb = 160;
	double ccc = 277;
	double p;
	double numPrimos[222];
	int i=0;
	double aux = 0;// 0 significa numero nao eh primo
	long double aux2 = 0 ;
	int opc = 0;
	p = bbb * ccc;
	
	//44.320
	 timestamp_t t0 = get_timestamp();
	while(contador != 222){
				
	
	aux = TestaPrimo3(p);	//chamada de funçao
							// retorna 1 = primo, 0 = nao primo
	
	if(aux == 1){
	
	numPrimos[i] = p;
//	cout<<numPrimos[i]<<endl;
	contador++;
	i++;
	p--;
	} else p--;
	
					
	}
	timestamp_t t1 = get_timestamp();
	double secs = (t1 - t0) / 1000000.0L; 
	
	for(int j = 0; j < 222; j++){ // loop para calcular a média de tempo
		
		aux2 = aux2 + numPrimos[j]; // somatória
	
	}   	
	
    
	cout<<"Somatorio de num primos:"<<aux2<<endl;
	cout<<"Tempo:"<<secs;
	
	return 0;
	
	
}

// tempo de forma tradicional:0.011481

