class Complex{
    private int real, imaginary;
    public Complex(int real, int imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }
    public void add(Complex C){
        System.out.println(this.real+C.real);
    }

class test5{
    public static void main(String[] args) {
        Complex C1 = new Complex(5,7);
        Complex C2 = new Complex(5,7);
        C2.add(C1);
    }
}