import java.util.Scanner;
interface AClass{
    int x = 0;
    public void print();
}
abstract class B implements AClass{
    public void print() {
        System.out.println("Shivam");
    }
}
class C extends B{

    public void print() {
        System.out.println("Shivam");
    }
}
public class test extends B{
    public static void main(String[] args) {
        C c = new C();
        try{
            c.print();
        } catch(LinkageError linkageError){
            System.out.println("Error found");
        } finally{

            System.out.println("this needs to execute");
        }
        
    }
}
