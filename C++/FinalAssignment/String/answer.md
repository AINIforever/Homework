# The answers for the class String





(a)What is the output?

    in constructor,nCharArray=0   
    // string s1 =  NULL.
    // Not create a char array in heap.
    in constructor,nCharArray=1   
    // string s2 =  "abc".
    // Create the 1st char array in heap.
    in constructor,nCharArray=1   
    // string s3 =  "abc", refernece to string s2.
    // Not create a char array in heap.
    in oprator[],nCharArray=2	  
    // we create a char array in heap.
    abc 	
    pbc 
    in operator=,nCharArray=2
    //For s1.str is a NULL pointer, we assign directly the copy of pointer in s3.str to s1.str.
    in operator=,nCharArray=1
    //We delete the pointer of s2.str,so there is only one char array in heap.
    //and then assign a copy of pointer in s3.str to s2.str.
    pbc
    pbc
    //Now there are two copies, and we output them.
    in destructor,nCharArray=1
    //we still have a char array in heap and two copies. Now we destruct one copy. 
    in destructor,nCharArray=1
    //we still have a char array in heap and one copy. Now we destruct the last copy.
    in destructor,nCharArray=0
    //We delete the pointer of the char array.





(b)What does nCharArray stand for?
 Is it equal to the number of String objects?

    1.nCharArray stands for the character arrays we alloc on heap.
    2.nCharArray is not necessarily equal to the number of String objects,
      because we use both shallow and deep copy to create string objects, and because we create s1 in stack.




    
(c)Why is the value of nCharArray less than the number of String objects?

    1.We can know from the object s1, is was created without initialization, so it is NULL, is not created in heap.
    2.We can know from the copy: String s3 = s2; We just link s3.str to s2.str. s3 is not in heap.



(d)In class String, str[0] is the reference count, whose maximum value is 255. Where is the content of String object?

    From str[1] to end.



(e)How can we know that two String objects share the same memory space?

    We know that the str[0] stands for the counter of the link number, and from str[1] to the end is the actual content of String object.
    This kind of mechanism remind me of the inode, which stores a piece of data similarily.
    So, we can look whether 	&(obj1.str) == &(obj2.str)  to know whether two String objects share the same memory space.