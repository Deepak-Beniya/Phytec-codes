#include<stdio.h>
#include<stdarg.h>

void unsigned_number_to_string(__uint64_t number,int base ,char *buffer){
   if (number==0){
	 *buffer++ ='0';
	 *buffer = 0;
	 return;
   }
   char buf[65];
   for(int i=0; i<65; i++){
        buf[i]=0;
     }
	int cur =0;

	while (number){
		int digit = number % base;
		if(digit >=10) {
			buf[cur++] = 'a' + (digit - 10);
		}else {
			buf[cur++]='0' + digit;
		}

		number /=base;
	}

	for (int i =cur-1; i !=0; i--)
	   { *buffer++ =buf[i]; }
	*buffer++ = buf[0];
	*buffer = 0;
} 

void number_to_string(__uint64_t number,int base ,char * buffer){
    if(number < 0) {
		*buffer++= '-';
		number = -number;	
	}
    else {
	unsigned_number_to_string(number,base,buffer);
	}

}



void vdisplay(const char *fmt, va_list args){

	int state =0;
	char number_buffer[65];
	while (*fmt) {
             if (state ==0) {
	     	     if (*fmt== '%') {
			     state =1;
		         } else {
			     putchar(*fmt);
			 }
		     } 
			 else if (state ==1){
				switch (*fmt){
			     case 'c': {
				  char ch = va_arg(args,int);
				  putchar(ch);
				  break;
				 }
                 case 's':
				  const char *s =va_arg(args,const char *);
				   while (*s) {
					putchar(*s++);
				   }
                   break;
                 case 'd': {
					  int n = va_arg(args,int);
					  
					  number_to_string(n,10,number_buffer);
					  for (int i=0;number_buffer[i]; i++){
						putchar(number_buffer[i]);
					  }
					  break;
				 }
				    
                                     
			     case 'x': {
					  int n=va_arg(args,int);
					  
					  unsigned_number_to_string(n,16,number_buffer);
					  for (int i=0;number_buffer[i]; i++){
						putchar(number_buffer[i]);
					  }
					  break;
				 }
                            
			     case 'p': {
				    putchar('0');
					putchar('x');
                    

                      void *n = va_arg(args,void *);
					  
					  unsigned_number_to_string((__uint64_t)n,16,number_buffer);
					  for (int i=0;number_buffer[i]; i++){
						putchar(number_buffer[i]);
					  }

                    break;
				 }
			 }	
			 state = 0;    
	     }
	     fmt++;
	}
       
}

void display(const char *fmt, ...){
	va_list args;
	va_start(args,fmt);
	
	vdisplay(fmt, args);
	
	va_end(args);


}

// int main(){
// 	void *pointer_to_main = (void *) main;

	

// 	display("Print a character : %c \n",'D');
//     display("Print a string : %s \n","Deepak");
// 	display("Print a integer : %d \n",25);
// 	display("Print a zero integer  : %d \n",0);
// 	display("Print an hex: %x \n",10);
// 	display("Print a zero hex integer : %x \n",0);
// 	display("Print a pointer : %p \n",pointer_to_main);

// 	__uint64_t n = (__uint64_t) -1;
// 	display("Largest 64bit: %lld, %x \n", n,n);

// 	return 0;
// }
