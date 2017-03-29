/**
 * Created by 민규 on 2017-03-29.
 */
// 비트 연산자
public class OperatorEx26 {
    public static void main (String[]  args) {
        int x = 3;
        int y = 5;

        System.out.println("x 는" + x + "이고 y는" + y + "일 때");
        System.out.println("x|y = " + (x | y));
        System.out.println("x&y = " + (x & y));
        System.out.println("x ^ y =" + (x ^ y));

        System.out.println("true | false = " + (true | false)); // |는 or 연산자.
        System.out.println("true & false =" + (true & false)); // &는 and 연산자
        System.out.println("true ^ false =" + (true ^ false)); //^는 xor연산자
    }
    }
