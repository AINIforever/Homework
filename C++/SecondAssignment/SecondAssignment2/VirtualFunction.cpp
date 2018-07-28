#include <iostream> 
using namespace std;

class shape{

 public:

   virtual void draw(){

   cout << "can not draw a general shape!"<<endl;

  }

};

class triangle:public shape{

public:  

    void draw(){

        cout << "  *  "<<endl;

        cout << " * * "<<endl;

        cout << "*****"<<endl;

    }

};

class rectangle:public shape{

public: 

    void draw(){

        cout << "*****"<<endl;

        cout << "*    *"<<endl;

        cout << "*****"<<endl;

    }

};

int main(int argc, char *argv[]){

	shape c;  triangle t;  rectangle r; 
   
	shape *p; 							

	shape &rt=t;   shape &rr=r; 		

	c.draw();   t.draw();  r.draw();	//A: c is a basic class object, it call the draw() defined in basic class;
										//	t and r is the subclass objects, they call draw() overload at subclass;

	p=&c;	p->draw();					//B: use pointer to call the functions;
    p=&t;   p->draw();					
	p=&r;	p->draw();					
    rt.draw();   rr.draw();				//C: use reference to call the functions;

 }
 /*1.What is the output? Is that the same as you imagin?
   If directly use the base class object to call the method, the realization of the virtual function;
   if the use of specific subclass call method, then realize the overload function at subclass;
   That is the same as I imagin.
	*/
/* 2.If we delete the keyword virtual in base class shape,what is the output? 
	B and C group will all call the function draw() in baisc class, they output:"can not draw a general shape!";
	Because they use the base class pointer or reference, without the virtual modifier, they will call the function draw() in basic class;	
	*/
/* 3.Outline the usage of virtual function in your words.
	to let the subclass can overload the function in basic class and to allow the use of the base class pointer to call the subclass of this function
	*/ 	

