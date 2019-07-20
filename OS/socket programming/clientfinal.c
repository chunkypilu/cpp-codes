	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h> 
	#include <sys/types.h>
	#include <string.h> 
	#include <unistd.h>
	#include<fcntl.h>
	

	    int main(int argc, char *argv[])
	    {

	    struct sockaddr_in server_add_structure, client_add_structure;
	    int curr_socket, port, k ,n,ch;
	    struct hostent *ser;
	    char arraybuff[5000];

	    port=atoi(argv[2]);
	//step 1. creating a socket
	    curr_socket=socket(AF_INET,SOCK_STREAM,0);
	       

	    if(curr_socket<0)
	      {
	       printf("failed to create a socket\n");  
	       exit(1);
	      }
            else
	      printf("socket creation sucessfull\n");  
      
      //getting localhost or ipaddress in server
	    ser=gethostbyname(argv[1]);

	    if(ser==NULL)
	     {
	       printf("no host\n");  
	       exit(1);
	     }
	    else
	      printf("got appropriate host\n"); 
    
	  

	//copying value of the server address	
	    server_add_structure.sin_family=AF_INET;
	    bcopy((char *)ser-> h_addr,(char *) & server_add_structure.sin_addr.s_addr,ser-> h_length);
	    server_add_structure.sin_port=htons(port);

	//step 2. connecting to the server
	    k=connect(curr_socket,(struct sockaddr *)&server_add_structure,sizeof(server_add_structure));
            if(k<0)
	      {
	       printf("error in connecting to the server\n");
	       exit(1);
	      }
	    else
	     printf("sucessfully connected to server\n");  
	      
	 
	     printf("enter mssg for checking communication:-\n");
	     scanf("%s",arraybuff);
	        
	     printf("mssg=%s\n",arraybuff);
	     write(curr_socket,arraybuff,499);
             read(curr_socket,arraybuff,500);
	     printf("%s\n",arraybuff);
	//////////////////////////////dont disturb above part//////////////////////////////////////////////////////////////////

	
	
	




	     
	    while(1)
	       {
		     printf("ftp>");
		     scanf("%s",arraybuff);
	      

		     if(strcmp(arraybuff,"pwd")==0)
		          { //pwd of server
		             write(curr_socket,arraybuff,499);
		             
		          }


		     if(strcmp(arraybuff,"ls")==0)
		          { 
		             write(curr_socket,arraybuff,499);
		             read(curr_socket,arraybuff,5000);
		             printf("%s\n",arraybuff);

		          }



		     if(strcmp(arraybuff,"cd")==0)
		          { 
		   
		               printf("Enter the path : ");
			       scanf("%s", arraybuff + 3);
		               write(curr_socket,arraybuff,499);
		               read(curr_socket,arraybuff,5000);
		               if(arraybuff[0]=='s')
		                   printf("server directory changed u can check by pwd command\n");
		               else
		                   printf("error in changing directory\n");
	 
		          }



		     if(strcmp(arraybuff,"chmod")==0)
		          { 
		             write(curr_socket,arraybuff,499);
		             arraybuff[5]=' ';
		             printf("Enter permissin\n");
		             scanf("%s",arraybuff+6);
		             arraybuff[9]=' ';
		             printf("Enter filemane\n");
		             scanf("%s",arraybuff+10);
		             write(curr_socket,arraybuff,499);
		             read(curr_socket,arraybuff,5000);
		             if(arraybuff[0]=='s')
		                   printf("per changed\n");
		             else
		                   printf("err in changing per\n");
		         }



		     if(strcmp(arraybuff,"lls")==0)
		         {
		             system("ls");
		         }


		     if(strcmp(arraybuff,"lchmod")==0)
		          { 
		              // write(curr_socket,arraybuff,499);

		              strcpy(arraybuff,"chmod");
		              arraybuff[5]=' ';
		              printf("Enter permissin\n");
		              scanf("%s",arraybuff+6);
		              arraybuff[9]=' ';
		              printf("Enter filemane\n");
		              scanf("%s",arraybuff+10); 
		              if(system(arraybuff)!=-1)
		                    printf("permission changed of local file\n");
		              else
		                    printf("error in changing per of local file\n");

		          }

		  
		     if(strcmp(arraybuff,"lcd")==0)
		          {
		            strcpy(arraybuff,"cd");
                            printf("Enter the path : ");
			    scanf("%s", arraybuff + 3);
			    if(chdir(arraybuff+3) == 0)
			        printf("local directory changed u can check by lpwd command\n");
		            else
		                printf("error in changing local directory\n");
	 
                            
                            
		          } 


	      
		     if(strcmp(arraybuff,"lpwd")==0)
		          {
	       
		              strcpy(arraybuff,"pwd");
		              printf("present dir is:-\n");
		              system("pwd");

		          }



		     if(strcmp(arraybuff,"put")==0)
		          {  //send commad to server
		               write(curr_socket,arraybuff,499);
		               char fname[10];
		               FILE *f;
		               int f_size;
		               printf("Enter name of file to be put\n");
		               scanf("%s",fname);      
		               strcpy(arraybuff,fname); 
		               f = fopen(fname, "r");
		               if (f == NULL)
		                      {
		                            printf("\nFile not exists at client side\n");arraybuff[0]='0';write(curr_socket,arraybuff,499);//setting first char 0
		                      }
		               else                             
		                      {
		                             printf("\nyes file exists and uploading to server \n");
		                             write(curr_socket,arraybuff,499);//sending this filename to the server
		                             //reading the file
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
		                             //writing content into buffer
		                             write(curr_socket,arraybuff,5000);
		                             read(curr_socket,arraybuff,500);
		                             printf("%s\n",arraybuff);
		                       }

	      
		          }

		
		    if(strcmp(arraybuff,"get")==0)
		         {    //sending command
		              char fname1[10];
		              write(curr_socket,arraybuff,499);
		              printf("Enter name of file to get from server\n");
		              scanf("%s",fname1);
		              strcpy(arraybuff,fname1);
		              //sending file name to the server
		              write(curr_socket,arraybuff,499);
		              //is file exists??
		              read(curr_socket,arraybuff,500);
		              if(arraybuff[0]=='0')
		                    printf("file doesntn exists\n");
		              if(arraybuff[0]=='1')      
		                   {  
		                       printf("file exists and downloading to client\n");
		                       //getting file content from server and creating new file here
		                       read(curr_socket,arraybuff,5000);
		                       FILE *fp;
		                       fp = fopen(fname1, "w");
		                       if(fp!=NULL)
		                          {
		                             //printf("file created\n");
		                          }
		                       else
		                             printf("file not created\n");

		                       //writing into the file      
		                       //read(curr_socket,arraybuff,5000);
		                       fwrite(arraybuff, sizeof(char), sizeof(arraybuff), fp);
		                       fclose(fp);
		                       printf("File downloaded sucessfully\n");
		                    }




		         }

                    
                    if(strcmp(arraybuff,"close")==0)
                         {
                            write(curr_socket,arraybuff,499);
                            read(curr_socket,arraybuff,5000);
                              if(arraybuff[0]=='0')
                                 {
                                  printf("server closed\n");
                                  exit(0);
                                 }
                              else
                                 printf("error in closing server\n");
                              
                            
                         
                         
                         }




	            arraybuff[0]='\0';
	       
	     }//end of while

	}



