#include <iostream>
#include <sys/time.h>
#include <pthread.h>
#include <cstdlib>
#define NUM_THREADS 1

//Filipi de Luca Valim dos Santos
//RA 22216027-7

using namespace std;

int contador=0;

struct thread_data {
   int  thread_id;
   char *message;
};

 
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
        d = d + 2;        /* testar apenas ímpares*/
    }
    return EhPrimo;
}

void *PrintHello(void *threadarg) {
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;
   
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
				
	
	aux = TestaPrimo3(p);	//chamada de fun�ao
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
	
	for(int j = 0; j < 222; j++){ // loop para calcular a m�dia de tempo
		
		aux2 = aux2 + numPrimos[j]; // somat�ria
	
	}   	
	
    
	cout<<"Somatorio de num primos:"<<aux2<<endl;
	cout<<"Tempo:"<<secs;

   pthread_exit(NULL);
}


int main(int argc, char** argv) {
	

  pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++ ) {   
      td[i].thread_id = i;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
      
   }
   pthread_exit(NULL);
	
	
	return 0;
	
	
}



