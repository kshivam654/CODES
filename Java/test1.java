import java.util.*;

class Complex{
    int real, imaginary;
    public Complex(int real, int imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }

    public void Add(Complex op){
        this.real += op.real;
        this.imaginary += op.imaginary;0
    }

    public void Print(){
        System.out.println("Real: "+ this.real);
        System.out.println("Imaginary: "+ this.imaginary);
    }

}

public class test1{

    static private void run1(){
        Scanner scanner = new Scanner(System.in);
        int real, imaginary;
        System.out.println("Enter the real and imaginary part: ");
        real = scanner.nextInt();
        imaginary = scanner.nextInt();
        Complex C1 = new Complex(real, imaginary);
        System.out.println("Enter the real and imaginary part: ");
        real = scanner.nextInt();
        imaginary = scanner.nextInt();
        Complex C2 = new Complex(real, imaginary);
        C2.Add(C1);
        C2.Print();
    }

    static private int rev(int a){
        int temp = 0;
        while(a > 0){
            temp = temp*10 + a%10;
            a = a/10;
        }
        return temp;
    }

    public static void main(String[] args) {

        //run1();

        int a = 122345;
        int b = rev(a);
        System.out.println("reverse is "+ b);

    }
}