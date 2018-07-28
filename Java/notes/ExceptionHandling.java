//Exception handling
//Proram continue to excute instead of terminating

//principle: excptions should be handled as soon as possible

//Throwable: 1. unchecked: Error
//           2. checked: Exception

//demo
public class Demo {
    public static void main(String[] args){
        try{
            a();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    private static void a() throws Exception{
        b();
    } 
    private static void b() throws Exception{
        c();
    } 
    private static void c() throws Exception{
        try{
            d();
            g();
        }catch(FileNptFoundException e){//we have the rule that: first child exception
            e.printStackTrace();
        }catch(Exception e){
            e.printStackTrace();
        }

    } 
    // or:
    //     private static void c() throws Exception{
    //     d();
    //     g();
    // } 
    // private static void d() throws Exception{
        throw new FileNptFoundException("This is my first exception");
    } 
    private static void g() throws Exception{
        throw new Exception("This is my first exception");
    } 


    public int readFile(String name){
        //step1. open the file
        //step2. read the first line
        //step3. convert the first line to int
        //step4. read the second line
        //step5. perfrom +
        //step6. return result

        //step1. open the file
        int result = openfile();
        if(result==0){
            //step2. read the first line
            int result2 = readline();
            if(result2 == 0){
                //step3. convert the first line to int
                //TODO...
            }
            else{...}
        }
        else{...}//this method is too difficult, and hard to read
        return 0;
    }
}