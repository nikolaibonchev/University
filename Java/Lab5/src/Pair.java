public class Pair {
    private Object a;
    private Object b;

    public Object getA() {
        return a;
    }

    public void setA(Object a) {
        this.a = a;
    }

    public Object getB() {
        return b;
    }

    public void setB(Object b) {
        this.b = b;
    }

    public <K, V> void printPair() {
        System.out.println(a + " : " + b);
    }
}
