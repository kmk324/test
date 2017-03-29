/**
 * Created by 민규 on 2017-03-29.
 */
public class OperatorEx24
{
public static void main (String [] args) {
    float f = 0.1f;
    double d = 0.1;
    double d2 = (double) f;

    System.out.println("10.0 == 10.0f ? " + (10.0 == 10.0f)); // true
    System.out.println("0.1== 0.1f ?" + (0.1 == 0.1f)); // false 값이 나온다. 정수형과 달리 실수형인 float과 double형은 근사값으로 저장되기 때문이다.
    System.out.println("f=" + f); // 0.1
    System.out.println("d= " + d); // 0.1
    System.out.println("d2= " + d2);    // d2값은 0.1000000000149011612 값이 출력 된다.
    System.out.println("d==f ? " + (d == f)); // false
    System.out.println("d==d2 ? " + (d == d2));  // false
    System.out.println("d2==f ? " + (d2 == f)); // true   d2를 선언할 때 float형 f 를 double형으로 형변환하여 좌변과 우변의 자료형이 다른데 왜 트루???
    System.out.println(0.1f==(double)0.1f); //test 용
    System.out.println((double)0.1); // test 용
}
}
