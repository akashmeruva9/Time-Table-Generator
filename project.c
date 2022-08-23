	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<time.h>
	
	typedef struct faculitydetails 
	{
	    char faculityname[16];
	    char Subjectname[10];
	    short int lectures;
	    char start[30];
	    
	}fac;
	
        //GLOBAL VARIABLE DECLARATION
		     	
        fac app[100];                                                                              
	    int as[300] , section , share , sub , per ; 
		int i=0;        
		char univ[20], course[10] ;  
		
		
		 //*********************************************************
		 
    void Input()
    {
    	printf("\n\n\n\n--------------------------------------------------TIME TABLE GENERATOR-------------------------------------------------\n\n\n");
			
		printf("\tINPUT \n\t-----\n");
		
	    printf("  Enter the name of university :- ");
		gets(univ);                                     
		
		printf("  Enter the name of the course :-");
		scanf("%s" , course);                           
		
		printf("  Enter the number of sections :-");
		scanf("%d" , &section);                          
		
		printf("  Enter the number of subjects to be taught in this course :- ");
		scanf("%d" , &sub);      
		
		for(i=1; i<=sub ; i++)
		{
		printf("  Enter the name of subject %d :-" , i);
		scanf("%s" , app[i].Subjectname) ;
		}                                                    
		
		printf("  Enter the number of periods you want daily :- ");
		scanf("%d" , &per);     
		
		for(i=1; i<=per ; i++)                                              
		{
		printf("  Enter the start and end time of period %d and mention am or pm without gap !! \n  ex :-(9.00am-10.00am) :- " , i);
		scanf("%s" ,app[i].start);
		}
		  
		printf("\n\n  !! For %d subjects we will have %d different faculty \n  For each subject we will have many faculty \n  we have %d sections \n  Single faculty can't teach all sections\n  Enter the maximum no. of sections one faculty can teach \n  make sure that this number divides the no. of sections perfectly so that every faculty gets equal share of sections !!", sub , sub , section);   
		printf("\n  Enter :- ");
		scanf("%d" , &share); 
    }
        
//THE RANDOM NUMBERS GENERATING ALGORITHM
void randomfunction(int l , int m , int ad)
{
 
        srand(time(NULL));                                                                              
		int low =1 , upp=sub;
          
	   for(l=0 ; l<=per ; l++)
	   {
		  for(m=0 ; m<=6 ; m++)
		  {
			int u;
	        u = (rand()%(upp-low+1))+low;   
	        as[ad]=u; //it stores randomised subject index for every iteration 
	        ad++;
		   }
	   }
}

//THE PRINTING FUNCTION
void Print()
{      
		int div=section/share; 
	    int sec=1 ; 
	    int r=1 ;
		
		                                             
		for(r=1 ; r<=div ; r++)                                                    
		{
		int ad=0;
		int sec1=0;
		int k=0 , l=0 , m=0;                                                   
	
		printf("\n\n  Enter the names of faculty for %d of %d sections \n" , sec , sec+share-1);  
		
		for(i=1; i<=sub ; i++)
		{
		printf("  Enter the name of the lecturer for %s :-" ,app[i].Subjectname );    
		scanf("%s" , app[i].faculityname) ;
		}
		
		randomfunction(l,m,ad);
		
	    
  	    for(k=1 ; k<=share ; k ++)
	    {
	   	ad=0;
	    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf("  %s\n" , univ);
		printf("  %s\n" , course);
		printf("  section %d\n\n" , sec);
		printf("\n");
		
	    for(l=0 ; l<=per ; l++)
	    {     
		  for(m=0 ; m<=6 ; m++)
		  {
	
	        if(m==0&&l==0)
	        {
		       printf("  PERIOD");
		       
	           for(int z=1 ; z<16-strlen(app[l].start) ;z++) // this for loop is used for printing spaces  in the time table
	           {
			    printf(" ");   
	           }
	       }
	        else if(m==0)                   // for printing period names in the first column only !!
	        {
		
            	printf("  %s" , app[l].start);
            	
	            for(int z=1 ; z<20-strlen(app[l].start) ;z++)
	            {
				 printf(" ");
				}
	
	        }
	        else if(l==0)
	        {
		
	         switch(m)
	        {
                case 1:(m==1);
	            printf("MONDAY         ");
	            break;
	
	            case 2:(m==2);
	            printf("TUESDAY        ");
            	break;
	
            	case 3:(m==3);
            	printf("WEDNESDAY      ");
            	break;
	
            	case 4:(m==4);
            	printf("THURSDAY       ");
            	break;
	
            	case 5:(m==5);
            	printf("FRIDAY         ");
            	break;
	
            	case 6:(m==6);
            	printf("SATURDAY       \n");
	            break;
				
			}
	
	       }
           else
            	{
            		// THE RANDOMISED SUBJECT ARRANGING code 
            		
	                int g;
	                
                	g=as[ad];  
					                                                         
	                g=(g+sec1); 
					                                                    
		            if(g>sub)                                                        
	                {
			            g = g-(sub);                                                     
		            }
		            /*else if(g<0)                                                    
		            {
						g = g+(sub);
					}*/
				
	                printf("  %s" , app[g].Subjectname);                                  
                   	for(int z=1 ; z<14-strlen(app[g].Subjectname) ;z++)                            
	                {
					  printf(" ");
					}
		
	           }ad++;
	        }printf("\n"); 
		  }        
		    sec++;                                      
			printf("\n");
		    printf("  Faculty Name :-\n\n");
	    	for(i=1; i<=sub ; i++)
	    	{
		      printf("  %s - %s\n" , app[i].Subjectname , app[i].faculityname );
		    }
		    sec1++;  
		}                                                                                                                                                 
	}                                                                                         
}	     
  
int main()
{
	Input();
	Print();
    return 0;
}                                                   