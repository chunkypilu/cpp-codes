	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <sys/types.h>
	#include <string.h> 
	#include <unistd.h>
	#include <netdb.h> 

	    int main(int argc, char *argv[])
	    {

	    struct sockaddr_in server_add_structure, client_add_structure;
	    int curr_socket, acc_socket,port, b, l ,lencli,n;
	    char arraybuff[5000];


	//step 1. creating a socket
	    curr_socket=socket(AF_INET,SOCK_STREAM,0);
	    if(curr_socket<0)
	      {
		printf("failed to create a socket\n");  
		exit(1);
	      }
	     else
	      printf("socket creation sucessfull\n");  

	//converting port # from char array to integer
	     port=atoi(argv[1]);

	//step 2. binding socket to address
	    server_add_structure.sin_port=htons(port);
	    server_add_structure.sin_addr.s_addr=INADDR_ANY;
	    server_add_structure.sin_family=AF_INET;

	    b=bind(curr_socket,(struct sockaddr *) & server_add_structure, sizeof(server_add_structure));
	    if(b<0)
	      {
	       printf("failed to bind\n"); 
	       exit(1);
	      }
	    else
	      printf("binding sucessfull\n");   

	//step 3. listening   
	     fork();
	    l=listen(curr_socket,4);  //can listen 4 client at a time
	    if(l<0)
	      {
	       printf("failed to listen\n");  
	       exit(1);
	      }
	    else
	      printf("listening sucessfull\n");  



	//step 4. Accepting the connection
	    lencli=sizeof(client_add_structure); 
	    acc_socket=accept(curr_socket,(struct sockaddr *) &client_add_structure, &lencli ); 
	    if(acc_socket<0)
	     {
	       printf("failed to accept the connection\n"); 
	       exit(1);
	     }
	    else
	      printf("sucessfully accepted the connection\n"); 
	   
	//step 5. sending and receiving the data 


	    
            read(acc_socket,arraybuff,499);
            printf("mssg receieved:-%s\n",arraybuff);
	    write(acc_socket,"Mr. Client I got yr message",27);


	///////////////////////////////////////////dont disturb above part///////////////////////////////////////////////////////
	   //server in listening mode
	   while(1)
	     {
		 read(acc_socket,arraybuff,499);
		 if(strcmp(arraybuff,"ls")==0)
		     {
		         system("ls >out.txt");
		         FILE *f=fopen("out.txt","r");
		         char ch;  
		         if(f==NULL)
		                {
		                     printf("sorry can't open\n"); exit(1);
		                }
		         ch=fgetc(f);
		         int i=0;
		         for(;(ch!=EOF);)
		            {
		                arraybuff[i]=ch;
		                i++;
		                ch=fgetc(f);
		             }
		        fclose(f);
		        n=write(acc_socket,arraybuff,5000);
		     }



		 if(strcmp(arraybuff,"pwd")==0)
		     {
	                  printf("present working dir. is:-\n");
		          system("pwd");
		     }



		 if(strcmp(arraybuff,"cd")==0)
		     {
	      
		         if(chdir(arraybuff+3) == 0)
		             arraybuff[0]='s'	 ;   
		             write(acc_socket,arraybuff,5000);
		     }



		 if(strcmp(arraybuff,"chmod")==0)
		     {
	      
		            
		          read(acc_socket,arraybuff,499);
		          if(system(arraybuff)!=-1)
		          arraybuff[0]='s'	 ;   
		          write(acc_socket,arraybuff,5000);
		
		     }


	     


	  
		 if(strcmp(arraybuff,"put")==0)
		     {
		          
		          //getting filename from the client
		          read(acc_socket,arraybuff,499);
		          if(arraybuff[0]!='0')  
		             { 
		                 FILE *fp;
		                 //creating file of same name
		                 fp = fopen(arraybuff, "w");
		                 if(fp!=NULL)
		                     {
		                        
		                        //writing into the file      
		                        read(acc_socket,arraybuff,5000);
		                        fwrite(arraybuff, sizeof(char), sizeof(arraybuff), fp);
		                        fclose(fp);
		                        strcpy(arraybuff,"File uploaded to server sucessfully\n");
		                        write(acc_socket,arraybuff,5000);
		                     }
		                 else
		                     printf("file not created\n");

		                 

		             }
	   

		     }


		 if(strcmp(arraybuff,"get")==0)
		     {
		         
		         //getting filename from the client
		         read(acc_socket,arraybuff,499);
		         //cheking if file exists   
		         FILE *f;
		         char fname[20];
		         strcpy(fname,arraybuff);
		         f = fopen(fname, "r");
		         if (f == NULL)
		                 {
		                     printf("\nFile not exists at server \n");
		                     arraybuff[0]='0';
		                     write(acc_socket,arraybuff,499);//setting first char 0
		       
		                 }
		        else                             
		                 {   printf("\nFile exists at server \n");
		                     arraybuff[0]='1';
		                     write(acc_socket,arraybuff,499);//setting first char 1
		                     char ch;
		                     ch=fgetc(f);
		                     int i=0;
		                     for(;(ch!=EOF);)
		                           {
		                               arraybuff[i]=ch;
		                               i++;
		                               ch=fgetc(f);
		                           }
		                     fclose(f);
		    
		                     //sending file content to the client
		                     write(acc_socket,arraybuff,5000);
		                     
		                    }
		}
		
	         if(strcmp(arraybuff,"close")==0)
	         {
	         
	          printf("server getting closed\n");
	          arraybuff[0]='0';
	          write(acc_socket,arraybuff,5000);
	          exit(0);
	           
	         
	         
	         }	




                  arraybuff[0]='\0';
	   } //while end
 } 



