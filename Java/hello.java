/**
 * hello
 */
class A extends Exception{
    public String toString(){
        return "Shivam is dumb";
    }
}
public class hello {

    public static void main(String[] args) {
        try{
            if(false){
                System.out.println("try");
            }
            else{

                throw new A();
            }
        }catch(A a){ 
            System.out.println(a);
        }

    }
}