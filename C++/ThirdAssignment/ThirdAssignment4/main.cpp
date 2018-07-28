#include <iostream>

int main(int argc, const char * argv[]) {
    static int count = -1;
    
    //1.Using break(only break current nested loop)
    for(int i=0;i<100;i++){
       
        for(int j=0;j<100;j++){
            
            for(int k=0;k<100;k++){
            	
                if( (i+j+k)%255==0 && (i+j+k) != 0 ){
					std::cout << "i:" << i << " j:" << j << " k:" << k << " sum:" << i+j+k << std::endl;
					std::cout << "Break in nested loop" << ++count << " times."<< std::endl;
                    break;
                }
            }
        }
    }
    
    //2.Using break(break all nested loops at once)
    #define QUIT_ALL {if(EXIT_ALL==1){break;}}
    int EXIT_ALL = 0;
    for(int i=0;i<100;i++){
    	QUIT_ALL;
        for(int j=0;j<100;j++){
		QUIT_ALL;   
            for(int k=0;k<100;k++){
			QUIT_ALL;	
                if( (i+j+k)%255==0 && (i+j+k) != 0 ){
                	EXIT_ALL = 1;
					std::cout << "i:" << i << " j:" << j << " k:" << k << " sum:" << i+j+k << std::endl;
					QUIT_ALL;
                }
            }
        }
    }
    std::cout << "Break " << ++count << " times."<< std::endl;
    //3.using goto
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                if( (i+j+k)%255==0 && (i+j+k) != 0 ){
                	std::cout << "i:" << i << " j:" << j << " k:" << k << " sum:" << i+j+k << std::endl;
                    goto exit_by_goto;
                }
            }
        }
    }
exit_by_goto:
    
    std::cout << "Break " << ++count << " times."<< std::endl;
    
    
    
    
    return 0;
}
//From these examples I have learn that "break" just can break the current nested loop, 
//while "goto" can jump all the nested loop at once!
//If I want to use "break" to break all the loop, I must use the method in 2.

