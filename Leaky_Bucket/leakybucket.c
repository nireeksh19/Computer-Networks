#include <stdio.h>

int main (){

    int i, n;
    int a[20];
    int buck_rem = 0, buck_cap = 4, rate = 3, sent, recv;
    printf ("Enter the number of packets: ");
    scanf("%d",&n);
    printf("Enter the packets: ");
    for (i = 1; i <= n; i++)
      scanf ("%d",&a[i]);
    printf("Clock \t packet size \t accept \t sent \t remaining");
    for (i = 1; i <= n; i++){

		if (a[i] != 0){
			if (buck_rem + a[i] > buck_cap)
	      		recv = -1;
	    	else{
				recv = a[i];
				buck_rem += a[i];
	      	}
	  	}
		else
	  		recv = 0;


		if (buck_rem != 0){
	    	if (buck_rem < rate){
				sent = buck_rem;
				buck_rem = 0;
	      	}
	    	else{
				sent = rate;
				buck_rem = buck_rem - rate;
	      	}
	  	}
		else
	  		sent = 0;

		if (recv == -1)
	   		printf("\n %d \t\t %d \tdropped\t\t %d \t\t %d" ,i,a[i],sent,buck_rem);
		else
	   		printf("\n %d \t\t %d \t %d \t\t %d \t\t %d" ,i,a[i],recv,sent,buck_rem);
    }

  return 0;
}

