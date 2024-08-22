import java.math.BigInteger;
import java.util.Scanner;

class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(true){
            String s;
            s = in.nextLine();
            if(s.equals("0")) break;
            BigInteger bigInteger = new BigInteger(s);
            StringBuilder sb = new StringBuilder();
            sb.append(s).append(" is");
            if(!bigInteger.mod(new BigInteger("11")).equals(new BigInteger("0"))) {
                sb.append(" not");
            }
            sb.append(" a multiple of 11");
            System.out.println(sb.toString());
        }
        in.close();
    }
}